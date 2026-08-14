#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include "../CryEngine/CryCommon/smartptr.h"

struct IMaterial;
struct S_MaterialFeature;

// -----------------------------------------------
// wh::I_MaterialInstance -- ref-counted material-instance interface
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x10.
// -----------------------------------------------
// RTTI chain: C_MaterialInstance -> I_MaterialInstance ->
// _i_multithread_reference_target<int>. The concrete primary vtable 0x183B2DCD8
// has slots [0..12]; slot 13 is data. Cry3DEngineBase is an unrelated secondary
// concrete-class base at +0x10.

namespace wh {

class I_MaterialBufferManager;

using MaterialFeatureCallback = std::function<void(::S_MaterialFeature&)>;
using NamedMaterialFeatureCallback =
    std::function<void(const CryStringT<char>&, ::S_MaterialFeature&)>;

class I_MaterialInstance : public _i_multithread_reference_target<int> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_MaterialInstance;

    virtual bool IsUniquelyReferenced() const = 0;                  // [3] 0x1825049D8
    virtual ::IMaterial* GetMaterial() const = 0;                   // [4] 0x180638480
    virtual void _vf5(std::uint64_t& outValue) const = 0;           // [5] 0x181A74250, original 8-byte return type OPEN
    virtual bool _vf6() const = 0;                                 // [6] 0x180752DC4
    virtual void _vf7(MaterialFeatureCallback callback) = 0;       // [7] 0x18068BD0C, callback consumed by value
    virtual void _vf8(MaterialFeatureCallback callback) = 0;       // [8] 0x180752E08, callback consumed by value
    virtual void _vf9(NamedMaterialFeatureCallback callback) = 0;  // [9] 0x180973904, callback consumed by value
    virtual void _vf10(bool enabled) = 0;                          // [10] 0x181A751E0
    virtual void _vf11(bool enabled) = 0;                          // [11] 0x1807535F0
    virtual I_MaterialBufferManager* _vf12() = 0;                  // [12] 0x181AAD440
};
static_assert(sizeof(I_MaterialInstance) == 0x10,
              "I_MaterialInstance must be vptr + refcount");

}  // namespace wh
