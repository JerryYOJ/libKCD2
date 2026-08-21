#pragma once
#include "../Offsets/Offsets_RTTI.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "S_SniffableItemData.h"

// -----------------------------------------------
// wh::entitymodule::I_SniffableItemManager -- sniffable class-GUID registry
// (KCD2 WHGame.dll 1.5.6). sizeof 0x8. No virtual destructor.
// -----------------------------------------------
// RTTI .?AVI_SniffableItemManager@entitymodule@wh@@. No own COL/vtable; the four
// slots live on C_SniffableItemManager 0x183BB0658. Lookup miss returns a process-
// lifetime empty S_SniffableItemData, never nullptr.

namespace wh::entitymodule {

class I_SniffableItemManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_SniffableItemManager;

    virtual void Insert(const CryGUID& itemClassGuid,
                        const S_SniffableItemData& data) = 0;           // [0] 0x182A8AB94
    virtual void Erase(const CryGUID& itemClassGuid) = 0;               // [1] 0x182A8B89C
    virtual S_SniffableItemData& Lookup(const CryGUID& itemClassGuid) = 0; // [2] 0x182A89F1C
    virtual bool Contains(const CryGUID& itemClassGuid) = 0;            // [3] 0x18055F1AC
};
static_assert(sizeof(I_SniffableItemManager) == 0x08,
              "I_SniffableItemManager is vptr-only");

}  // namespace wh::entitymodule
