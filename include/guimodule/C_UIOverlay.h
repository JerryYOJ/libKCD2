#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "framework/I_SourceMonitorListener.h"

namespace wh::guimodule {

class C_UIOverlay : public C_UIFlashBase,
                    public wh::framework::I_SourceMonitorListener {
public:
    C_UIOverlay();                                    // 0x181863CFC
    ~C_UIOverlay() override;                          // primary [0] 0x182BB87AC
    void Init(C_GUIModule* module) override;          // [1] 0x180C3BB78
    void Deinit() override;                           // [2] 0x182BB9220
    void OnModuleMessage(void* message) override;     // [3] 0x18085DCDC
    void Update() override;                           // [4] 0x181138848
    RTTR_ENABLE(C_UIBase)                             // [7..9]
    const char* GetElementName() const override;      // [11] 0x181A719A0

    virtual void AddOverlay(
        std::uint8_t index, std::int32_t overlayId);   // [14] 0x180EC9F04
    virtual void RemoveOverlay(std::uint8_t index);   // [15] 0x180C60364
    virtual void RemoveAllOverlays();                 // [16] 0x1819DA4E0
    virtual void SetAlpha(
        std::uint8_t index, std::int32_t alpha);       // [17] 0x180EC9CDC
    virtual void ShowCinematicOverlay(bool enabled);  // [18] 0x181F95940
    virtual void HideCinematicOverlay();              // [19] 0x181F95660
    virtual void HideOverlays(
        std::uint8_t group, bool animated);            // [20] 0x1808BCF3C
    virtual void ShowOverlays(
        std::uint8_t group, bool animated);            // [21] 0x1808BCFF8

    void OnSourceEvent(void* source, bool active) override; // secondary [0] 0x1819A9FA4

    float m_vignetteIntensity;                        // +0x60 CVar wh_ui_photomodeVignetteIntensity
    float m_vignetteRadius;                           // +0x64 CVar wh_ui_photomodeVignetteRadius
    std::int32_t m_logoType;                          // +0x68 CVar wh_ui_photomodeLogoType
    std::int32_t m_logoPosition;                      // +0x6C CVar wh_ui_photomodeLogoPosition
    std::int32_t m_logoSize;                          // +0x70 CVar wh_ui_photomodeLogoSize
    std::int32_t m_frameAspect;                       // +0x74 CVar wh_ui_photomodeScreenShotFrameAspect
    std::int32_t m_grid;                              // +0x78 CVar wh_ui_photomodeGrid
    std::int32_t m_smallLogoPixels;                   // +0x7C
    std::int32_t m_mediumLogoPixels;                  // +0x80
    std::int32_t m_largeLogoPixels;                   // +0x84
    std::int32_t m_overlayIds[12];                    // +0x88
    bool m_hiddenGroups[4];                           // +0xB8
    std::uint8_t m_unknownBC[0x18];
    float m_unknownD4;                                // +0xD4, ctor 1.0
    float m_unknownD8;                                // +0xD8, ctor 1.0
    float m_unknownDC;                                // +0xDC, ctor 1.0
    std::uint8_t m_unknownE0[0x18];
};

static_assert(offsetof(C_UIOverlay, m_vignetteIntensity) == 0x60,
              "C_UIOverlay::m_vignetteIntensity offset mismatch");
static_assert(offsetof(C_UIOverlay, m_overlayIds) == 0x88,
              "C_UIOverlay::m_overlayIds offset mismatch");
static_assert(offsetof(C_UIOverlay, m_hiddenGroups) == 0xB8,
              "C_UIOverlay::m_hiddenGroups offset mismatch");
static_assert(sizeof(C_UIOverlay) == 0xF8,
              "C_UIOverlay size mismatch");

}  // namespace wh::guimodule
