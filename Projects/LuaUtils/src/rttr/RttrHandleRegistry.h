#pragma once

#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <utility>

#include "rttr/type.h"
#include "rttr/variant.h"

namespace luautils {

// Refcounted: Store() with a matching DedupKey folds repeated stores of the
// same underlying native object onto one Handle (e.g. two Lua reads of the
// same soul's Inventory), incrementing a refcount rather than minting a new
// entry. Release() decrements and only erases at zero. This is required, not
// an optimization: without it, one of two independent Lua wrappers around a
// deduped Handle releasing it would invalidate the other still-live wrapper.
class RttrHandleRegistry
{
public:
    using Handle = std::uint64_t;

    // Identity key for dedup: the raw (most-stripped) type and pointer of the
    // native value, e.g. (get_raw_type(), get_raw_ptr()). Both fields must be
    // valid for dedup to apply; pass nullptr to Store() to always mint fresh
    // (correct for values with no reusable identity: SKALD node wrappers,
    // freshly-built array constants, enum tokens).
    struct DedupKey
    {
        rttr::type type;
        const void* pointer = nullptr;
    };

    RttrHandleRegistry() = default;
    RttrHandleRegistry(const RttrHandleRegistry&) = delete;
    RttrHandleRegistry& operator=(const RttrHandleRegistry&) = delete;

    Handle Store(rttr::variant&& value, const DedupKey* dedupKey = nullptr);
    const rttr::variant* Lookup(Handle handle) const noexcept;
    bool Release(Handle handle) noexcept;
    void Clear() noexcept;

    std::size_t Size() const noexcept { return m_entries.size(); }

private:
    struct Entry
    {
        rttr::variant value;
        std::uint32_t refCount = 1;
        rttr::type dedupType;             // invalid if this entry was not deduped
        const void* dedupPointer = nullptr;
    };

    struct PointerKeyHash
    {
        std::size_t operator()(
            const std::pair<rttr::type, const void*>& key) const noexcept
        {
            const std::size_t typeHash =
                std::hash<const void*>()(key.first.m_type_data);
            const std::size_t ptrHash = std::hash<const void*>()(key.second);
            // boost::hash_combine's constant, no boost dependency
            return typeHash ^ (ptrHash + 0x9e3779b9u + (typeHash << 6) +
                               (typeHash >> 2));
        }
    };

    std::unordered_map<Handle, Entry> m_entries;
    std::unordered_map<std::pair<rttr::type, const void*>, Handle,
                       PointerKeyHash> m_byPointer;
    Handle m_nextHandle = 1;
};

}  // namespace luautils
