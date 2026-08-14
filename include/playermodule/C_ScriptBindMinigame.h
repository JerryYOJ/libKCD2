#pragma once
#include <cstdint>
#include "../crysystem/CScriptableBase.h"
#include "../Offsets/vtables/IFunctionHandler.h"

// -----------------------------------------------
// wh::playermodule::C_ScriptBindMinigame -- Lua "Minigame" table
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x68.
// -----------------------------------------------
// RTTI .?AVC_ScriptBindMinigame@playermodule@wh@@; vtable 0x183ACED40;
// ctor sub_180EF7484, registration sub_181795808. The owner at +0x60 is the
// C_MinigameManager passed directly to FindOrCreateSession by every Start handler.

namespace wh::playermodule {

class C_MinigameManager;

class C_ScriptBindMinigame : public CScriptableBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ScriptBindMinigame;

    virtual int StartHerbGathering(Offsets::IFunctionHandler* pH,
                                   uint32_t pickableAreaEntityId); // [4] sub_182ED0244
    virtual int StartLockPicking(Offsets::IFunctionHandler* pH,
                                 uint32_t entityId);               // [5] sub_1819C9A5C
    virtual int StartHoleDigging(Offsets::IFunctionHandler* pH,
                                 uint32_t entityId);               // [6] sub_182ED02A8
    virtual int StartDice(Offsets::IFunctionHandler* pH, uint32_t playerId,
                          uint32_t tableId, uint32_t opponentId);  // [7] sub_182ECFCF8
    virtual int StartDiceWithScore(Offsets::IFunctionHandler* pH,
                                   int32_t targetScore);           // [8] sub_182ED01D4
    virtual int StartDiceByName(Offsets::IFunctionHandler* pH,
                                const char* entityName);           // [9] sub_182ED005C
    virtual int CanUseMinigame(Offsets::IFunctionHandler* pH,
                               uint32_t playerId);                 // [10] sub_1809379C8

    C_MinigameManager* m_pOwner; // +0x60
};
static_assert(sizeof(C_ScriptBindMinigame) == 0x68,
              "C_ScriptBindMinigame must match its 0x68 allocation");
static_assert(offsetof(C_ScriptBindMinigame, m_pOwner) == 0x60,
              "minigame-manager owner must be at +0x60");

}  // namespace wh::playermodule
