#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "C_UIFlashDynTextureHelper.h"

namespace wh::guimodule {

class C_UIForgeBuilder;

class C_UIForgeBuilderPlan : public C_UIFlashBase {
public:
    C_UIForgeBuilderPlan(C_UIForgeBuilder* owner, std::uint8_t index); // 0x181F77530
    ~C_UIForgeBuilderPlan() override;                                  // [0] 0x181F781C0

    C_UIFlashDynTextureHelper m_textureHelper;                         // +0x58
    C_UIForgeBuilder* m_owner;                                         // +0x80
    std::uint8_t m_index;                                              // +0x88
    bool m_unknown89;                                                  // +0x89
    std::uint8_t m_padding8A[6];
};

static_assert(offsetof(C_UIForgeBuilderPlan, m_textureHelper) == 0x58,
              "C_UIForgeBuilderPlan::m_textureHelper offset mismatch");
static_assert(sizeof(C_UIForgeBuilderPlan) == 0x90,
              "C_UIForgeBuilderPlan size mismatch");

}  // namespace wh::guimodule
