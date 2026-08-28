#pragma once
#include <cstddef>
#include <cstdint>
#include "../framework/C_LocalizedString.h"
#include "S_Tutorial.h"

namespace wh::playermodule {

class S_OverlayTutorial : public S_Tutorial {
public:
    ~S_OverlayTutorial() override;
    RTTR_ENABLE(S_Tutorial)
    wh::framework::C_LocalizedString m_uiName;            // +0x28 RTTR "UiName"
    std::int32_t m_uiOrder;                               // +0x38 RTTR "UiOrder"
    std::uint8_t _pad3C[4];                               // +0x3C
    CryStringT<char> m_uiScreenName;                      // +0x40 RTTR "UiScreenName"
    bool m_visibleInMenu;                                 // +0x48 RTTR "VisibleInMenu"
    bool m_isSystemOverlay;                               // +0x49 RTTR "IsSystemOverlay"
    std::uint8_t _pad4A[6];                               // +0x4A
};

static_assert(offsetof(S_OverlayTutorial, m_uiName) == 0x28,
              "S_OverlayTutorial::m_uiName offset mismatch");
static_assert(offsetof(S_OverlayTutorial, m_uiScreenName) == 0x40,
              "S_OverlayTutorial::m_uiScreenName offset mismatch");
static_assert(sizeof(S_OverlayTutorial) == 0x50,
              "S_OverlayTutorial size mismatch");

}  // namespace wh::playermodule
