#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "CryEngine/CryCommon/CryString.h"
#include "Offsets/vtables/IActionListener.h"

namespace wh::guimodule {

class C_UIHelpOverlay : public C_UIFlashBase,
                        public Offsets::IActionListener {
public:
    C_UIHelpOverlay();                                // 0x180C09BB4
    ~C_UIHelpOverlay() override;                      // primary [0] 0x182BA5A48
    void Init(C_GUIModule* module) override;          // [1] 0x180612B64
    void Deinit() override;                           // [2] 0x182BA6F40
    void OnModuleMessage(void* message) override;     // [3] 0x18085DD10
    void Update() override;                           // [4] 0x180C078E0
    RTTR_ENABLE(C_UIBase)                             // [7..9]
    const char* GetElementName() const override;      // [11] 0x181A8F230
    void OnAction(
        Offsets::SActionId const& action,
        int activationMode, float value) override;    // secondary [1] 0x1818102E0

    std::uint8_t m_runtimeEntries[0x28];              // +0x60, custom hash container
    CryStringT<char> m_helpName;                      // +0x88
    CryStringT<char> m_inputName;                     // +0x90
    void* m_unknown98;                                // +0x98
    std::int32_t m_unknownA0;                         // +0xA0, ctor -1
    float m_unknownA4;                                // +0xA4, ctor -1.0
};

static_assert(offsetof(C_UIHelpOverlay, m_runtimeEntries) == 0x60,
              "C_UIHelpOverlay::m_runtimeEntries offset mismatch");
static_assert(offsetof(C_UIHelpOverlay, m_helpName) == 0x88,
              "C_UIHelpOverlay::m_helpName offset mismatch");
static_assert(sizeof(C_UIHelpOverlay) == 0xA8,
              "C_UIHelpOverlay size mismatch");

}  // namespace wh::guimodule
