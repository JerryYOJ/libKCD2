#pragma once
#include <cstdint>
#include "REL/Offset.h"

// -----------------------------------------------
// SSystemGlobalEnvironment (gEnv) -- KCD2 binary layout
// -----------------------------------------------
// Address: WHGame+0x492D7F8 (.data, IDA labels as gEnv)
// Non-polymorphic global; every +0x08 slot from +0x00 to +0x1B8 named.
// VERIFIED slots recovered from direct-absolute field reads + the vtable call each reader makes.
// Offsets that differ from KCD1: pPhysicalWorld +0x28->+0x38, pLog +0xE0->+0xE8, pFlashUI +0x130->+0x140.

namespace Offsets {
    struct IScriptSystem; struct IPhysicalWorld; struct IInput; struct ITimer;
    struct IGame; struct IEntitySystem; struct IConsole; struct ISystem;
    struct ILog; struct IRenderer; struct IFlashUI;
}

struct SSystemGlobalEnvironment {
    void*                       pDialogSystem;          // +0x00
    void*                       p3DEngine_DEAD;         // +0x08  guarded dead slot (as in KCD1)
    void*                       pNetwork;               // +0x10
    void*                       pLobby;                 // +0x18
    void*                       _unk20;                 // +0x20
    void*                       _unk28;                 // +0x28
    Offsets::IScriptSystem*     pScriptSystem;          // +0x30  VERIFIED: GetGlobalValue/ExecuteBuffer
    Offsets::IPhysicalWorld*    pPhysicalWorld;         // +0x38  VERIFIED: RayWorldIntersection (was +0x28)
    void*                       _unk40;                 // +0x40
    Offsets::IInput*            pInput;                 // +0x48  VERIFIED: AddEventListener("C_Keybinds")
    void*                       _unk50;                 // +0x50
    void*                       _unk58;                 // +0x58
    void*                       _unk60;                 // +0x60
    void*                       _unk68;                 // +0x68
    void*                       _unk70;                 // +0x70
    void*                       _unk78;                 // +0x78
    void*                       _unk80;                 // +0x80
    Offsets::ITimer*            pTimer;                 // +0x88  VERIFIED: GetCurrTime
    void*                       _unk90;                 // +0x90
    Offsets::IGame*             pGame;                  // +0x98  VERIFIED: GetIGameFramework chain
    void*                       _unkA0;                 // +0xA0
    Offsets::IEntitySystem*     pEntitySystem;          // +0xA8  VERIFIED: GetEntity(entityId)
    Offsets::IConsole*          pConsole;               // +0xB0  VERIFIED: GetCVar/RegisterVariable
    void*                       _unkB8;                 // +0xB8
    void*                       _unkC0;                 // +0xC0
    Offsets::ISystem*           pSystem;                // +0xC8  VERIFIED: == CSystem self
    void*                       _unkD0;                 // +0xD0
    void*                       _unkD8;                 // +0xD8
    void*                       pCharacterManager;      // +0xE0  ("MediumSizedCharacters"); NOT pLog in KCD2
    Offsets::ILog*              pLog;                   // +0xE8  VERIFIED: Log/LogError (was +0xE0)
    void*                       _unkF0;                 // +0xF0
    void*                       _unkF8;                 // +0xF8
    void*                       _unk100;                // +0x100
    void*                       _unk108;                // +0x108
    Offsets::IRenderer*         pRenderer;              // +0x110  VERIFIED: renderer vtable calls
    void*                       _unk118;                // +0x118
    void*                       _unk120;                // +0x120
    void*                       _unk128;                // +0x128
    void*                       _unk130;                // +0x130
    void*                       _unk138;                // +0x138
    Offsets::IFlashUI*          pFlashUI;               // +0x140  VERIFIED: GetUIElement("hud") (was +0x130)
    void*                       _unk148;                // +0x148
    void*                       _unk150;                // +0x150
    void*                       _unk158;                // +0x158
    void*                       _unk160;                // +0x160
    void*                       _unk168;                // +0x168
    void*                       _unk170;                // +0x170
    void*                       _unk178;                // +0x178
    void*                       _unk180;                // +0x180
    void*                       _unk188;                // +0x188
    void*                       _unk190;                // +0x190
    void*                       _unk198;                // +0x198
    void*                       _unk1A0;                // +0x1A0
    void*                       _unk1A8;                // +0x1A8
    void*                       _unk1B0;                // +0x1B0
    void*                       _unk1B8;                // +0x1B8

    static SSystemGlobalEnvironment* GetInstance()
    {
        return reinterpret_cast<SSystemGlobalEnvironment*>(REL::Offset(0x492D7F8).address());
    }
};
static_assert(sizeof(SSystemGlobalEnvironment) == 0x1C0);
