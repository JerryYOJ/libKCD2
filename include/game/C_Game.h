#pragma once

#include <cstdint>
#include "REL/Offset.h"
#include "../Offsets/vtables/IGame.h"

// -----------------------------------------------
// C_Game — Warhorse KCD2 game module (CryEngine IGame implementation)
// -----------------------------------------------
// RTTI:  .?AVC_Game@game@wh@@
// Target: WHGame.dll 1.5.6 (KCD2), image base 0x180000000
// Constructor:            0x180C10F98  (sub_180C10F8C)
// Base destructor:        0x1839D7E90  (frees sub-objects; does NOT free `this`)
// Scalar deleting dtor:   0x1839D8468  (vtable slot 0) -> operator delete(this, 0x198)
// Total size: 0x198        (recovered from the deleting dtor's sub_181AB5160(this, 408))
//
// Five polymorphic bases, each one vptr (no data), laid out at:
//   +0x00 IGame                 (primary, 41-slot vtable 0x184095688)
//   +0x08 IGameFrameworkListener
//   +0x10 ILevelSystemListener
//   +0x18 IInputEventListener
//   +0x20 wh::framework::I_ModuleMessageListener
// C_Game's own members begin at +0x28.
//
// Singleton:
//   Global qword_18549D300 (RVA 0x549D300) holds the sole C_Game*.
//   The ctor writes it (this) and the dtor clears it. See GetInstance() below.
//   A second global qword_18547E6C0 (RVA 0x547E6C0) aliases the +0x148 sub-object.
//
// Confidence: base layout, sub-manager types (from their ctor vtables) and sizeof are
// VERIFIED from disasm of the ctor/dtor. Members marked /* tentative */ are inferred
// (role only) and members named m_unk*/_pad* are zero-initialised but otherwise
// unreferenced in the ctor/dtor — treat their types as provisional.

namespace wh::framework {
    class C_RuntimePrefabManager;   // +0x150 sub-manager (0x68 bytes)
}

namespace wh::game {

class C_LevelManager;               // +0xA8 sub-manager (0xF8 bytes)
class C_ExtraRewardsManager;        // +0xB0 sub-manager (0x68 bytes)
class C_NewGameHelper;              // +0xB8 sub-manager (0xC0 bytes)
class C_PlatformActivityManager;    // +0x180 sub-manager (0x08 bytes, vtable only)

class C_Game : public Offsets::IGame,                    // +0x00
               public Offsets::IGameFrameworkListener,   // +0x08
               public Offsets::ILevelSystemListener,     // +0x10
               public Offsets::IInputEventListener,      // +0x18
               public Offsets::I_ModuleMessageListener   // +0x20
{
public:
    static C_Game* GetInstance() { return *reinterpret_cast<C_Game**>(REL::Offset(0x549D300).address()); }

    // ===================================================================
    // Data members (+0x28 onwards, after the five interface vptrs)
    // ===================================================================

    void*       m_unk28;                    // +0x28  (ctor=0)
    uint32_t    m_levelLoadState;           // +0x30  load-state enum (IGame[34] init-once; ILevelSystemListener transitions 5->6) /* tentative */
    uint32_t    m_unk34;                    // +0x34  (ctor=0)
    uint8_t     m_flag38;                   // +0x38  (ctor=0)
    uint8_t     _pad39[3];                  // +0x39
    uint32_t    m_unk3C;                    // +0x3C  set by IGame vtable[11]
    void*       m_unk40;                    // +0x40  (ctor=0)
    uint8_t     m_flag48;                   // +0x48  (ctor=0)
    uint8_t     _pad49[3];                  // +0x49
    uint8_t     _blk4C[0x20];               // +0x4C  zero-init region (coalesced unaligned stores; ~4 ptr/id pairs) /* tentative */
    uint8_t     m_flag6C;                   // +0x6C  (ctor=0)
    uint8_t     _pad6D[3];                  // +0x6D
    void*       m_pInputHandler;            // +0x70  read by IInputEventListener::OnInputEventUI /* tentative */ (ctor=0)

    // File-profiling intrusive list holder (+0x78, size 0x28; ctor sub_180C10D70,
    // registers the "WH_Enable_FileProfiling" CVar change callback).
    void*       m_profList_head;            // +0x78
    void*       m_profList_tail;            // +0x80
    void*       m_profList_x88;             // +0x88
    void*       m_pProfListNode;            // +0x90  self-referential list sentinel node (freed 0x60 in dtor)
    void*       m_profList_x98;             // +0x98

    // Sub-managers (all heap-allocated in the ctor; types from their own ctor vtables)
    void*                         m_pManagerA0;             // +0xA0  16-byte heap holder (sub_180C10E04; dtor sub_180C130FC) /* role tentative */
    wh::game::C_LevelManager*     m_pLevelManager;          // +0xA8  0xF8 bytes (sub_180C10CB0)  VERIFIED type
    wh::game::C_ExtraRewardsManager* m_pExtraRewardsManager;// +0xB0  0x68 bytes (sub_180C10BFC)  VERIFIED type
    wh::game::C_NewGameHelper*    m_pNewGameHelper;         // +0xB8  0xC0 bytes (sub_180C12704)  VERIFIED type

    // Embedded C_GameModeStartupScript (derives CScriptableBase); ctor sub_180C126E0.
    uint8_t     m_gameModeStartupScript[0x70];              // +0xC0  size 0x70  VERIFIED (dtor rebinds &CScriptableBase::vftable @+0xC0)

    void*       m_pReleasable130;           // +0x130  ref-counted, released via vtable(1) in dtor; used by IGame[40] (ctor=0) /* tentative */
    void*       m_pReleasable138;           // +0x138  ref-counted, released via vtable(1) in dtor (ctor=0) /* tentative */
    void*       m_pReleasable140;           // +0x140  ref-counted; exposed by IGame vtable[32] getter (ctor=0) /* tentative */
    void*       m_pSingleton148;            // +0x148  8-byte heap obj; also stored in global qword_18547E6C0; freed 0x08 in dtor
    wh::framework::C_RuntimePrefabManager* m_pRuntimePrefabManager; // +0x150  0x68 bytes (sub_180C10A34)  VERIFIED type
    void*       m_unk158;                    // +0x158  uninitialised in ctor (reserved/padding) /* tentative */

    // std::vector<T> (0x40-byte elements), begin/end/capacity_end; &vector via IGame vtable[39]
    std::vector<void*> m_vec;   // +0x160  begin/end/capacity (0x18); element type unidentified

    void*       m_pObj178;                  // +0x178  ptr to 0x2F0-byte heap obj (sub_180C127C0/sub_180C12834); IGame vtable[35] getter
    wh::game::C_PlatformActivityManager* m_pPlatformActivityManager; // +0x180  8-byte heap obj (sub_180C12760)  VERIFIED type

    uint32_t    m_unk188;                    // +0x188  (unreferenced) /* tentative */
    uint8_t     m_flag18C;                   // +0x18C  (ctor=0)
    uint8_t     _pad18D[3];                  // +0x18D
    uint32_t    m_unk190;                    // +0x190  set by IGame vtable[36]
    uint32_t    _pad194;                     // +0x194
};
static_assert(sizeof(C_Game) == 0x198);

} // namespace wh::game
