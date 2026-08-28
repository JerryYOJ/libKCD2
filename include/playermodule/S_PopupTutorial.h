#pragma once
#include <cstddef>
#include <cstdint>
#include "S_Tutorial.h"

namespace wh::playermodule {

class S_PopupTutorial : public S_Tutorial {
public:
    ~S_PopupTutorial() override;
    RTTR_ENABLE(S_Tutorial)
    CryStringT<char> m_text;                              // +0x28 RTTR "Text"
    std::uint32_t m_priority;                             // +0x30 RTTR "Priority"
    bool m_dialogueSync;                                  // +0x34 RTTR "DialogueSync"
    bool m_disableCloseButton;                            // +0x35 RTTR "DisableCloseButton"
    std::uint8_t _pad36[2];                               // +0x36
    std::int32_t m_windowSize;                            // +0x38 RTTR "WindowSize"
    std::uint8_t _pad3C[4];                               // +0x3C
    CryStringT<char> m_durationOverride;                  // +0x40 RTTR "DurationOverride"
    CryStringT<char> m_overlayLink;                       // +0x48 RTTR "OverlayLink"
};

static_assert(offsetof(S_PopupTutorial, m_text) == 0x28,
              "S_PopupTutorial::m_text offset mismatch");
static_assert(offsetof(S_PopupTutorial, m_overlayLink) == 0x48,
              "S_PopupTutorial::m_overlayLink offset mismatch");
static_assert(sizeof(S_PopupTutorial) == 0x50,
              "S_PopupTutorial size mismatch");

}  // namespace wh::playermodule
