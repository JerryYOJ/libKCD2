#pragma once
#include <cstdint>
#include "framework/C_BaseModule.h"
#include "Offsets/vtables/ISystem.h"   // Offsets::ISystemEventListener

// -----------------------------------------------
// wh::playermodule::C_PlayerModule -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xA0.
// -----------------------------------------------
// RTTI .?AVC_PlayerModule@playermodule@wh@@  primary vtable 0x183F74448 (11 slots)
// ctor sub_180BE9208  scalar-deleting dtor sub_182EA7BF8 (operator delete this,0xA0)
// Stored at S_GameContext+0x128 (VERIFIED, module registration sub_180C9DA44).
//
// Bases (from ctor vtable writes): C_BaseModule/I_ModuleMessageListener @+0x00,
// ISystemEventListener @+0x10. All members from +0x18 are owned sub-managers built
// by the ctor; only the two named ones below are load-bearing for the plugins.
//
// [FUNDAMENTAL vs KCD1] The KCD1 autosave mechanic is gone. KCD1 AutoSave set
// bool m_autoSaveRequested@+0x108 and the per-frame tick polled/cleared it and
// dispatched C_ModuleMessageSaveGameRequest(saveType=1). In KCD2, Update (slot4,
// sub_180533478) polls no such byte and no method reads +0x98 as a flag; save
// requests are driven from other subsystems and E_SaveType values shifted (KCD1
// autosave=1; KCD2 callers use 2/6/8). Writing a bool here will NOT trigger a save
// -- AutoSave must be re-implemented (call the SaveGameRequest dispatch directly).
// m_98 below is exposed only as an UNVERIFIED placeholder, not the KCD1 flag.
//
// [MODERATE vs KCD1] m_pFastTravel moved +0xB0 -> +0x28 (still an owned C_FastTravel*).

namespace wh::playermodule {

class C_FastTravel;
class C_ForgeWardrobeManager;   // NEW in KCD2

class C_PlayerModule
    : public wh::framework::C_BaseModule
    , public Offsets::ISystemEventListener
{
public:
    // C_BaseModule base occupies +0x00 (vtable) / +0x08 (m_state) / +0x0C (pad);
    // ISystemEventListener base occupies +0x10 (vtable). Members follow at +0x18.
    void*                   m_sub18;            // +0x18  sub-manager (0xB0,  ctor sub_180EF7184)
    void*                   m_sub20;            // +0x20  sub-manager (0x50,  ctor sub_18179FD3C)
    C_FastTravel*           m_pFastTravel;      // +0x28  (0x130, ctor sub_180BE9BA0)            VERIFIED
    void*                   m_sub30;            // +0x30  sub-manager (0x118, ctor sub_180BE83E8)
    void*                   m_sub38;            // +0x38  sub-manager (0xA8,  ctor sub_180BE9FB4)
    void*                   m_sub40;            // +0x40  sub-manager (0x1F0, ctor sub_18124417C)
    void*                   m_sub48;            // +0x48  sub-manager (0x20,  intrusive list node)
    void*                   m_sub50;            // +0x50  sub-manager (0x50,  C_Signal-like)
    void*                   m_sub58;            // +0x58  sub-manager (0x140, ctor sub_181748CFC)
    void*                   m_sub60;            // +0x60  sub-manager (0x90,  ctor sub_180BE9E68)
    void*                   m_sub68;            // +0x68  sub-manager (0x20,  C_Signal-like)
    void*                   m_sub70;            // +0x70  sub-manager (0x10,  single-node list)
    void*                   m_sub78;            // +0x78  sub-manager (0xD8,  ctor sub_180BE9868)
    void*                   m_sub80;            // +0x80  sub-manager (0x88,  ctor sub_180794D8C)
    void*                   m_sub88;            // +0x88  sub-manager (0x58,  ctor sub_180C3D1CC)
    C_ForgeWardrobeManager* m_pForgeWardrobe;   // +0x90  (0x20)  NEW in KCD2                    VERIFIED
    uint64_t                m_98;               // +0x98  zero-init, no verified reader; NOT the KCD1 autosave flag (UNVERIFIED)
};
static_assert(sizeof(C_PlayerModule) == 0xA0, "C_PlayerModule must be 0xA0");

}  // namespace wh::playermodule
