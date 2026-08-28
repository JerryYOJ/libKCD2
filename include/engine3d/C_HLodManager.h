#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "C_HLod.h"
#include "C_HLodManagerStreaming.h"
#include "S_HLodStats.h"

namespace wh::engine3d {

class C_HLodManager : public C_HLodManagerStreaming {
public:
    bool IsEnabled() const override;                         // [0] 0x18043FABC
    bool IsEnabledForLevel() const override;                 // [1] 0x181AAD570
    void SetLevelHash(std::uint32_t levelHash) override;     // [2] 0x181AAD650
    std::shared_ptr<C_HLod> GetHLodTree() const override;    // [3] 0x1834C2DCC
    void unk_07(void* context) override;                     // [7] 0x1834C5708
    void unk_08(void* context) override;                     // [8] 0x18043CAE4
    void UpdateStreaming(bool force) override;               // [9] 0x18043F614
    RTTR_ENABLE(C_HLodManagerStreaming)                      // [10..12]
    void Clear() override;                                   // [14] 0x1813F3AC8
    std::shared_ptr<C_HLod>& GetHLodTreeRef() override;      // [15] 0x181AAD510

    int m_systemEnabled;                                     // +0x1C8 RTTR "SystemEnabled"
    std::uint8_t m_unknown1CC[4];                           // +0x1CC unreflected
    bool m_enabledForLevel;                                  // +0x1D0 accessor backing
    std::uint8_t m_unknown1D1[3];                           // +0x1D1 unreflected
    std::uint32_t m_levelHash;                               // +0x1D4 RTTR "LevelHash"
    std::shared_ptr<C_HLod> m_hLodTree;                      // +0x1D8 RTTR "HLodTree"
    std::uint8_t m_unknown1E8[0x200 - 0x1E8];               // +0x1E8 unreflected
    S_HLodStats m_stats;                                     // +0x200 RTTR "Stats"
    std::uint8_t m_unknown380[0x3A0 - 0x380];               // +0x380 unreflected
};

static_assert(offsetof(C_HLodManager, m_systemEnabled) == 0x1C8,
              "C_HLodManager::m_systemEnabled offset mismatch");
static_assert(offsetof(C_HLodManager, m_enabledForLevel) == 0x1D0,
              "C_HLodManager::m_enabledForLevel offset mismatch");
static_assert(offsetof(C_HLodManager, m_levelHash) == 0x1D4,
              "C_HLodManager::m_levelHash offset mismatch");
static_assert(offsetof(C_HLodManager, m_hLodTree) == 0x1D8,
              "C_HLodManager::m_hLodTree offset mismatch");
static_assert(offsetof(C_HLodManager, m_stats) == 0x200,
              "C_HLodManager::m_stats offset mismatch");
static_assert(sizeof(C_HLodManager) == 0x3A0,
              "C_HLodManager size mismatch");

}  // namespace wh::engine3d
