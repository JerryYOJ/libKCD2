#pragma once
#include <cstddef>
#include <cstdint>
#include "../entitymodule/C_ItemHolder.h"

// -----------------------------------------------
// wh::xgenaimodule::C_SpawnedItemsHolder : entitymodule::C_ItemHolder
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x40 (embedded at C_AnimActionBase+0x128,
// next member +0x168 pins the size). vtable 0x183A2D998; ctor 0x1803A7D28.
// -----------------------------------------------
// RTTI .?AVC_SpawnedItemsHolder@xgenaimodule@wh@@ : C_ItemHolder.
// C_AnimActionBase slot 27 attaches it to the runtime request +0x50 when
// ProvidesSpawnedItemsHolder(); slot 30 drains via +0x130/+0x138 (own +0x08/+0x10).

namespace wh::xgenaimodule {

class C_SpawnedItemsHolder : public wh::entitymodule::C_ItemHolder {
public:
    // concrete in retail (vt 0x183A2D998 fully populated); slot bodies unnamed
    wh::entitymodule::E_ItemHolderType GetHolderType() const override; // [1]
    void _vf3(const ItemVisitor& visitor) override;                    // [3]
    void _vf9(wh::entitymodule::C_Item* item, wh::entitymodule::E_ItemHolderChangeFlags flags,
              std::uint32_t amount) override;                          // [9]
    void _vf10(wh::entitymodule::C_Item* item, wh::entitymodule::E_ItemHolderChangeFlags flags,
               std::uint32_t amount) override;                         // [10]

    std::uint8_t _pad08[0x38];   // +0x08 own state pending writer tracing
};

static_assert(sizeof(C_SpawnedItemsHolder) == 0x40,
              "C_SpawnedItemsHolder size mismatch");

}  // namespace wh::xgenaimodule
