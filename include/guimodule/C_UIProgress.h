#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "I_LoadingProgressListener.h"

namespace wh::guimodule {

class C_UIProgress : public C_UIFlashBase,
                     public wh::I_LoadingProgressListener {
public:
    C_UIProgress();                                  // construction path 0x18188E414
    ~C_UIProgress() override;                        // primary [0] 0x182BB884C
    void Init(C_GUIModule* module) override;         // [1] 0x180C3D024
    void Deinit() override;                          // [2] 0x182BB9394
    RTTR_ENABLE(C_UIBase)                            // [7..9]
    const char* GetElementName() const override;     // [11] 0x181A71980
    void SetDebug(std::int32_t value) override;      // secondary [1] 0x182BBA138

    std::int32_t m_debugValue;                       // +0x60, ctor 0
    std::uint8_t m_unknown64[4];
};

static_assert(offsetof(C_UIProgress, m_debugValue) == 0x60,
              "C_UIProgress::m_debugValue offset mismatch");
static_assert(sizeof(C_UIProgress) == 0x68,
              "C_UIProgress size mismatch");

}  // namespace wh::guimodule
