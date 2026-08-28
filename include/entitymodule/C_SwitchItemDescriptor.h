#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../rttr/rttr_enable.h"
#include "I_ItemDescriptor.h"

namespace wh::entitymodule {

class C_SwitchItemDescriptor : public I_ItemDescriptor {
public:
    ~C_SwitchItemDescriptor() override; // [0] 0x182A6879C
    std::vector<C_Item*> GetMatchingItems(
        const std::vector<C_Item*>& items) const override; // [1] 0x182A69204
    void unk2() override; // [2] 0x182A692D8
    std::uint32_t GetMatchFailReason(
        C_Item* item, std::uint32_t flags) const override; // [4] 0x182A694CC
    std::int32_t unk5() const override; // [5] 0x182A69A18
    RTTR_ENABLE(I_ItemDescriptor) // [6..8]

    std::vector<std::shared_ptr<I_ItemDescriptor>> m_descriptors; // +0x08
};

static_assert(offsetof(C_SwitchItemDescriptor, m_descriptors) == 0x08,
              "C_SwitchItemDescriptor::m_descriptors offset mismatch");
static_assert(sizeof(C_SwitchItemDescriptor) == 0x20,
              "C_SwitchItemDescriptor size mismatch");

} // namespace wh::entitymodule
