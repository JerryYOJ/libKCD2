#pragma once

#include <unordered_map>
#include "../../framework/HashPrimitives.h"
#include "../../framework/WUID.h"

namespace wh::xgenaimodule::movement {

class C_Formation;

class C_FormationManager {
public:
    static C_FormationManager* GetInstance();
    C_Formation* FindByWuid(const framework::WUID& wuid);

    virtual ~C_FormationManager(); // [0] sub_1832A0A7C

    std::unordered_map<framework::WUID, C_Formation*,
                       shared::S_DefaultHash<framework::WUID>> m_formationsByWuid; // +0x08
    std::uint8_t _unknown48[0x40];
    std::uint64_t m_wuidCounter; // +0x88
    std::uint8_t _unknown90[0x50];
};
static_assert(sizeof(C_FormationManager) == 0xE0, "C_FormationManager must be 0xE0");

}  // namespace wh::xgenaimodule::movement
