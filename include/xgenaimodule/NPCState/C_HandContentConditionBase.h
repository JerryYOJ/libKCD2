#pragma once
#include <cstddef>
#include <cstdint>
#include "E_DataSource.h"
#include "I_Condition.h"
#include "S_EffectObjectSource.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_HandContentConditionBase : I_Condition
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x40; vtable 0x183A44EE8 (12 slots).
// -----------------------------------------------
// Abstract: clone [1] and [5] stay pure. Adds three slots after the trio.
// Slot names are not encoded. Member offsets are RTTR member_object_ptr.

namespace wh::xgenaimodule::NPCState {

class C_HandContentConditionBase : public I_Condition {
public:
    ~C_HandContentConditionBase() override;               // [0] 0x18067A878
    bool unk_02(void* arg) override;                      // [2] 0x1808F9BC0
    bool unk_03(void* arg) override;                      // [3] 0x1808FC6D4
    bool unk_04(void* arg) override;                      // [4] 0x1803A1500
    RTTR_ENABLE(I_Condition)                              // [6..8]
    virtual std::uint32_t unk_09() = 0;                   // [9] called at vtable+0x48
    virtual void unk_10(void* out, void* arg) = 0;        // [10] vtable+0x50 sret
    virtual bool unk_11(void* arg);                       // [11] 0x1808F9CD0

    E_DataSource m_dataSource;                            // +0x08 RTTR "DataSource"
    bool m_requiresEmpty;                                 // +0x0C RTTR "RequiresEmpty"
    bool m_initializeItemFromRequest;                     // +0x0D RTTR "InitializeItemFromRequest"
    std::uint8_t _pad0E[2];                               // +0x0E
    S_EffectObjectSource m_setAsideSlotSource;            // +0x10 RTTR "SetAsideSlotSource"
    E_DataSource m_setAsideSlotDataSource;                // +0x30 RTTR "SetAsideSlotDataSource"
    std::uint8_t _pad34[0xC];                             // +0x34
};

static_assert(offsetof(C_HandContentConditionBase, m_dataSource) == 0x08,
              "C_HandContentConditionBase::m_dataSource offset mismatch");
static_assert(offsetof(C_HandContentConditionBase, m_setAsideSlotSource) == 0x10,
              "C_HandContentConditionBase::m_setAsideSlotSource offset mismatch");
static_assert(offsetof(C_HandContentConditionBase, m_setAsideSlotDataSource) == 0x30,
              "C_HandContentConditionBase::m_setAsideSlotDataSource offset mismatch");
static_assert(sizeof(C_HandContentConditionBase) == 0x40,
              "C_HandContentConditionBase size mismatch");

}  // namespace wh::xgenaimodule::NPCState
