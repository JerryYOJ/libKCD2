#pragma once

namespace wh::entitymodule {

class C_Item;

class I_ItemSlotListener {
public:
    virtual void OnAfterAcquire(C_Item* item) = 0;                       // [0] ItemSlotTrigger 0x1816571A8
    virtual void OnBeforeLose(C_Item* item) = 0;                         // [1] ItemSlotTrigger 0x181657194
    virtual void OnSlotItem(C_Item* item) = 0;                           // [2] ItemSlotTrigger 0x1819DF2F0
    virtual ~I_ItemSlotListener() = default;                             // [3]
};

static_assert(sizeof(I_ItemSlotListener) == 0x08,
              "I_ItemSlotListener size mismatch");

} // namespace wh::entitymodule
