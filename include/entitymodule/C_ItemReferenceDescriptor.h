#pragma once
#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"
#include "C_HomogenousItemDescriptor.h"

namespace wh::entitymodule {

class C_ItemReferenceDescriptor : public C_HomogenousItemDescriptor {
public:
    ~C_ItemReferenceDescriptor() override; // [0] 0x182A686C0
    std::uint32_t GetMatchFailReason(
        C_Item* item, std::uint32_t flags) const override; // [4] 0x182A6949C
    RTTR_ENABLE(C_HomogenousItemDescriptor) // [6..8]
    std::int32_t GetAmount() const override; // [9] 0x182A699EC

    C_Item* m_item; // +0x08, destruction-listener tracked
};

static_assert(offsetof(C_ItemReferenceDescriptor, m_item) == 0x08,
              "C_ItemReferenceDescriptor::m_item offset mismatch");
static_assert(sizeof(C_ItemReferenceDescriptor) == 0x10,
              "C_ItemReferenceDescriptor size mismatch");

} // namespace wh::entitymodule
