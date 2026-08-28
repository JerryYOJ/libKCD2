#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "framework/I_SourceMonitorListener.h"

namespace wh::guimodule {

class C_UIHorseInspect : public C_UIFlashBase,
                         public wh::framework::I_SourceMonitorListener {
public:
    C_UIHorseInspect();                               // construction path 0x18188E6EC
    ~C_UIHorseInspect() override;                     // primary [0] 0x182BB8744
    void Init(C_GUIModule* module) override;          // [1] 0x180ED155C
    void Deinit() override;                           // [2] 0x182BB905C
    void OnModuleMessage(void* message) override;     // [3] 0x18085DCCC
    RTTR_ENABLE(C_UIBase)                             // [7..9]
    const char* GetElementName() const override;      // [11] 0x181A719E0
    virtual bool Show(std::uint32_t horseId);         // [14] 0x182BBB21C
    virtual void Hide();                              // [15] 0x1815FF200
    void OnSourceEvent(void* source, bool active) override; // secondary [0] 0x182BB9D30
};

static_assert(sizeof(C_UIHorseInspect) == 0x60,
              "C_UIHorseInspect size mismatch");

}  // namespace wh::guimodule
