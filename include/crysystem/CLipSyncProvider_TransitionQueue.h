#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "CryCharAnimationParams.h"
#include "../Offsets/vtables/ILipSyncProvider.h"

typedef unsigned int EntityId;

class CLipSyncProvider_TransitionQueue : public Offsets::ILipSyncProvider {
public:
    explicit CLipSyncProvider_TransitionQueue(EntityId entityId);
    ~CLipSyncProvider_TransitionQueue() override; // [0]

    void _vf1(Offsets::LipSyncProviderContextArg context,
              std::uint32_t value,
              bool condition) override; // [1]
    void _vf2(Offsets::LipSyncProviderContextArg context,
              std::uint32_t soundId,
              bool active) override; // [2]
    void _vf3(Offsets::LipSyncProviderContextArg context,
              std::uint32_t value,
              bool condition) override; // [3]
    void _vf4(Offsets::LipSyncProviderContextArg context,
              std::uint32_t value,
              bool condition) override; // [4]
    void _vf5(Offsets::LipSyncProviderContextArg context,
              std::uint32_t value,
              bool condition) override; // [5]
    void _vf6(Offsets::LipSyncProviderContextArg context,
              std::uint32_t value,
              bool condition) override; // [6]

    EntityId m_entityId;                       // +0x08
    std::int32_t m_nCharacterSlot;             // +0x0C
    std::int32_t m_nAnimLayer;                 // +0x10
    std::byte _pad14[4];                       // +0x14
    CryStringT<char> m_sDefaultAnimName;       // +0x18
    std::int32_t m_state;                      // +0x20, enum identity OPEN
    bool m_isSynchronized;                     // +0x24
    std::byte _pad25[3];                       // +0x25
    std::int32_t m_requestedAnimId;            // +0x28
    CryCharAnimationParams m_animationParams;  // +0x2C
    std::byte _pad6C[4];                       // +0x6C
    std::uint64_t m_filePathCRC;               // +0x70, owning CAF-retention payload
    std::uint32_t m_nCurrentAnimationToken;    // +0x78
    std::uint32_t m_soundId;                   // +0x7C
};
static_assert(sizeof(CLipSyncProvider_TransitionQueue) == 0x80,
              "CLipSyncProvider_TransitionQueue must be 0x80");
static_assert(offsetof(CLipSyncProvider_TransitionQueue, m_sDefaultAnimName) == 0x18,
              "transition provider default animation must be at 0x18");
static_assert(offsetof(CLipSyncProvider_TransitionQueue, m_animationParams) == 0x2C,
              "transition provider animation params must be at 0x2C");
static_assert(offsetof(CLipSyncProvider_TransitionQueue, m_filePathCRC) == 0x70,
              "transition provider CAF payload must be at 0x70");
static_assert(offsetof(CLipSyncProvider_TransitionQueue, m_soundId) == 0x7C,
              "transition provider sound ID must be at 0x7C");
