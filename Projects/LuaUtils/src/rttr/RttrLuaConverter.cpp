#include "rttr/RttrLuaConverter.h"

#include <cmath>
#include <cstring>
#include <limits>
#include <mutex>
#include <new>
#include <string_view>
#include <type_traits>
#include <unordered_set>
#include <utility>

#include <vector>

#include "CryEngine/CryCommon/CryString.h"
#include "REL.h"
#include "LuaHelpers.h"
#include "Offsets/vtables/IFunctionHandler.h"
#include "rttr/constructor.h"
#include "rttr/detail/class_data.h"
#include "rttr/detail/type_data.h"
#include "rttr/enumeration.h"
#include "rttr/instance.h"
#include "rttr/parameter_info.h"
#include "rttr/parameter_info_iterator.h"
#include "rttr/parameter_info_range.h"

namespace luautils {
namespace {

enum class ValueKind
{
    Unsupported,
    Bool,
    Char,
    SignedChar,
    UnsignedChar,
    Short,
    UnsignedShort,
    Int,
    UnsignedInt,
    Long,
    UnsignedLong,
    Int64,
    UInt64,
    Float,
    Double,
    LongDouble,
    WChar,
    String,
    CryString,
    Enumeration,
    Object,
    ObjectPointer
};

rttr::type StoredType(const rttr::detail::variant_data* data)
{
    return rttr::type(
        static_cast<rttr::detail::type_data*>(data->m_storage[1]));
}

void* ScalarAddress(rttr::detail::variant_data* data)
{
    return &data->m_storage[0];
}

void* StringAddress(rttr::detail::variant_data* data)
{
    return data->m_storage[0];
}

bool FillAddressContainer(rttr::detail::variant_data* data, void* argument,
                          void* value)
{
    if (!argument)
        return false;
    const rttr::type valueType = StoredType(data);
    auto* container = static_cast<rttr::instance*>(argument);
    container->m_type = valueType;
    container->m_rawType = valueType;
    container->m_ptr = value;
    container->m_rawPtr = value;
    return true;
}

bool ScalarPolicy(std::uint8_t operation,
                  rttr::detail::variant_data* data,
                  void* argument)
{
    using Operation = rttr::detail::variant_policy_operation;
    switch (static_cast<Operation>(operation)) {
    case Operation::destroy:
        return true;
    case Operation::clone:
    case Operation::swap:
        if (!argument)
            return false;
        *static_cast<rttr::detail::variant_data*>(argument) = *data;
        return true;
    case Operation::get_value:
    case Operation::get_ptr:
    case Operation::get_raw_ptr:
        if (!argument)
            return false;
        *static_cast<void**>(argument) = ScalarAddress(data);
        return true;
    case Operation::get_type:
    case Operation::get_raw_type:
        if (!argument)
            return false;
        *static_cast<rttr::type*>(argument) = StoredType(data);
        return true;
    case Operation::get_address_container:
        return FillAddressContainer(data, argument, ScalarAddress(data));
    case Operation::is_valid:
        return StoredType(data).is_valid();
    case Operation::is_nullptr:
        return false;
    default:
        return false;
    }
}

bool StringPolicy(std::uint8_t operation,
                  rttr::detail::variant_data* data,
                  void* argument)
{
    using Operation = rttr::detail::variant_policy_operation;
    switch (static_cast<Operation>(operation)) {
    case Operation::destroy:
        delete static_cast<std::string*>(data->m_storage[0]);
        data->m_storage[0] = nullptr;
        return true;
    case Operation::clone: {
        if (!argument || !data->m_storage[0])
            return false;
        auto* destination = static_cast<rttr::detail::variant_data*>(argument);
        destination->m_storage[0] = new std::string(
            *static_cast<const std::string*>(data->m_storage[0]));
        destination->m_storage[1] = data->m_storage[1];
        return true;
    }
    case Operation::swap:
        if (!argument)
            return false;
        *static_cast<rttr::detail::variant_data*>(argument) = *data;
        return true;
    case Operation::get_value:
    case Operation::get_ptr:
    case Operation::get_raw_ptr:
        if (!argument)
            return false;
        *static_cast<void**>(argument) = StringAddress(data);
        return true;
    case Operation::get_type:
    case Operation::get_raw_type:
        if (!argument)
            return false;
        *static_cast<rttr::type*>(argument) = StoredType(data);
        return true;
    case Operation::get_address_container:
        return FillAddressContainer(data, argument, StringAddress(data));
    case Operation::is_valid:
        return data->m_storage[0] && StoredType(data).is_valid();
    case Operation::is_nullptr:
        return false;
    default:
        return false;
    }
}

template <class T>
rttr::variant MakeScalarVariant(T value, rttr::type valueType)
{
    static_assert(std::is_trivially_copyable_v<T>);
    static_assert(sizeof(T) <= sizeof(void*));

    rttr::detail::variant_data data{};
    std::memcpy(&data.m_storage[0], &value, sizeof(value));
    data.m_storage[1] = valueType.m_type_data;
    return rttr::variant::from_policy(data, &ScalarPolicy);
}

rttr::variant MakeStringVariant(const char* value, rttr::type valueType)
{
    rttr::detail::variant_data data{};
    data.m_storage[0] = new std::string(value);
    data.m_storage[1] = valueType.m_type_data;
    return rttr::variant::from_policy(data, &StringPolicy);
}

// A std::string_view is NON-OWNING, so anything the game copies one into
// outlives the variant it came from (C_ObjectProperties::DeclaringType stores
// the view and dereferences it later, during dynamic pin synthesis). Views
// handed to the game must therefore point at a buffer that never dies:
// std::unordered_set is node-based, so interned strings keep stable addresses.
const std::string& InternString(const char* value)
{
    static std::mutex mutex;
    static std::unordered_set<std::string> pool;
    const std::lock_guard<std::mutex> lock(mutex);
    return *pool.emplace(value).first;
}

void* StringViewAddress(const rttr::detail::variant_data* data)
{
    return data->m_storage[0];
}

// Owns the 16-byte view object; the buffer it points at is interned.
bool StringViewPolicy(std::uint8_t operation,
                      rttr::detail::variant_data* data,
                      void* argument)
{
    using Operation = rttr::detail::variant_policy_operation;
    switch (static_cast<Operation>(operation)) {
    case Operation::destroy:
        delete static_cast<std::string_view*>(data->m_storage[0]);
        data->m_storage[0] = nullptr;
        return true;
    case Operation::clone: {
        if (!argument || !data->m_storage[0])
            return false;
        auto* destination = static_cast<rttr::detail::variant_data*>(argument);
        destination->m_storage[0] = new std::string_view(
            *static_cast<const std::string_view*>(data->m_storage[0]));
        destination->m_storage[1] = data->m_storage[1];
        return true;
    }
    case Operation::swap:
        if (!argument)
            return false;
        *static_cast<rttr::detail::variant_data*>(argument) = *data;
        return true;
    case Operation::get_value:
    case Operation::get_ptr:
    case Operation::get_raw_ptr:
        if (!argument)
            return false;
        *static_cast<void**>(argument) = StringViewAddress(data);
        return true;
    case Operation::get_type:
    case Operation::get_raw_type:
        if (!argument)
            return false;
        *static_cast<rttr::type*>(argument) = StoredType(data);
        return true;
    case Operation::get_address_container:
        return FillAddressContainer(data, argument, StringViewAddress(data));
    case Operation::is_valid:
        return data->m_storage[0] && StoredType(data).is_valid();
    case Operation::is_nullptr:
        return false;
    default:
        return false;
    }
}

rttr::variant MakeStringViewVariant(const char* value, rttr::type valueType)
{
    rttr::detail::variant_data data{};
    data.m_storage[0] = new std::string_view(InternString(value));
    data.m_storage[1] = valueType.m_type_data;
    return rttr::variant::from_policy(data, &StringViewPolicy);
}

// Same shape as StringPolicy, for the game's OWN COW string type: several
// registered converters (e.g. S_BuffDefinitionId, S_PlayerId) take
// CryStringT<char> as their source, not std::string -- convert_to only
// matches an EXACT (source, target) pair, so a std::string-sourced variant
// silently fails to find these even though a converter genuinely exists.
bool CryStringPolicy(std::uint8_t operation,
                    rttr::detail::variant_data* data,
                    void* argument)
{
    using Operation = rttr::detail::variant_policy_operation;
    switch (static_cast<Operation>(operation)) {
    case Operation::destroy:
        delete static_cast<CryStringT<char>*>(data->m_storage[0]);
        data->m_storage[0] = nullptr;
        return true;
    case Operation::clone: {
        if (!argument || !data->m_storage[0])
            return false;
        auto* destination = static_cast<rttr::detail::variant_data*>(argument);
        destination->m_storage[0] = new CryStringT<char>(
            *static_cast<const CryStringT<char>*>(data->m_storage[0]));
        destination->m_storage[1] = data->m_storage[1];
        return true;
    }
    case Operation::swap:
        if (!argument)
            return false;
        *static_cast<rttr::detail::variant_data*>(argument) = *data;
        return true;
    case Operation::get_value:
    case Operation::get_ptr:
    case Operation::get_raw_ptr:
        if (!argument)
            return false;
        *static_cast<void**>(argument) = data->m_storage[0];
        return true;
    case Operation::get_type:
    case Operation::get_raw_type:
        if (!argument)
            return false;
        *static_cast<rttr::type*>(argument) = StoredType(data);
        return true;
    case Operation::get_address_container:
        return FillAddressContainer(data, argument, data->m_storage[0]);
    case Operation::is_valid:
        return data->m_storage[0] && StoredType(data).is_valid();
    case Operation::is_nullptr:
        return false;
    default:
        return false;
    }
}

rttr::variant MakeCryStringVariant(const char* value, rttr::type valueType)
{
    rttr::detail::variant_data data{};
    data.m_storage[0] = new CryStringT<char>(value);
    data.m_storage[1] = valueType.m_type_data;
    return rttr::variant::from_policy(data, &CryStringPolicy);
}

rttr::type CryStringType()
{
    static const rttr::type resolved = [] {
        for (const char* name : {"classCryStringT<char>", "CryStringT<char>"}) {
            const rttr::type candidate = rttr::type::get_by_name(name);
            if (candidate.is_valid())
                return candidate;
        }
        return rttr::type{};
    }();
    return resolved;
}


// Construct an EMPTY, game-owned container variant of `containerType` by
// invoking the type's own registered default constructor -- the same
// reflection path the game uses to build UI screens. No per-type addresses:
// every step is a field read off the type's class_data.
//
//   type_data(+0xB8 factory) -> class_data -> m_ctors[0] -> constructor_wrapper
//   -> vtable[15] = `variant invoke()` (zero-arg). Verified as_object for the
//   value-vector types (sizeof 0x18, ctors=1): the returned variant carries
//   the game's own container policy at +0x10 and, at +0x00, a pointer to a
//   freshly heap-allocated, empty {0,0,0} vector. That policy answers every
//   opcode natively (sequential view, compare, destroy) -- which is exactly
//   why this replaces our hand-rolled ArrayPolicy and its view-filler table.
//
// Returns an invalid variant if the type has no reachable default constructor.
rttr::variant ConstructEmptyContainer(rttr::type containerType)
{
    rttr::detail::type_data* typeData = containerType.m_type_data;
    if (!typeData || !typeData->get_class_data)
        return rttr::variant{};

    rttr::detail::class_data& classData = typeData->get_class_data();
    if (classData.m_ctors.empty())
        return rttr::variant{};

    const rttr::detail::constructor_wrapper_base* wrapper =
        reinterpret_cast<const rttr::detail::constructor_wrapper_base*>(
            classData.m_ctors[0].m_wrapper);
    if (!wrapper)
        return rttr::variant{};

    // constructor_wrapper_base vtable slot 15 = `variant invoke()` (zero args),
    // writing the constructed variant through the second (output) argument.
    using InvokeFn = void* (__fastcall*)(const void* self, void* out);
    void* const* const vtable = *reinterpret_cast<void* const* const*>(wrapper);
    const auto invoke = reinterpret_cast<InvokeFn>(vtable[15]);

    // Raw storage for the output variant: the game writes m_data(+0x00) and
    // m_policy(+0x10) directly and leaves m_storage[1] untouched, so zero-init
    // first (matches a fresh game-side variant). Bytes only -- no variant dtor
    // runs on `buffer`; the returned from_policy variant becomes sole owner.
    alignas(rttr::variant) unsigned char buffer[sizeof(rttr::variant)] = {};
    invoke(wrapper, buffer);

    // Layout: [m_data : variant_data (0x10)][m_policy : policy_func (0x8)].
    const rttr::detail::variant_data data =
        *reinterpret_cast<const rttr::detail::variant_data*>(buffer);
    const auto policy = *reinterpret_cast<rttr::variant::policy_func*>(
        buffer + sizeof(rttr::detail::variant_data));
    if (!policy || !data.m_storage[0])
        return rttr::variant{};
    return rttr::variant::from_policy(data, policy);
}

// Identity compare shared by the two pointer-shaped policies. Reached via the
// compare helper 0x1804F86E4, which always dispatches to the LEFT variant's
// policy with {uint8* equal_out, variant* other, variant* self}. Compares
// against the other side's address container: its m_rawPtr is the
// fully-dereferenced object pointer under every observed policy shape --
// heap-container and inline-value policies store it directly, and the
// sequential view's element-reference policy (0x180825C0C) double-derefs its
// slot pointer there while its get_value/get_ptr/get_raw_ptr return storage
// addresses instead. Both the out byte and the return value carry equality --
// C_ContainsElement breaks its element loop on the return value.
bool ComparePointeeIdentity(void* pointee, void* argument)
{
    using Operation = rttr::detail::variant_policy_operation;
    if (!argument)
        return false;
    void** args = static_cast<void**>(argument);
    auto* equalOut = static_cast<std::uint8_t*>(args[0]);
    const auto* other = static_cast<const rttr::variant*>(args[1]);
    if (!equalOut || !other || !other->m_policy)
        return false;
    rttr::instance box{};
    if (!other->m_policy(
            static_cast<std::uint8_t>(Operation::get_address_container),
            const_cast<rttr::detail::variant_data*>(&other->m_data),
            &box))
        return false;
    const bool equal = box.m_rawPtr == pointee;
    *equalOut = equal ? 1 : 0;
    return equal;
}

// Non-owning: storage[0] IS the pointer itself (not "address of", unlike
// ScalarPolicy's inline scalar), and destroy is a no-op -- the pointee is
// natively owned elsewhere (e.g. a C_Soul* resolved via C_SoulList).
// The stored type is the OBJECT type `T`; for a port declaring the pointer
// type `T*` use TypedPointerPolicy instead -- see its comment for why the
// two cannot share one accessor shape.
bool ObjectPointerPolicy(std::uint8_t operation,
                         rttr::detail::variant_data* data,
                         void* argument)
{
    using Operation = rttr::detail::variant_policy_operation;
    switch (static_cast<Operation>(operation)) {
    case Operation::destroy:
        return true;
    case Operation::clone:
    case Operation::swap:
        if (!argument)
            return false;
        *static_cast<rttr::detail::variant_data*>(argument) = *data;
        return true;
    case Operation::get_value:
    case Operation::get_ptr:
    case Operation::get_raw_ptr:
        if (!argument)
            return false;
        *static_cast<void**>(argument) = data->m_storage[0];
        return true;
    case Operation::get_type:
    case Operation::get_raw_type:
        if (!argument)
            return false;
        *static_cast<rttr::type*>(argument) = StoredType(data);
        return true;
    case Operation::get_address_container:
        return FillAddressContainer(data, argument, data->m_storage[0]);
    case Operation::compare_equal:
        return ComparePointeeIdentity(data->m_storage[0], argument);
    case Operation::is_valid:
        return data->m_storage[0] && StoredType(data).is_valid();
    case Operation::is_nullptr:
        return data->m_storage[0] == nullptr;
    default:
        return false;
    }
}

// A variant whose stored TYPE is a pointer type `T*` -- what a port declaring
// `T*` reads back. storage[0] is still the pointee address, but the two
// pointer accessors must now answer DIFFERENTLY, and both consumers matter:
//   get_value / get_ptr -> &storage[0], because the game's exact-type read
//       (0x1823C8F84, policy opcode 5) does `*(void**)get_value(...)` and has
//       to land on the pointer VALUE;
//   get_raw_ptr, and instance.m_rawPtr -> storage[0], the fully dereferenced
//       object, which is what every instance-based reflected call reads.
// Neither existing policy can serve: ObjectPointerPolicy collapses both onto
// storage[0] (correct for an object-typed variant) and ScalarPolicy collapses
// both onto &storage[0] (correct for an inline scalar). get_raw_type reports
// the pointee class, matching how the game types `T*` (raw_type_data of the
// `T*` type_data is the `T` type_data -- measured).
bool TypedPointerPolicy(std::uint8_t operation,
                        rttr::detail::variant_data* data,
                        void* argument)
{
    using Operation = rttr::detail::variant_policy_operation;
    switch (static_cast<Operation>(operation)) {
    case Operation::destroy:
        return true;
    case Operation::clone:
    case Operation::swap:
        if (!argument)
            return false;
        *static_cast<rttr::detail::variant_data*>(argument) = *data;
        return true;
    case Operation::get_value:
    case Operation::get_ptr:
        if (!argument)
            return false;
        *static_cast<void**>(argument) = ScalarAddress(data);
        return true;
    case Operation::get_raw_ptr:
        if (!argument)
            return false;
        *static_cast<void**>(argument) = data->m_storage[0];
        return true;
    case Operation::get_type:
        if (!argument)
            return false;
        *static_cast<rttr::type*>(argument) = StoredType(data);
        return true;
    case Operation::get_raw_type:
        if (!argument)
            return false;
        *static_cast<rttr::type*>(argument) = StoredType(data).get_raw_type();
        return true;
    case Operation::get_address_container: {
        if (!argument)
            return false;
        const rttr::type pointerType = StoredType(data);
        auto* container = static_cast<rttr::instance*>(argument);
        container->m_type = pointerType;
        container->m_rawType = pointerType.get_raw_type();
        container->m_ptr = ScalarAddress(data);
        container->m_rawPtr = data->m_storage[0];
        return true;
    }
    case Operation::compare_equal:
        return ComparePointeeIdentity(data->m_storage[0], argument);
    case Operation::is_valid:
        return data->m_storage[0] && StoredType(data).is_valid();
    case Operation::is_nullptr:
        return data->m_storage[0] == nullptr;
    default:
        return false;
    }
}

rttr::type GameStringType()
{
    // The registry key is the derive_name spelling (whitespace-stripped, cv
    // keywords kept); registered string->T converters are keyed off this
    // source type, so a string variant must carry it to convert.
    static const rttr::type resolved = [] {
        for (const char* name : {
                 "classstd::basic_string<char,structstd::char_traits<char>,"
                 "classstd::allocator<char>>",
                 "std::string" }) {
            const rttr::type candidate = rttr::type::get_by_name(name);
            if (candidate.is_valid())
                return candidate;
        }
        return rttr::type{};
    }();
    return resolved;
}

// A variant's sequential VIEW: 21 qwords the policy's create_sequential_view
// case (opcode 0xE) hands to the per-container filler, which authors every
// slot (verified for Souls 0x1810DC86C and Strings 0x1806DF698 -- both write
// [0..20], so zero-init needs no stub pre-fill). Operation slots take the
// CONTAINER pointer (slot [2]), not the view; accessor comments carry each
// op's view qword index.
struct GameSequentialView
{
    rttr::type containerType;  // [0]
    rttr::type elementType;    // [1] the insert ops' gate type: they compare
                               //     argument[2] against it VERBATIM and
                               //     return end() without inserting on any
                               //     mismatch (Souls 0x180F0FDB4, Strings
                               //     0x180F105D8)
    void* container = nullptr; // [2]
    void* ops[18] = {};        // [3..20]

    using SizeOp = std::size_t(__fastcall*)(void* container);
    using EndOp = void(__fastcall*)(void* container, void** payloadOut);
    using CleanupOp = void(__fastcall*)(void** payload);
    using InsertOp = void(__fastcall*)(void* container, void** argument,
                                       void** positionPayload,
                                       void** payloadOut);

    std::size_t Size() const  // view[4]
    {
        return reinterpret_cast<SizeOp>(ops[1])(container);
    }
    void End(void** payloadOut) const  // view[10]
    {
        reinterpret_cast<EndOp>(ops[7])(container, payloadOut);
    }
    void CleanupIterator(void** payload) const  // view[13]
    {
        reinterpret_cast<CleanupOp>(ops[10])(payload);
    }
    void Insert(void** argument, void** positionPayload,
                void** payloadOut) const  // view[18]
    {
        reinterpret_cast<InsertOp>(ops[15])(container, argument,
                                            positionPayload, payloadOut);
    }
    bool IsUsable() const
    {
        return container && elementType.is_valid() && ops[1] && ops[7] &&
               ops[10] && ops[15];
    }
};
static_assert(sizeof(GameSequentialView) == 21 * sizeof(void*),
              "sequential view is 21 qwords");

// Mints the variant for one TEXT element: route the text through the game's
// registered converters to the container's element type (std::string source
// first, CryStringT source second -- the same two-source order ConvertValue
// uses; std::string -> CryStringT is registered, converter RTTI 0x184A7A280).
bool MintTextElement(const std::string& text, rttr::type elementType,
                     rttr::variant& out)
{
    const rttr::type stringType = GameStringType();
    if (stringType.is_valid()) {
        const rttr::variant source =
            MakeStringVariant(text.c_str(), stringType);
        if (source.convert_to(elementType, out) && out.is_valid())
            return true;
    }
    const rttr::type cryStringType = CryStringType();
    if (cryStringType.is_valid()) {
        const rttr::variant source =
            MakeCryStringVariant(text.c_str(), cryStringType);
        if (source.convert_to(elementType, out) && out.is_valid())
            return true;
    }
    return false;
}

// Fills a game-constructed container through its own sequential view -- the
// same loop C_MakeArray::GetPortValue (0x1806A98B8) runs over its pins: per
// element, an {value address, variant, type} argument triple (the shape the
// game's argument ctor 0x1804F81F8 builds via get_ptr + get_type) is
// inserted at end(). Success is proven by the view's own size after every
// insert, never assumed: the insert ops refuse silently by returning end().
bool FillSequentialContainer(
    rttr::variant& container,
    const std::vector<RttrLuaConverter::ArrayElement>& elements,
    std::string& error)
{
    GameSequentialView view{};
    container.m_policy(
        static_cast<std::uint8_t>(
            rttr::detail::variant_policy_operation::create_sequential_view),
        &container.m_data, &view);
    if (!view.IsUsable()) {
        error = "the container type did not produce a usable sequential view";
        return false;
    }
    const rttr::type elementType = view.elementType;

    for (std::size_t index = 0; index < elements.size(); ++index) {
        const RttrLuaConverter::ArrayElement& element = elements[index];
        rttr::variant value;
        if (element.isText) {
            if (!MintTextElement(element.text, elementType, value)) {
                error = "element " + std::to_string(index + 1) + " ('" +
                    element.text + "') has no registered conversion to '" +
                    RttrLuaConverter::GetTypeName(elementType) + "'";
                return false;
            }
        } else {
            // An object pointer IS the element value for vector<T*>; the
            // variant must carry the view's exact element type to pass the
            // insert gate, and ScalarPolicy's get_ptr answers the address
            // of the stored value, which is what the insert copies from.
            if (!elementType.m_type_data ||
                elementType.m_type_data->get_pointer_dimension != 1) {
                error = "element " + std::to_string(index + 1) +
                    " is an object handle, but '" +
                    RttrLuaConverter::GetTypeName(elementType) +
                    "' elements are not object pointers";
                return false;
            }
            rttr::detail::variant_data data{};
            data.m_storage[0] = element.pointer;
            data.m_storage[1] = elementType.m_type_data;
            value = rttr::variant::from_policy(data, &ScalarPolicy);
        }

        void* argument[3] = {};
        value.m_policy(
            static_cast<std::uint8_t>(
                rttr::detail::variant_policy_operation::get_ptr),
            &value.m_data, &argument[0]);
        argument[1] = &value;
        value.m_policy(
            static_cast<std::uint8_t>(
                rttr::detail::variant_policy_operation::get_type),
            &value.m_data, &argument[2]);

        const std::size_t before = view.Size();
        void* endPayload = nullptr;
        view.End(&endPayload);
        void* insertedPayload = nullptr;
        view.Insert(argument, &endPayload, &insertedPayload);
        view.CleanupIterator(&endPayload);
        view.CleanupIterator(&insertedPayload);
        if (view.Size() != before + 1) {
            error = "the container refused element " +
                std::to_string(index + 1) + " (inserted type '" +
                RttrLuaConverter::GetTypeName(value.get_type()) +
                "' vs element type '" +
                RttrLuaConverter::GetTypeName(elementType) + "')";
            return false;
        }
    }
    return true;
}

template <class T>
bool ReadIntegral(float number, T& value, std::string& error)
{
    static_assert(std::is_integral_v<T>);
    const double converted = static_cast<double>(number);
    if (std::trunc(converted) != converted) {
        error = "argument must be an integral number";
        return false;
    }
    if (converted < static_cast<double>(std::numeric_limits<T>::lowest()) ||
        converted > static_cast<double>(std::numeric_limits<T>::max())) {
        error = "integral argument is outside the reflected type's range";
        return false;
    }
    value = static_cast<T>(converted);
    return true;
}

template <class T>
T ReadScalarValue(const rttr::variant& value)
{
    T result{};
    if (void* source = value.get_value())
        std::memcpy(&result, source, sizeof(result));
    return result;
}

std::string_view RawTypeName(rttr::type valueType)
{
    if (!valueType.m_type_data)
        return {};
    return valueType.m_type_data->type_name;
}

bool IsStdString(rttr::type valueType)
{
    if (!valueType.is_class() || valueType.get_sizeof() != sizeof(std::string))
        return false;

    std::string compact;
    const std::string_view rawName = RawTypeName(valueType);
    compact.reserve(rawName.size());
    for (char character : rawName) {
        if (character != ' ' && character != '\t' &&
            character != '\r' && character != '\n')
            compact.push_back(character);
    }
    return compact ==
        "classstd::basic_string<char,structstd::char_traits<char>,classstd::allocator<char>>";
}

bool IsStdStringView(rttr::type valueType)
{
    if (!valueType.is_class() || valueType.get_sizeof() != sizeof(std::string_view))
        return false;
    return RawTypeName(valueType).find("basic_string_view") !=
           std::string_view::npos;
}

bool IsCryString(rttr::type valueType)
{
    if (!valueType.is_class() ||
        valueType.get_sizeof() != sizeof(CryStringT<char>))
        return false;
    std::string compact;
    const std::string_view rawName = RawTypeName(valueType);
    compact.reserve(rawName.size());
    for (char character : rawName) {
        if (character != ' ' && character != '\t' &&
            character != '\r' && character != '\n')
            compact.push_back(character);
    }
    return compact == "classCryStringT<char>" || compact == "CryStringT<char>";
}

bool IsContainer(rttr::type valueType)
{
    if (!valueType.m_type_data)
        return false;
    const auto& traits = valueType.m_type_data->m_type_traits;
    return traits.test(static_cast<std::size_t>(
               rttr::detail::type_trait_infos::is_associative_container)) ||
           traits.test(static_cast<std::size_t>(
               rttr::detail::type_trait_infos::is_sequential_container));
}

ValueKind Classify(rttr::type valueType)
{
    if (!valueType.is_valid())
        return ValueKind::Unsupported;
    if (valueType.is_arithmetic()) {
        const std::string_view name = RawTypeName(valueType);
        if (name == "bool") return ValueKind::Bool;
        if (name == "char") return ValueKind::Char;
        if (name == "signed char") return ValueKind::SignedChar;
        if (name == "unsigned char") return ValueKind::UnsignedChar;
        if (name == "short") return ValueKind::Short;
        if (name == "unsigned short") return ValueKind::UnsignedShort;
        if (name == "int") return ValueKind::Int;
        if (name == "unsigned int") return ValueKind::UnsignedInt;
        if (name == "long") return ValueKind::Long;
        if (name == "unsigned long") return ValueKind::UnsignedLong;
        if (name == "__int64") return ValueKind::Int64;
        if (name == "unsigned __int64") return ValueKind::UInt64;
        if (name == "float") return ValueKind::Float;
        if (name == "double") return ValueKind::Double;
        if (name == "long double") return ValueKind::LongDouble;
        if (name == "wchar_t") return ValueKind::WChar;
        return ValueKind::Unsupported;
    }
    if (valueType.is_enumeration())
        return ValueKind::Enumeration;
    if (IsStdString(valueType))
        return ValueKind::String;
    if (IsCryString(valueType))
        return ValueKind::CryString;
    if (valueType.is_pointer())
        return valueType.get_raw_type().is_class()
            ? ValueKind::ObjectPointer
            : ValueKind::Unsupported;
    if (valueType.is_class() && !IsContainer(valueType))
        return ValueKind::Object;
    return ValueKind::Unsupported;
}

bool ReadAny(Offsets::IFunctionHandler* pH, int index,
             ScriptAnyValue& value, std::string& error)
{
    if (index < 1 || index > pH->GetParamCount()) {
        error = "missing required argument";
        return false;
    }
    value.type = ANY_ANY;
    value.table = nullptr;
    if (!pH->GetParamAny(index, value)) {
        error = "could not read argument";
        return false;
    }
    return true;
}

bool ReadRegistryToken(const ScriptAnyValue& value,
                       RttrHandleRegistry::Handle& handle,
                       std::string& error)
{
    if (value.type != ANY_THANDLE || value.nHandle == 0) {
        error = "argument must be a nonzero RTTR handle";
        return false;
    }
    handle = static_cast<RttrHandleRegistry::Handle>(value.nHandle);
    return true;
}

bool RequireExactResultType(const rttr::variant& value,
                            rttr::type declaredType,
                            std::string& error)
{
    const rttr::type actualType = value.get_type();
    if (actualType == declaredType)
        return true;
    error = "reflected result type '" + RttrLuaConverter::GetTypeName(actualType) +
            "' does not match declared type '" +
            RttrLuaConverter::GetTypeName(declaredType) + "'";
    return false;
}

}  // namespace

RttrLuaConverter::RttrLuaConverter(RttrHandleRegistry& registry) noexcept
    : m_registry(registry)
{}

rttr::variant RttrLuaConverter::MakeObjectPointerVariant(void* pointer,
                                                         rttr::type valueType)
{
    rttr::detail::variant_data data{};
    data.m_storage[0] = pointer;
    data.m_storage[1] = valueType.m_type_data;
    return rttr::variant::from_policy(data, &ObjectPointerPolicy);
}

rttr::variant RttrLuaConverter::MakeTypedPointerVariant(void* pointee,
                                                        rttr::type pointerType)
{
    if (!pointee || !pointerType.is_valid() || !pointerType.is_pointer())
        return rttr::variant{};
    rttr::detail::variant_data data{};
    data.m_storage[0] = pointee;
    data.m_storage[1] = pointerType.m_type_data;
    return rttr::variant::from_policy(data, &TypedPointerPolicy);
}

rttr::variant RttrLuaConverter::MakeArrayVariant(
    std::vector<ArrayElement>&& elements, rttr::type containerType,
    std::string& error)
{
    // Ask the game to construct an empty container of this type; the result is
    // game-owned and carries the game's own container policy, so every read
    // path (sequential view, contains, length) works natively -- no hand-rolled
    // policy, no per-type addresses. Elements are then inserted through the
    // container's own sequential view, the same loop C_MakeArray runs over its
    // pins, so element construction and ownership stay game-side for every
    // element kind (object pointers and strings alike).
    rttr::variant container = ConstructEmptyContainer(containerType);
    if (!container.is_valid()) {
        error = "'" + GetTypeName(containerType) +
            "' is not default-constructible via reflection";
        return rttr::variant{};
    }
    if (elements.empty())
        return container;  // empty is already correct
    if (!FillSequentialContainer(container, elements, error))
        return rttr::variant{};
    return container;
}

bool RttrLuaConverter::GetHandleParam(Offsets::IFunctionHandler* pH, int index,
                                      RttrHandleRegistry::Handle& handle,
                                      std::string& error) const
{
    ScriptAnyValue value;
    return ReadAny(pH, index, value, error) &&
           ReadRegistryToken(value, handle, error);
}

const rttr::variant* RttrLuaConverter::ResolveObject(
    RttrHandleRegistry::Handle handle, rttr::type declaringType,
    std::string& error) const
{
    if (!declaringType.is_valid() || !declaringType.is_class()) {
        error = "declaring type is not a reflected class";
        return nullptr;
    }

    const rttr::variant* value = m_registry.Lookup(handle);
    if (!value) {
        error = "unknown or stale RTTR handle";
        return nullptr;
    }

    const rttr::type actualType = value->get_type();
    const rttr::instance object(*value);
    if (!object.m_rawPtr) {
        error = "RTTR handle contains a null object";
        return nullptr;
    }

    rttr::type objectType = object.m_rawType;
    if (objectType.is_pointer())
        objectType = objectType.get_raw_type();
    if (!objectType.is_class()) {
        error = "RTTR handle does not contain an object";
        return nullptr;
    }

    if (objectType != declaringType && !objectType.is_derived_from(declaringType)) {
        error = "RTTR handle type '" + GetTypeName(actualType) +
                "' is incompatible with declaring type '" +
                GetTypeName(declaringType) + "'";
        return nullptr;
    }
    return value;
}

bool RttrLuaConverter::BuildArguments(
    Offsets::IFunctionHandler* pH, int firstIndex, const rttr::method& method,
    std::vector<rttr::variant>& values,
    std::vector<rttr::argument>& arguments,
    std::string& error) const
{
    rttr::parameter_info_range parameters = method.get_parameter_infos();
    const std::size_t parameterCount = parameters.size();
    const int suppliedCount = pH->GetParamCount() >= firstIndex
        ? pH->GetParamCount() - firstIndex + 1
        : 0;
    if (suppliedCount > static_cast<int>(parameterCount)) {
        error = "too many arguments for reflected method";
        return false;
    }

    values.clear();
    arguments.clear();
    values.reserve(parameterCount);
    arguments.reserve(parameterCount);

    std::size_t parameterIndex = 0;
    for (auto iterator = parameters.begin(); iterator != parameters.end();
         ++iterator, ++parameterIndex) {
        const rttr::parameter_info& parameter = *iterator;
        const rttr::type expectedType = parameter.get_type();
        rttr::variant converted;
        std::string conversionError;

        if (parameterIndex < static_cast<std::size_t>(suppliedCount)) {
            ScriptAnyValue input;
            if (!ReadAny(pH, firstIndex + static_cast<int>(parameterIndex),
                         input, conversionError) ||
                !ConvertValue(input, expectedType, converted,
                              conversionError)) {
                const std::string parameterName(parameter.get_name());
                error = "argument " + std::to_string(parameterIndex + 1);
                if (!parameterName.empty())
                    error += " ('" + parameterName + "')";
                error += ": " + conversionError;
                return false;
            }
        } else {
            if (!parameter.has_default_value()) {
                error = "missing required argument " +
                        std::to_string(parameterIndex + 1);
                return false;
            }
            converted = parameter.get_default_value();
            if (!converted.is_valid()) {
                error = "reflected default for argument " +
                        std::to_string(parameterIndex + 1) + " is invalid";
                return false;
            }
        }
        values.emplace_back(std::move(converted));
    }

    for (const rttr::variant& value : values)
        arguments.emplace_back(value);
    return true;
}

bool RttrLuaConverter::ConvertValue(const ScriptAnyValue& value,
                                    rttr::type expectedType,
                                    rttr::variant& result,
                                    std::string& error) const
{
    const ValueKind kind = Classify(expectedType);
    if (kind == ValueKind::LongDouble) {
        error = "long double parameters are not supported";
        return false;
    }
    if (kind == ValueKind::WChar) {
        error = "wchar_t parameters are not supported";
        return false;
    }

    if (kind == ValueKind::Bool) {
        if (value.type != ANY_TBOOLEAN) {
            error = "argument must be a Boolean";
            return false;
        }
        result = MakeScalarVariant(value.b, expectedType);
        return true;
    }

    if (kind == ValueKind::Int64 || kind == ValueKind::UInt64) {
        if (value.type != ANY_THANDLE) {
            error = "64-bit arithmetic arguments require ScriptHandle transport";
            return false;
        }
        if (kind == ValueKind::Int64)
            result = MakeScalarVariant(static_cast<std::int64_t>(value.nHandle),
                                       expectedType);
        else
            result = MakeScalarVariant(static_cast<std::uint64_t>(value.nHandle),
                                       expectedType);
        return true;
    }

    if (kind == ValueKind::Float || kind == ValueKind::Double) {
        if (value.type != ANY_TNUMBER || !std::isfinite(value.number)) {
            error = "argument must be a finite number";
            return false;
        }
        if (kind == ValueKind::Float)
            result = MakeScalarVariant(value.number, expectedType);
        else
            result = MakeScalarVariant(static_cast<double>(value.number),
                                       expectedType);
        return true;
    }

    if (kind >= ValueKind::Char && kind <= ValueKind::UnsignedLong) {
        if (value.type != ANY_TNUMBER || !std::isfinite(value.number)) {
            error = "argument must be a finite number";
            return false;
        }
        switch (kind) {
        case ValueKind::Char: {
            char converted{};
            if (!ReadIntegral(value.number, converted, error)) return false;
            result = MakeScalarVariant(converted, expectedType);
            return true;
        }
        case ValueKind::SignedChar: {
            signed char converted{};
            if (!ReadIntegral(value.number, converted, error)) return false;
            result = MakeScalarVariant(converted, expectedType);
            return true;
        }
        case ValueKind::UnsignedChar: {
            unsigned char converted{};
            if (!ReadIntegral(value.number, converted, error)) return false;
            result = MakeScalarVariant(converted, expectedType);
            return true;
        }
        case ValueKind::Short: {
            short converted{};
            if (!ReadIntegral(value.number, converted, error)) return false;
            result = MakeScalarVariant(converted, expectedType);
            return true;
        }
        case ValueKind::UnsignedShort: {
            unsigned short converted{};
            if (!ReadIntegral(value.number, converted, error)) return false;
            result = MakeScalarVariant(converted, expectedType);
            return true;
        }
        case ValueKind::Int: {
            int converted{};
            if (!ReadIntegral(value.number, converted, error)) return false;
            result = MakeScalarVariant(converted, expectedType);
            return true;
        }
        case ValueKind::UnsignedInt: {
            unsigned int converted{};
            if (!ReadIntegral(value.number, converted, error)) return false;
            result = MakeScalarVariant(converted, expectedType);
            return true;
        }
        case ValueKind::Long: {
            long converted{};
            if (!ReadIntegral(value.number, converted, error)) return false;
            result = MakeScalarVariant(converted, expectedType);
            return true;
        }
        case ValueKind::UnsignedLong: {
            unsigned long converted{};
            if (!ReadIntegral(value.number, converted, error)) return false;
            result = MakeScalarVariant(converted, expectedType);
            return true;
        }
        default:
            break;
        }
    }

    if (kind == ValueKind::String) {
        if (value.type != ANY_TSTRING || !value.str) {
            error = "argument must be a string";
            return false;
        }
        result = MakeStringVariant(value.str, expectedType);
        return true;
    }

    if (kind == ValueKind::CryString) {
        if (value.type != ANY_TSTRING || !value.str) {
            error = "argument must be a string";
            return false;
        }
        result = MakeCryStringVariant(value.str, expectedType);
        return true;
    }

    if (kind == ValueKind::Enumeration || kind == ValueKind::Object ||
        kind == ValueKind::ObjectPointer) {
        if (value.type == ANY_TSTRING && value.str) {
            if (kind == ValueKind::Enumeration) {
                const rttr::enumeration enumeration =
                    expectedType.get_enumeration();
                if (enumeration.is_valid()) {
                    rttr::variant named = enumeration.name_to_value(value.str);
                    if (named.is_valid()) {
                        result = std::move(named);
                        return true;
                    }
                }
                error = "'" + std::string(value.str) +
                        "' is not a value of reflected enumeration '" +
                        GetTypeName(expectedType) + "'";
                return false;
            }
            // A string_view target must be built directly over an interned
            // buffer: routing it through convert_to would leave the view
            // pointing into the temporary source variant's string.
            if (IsStdStringView(expectedType)) {
                result = MakeStringViewVariant(value.str, expectedType);
                return true;
            }
            // Route string inputs through the game's own registered
            // converters (variant convert 0x1804F9640) -- the same machinery
            // that types authored SKALD graph constants, so whatever the game
            // registered (item-class GUIDs, WUIDs, ...) becomes passable.
            const rttr::type stringType = GameStringType();
            if (stringType.is_valid()) {
                const rttr::variant source =
                    MakeStringVariant(value.str, stringType);
                rttr::variant converted;
                if (source.convert_to(expectedType, converted) &&
                    converted.is_valid()) {
                    result = std::move(converted);
                    return true;
                }
            }
            // Some registered converters key off CryStringT<char> as the
            // source type rather than std::string (see CryStringPolicy).
            const rttr::type cryStringType = CryStringType();
            if (cryStringType.is_valid()) {
                const rttr::variant source =
                    MakeCryStringVariant(value.str, cryStringType);
                rttr::variant converted;
                if (source.convert_to(expectedType, converted) &&
                    converted.is_valid()) {
                    result = std::move(converted);
                    return true;
                }
            }
            error = "no registered conversion from string to reflected type '" +
                    GetTypeName(expectedType) + "'";
            return false;
        }

        RttrHandleRegistry::Handle handle = 0;
        if (!ReadRegistryToken(value, handle, error))
            return false;
        const rttr::variant* stored = m_registry.Lookup(handle);
        if (!stored) {
            error = "unknown or stale RTTR handle";
            return false;
        }
        const rttr::type actualType = stored->get_type();
        if (kind == ValueKind::Enumeration) {
            if (actualType != expectedType) {
                error = "enum handle type '" + GetTypeName(actualType) +
                        "' does not match expected type '" +
                        GetTypeName(expectedType) + "'";
                return false;
            }
        } else if (!IsObjectCompatible(actualType, expectedType)) {
            // The rttr class graph has no edge between wrapper
            // instantiations (shared_ptr<Derived> vs shared_ptr<Base>), but
            // the game's registered converters do handle those transports --
            // authored graphs feed CreateItemClassDescriptor results into
            // shared_ptr<I_ItemDescriptor> pins through the same machinery.
            rttr::variant converted;
            if (stored->convert_to(expectedType, converted) &&
                converted.is_valid()) {
                result = std::move(converted);
                return true;
            }
            error = "object handle type '" + GetTypeName(actualType) +
                    "' is incompatible with expected type '" +
                    GetTypeName(expectedType) + "'";
            return false;
        }
        result = *stored;
        return true;
    }

    if (value.type == ANY_TNIL)
        error = "nil cannot be converted to reflected type '" +
                GetTypeName(expectedType) + "'";
    else
        error = "reflected type '" + GetTypeName(expectedType) +
                "' is not supported by the Lua RTTR bridge";
    return false;
}

bool RttrLuaConverter::ConvertResult(rttr::variant&& value,
                                     rttr::type declaredType,
                                     ScriptAnyValue& result,
                                     std::string& stringStorage,
                                     std::string& error)
{
    // The registry registers `void` as a real, VALID type (void-returning
    // natives report it from get_return_type), so void-ness cannot be tested
    // with is_valid() alone -- AdvanceWorldTime executed fine yet failed here
    // until the name check below existed. Both spellings map to `ok = true`.
    if (!declaredType.is_valid() || declaredType.get_name() == "void") {
        if (value.is_valid() && value.get_type().is_valid() &&
            value.get_type().get_name() != "void") {
            error = "void reflected callable returned a value";
            return false;
        }
        result = ScriptAnyValue(true);
        return true;
    }
    if (!value.is_valid()) {
        error = "reflected callable returned an invalid non-void result";
        return false;
    }

    const ValueKind kind = Classify(declaredType);
    if (kind == ValueKind::LongDouble) {
        error = "long double results are not supported";
        return false;
    }
    if (kind == ValueKind::WChar) {
        error = "wchar_t results are not supported";
        return false;
    }

    // Container RESULTS round-trip as opaque registry handles: there is no
    // Lua-table conversion (Classify deliberately excludes containers), but the
    // handle feeds straight back into another node's array input, which is the
    // same transport the proven Souls-array path already uses. Arguments are
    // untouched -- building a container FROM Lua still needs __array_type.
    if (kind == ValueKind::Unsupported && IsContainer(declaredType)) {
        const RttrHandleRegistry::DedupKey dedupKey{
            value.get_type().get_raw_type(), value.get_raw_ptr()};
        result = HandleValue(m_registry.Store(std::move(value), &dedupKey));
        return true;
    }

    if (kind == ValueKind::ObjectPointer && value.is_nullptr()) {
        result.type = ANY_TNIL;
        result.nHandle = 0;
        return true;
    }

    if (kind != ValueKind::Object && kind != ValueKind::ObjectPointer &&
        !RequireExactResultType(value, declaredType, error))
        return false;

    switch (kind) {
    case ValueKind::Bool:
        result = ScriptAnyValue(ReadScalarValue<bool>(value));
        return true;
    case ValueKind::Char:
        result = ScriptAnyValue(static_cast<int>(ReadScalarValue<char>(value)));
        return true;
    case ValueKind::SignedChar:
        result = ScriptAnyValue(static_cast<int>(ReadScalarValue<signed char>(value)));
        return true;
    case ValueKind::UnsignedChar:
        result = ScriptAnyValue(static_cast<unsigned int>(
            ReadScalarValue<unsigned char>(value)));
        return true;
    case ValueKind::Short:
        result = ScriptAnyValue(static_cast<int>(ReadScalarValue<short>(value)));
        return true;
    case ValueKind::UnsignedShort:
        result = ScriptAnyValue(static_cast<unsigned int>(
            ReadScalarValue<unsigned short>(value)));
        return true;
    case ValueKind::Int:
        result = ScriptAnyValue(ReadScalarValue<int>(value));
        return true;
    case ValueKind::UnsignedInt:
        result = ScriptAnyValue(ReadScalarValue<unsigned int>(value));
        return true;
    case ValueKind::Long:
        result = ScriptAnyValue(static_cast<int>(ReadScalarValue<long>(value)));
        return true;
    case ValueKind::UnsignedLong:
        result = ScriptAnyValue(static_cast<unsigned int>(
            ReadScalarValue<unsigned long>(value)));
        return true;
    case ValueKind::Int64:
        result = HandleValue(static_cast<std::uint64_t>(
            ReadScalarValue<std::int64_t>(value)));
        return true;
    case ValueKind::UInt64:
        result = HandleValue(ReadScalarValue<std::uint64_t>(value));
        return true;
    case ValueKind::Float:
        result = ScriptAnyValue(ReadScalarValue<float>(value));
        return true;
    case ValueKind::Double:
        result = ScriptAnyValue(ReadScalarValue<double>(value));
        return true;
    case ValueKind::String: {
        const auto* text = static_cast<const std::string*>(value.get_value());
        if (!text) {
            error = "reflected string result has no value";
            return false;
        }
        stringStorage = *text;
        result = ScriptAnyValue(stringStorage.c_str());
        return true;
    }
    case ValueKind::CryString: {
        const auto* text =
            static_cast<const CryStringT<char>*>(value.get_value());
        if (!text) {
            error = "reflected string result has no value";
            return false;
        }
        stringStorage.assign(text->c_str());
        result = ScriptAnyValue(stringStorage.c_str());
        return true;
    }
    case ValueKind::Enumeration: {
        const RttrHandleRegistry::Handle handle =
            m_registry.Store(std::move(value));
        result = HandleValue(handle);
        return true;
    }
    case ValueKind::Object:
    case ValueKind::ObjectPointer: {
        const rttr::type actualType = value.get_type();
        if (!IsObjectCompatible(actualType, declaredType)) {
            error = "reflected result type '" + GetTypeName(actualType) +
                    "' is incompatible with declared type '" +
                    GetTypeName(declaredType) + "'";
            return false;
        }
        // Dedup key uses the raw (most-stripped) type+pointer pair so two
        // reads of the same underlying native object (e.g. the same soul's
        // Inventory fetched twice) fold onto one refcounted handle instead
        // of minting an independent one each time.
        const RttrHandleRegistry::DedupKey dedupKey{
            value.get_type().get_raw_type(), value.get_raw_ptr()};
        const RttrHandleRegistry::Handle handle =
            m_registry.Store(std::move(value), &dedupKey);
        result = HandleValue(handle);
        return true;
    }
    default:
        error = "reflected result type '" + GetTypeName(declaredType) +
                "' is not supported by the Lua RTTR bridge";
        return false;
    }
}

bool RttrLuaConverter::IsObjectCompatible(rttr::type actualType,
                                          rttr::type expectedType) const
{
    if (expectedType.is_pointer()) {
        if (!actualType.is_pointer())
            return false;
        const rttr::type actualRaw = actualType.get_raw_type();
        const rttr::type expectedRaw = expectedType.get_raw_type();
        return actualType == expectedType || actualRaw == expectedRaw ||
               actualRaw.is_derived_from(expectedRaw);
    }
    if (!expectedType.is_class() || actualType.is_pointer() ||
        !actualType.is_class())
        return false;
    return actualType == expectedType || actualType.is_derived_from(expectedType);
}

bool RttrLuaConverter::IsStringViewType(rttr::type valueType)
{
    return IsStdStringView(valueType);
}

std::string RttrLuaConverter::GetTypeName(rttr::type valueType)
{
    if (!valueType.is_valid())
        return "<invalid>";
    const rttr::string_view name = valueType.get_name();
    if (!name.empty())
        return std::string(name);
    return std::string(RawTypeName(valueType));
}

}  // namespace luautils
