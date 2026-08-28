#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../rttr/rttr_enable.h"
#include "C_HomogenousItemDescriptor.h"

namespace wh::entitymodule {

class C_AnyOfItemDescriptor : public C_HomogenousItemDescriptor {
public:
    ~C_AnyOfItemDescriptor() override; // [0] 0x181F0D9C0
    std::uint32_t GetMatchFailReason(
        C_Item* item, std::uint32_t flags) const override; // [4] 0x181F0E670
    RTTR_ENABLE(C_HomogenousItemDescriptor) // [6..8]
    std::int32_t GetAmount() const override; // [9] 0x181F0EC20

    std::vector<std::shared_ptr<C_HomogenousItemDescriptor>> m_descriptors; // +0x08
};

static_assert(offsetof(C_AnyOfItemDescriptor, m_descriptors) == 0x08,
              "C_AnyOfItemDescriptor::m_descriptors offset mismatch");
static_assert(sizeof(C_AnyOfItemDescriptor) == 0x20,
              "C_AnyOfItemDescriptor size mismatch");

} // namespace wh::entitymodule
