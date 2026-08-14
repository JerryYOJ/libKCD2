#pragma once
#include <cstddef>
#include <cstdint>
#include "CProjectile.h"

namespace wh::entitymodule {

// KCD2 WHGame.dll 1.5.6: primary 0x184711C10; allocation witness 0x1829440D0.
class C_Decoy : public CProjectile {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Decoy;

    ~C_Decoy() override;                                               // [0] 0x18295C3A8
    void HandleEvent(const SGameObjectEvent& event) override;          // [23] 0x182ACC808
    bool Detonate() override;                                          // [38] 0x180838AE0
    bool CanDetonate() override;                                       // [39] 0x180838AE0
    bool HandleCollision(const EventPhysCollision& collision) override; // [47] 0x182ACC6B8

    void OnHit(const HitInfo& hit) override;                           // hit [1] nullsub_1
    void OnExplosion(const ExplosionInfo& explosion) override;        // hit [2] nullsub_1
    void OnServerExplosion(const ExplosionInfo& explosion) override;  // hit [3] nullsub_1

    bool SetAspectProfile(EEntityAspects aspect,
                          std::uint8_t profile) override;              // profile [1] 0x182ACDB74

    bool m_collisionProcessed;      // +0x160
    bool m_waterBounceFinished;     // +0x161
    std::uint8_t _pad162[6];        // +0x162
};
static_assert(sizeof(C_Decoy) == 0x168, "C_Decoy must be 0x168");
static_assert(offsetof(C_Decoy, m_collisionProcessed) == 0x160,
              "decoy collision state must be at 0x160");
static_assert(offsetof(C_Decoy, m_waterBounceFinished) == 0x161,
              "decoy water-bounce state must be at 0x161");

}  // namespace wh::entitymodule
