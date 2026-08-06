#pragma once
#include <cstdint>
#include <functional>

// -----------------------------------------------
// wh::framework::WUID -- Warhorse unique id (KCD2 WHGame.dll 1.5.6, kd7u).  8 bytes.
// -----------------------------------------------
// A tagged 64-bit handle: (slot | gen<<18 | tag<<56). The high byte is the object-kind tag
// (e.g. 0x02 == Item, 0x03 == Inventory, 0x05 == Soul). A default/invalid WUID is 0. Used
// pervasively as the registry key for bindable objects and as the element/key of the game's
// std::unordered_set<WUID> / std::unordered_map<WUID,V> (which hash it with std::hash<WUID>).

namespace wh::framework {

// Object-kind tag in the top byte; each tag has its own registry, reached via a class
// implementing I_WUIDMappingProvider. Recovered by scanning .text for `mov r64, tag<<56`
// stamp sites and naming the object each builds -- not an exhaustive 0..255 sweep.
// Unrelated to the RTTR enum wh::xgenaimodule::E_ConceptAIWuidType (different values).
enum class E_WUIDTag : uint8_t {
    BuffDefinition        = 0x01,  // default buff-definition id, C_BuffInstanceBase+0x08
    Item                  = 0x02,  // C_ItemManager
    Inventory             = 0x03,  // C_InventoryManager, acquire sub_1823D154C
    LinkableObjectHolder  = 0x04,  // VIEW: re-tags another WUID's slot (sub_18096DBDC)
    Soul                  = 0x05,  // C_SoulList
    ItemIndexerOrGroup    = 0x06,  // C_ItemIndexer/C_InventoryGroup, sub_180C47464 [U which]
    Unnamed07             = 0x07,  // sub_180D9B474, counter @mgr+0x430 [U leaf]
    GeneratedSOPuppet     = 0x08,  // puppet registry q_185496338
    Situation             = 0x09,  // C_Situation
    DynamicLinkableObject = 0x0A,  // C_DynamicLinkablesManager, registry q_1854961A0
    PerceptibleVolume     = 0x0D,  // C_PerceptibleVolumeCylinder ctor 0x180D45BCC
    Unnamed0F             = 0x0F,  // sub_180A2C970, alloc 0x128 [U leaf]
    Unnamed10             = 0x10,  // sub_180FA53C4, counter @+0x48 [U leaf]
    Formation             = 0x11,  // C_FormationManager -> C_Formation (sub_1807D36DC)
    FormationAIObject     = 0x12,  // C_FormationManager -> C_AIObject (sub_1832A245C)
    FormationSpinePoint   = 0x13,  // C_FormationSpinePointPuppet
    AreaUnion             = 0x14,  // C_AreaUnionManager (sub_1811A4DF4)
    Unnamed15             = 0x15,  // sub_1820B3900, alloc 0xA0 [U leaf]
};

struct WUID {
    uint64_t m_value;   // (slot | gen<<18 | tag<<56)

    constexpr uint32_t slot()       const { return (uint32_t)(m_value & 0x1FFFF); }
    constexpr uint16_t generation() const { return (uint16_t)(m_value >> 0x11); }
    constexpr uint8_t  tag()        const { return (uint8_t)(m_value >> 56); }
    constexpr E_WUIDTag tagEnum()   const { return (E_WUIDTag)tag(); }

    constexpr bool operator==(const WUID& o) const { return m_value == o.m_value; }
    constexpr bool operator!=(const WUID& o) const { return m_value != o.m_value; }
    constexpr bool operator<(const WUID& o) const { return m_value < o.m_value; }   // std::map/std::set ordering
};
static_assert(sizeof(WUID) == 8);

}  // namespace wh::framework

// The binary's std::unordered_set<WUID> / std::unordered_map<WUID,V> use std::hash<WUID> (FNV-1a of
// the 8-byte handle, matching MSVC std::hash for a trivially-copyable key) and std::equal_to<WUID>.
template<>
struct std::hash<wh::framework::WUID> {
    size_t operator()(const wh::framework::WUID& w) const noexcept {
        uint64_t h = 0xCBF29CE484222325ULL;
        for (int i = 0; i < 8; ++i) h = (h ^ ((w.m_value >> (i * 8)) & 0xFF)) * 0x100000001B3ULL;
        return (size_t)h;
    }
};
