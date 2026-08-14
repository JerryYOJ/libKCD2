#pragma once
#include <cstdint>
#include "C_LinkableObject.h"

namespace wh::xgenaimodule {

// Runtime-created linkable. It adds one virtual discriminator and no data to the
// C_LinkableObject extent.
class C_DynamicLinkableObject : public C_LinkableObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DynamicLinkableObject;
    ~C_DynamicLinkableObject() override; // [0] 0x1810AF9D8
    std::uint32_t GetTypeMask() override; // [1] 0x1805D2A10
    virtual bool _vf19();                 // [19] 0x180838AE0, false
};
static_assert(sizeof(C_DynamicLinkableObject) == 0x60,
              "C_DynamicLinkableObject must be 0x60");

}  // namespace wh::xgenaimodule
