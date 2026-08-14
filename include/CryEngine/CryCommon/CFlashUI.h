#pragma once
#include <cstddef>
#include <cstdint>
#include "Offsets/vtables/IFlashUI.h"
#include "Offsets/vtables/IInputEventListener.h"
#include "Offsets/vtables/IGameFrameworkListener.h"
#include "Offsets/vtables/ILevelSystemListener.h"
#include "Offsets/vtables/ISystem.h"
#include "Offsets/vtables/IHardwareMouseEventListener.h"
#include "Offsets/vtables/ILoadtimeCallback.h"

// -----------------------------------------------
// CFlashUI -- CryEngine FlashUI singleton (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x1D8.
// -----------------------------------------------
// RTTI .?AVCFlashUI@@ (TD RVA 0x5022338); ctor sub_1816F27F0; factory sub_1816F264C.
// Seven one-vptr bases occupy +0x00..+0x30. The complete callable IFlashUI surface is
// defined by Offsets::IFlashUI; this header recovers the concrete object and load-bearing
// data offsets without duplicating the 49 inherited slots.

class CFlashUI : public Offsets::IFlashUI,                           // +0x00
                 public Offsets::IHardwareMouseEventListener,         // +0x08
                 public Offsets::IInputEventListener,                 // +0x10
                 public Offsets::IGameFrameworkListener,              // +0x18
                 public Offsets::ILevelSystemListener,                // +0x20
                 public Offsets::ISystemEventListener,                // +0x28
                 public Offsets::ILoadtimeCallback                    // +0x30
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CFlashUI;
    void* m_pUIActionEvents;                                  // +0x038  created by IFlashUI::Init
    uint8_t _registries40[0x98];                              // +0x040  elements/actions/event-system registries
    Offsets::IUIActionManager* m_pUIActionManager;            // +0x0D8  IFlashUI [24]
    uint8_t _modulesE0[0x28];                                 // +0x0E0  registered UI modules and iteration state
    uint32_t m_unk108;                                        // +0x108  ctor 1; role OPEN
    uint32_t m_unk10C;                                        // +0x10C  ctor 1; role OPEN
    uint8_t m_editorCallbacks[0x60];                          // +0x110  three 0x20-byte editor callback functors
    uint64_t m_unk170;                                        // +0x170  ctor 0
    uint32_t m_unk178;                                        // +0x178  ctor 0
    bool m_hudElementsVisible;                                // +0x17C  SetHudElementsVisible [28]
    uint8_t _pad17D[3];                                       // +0x17D
    uint32_t m_unk180;                                        // +0x180  ctor 2; role OPEN
    uint32_t _pad184;                                         // +0x184
    uint64_t m_unk188;                                        // +0x188  ctor 0
    uint64_t m_unk190;                                        // +0x190  ctor 0
    uint8_t _state198[0x30];                                  // +0x198  input/event state
    int32_t m_unk1C8;                                         // +0x1C8  ctor -1; role OPEN
    uint32_t m_unk1CC;                                        // +0x1CC  ctor 0
    bool m_updatingFlowGraph;                                 // +0x1D0  UpdateFG [25] reentrancy guard
    uint8_t _pad1D1[7];                                       // +0x1D1
};

static_assert(sizeof(CFlashUI) == 0x1D8, "CFlashUI must be 0x1D8");
static_assert(offsetof(CFlashUI, m_pUIActionEvents) == 0x38,
              "m_pUIActionEvents must be at 0x38");
static_assert(offsetof(CFlashUI, m_pUIActionManager) == 0xD8,
              "m_pUIActionManager must be at 0xD8");
static_assert(offsetof(CFlashUI, m_hudElementsVisible) == 0x17C,
              "m_hudElementsVisible must be at 0x17C");
static_assert(offsetof(CFlashUI, m_updatingFlowGraph) == 0x1D0,
              "m_updatingFlowGraph must be at 0x1D0");
