#pragma once

#include <cstddef>
#include <cstdint>

#include "../../entitymodule/I_InventoryListener.h"
#include "../../entitymodule/I_ItemSlotListener.h"
#include "I_Element.h"

namespace wh::xgenaimodule::NPCState {

class C_ItemSetAsideElement
    : public I_Element,
      public wh::entitymodule::I_ItemSlotListener,
      public wh::entitymodule::I_InventoryListener {
public:
    C_ItemSetAsideElement();                                             // 0x180FD7190
    ~C_ItemSetAsideElement() override;                                   // [0]
    E_ElementType::Type unk_02() override;
    I_Element* Clone() const override;
    std::uint64_t GetHash() const override;
    void OnAfterAcquire(wh::entitymodule::C_Item* item) override;
    void OnBeforeLose(wh::entitymodule::C_Item* item) override;
    void OnSlotItem(wh::entitymodule::C_Item* item) override;
    RTTR_ENABLE(I_Element)                                               // [30..32], vtable 0x183B01848

    std::uint8_t m_unknown28[0x18];                                      // +0x28
};

static_assert(sizeof(C_ItemSetAsideElement) == 0x40,
              "C_ItemSetAsideElement size mismatch");

} // namespace wh::xgenaimodule::NPCState
