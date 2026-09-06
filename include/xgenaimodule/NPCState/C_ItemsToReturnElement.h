#pragma once

#include <cstddef>
#include <cstdint>

#include "../../entitymodule/I_ItemCollectionListener.h"
#include "I_Element.h"

namespace wh::xgenaimodule::NPCState {

class C_ItemsToReturnElement
    : public I_Element,
      public wh::entitymodule::I_ItemCollectionListener {
public:
    C_ItemsToReturnElement();                                            // 0x18186FB9C
    ~C_ItemsToReturnElement() override;                                  // [0]
    E_ElementType::Type unk_02() override;
    I_Element* Clone() const override;
    std::uint64_t GetHash() const override;
    RTTR_ENABLE(I_Element)                                               // [30..32], vtable 0x18476F1A8

    std::uint8_t m_unknown20[0x20];                                      // +0x20
};

static_assert(sizeof(C_ItemsToReturnElement) == 0x40,
              "C_ItemsToReturnElement size mismatch");

} // namespace wh::xgenaimodule::NPCState
