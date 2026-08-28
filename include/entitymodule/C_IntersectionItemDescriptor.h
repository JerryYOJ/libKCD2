#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../rttr/rttr_enable.h"
#include "C_HomogenousItemDescriptor.h"

namespace wh::entitymodule {

class C_IntersectionItemDescriptor : public C_HomogenousItemDescriptor {
public:
    ~C_IntersectionItemDescriptor() override; // [0] 0x182A68610
    std::uint32_t GetMatchFailReason(
        C_Item* item, std::uint32_t flags) const override; // [4] 0x182A69440
    RTTR_ENABLE(C_HomogenousItemDescriptor) // [6..8]
    std::int32_t GetAmount() const override; // [9] 0x181F0EC20

    std::vector<std::shared_ptr<C_HomogenousItemDescriptor>> m_descriptors; // +0x08
};

static_assert(offsetof(C_IntersectionItemDescriptor, m_descriptors) == 0x08,
              "C_IntersectionItemDescriptor::m_descriptors offset mismatch");
static_assert(sizeof(C_IntersectionItemDescriptor) == 0x20,
              "C_IntersectionItemDescriptor size mismatch");

} // namespace wh::entitymodule
