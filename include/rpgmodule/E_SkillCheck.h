#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_SkillCheck {
    enum Type : std::uint32_t {
        persuade               = 0,
        impress                = 1,
        dread                  = 2,
        coerce                 = 3,
        dominate               = 4,
        might                  = 5,
        stealth                = 6,
        horse_riding           = 7,
        fencing                = 8,
        bard                   = 9,
        thievery               = 10,
        pickpocketing_obsolete = 11,
        alchemy                = 12,
        cooking                = 13,
        craftsmanship          = 14,
        smithing_obsolete      = 15,
        fishing                = 16,
        mining                 = 17,
        first_aid              = 18,
        drinking               = 19,
        survival               = 20,
        defense                = 21,
        weapon_sword           = 22,
        heavy_weapons          = 23,
        weapon_bow_obsolete    = 24,
        marksmanship           = 25,
        weapon_shield          = 26,
        weapon_mace_obsolete   = 27,
        weapon_dagger          = 28,
        weapon_large           = 29,
        weapon_unarmed         = 30,
        herbalism_obsolete     = 31,
        scholarship            = 32,
        tailoring              = 33,
        armourer               = 34,
        weaponsmithing         = 35,
        shoemaking             = 36,
        gunsmithing            = 37,
        bowyery                = 38,
        gambling               = 39,
        houndmaster            = 40,
        strength               = 41,
        agility                = 42,
        vitality               = 43,
        speech                 = 44,
        vision                 = 45,
        hearing                = 46,
        barter                 = 47,
        courage                = 48,
        storyProgress          = 49,
        prestige               = 50,
    };
};
static_assert(sizeof(E_SkillCheck::Type) == 4, "E_SkillCheck::Type size mismatch");

}  // namespace wh::rpgmodule
