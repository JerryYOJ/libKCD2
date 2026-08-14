#pragma once
#include <cstdint>
#include "C_DynamicLinkableObject.h"

namespace wh::xgenaimodule {

// Concrete no-ownership leaf created by C_LinkableObjectHolder's normal path.
class C_RemoteDynamicLinkableObject : public C_DynamicLinkableObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RemoteDynamicLinkableObject;
    ~C_RemoteDynamicLinkableObject() override; // [0] 0x18096D6A8
    std::uint32_t GetTypeMask() override;       // [1] 0x1813FBA80
    bool _vf19() override;                      // [19] 0x18041A6A0, true
};
static_assert(sizeof(C_RemoteDynamicLinkableObject) == 0x60,
              "C_RemoteDynamicLinkableObject must be 0x60");

}  // namespace wh::xgenaimodule
