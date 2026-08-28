#pragma once
#include <cstddef>
#include <cstdint>
#include "../cry3dengine/Cry3DEngineBase.h"
#include "../wh/I_HLodManager.h"
#include "S_HLodConfig.h"

namespace wh::engine3d {

class C_HLodManagerStreaming : public Cry3DEngineBase,
                               public wh::I_HLodManager {
public:
    std::uint32_t unk_04() override;                         // [4] 0x181A72E50
    std::uint32_t unk_05() override;                         // [5] 0x1834C1A18
    std::uintptr_t unk_06(
        std::uint32_t* data,
        int size,
        std::uintptr_t* a4,
        std::uintptr_t* a5,
        std::uintptr_t* a6) override;                        // [6] 0x1834C1994
    void UpdateStreaming(bool force) override;               // [9] 0x18043FAD4
    RTTR_ENABLE(wh::I_HLodManager)                           // [10..12]
    std::uintptr_t unk_13(
        std::uintptr_t a2,
        std::uintptr_t a3,
        std::uintptr_t a4) override;                         // [13] 0x1834C16E4
    void Clear() override;                                   // [14] 0x1834C3AF8

    S_HLodConfig m_config;                                   // +0x08 RTTR "Config"
    std::uint8_t m_unknown90[0x1C8 - 0x90];                 // +0x90 unreflected
};

static_assert(offsetof(C_HLodManagerStreaming, m_config) == 0x08,
              "C_HLodManagerStreaming::m_config offset mismatch");
static_assert(sizeof(C_HLodManagerStreaming) == 0x1C8,
              "C_HLodManagerStreaming size mismatch");

}  // namespace wh::engine3d
