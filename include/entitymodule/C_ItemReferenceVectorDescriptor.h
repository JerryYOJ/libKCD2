#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../rttr/rttr_enable.h"
#include "C_HomogenousItemDescriptor.h"

namespace wh::entitymodule {

class C_ItemReferenceVectorDescriptor : public C_HomogenousItemDescriptor {
public:
    ~C_ItemReferenceVectorDescriptor() override; // [0] 0x182A686F4
    std::uint32_t GetMatchFailReason(
        C_Item* item, std::uint32_t flags) const override; // [4] 0x182A694A4
    RTTR_ENABLE(C_HomogenousItemDescriptor) // [6..8]
    std::int32_t GetAmount() const override; // [9] 0x182A699FC

    std::vector<C_Item*> m_items; // +0x08, destruction-listener tracked
};

static_assert(offsetof(C_ItemReferenceVectorDescriptor, m_items) == 0x08,
              "C_ItemReferenceVectorDescriptor::m_items offset mismatch");
static_assert(sizeof(C_ItemReferenceVectorDescriptor) == 0x20,
              "C_ItemReferenceVectorDescriptor size mismatch");

} // namespace wh::entitymodule
