#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../framework/S_ResourceHandle.h"
#include "../rttr/rttr_enable.h"
#include "C_ItemHolder.h"
#include "C_ItemIndexer.h"
#include "E_ItemDeliveryMode.h"
#include "I_ItemDescriptor.h"

namespace wh::entitymodule {

class C_ItemDelivery {
public:
    virtual ~C_ItemDelivery(); // [0] 0x182A43F60
    RTTR_ENABLE() // [1..3]

    wh::framework::S_ResourceHandle m_resource; // +0x08
    std::vector<std::shared_ptr<I_ItemDescriptor>> m_descriptors18; // +0x18
    C_ItemHolder* m_itemHolder;                 // +0x30, borrowed
    std::vector<std::shared_ptr<I_ItemDescriptor>> m_descriptors38; // +0x38
    std::uint8_t m_unknown50;                   // +0x50, ctor 7
    bool m_unknown51;                           // +0x51
    std::uint8_t m_padding52[6];
    C_ItemIndexer m_itemIndexer;                // +0x58
    std::uint16_t m_unknownE8;                  // +0xE8
    E_ItemDeliveryMode::Type m_mode;            // +0xEA
    std::uint8_t m_paddingEB[5];
    std::vector<CryStringT<char>> m_messages;   // +0xF0, localized inputs normalized to text
    bool m_unknown108;                          // +0x108
    bool m_unknown109;                          // +0x109
    std::uint8_t m_padding10A[6];
};

static_assert(offsetof(C_ItemDelivery, m_descriptors18) == 0x18,
              "C_ItemDelivery::m_descriptors18 offset mismatch");
static_assert(offsetof(C_ItemDelivery, m_itemIndexer) == 0x58,
              "C_ItemDelivery::m_itemIndexer offset mismatch");
static_assert(offsetof(C_ItemDelivery, m_mode) == 0xEA,
              "C_ItemDelivery::m_mode offset mismatch");
static_assert(offsetof(C_ItemDelivery, m_messages) == 0xF0,
              "C_ItemDelivery::m_messages offset mismatch");
static_assert(sizeof(C_ItemDelivery) == 0x110,
              "C_ItemDelivery size mismatch");

} // namespace wh::entitymodule
