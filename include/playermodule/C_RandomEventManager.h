#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

#include "../conceptmodule/C_Node.h"
#include "../conceptmodule/C_NodeManager.h"
#include "C_GenericRandomEvent.h"
#include "C_RandomEventPlace.h"

namespace wh::playermodule {

class C_RandomEventManager : public wh::conceptmodule::C_NodeManager {
public:
    C_RandomEventManager();
    ~C_RandomEventManager() override;                       // [0] 0x182EA7C60
    virtual void unk1(void* registrationContext);           // [1] 0x1816CADA8
    virtual void unk2(_smart_ptr<wh::conceptmodule::C_Node> node); // [2] 0x1804C50C4, adds generic event
    virtual void unk3(_smart_ptr<wh::conceptmodule::C_Node> node); // [3] 0x1816BDD8C, removes generic event
    virtual void unk4(_smart_ptr<wh::conceptmodule::C_Node> node); // [4] 0x1804C44B8, adds place
    virtual void unk5(_smart_ptr<wh::conceptmodule::C_Node> node); // [5] 0x1816AFCA0, removes place
    RTTR_ENABLE(wh::conceptmodule::C_NodeManager) // [6..8]

    CryStringT<char> m_name;                               // +0x08
    std::uint16_t m_unknown10;                             // +0x10, ctor 0xFFFF
    std::uint16_t m_unknown12;                             // +0x12, ctor 0xFFFF
    std::uint8_t m_padding14[4];
    std::vector<_smart_ptr<C_RandomEventPlace>> m_places;  // +0x18
    std::vector<_smart_ptr<wh::conceptmodule::C_Node>>
        m_unknownNodes30;                                  // +0x30, owning; exact subtype/role unresolved
    std::vector<_smart_ptr<wh::conceptmodule::C_Node>>
        m_unknownNodes48;                                  // +0x48, owning; exact subtype/role unresolved
    std::vector<_smart_ptr<C_RandomEventPlace>>
        m_pendingPlaces;                                   // +0x60, area-enter queue
    std::vector<_smart_ptr<C_GenericRandomEvent>>
        m_genericEvents;                                   // +0x78
    std::vector<_smart_ptr<C_RandomEventBase>>
        m_activeEvents;                                    // +0x90
    bool m_placeSelectionInProgress;                       // +0xA8
    std::uint8_t m_paddingA9[7];
    std::vector<std::pair<CryStringT<char>, std::int32_t>>
        m_tagBlockCounts;                                  // +0xB0
    std::uint16_t m_unknownC8;                             // +0xC8
    std::uint8_t m_paddingCA[6];
    std::vector<std::pair<CryStringT<char>, std::int64_t>>
        m_cooldownTimestamps;                              // +0xD0, milliseconds
    std::vector<std::pair<CryStringT<char>, std::int32_t>>
        m_spawnCounts;                                     // +0xE8, incremented on event start
    std::uint8_t m_unknown100[0x18];                       // +0x100, runtime object; exact type unresolved
};

static_assert(sizeof(C_RandomEventManager) == 0x118,
              "C_RandomEventManager size mismatch");
static_assert(offsetof(C_RandomEventManager, m_places) == 0x18,
              "C_RandomEventManager places offset mismatch");
static_assert(offsetof(C_RandomEventManager, m_pendingPlaces) == 0x60,
              "C_RandomEventManager pending places offset mismatch");
static_assert(offsetof(C_RandomEventManager, m_genericEvents) == 0x78,
              "C_RandomEventManager generic events offset mismatch");
static_assert(offsetof(C_RandomEventManager, m_activeEvents) == 0x90,
              "C_RandomEventManager active events offset mismatch");
static_assert(offsetof(C_RandomEventManager, m_tagBlockCounts) == 0xB0,
              "C_RandomEventManager tag blocks offset mismatch");
static_assert(offsetof(C_RandomEventManager, m_cooldownTimestamps) == 0xD0,
              "C_RandomEventManager cooldown timestamps offset mismatch");
static_assert(offsetof(C_RandomEventManager, m_spawnCounts) == 0xE8,
              "C_RandomEventManager spawn counts offset mismatch");
static_assert(offsetof(C_RandomEventManager, m_unknown100) == 0x100,
              "C_RandomEventManager runtime tail offset mismatch");

} // namespace wh::playermodule
