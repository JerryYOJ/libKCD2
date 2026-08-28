#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <set>

#include "../CryEngine/CryCommon/smartptr.h"

namespace wh::playermodule {

class C_RandomEventBase;
class C_RandomEventVariantBase;
struct S_RandomEventOption;

struct S_RandomEventEncounter {
    _smart_ptr<C_RandomEventVariantBase> m_variant; // +0x00
    _smart_ptr<C_RandomEventBase> m_event;          // +0x08
    std::uint32_t m_unknown10;                      // +0x10
    float m_difficulty;                             // +0x14
    std::shared_ptr<void> m_context;                // +0x18, exact pointee unresolved
    std::set<std::uint64_t> m_unknownIds;           // +0x28
    float m_unknown38;                              // +0x38, ctor default -1.0f
    bool m_unknown3C;                               // +0x3C, ctor default true
    std::uint8_t m_padding3D[3];
    S_RandomEventOption* m_option;                  // +0x40
    bool m_unknown48;                               // +0x48
    std::uint8_t m_padding49[7];
    std::uint32_t m_spawnEntityId;                  // +0x50
    std::uint8_t m_padding54[4];
};

static_assert(sizeof(S_RandomEventEncounter) == 0x58,
              "S_RandomEventEncounter size mismatch");
static_assert(offsetof(S_RandomEventEncounter, m_context) == 0x18,
              "S_RandomEventEncounter context offset mismatch");
static_assert(offsetof(S_RandomEventEncounter, m_unknownIds) == 0x28,
              "S_RandomEventEncounter ID set offset mismatch");
static_assert(offsetof(S_RandomEventEncounter, m_option) == 0x40,
              "S_RandomEventEncounter option offset mismatch");
static_assert(offsetof(S_RandomEventEncounter, m_spawnEntityId) == 0x50,
              "S_RandomEventEncounter entity ID offset mismatch");

} // namespace wh::playermodule
