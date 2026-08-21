#pragma once
#include <cstdint>
#include "guimodule/C_UIFlashBase.h"
#include "guimodule/C_UIModalDialogItem.h"
#include "framework/I_UIHudMessages.h"

// -----------------------------------------------
// wh::guimodule::C_UIHudMessages -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x320.
// -----------------------------------------------
// RTTI .?AVC_UIHudMessages@guimodule@wh@@ (TD 0x184CCFB98).
// Bases: C_UIFlashBase @+0x00 (COL 0x4136080), IUIElementEventListener @+0x10
// (COL 0x41360A8), framework::I_UIHudMessages @+0x58 (COL 0x41360D0).
// vtables: primary 0x183D2C340 (14; GetElementName [11] 0x181A8E8F0 = "hud";
// [4] Update 0x180533C20 own), listener 0x183D2E4C8 (8), messages 0x183D2EA98 (7).
// ctor sub_180BC9680; rttr as_std_shared_ptr creator sub_1818AC318 (alloc 0x320).
//
// Info-text HUD. EMBEDS C_UIModalDialogItem @+0x60 ("ApseModalDialog").
// Init [1] 0x180EC7678 -> loc-key table writer 0x180EC6E98 (57 assigns; 9 slots
// stay ctor-empty). I_UIHudMessages [M2] GetMessageText 0x181A8E8E0 is a FLAT
// index over the 66-slot block: owner+0x110+8*id (id 0..65). Per-minigame HUD
// consumers index their own array locally (this+base+8*code), usually skipping 0.
//
// Enumerators match Init keys / Lua E_SkipTimeMessage where named.

namespace wh::guimodule {

struct E_SkipTimeMessage {
    enum Type : uint8_t {
        Empty             = 0,   // explicit ""
        NotIdle           = 1,   // ui_playerCantSkiptime_notIdle
        TimePause         = 2,   // ui_playerCantSkiptime_timePause
        Oversleep         = 3,   // ui_playerCantSleep_oversleep
        Overread          = 4,   // ui_playerCantStudy_overread
        Combat            = 5,   // ui_playerCantSkiptime_combat
        LowHealth         = 6,   // ui_playerCantSkiptime_lowHealth
        LowFood           = 7,   // ui_playerCantSkiptime_lowFood
        TenseCircumstance = 8,   // ui_playerCantSkiptime_tenseCircumstance
        InCart            = 9,   // ui_playerCantSkiptime_inCart
        Trespass          = 10,  // ui_playerCantSkiptime_trespass
        OnHorse           = 11,  // ui_playerCantSkiptime_onHorse
    };
};

struct E_PickpocketingHandle {
    enum Type : uint8_t {
        Interrupted     = 0,   // ui_pickpocket_fail_interrupted  (consumer does NOT skip 0)
        Succeeded       = 1,   // ui_pickpocket_suceeded
        DetectedByVictim = 2,  // ui_hud_pickpocket_fail_detected_by_victim
        Lost            = 3,   // ui_hud_pickpocket_fail_lost
        Empty           = 4,   // ctor-empty, never assigned
        NothingStolen   = 5,   // ui_pickpocket_success_nothing_stolen
        SeenBySomeone   = 6,   // ui_hud_pickpocket_fail_seen_by_someone
    };
};

struct E_DiceMessage {
    enum Type : uint8_t {
        Empty                 = 0,
        YouWon                = 1,   // ui_dice_you_won
        YouLost               = 2,   // ui_dice_you_lost
        YouGaveUp             = 3,   // ui_dice_you_gave_up
        Bust                  = 4,   // ui_dice_bust
        RerollTooMany         = 5,   // ui_dice_reroll_too_many
        RerollNoDie           = 6,   // ui_dice_reroll_no_die
        RerollNotSameValue    = 7,   // ui_dice_reroll_not_same_value
        OpponentUsedNullBadge = 8,   // ui_dice_opponent_used_null_badge
    };
};

struct E_LockpickingHandle {
    enum Type : uint8_t {
        Empty                = 0,   // consumer 0x1812C0C68 no-ops code==0
        CannotStart          = 1,   // dlg_lp_cannotStart
        DifficultInfo        = 2,   // dlg_lp_difficult_info  (+0x200)
        Success              = 3,   // ui_hud_lp_success
        Fail                 = 4,   // ui_hud_lp_fail
        CannotStartMinigame  = 5,   // dlg_cannotStartMinigame (same literal as E_ActivityStart::CannotStartMinigame)
    };
};

struct E_AlchemyMessage {
    enum Type : uint8_t {
        Empty                       = 0,
        RecipeFailed                = 1,   // dlg_alch_recipe_failed
        ResettableInfo              = 2,   // dlg_alch_resettable_info
        PotionCreated               = 3,   // dlg_alch_potion_created
        RecipeUnlocked              = 4,   // dlg_alch_recipe_unlocked
        PotionCreatedRecipeUnlocked = 5,   // dlg_alch_potion_created_recipe_unlocked
        PrepareInfo                 = 6,   // dlg_alch_prepare_info
    };
};

struct E_BlacksmithingHandle {
    enum Type : uint8_t {
        Empty                = 0,
        Success              = 1,   // ui_blacksmithing_success
        SuccessWithLockpicks = 2,   // ui_blacksmithing_success_with_lockpicks
        Failed               = 3,   // ui_blacksmithing_failed
    };
};

struct E_ReadingHandle {
    enum Type : uint8_t {
        Empty        = 0,
        BookIsFinish = 1,   // ui_playerCantStudy_bookIsFinish
        LowReading   = 2,   // ui_playerCantStudy_lowReading
        LowSkill     = 3,   // ui_playerCantStudy_lowSkill
    };
};

struct E_ActivityStart {
    enum Type : uint8_t {
        Empty                       = 0,
        NewHomesMissingPrerequisites = 1,  // ui_new_homes_missing_prerequisities
        HoleDiggingCannotStart      = 2,   // dlg_hd_cannotStart
        CannotStartMinigame         = 3,   // dlg_cannotStartMinigame
    };
};

struct E_DeniedAction {
    enum Type : uint8_t {
        Empty                       = 0,
        CannotSprintWhileEncumbered = 1,   // ui_rpg_CannotSprintWhileEncumbered
        CannotMount                 = 2,   // dlg_horse_cannotMount
        HorseWhistleSuppressed      = 3,   // log_horse_whistle_supressed
        CannotCallDog               = 4,   // ui_hud_you_cant_call_dog
        DogHuntTired                = 5,   // log_dog_hunt_tired
        DontHaveSoap                = 6,   // ui_hud_you_dont_have_soap
        HorseEncumbered             = 7,   // ui_horse_Encumbered
        NoSpaceForDismount          = 8,   // ui_horse_NoSpaceForDismount
    };
};

struct E_SaveGameMessage {
    enum Type : uint8_t {
        Empty            = 0,
        Saved            = 1,   // log_game_saved
        SaveFailed       = 2,   // log_game_save_failed
        SaveDeleteFailed = 3,   // log_game_save_delete_failed
    };
};

class C_UIHudMessages : public C_UIFlashBase, public wh::framework::I_UIHudMessages {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_UIHudMessages;
    void Init(C_GUIModule* pModule) override;   // [1] 0x180EC7678
    void Update() override;                     // [4] 0x180533C20
    void OnGameStart(void* pGame) override;     // [5] 0x180EC8510
    void OnGameEnd(void* pGame) override;       // [6] 0x180EC7D3C
    void ShowInfoText(const CryStringT<char>& text, int a3, int a4) override;   // [M0] 0x1812C15EC
    void HideInfoText() override;                                               // [M1] 0x180C44E70
    // Flat 0..65 over the 66-slot block (owner+0x110+8*id), not one array.
    CryStringT<char>* GetMessageText(uint8_t messageId) override;               // [M2] 0x181A8E8E0
    CryStringT<char>* GetMessageSound(uint16_t typeFlags) override;             // [M3] 0x182B8D9AC  statics, not this block

    C_UIModalDialogItem m_modalDialog;                         // +0x60
    CryStringT<char> m_skipTimeMessages[12];                   // +0x110  E_SkipTimeMessage
    CryStringT<char> m_pickpocketingHandleKeys[7];             // +0x170  E_PickpocketingHandle
    CryStringT<char> m_diceMessages[9];                        // +0x1A8  E_DiceMessage
    CryStringT<char> m_lockpickingHandleKeys[6];               // +0x1F0  E_LockpickingHandle
    CryStringT<char> m_alchemyMessages[7];                     // +0x220  E_AlchemyMessage
    CryStringT<char> m_blacksmithingHandleKeys[4];             // +0x258  E_BlacksmithingHandle
    CryStringT<char> m_readingHandleKeys[4];                   // +0x278  E_ReadingHandle
    CryStringT<char> m_activityStartKeys[4];                   // +0x298  E_ActivityStart
    CryStringT<char> m_deniedActionTexts[9];                   // +0x2B8  E_DeniedAction
    CryStringT<char> m_saveGameMessages[4];                    // +0x300  E_SaveGameMessage
};
static_assert(sizeof(C_UIHudMessages) == 0x320, "C_UIHudMessages must be 0x320");
static_assert(offsetof(C_UIHudMessages, m_modalDialog) == 0x60, "modal dialog item at 0x60");
static_assert(offsetof(C_UIHudMessages, m_skipTimeMessages) == 0x110, "skip-time keys at 0x110");
static_assert(offsetof(C_UIHudMessages, m_pickpocketingHandleKeys) == 0x170, "pickpocket keys at 0x170");
static_assert(offsetof(C_UIHudMessages, m_diceMessages) == 0x1A8, "dice keys at 0x1A8");
static_assert(offsetof(C_UIHudMessages, m_lockpickingHandleKeys) == 0x1F0, "lockpicking keys at 0x1F0");
static_assert(offsetof(C_UIHudMessages, m_alchemyMessages) == 0x220, "alchemy keys at 0x220");
static_assert(offsetof(C_UIHudMessages, m_blacksmithingHandleKeys) == 0x258, "blacksmithing keys at 0x258");
static_assert(offsetof(C_UIHudMessages, m_readingHandleKeys) == 0x278, "reading keys at 0x278");
static_assert(offsetof(C_UIHudMessages, m_activityStartKeys) == 0x298, "activity-start keys at 0x298");
static_assert(offsetof(C_UIHudMessages, m_deniedActionTexts) == 0x2B8, "denied-action keys at 0x2B8");
static_assert(offsetof(C_UIHudMessages, m_saveGameMessages) == 0x300, "save-game keys at 0x300");

}  // namespace wh::guimodule
