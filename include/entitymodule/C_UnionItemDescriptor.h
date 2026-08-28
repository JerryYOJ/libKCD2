#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../rttr/rttr_enable.h"
#include "C_HomogenousItemDescriptor.h"

namespace wh::entitymodule {

class C_UnionItemDescriptor : public I_ItemDescriptor {
public:
    ~C_UnionItemDescriptor() override; // [0] 0x1819DC7E0
    std::vector<C_Item*> GetMatchingItems(
        const std::vector<C_Item*>& items) const override; // [1] 0x181374554
    void unk2() override; // [2] 0x181374D0C
    std::uint32_t GetMatchFailReason(
        C_Item* item, std::uint32_t flags) const override; // [4] 0x18096EEF0
    std::int32_t unk5() const override; // [5] 0x1819A264C
    RTTR_ENABLE(I_ItemDescriptor) // [6..8]

    std::vector<std::shared_ptr<C_HomogenousItemDescriptor>> m_descriptors; // +0x08
};

static_assert(offsetof(C_UnionItemDescriptor, m_descriptors) == 0x08,
              "C_UnionItemDescriptor::m_descriptors offset mismatch");
static_assert(sizeof(C_UnionItemDescriptor) == 0x20,
              "C_UnionItemDescriptor size mismatch");

} // namespace wh::entitymodule
