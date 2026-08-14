#pragma once
#include <cstdint>

namespace wh::entitymodule {

enum class ProjectileFlags : std::uint32_t {
    None                       = 0x00000000,
    Collided                   = 0x00000001,
    HitListener                = 0x00000002,
    Remote                     = 0x00000004,
    Destroying                 = 0x00000008,
    NoBulletHits               = 0x00000010,
    KnocksTarget               = 0x00000020,
    Launched                   = 0x00000040,
    ThreatTrailEmitted         = 0x00000080,
    DelayedDetonation          = 0x00000100,
    FiredViaProxy              = 0x00000200,
    NeedDestruction            = 0x00000400,
    OwnerIsPlayer              = 0x00000800,
    Linked                     = 0x00001000,
    HitRecorded                = 0x00002000,
    FailedDetonation           = 0x00004000,
    AimedShot                  = 0x00008000,
    DontNetSerialisePhysics    = 0x00010000,
    HitListenerMpExplosionOnly = 0x00020000,
    ElectricHit                = 0x00040000,
    Flag80000                  = 0x00080000,
};
static_assert(sizeof(ProjectileFlags) == 0x04,
              "ProjectileFlags must be 0x04");

constexpr ProjectileFlags operator|(ProjectileFlags lhs, ProjectileFlags rhs) noexcept {
    return static_cast<ProjectileFlags>(
        static_cast<std::uint32_t>(lhs) | static_cast<std::uint32_t>(rhs));
}

constexpr ProjectileFlags operator&(ProjectileFlags lhs, ProjectileFlags rhs) noexcept {
    return static_cast<ProjectileFlags>(
        static_cast<std::uint32_t>(lhs) & static_cast<std::uint32_t>(rhs));
}

constexpr ProjectileFlags& operator|=(ProjectileFlags& lhs, ProjectileFlags rhs) noexcept {
    lhs = lhs | rhs;
    return lhs;
}

}  // namespace wh::entitymodule
