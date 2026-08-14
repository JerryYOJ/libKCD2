#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../Offsets/vtables/IScriptSystem.h"

// -----------------------------------------------
// wh::entitymodule::C_InteractionType -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x48.
// -----------------------------------------------
// RTTI .?AVC_InteractionType@entitymodule@wh@@; vtable 0x183A69FE0, 22 slots.
// Slots [3], [4], and [7] are abstract. ABI-uncertain slots [8] and [11] deliberately
// retain opaque declarations and must not be called through this replica.

namespace wh::entitymodule {

class C_Player;

class C_InteractionType {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_InteractionType;
    virtual ~C_InteractionType() = default;                         // [0] sub_1809ECA80
    virtual void Initialize(C_Player* pPlayer);                     // [1] sub_182A00060
    virtual void unk_02();                                         // [2] nullsub_1
    virtual bool IsEnabled() = 0;                                  // [3] pure
    virtual void RefreshInteractionBounds() = 0;                   // [4] pure
    virtual bool unk_05();                                         // [5] returns false
    virtual float GetMaximumInteractionDistance();                 // [6] [7] * 5.0f
    virtual float GetInteractionDistance() = 0;                    // [7] pure
    virtual void unk_08();                                         // [8] two-byte result ABI OPEN; do not call
    virtual HSCRIPTFUNCTION GetIsUsableFunction();                 // [9] returns +0x10
    virtual HSCRIPTFUNCTION GetOnUsableMessageFunction();          // [10] returns +0x18
    virtual void unk_11();                                         // [11] two-byte result ABI OPEN; do not call
    virtual bool unk_12(void* pTarget);                            // [12] target-state predicate; role OPEN
    virtual bool unk_13();                                         // [13] returns false
    virtual bool unk_14();                                         // [14] returns false
    virtual bool unk_15();                                         // [15] returns false
    virtual float GetScreenMinX();                                 // [16] returns +0x20
    virtual float GetScreenMaxX();                                 // [17] returns +0x24
    virtual float GetScreenMinY();                                 // [18] returns +0x28
    virtual float GetScreenMaxY();                                 // [19] returns +0x2C
    virtual bool unk_20();                                         // [20] returns false
    virtual void UpdateInteractionBounds(float horizontalExtent,
                                         float verticalExtent);    // [21] sub_1816DBEAC

    C_Player*       m_pPlayer;                 // +0x08
    HSCRIPTFUNCTION m_isUsableFunction;        // +0x10  script callback "IsUsable"
    HSCRIPTFUNCTION m_onUsableMessageFunction; // +0x18  script callback "OnUsableMessage"
    float           m_screenMinX;              // +0x20  clamped to [0,100]
    float           m_screenMaxX;              // +0x24  clamped to [0,100]
    float           m_screenMinY;              // +0x28  clamped to [0,100]
    float           m_screenMaxY;              // +0x2C  clamped to [0,100]
    std::vector<uint32_t> m_typeIds;            // +0x30  32-bit lookup keys; exact key domain OPEN
};

static_assert(sizeof(C_InteractionType) == 0x48, "C_InteractionType must be 0x48");
static_assert(offsetof(C_InteractionType, m_typeIds) == 0x30, "m_typeIds must be at 0x30");

}  // namespace wh::entitymodule
