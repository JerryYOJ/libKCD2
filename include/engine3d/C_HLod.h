#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "../E_HLodType.h"
#include "C_HLodStreaming.h"
#include "E_HLodState.h"

namespace wh::engine3d {

class C_HLod : public C_HLodStreaming {
public:
    const CryStringT<char>& GetPath() const override;         // [0] 0x181A7CCA0
    void SetPath(const CryStringT<char>& path) override;      // [1] 0x1813F3E88
    E_HLodType::Type GetType() const override;                // [2] 0x181A7D920
    void SetType(E_HLodType::Type type) override;             // [3] 0x1813F3EA0
    void SetPosition(const Vec3& position) override;          // [4] 0x181AAD680
    float GetRadius() const override;                         // [5] 0x181AAD500
    void SetRadius(float radius) override;                    // [6] 0x181AAD6A0
    std::uint16_t GetLayerId() override;                      // [7] 0x181AAD4C0
    void SetLayerId(std::uint16_t layerId) override;          // [8] 0x181AAD640
    std::shared_ptr<wh::I_HLod> unk_15() override;            // [15] 0x1834C0F58
    void* unk_16() const override;                            // [16] 0x181AAD290
    void unk_17() override;                                  // [17] 0x1834C5304
    void SetSelectedForDebug(bool selected) override;         // [18] 0x18043D674
    float GetSwitchingDistance() const override;              // [19] 0x18043F8D4
    bool unk_20() const override;                             // [20] 0x18041A6A0
    RTTR_ENABLE(C_HLodStreaming)                              // [21..23]
    std::uintptr_t unk_24(
        std::uint32_t** cursor,
        int* remaining,
        int* offset,
        std::uintptr_t a5,
        std::uintptr_t a6,
        std::uintptr_t a7,
        bool flag) override;                                 // [24] 0x1834C1A80
    void unk_25(void* a2, void* a3, void* a4) override;      // [25] 0x1834C1670
    void unk_26(void* output) override;                       // [26] 0x1834C4E14
    float GetNearestObserverDistance() const override;        // [27] 0x181AAD460
    virtual void unk_28();                                   // [28] 0x1820D68F0

    CryStringT<char> m_path;                                 // +0x88 virtual get/set
    E_HLodType::Type m_type;                                 // +0x90 virtual get/set
    E_HLodState::Type m_state;                               // +0x91 state machine readers
    std::uint8_t m_unknown92[2];                             // +0x92 unreflected
    Vec3 m_position;                                         // +0x94 RTTR "Pos"
    float m_radius;                                          // +0xA0 RTTR "Radius"
    std::uint16_t m_layerId;                                 // +0xA4 virtual get/set
    std::uint8_t m_unknownA6[2];                             // +0xA6 unreflected
    int m_unknownA8;                                         // +0xA8 unreflected
    std::uint8_t m_unknownAC;                                // +0xAC unreflected
    bool m_selectedForDebug;                                 // +0xAD virtual setter
    std::uint8_t m_unknownAE[2];                             // +0xAE unreflected
    std::vector<std::shared_ptr<C_HLod>> m_children;         // +0xB0 RTTR "Children"
    void* m_unknownC8;                                       // +0xC8 unreflected
    std::uint8_t m_unknownD0[4];                             // +0xD0 unreflected
    float m_nearestObserverDistance;                         // +0xD4 RTTR "NearestObserverDistance"
};

static_assert(offsetof(C_HLod, m_path) == 0x88,
              "C_HLod::m_path offset mismatch");
static_assert(offsetof(C_HLod, m_type) == 0x90,
              "C_HLod::m_type offset mismatch");
static_assert(offsetof(C_HLod, m_position) == 0x94,
              "C_HLod::m_position offset mismatch");
static_assert(offsetof(C_HLod, m_layerId) == 0xA4,
              "C_HLod::m_layerId offset mismatch");
static_assert(offsetof(C_HLod, m_children) == 0xB0,
              "C_HLod::m_children offset mismatch");
static_assert(offsetof(C_HLod, m_nearestObserverDistance) == 0xD4,
              "C_HLod::m_nearestObserverDistance offset mismatch");
static_assert(sizeof(C_HLod) == 0xD8, "C_HLod size mismatch");

}  // namespace wh::engine3d
