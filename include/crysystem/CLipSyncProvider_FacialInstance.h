#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/ILipSyncProvider.h"

typedef unsigned int EntityId;

class CLipSyncProvider_FacialInstance : public Offsets::ILipSyncProvider {
public:
    explicit CLipSyncProvider_FacialInstance(EntityId entityId);
    ~CLipSyncProvider_FacialInstance() override; // [0]

    void _vf1(Offsets::LipSyncProviderContextArg context,
              std::uint32_t value,
              bool condition) override; // [1]
    void _vf2(Offsets::LipSyncProviderContextArg context,
              std::uint32_t soundId,
              bool active) override; // [2]
    void _vf3(Offsets::LipSyncProviderContextArg context,
              std::uint32_t soundId,
              bool active) override; // [3]
    void _vf4(Offsets::LipSyncProviderContextArg context,
              std::uint32_t soundId,
              bool active) override; // [4]
    void _vf5(Offsets::LipSyncProviderContextArg context,
              std::uint32_t soundId,
              bool active) override; // [5]
    void _vf6(Offsets::LipSyncProviderContextArg context,
              std::uint32_t value,
              bool condition) override; // [6]

    EntityId m_entityId;  // +0x08
    std::uint32_t _pad0C; // +0x0C
};
static_assert(sizeof(CLipSyncProvider_FacialInstance) == 0x10,
              "CLipSyncProvider_FacialInstance must be 0x10");
static_assert(offsetof(CLipSyncProvider_FacialInstance, m_entityId) == 0x08,
              "facial provider entity ID must be at 0x08");
