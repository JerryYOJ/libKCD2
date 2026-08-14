#pragma once
#include <cstdint>
#include <functional>

// -----------------------------------------------
// wh::framework::WUID -- Warhorse unique id (KCD2 WHGame.dll 1.5.6, kd7u). 8 bytes.
// -----------------------------------------------
// The high byte identifies the owning object domain. The remaining 56 bits are encoded by that
// domain's registry; Item, Inventory, and Soul use different slot/generation partitions.

namespace wh::framework {

enum class E_WUIDTag : std::uint8_t {
    Invalid               = 0x00,
    SoulBuffInstance      = 0x01,
    Item                  = 0x02,
    Inventory             = 0x03,
    Shop                  = 0x04,
    Soul                  = 0x05,
    ItemIndexer           = 0x06,
    SmartArea             = 0x07,
    SmartObject           = 0x08,
    Situation             = 0x09,
    DynamicLinkableObject = 0x0A,
    Quest                 = 0x0B,
    PredefinedPath        = 0x0C,
    PerceptibleVolume     = 0x0D,
    // 0x0E is invalid/unassigned.
    TriggerArea           = 0x0F,
    ParticleEffect        = 0x10,
    Formation             = 0x11,
    FormationAnchor       = 0x12,
    FormationSpinePoint   = 0x13,
    AreaUnion             = 0x14,
    ReplanMoveArea        = 0x15,
};

struct WUID {
    std::uint64_t m_value;

    constexpr std::uint8_t tagValue() const noexcept {
        return static_cast<std::uint8_t>(m_value >> 56);
    }
    constexpr E_WUIDTag tag() const noexcept {
        return static_cast<E_WUIDTag>(tagValue());
    }
    constexpr explicit operator bool() const noexcept { return m_value != 0; }

    constexpr bool operator==(const WUID& other) const noexcept { return m_value == other.m_value; }
    constexpr bool operator!=(const WUID& other) const noexcept { return m_value != other.m_value; }
    constexpr bool operator<(const WUID& other) const noexcept { return m_value < other.m_value; }
};
static_assert(sizeof(WUID) == 0x08);

}  // namespace wh::framework

// The game's unordered WUID registries use FNV-1a over the raw eight-byte handle.
template<>
struct std::hash<wh::framework::WUID> {
    std::size_t operator()(const wh::framework::WUID& wuid) const noexcept {
        std::uint64_t hash = 0xCBF29CE484222325ULL;
        for (int i = 0; i < 8; ++i)
            hash = (hash ^ ((wuid.m_value >> (i * 8)) & 0xFF)) * 0x100000001B3ULL;
        return static_cast<std::size_t>(hash);
    }
};
