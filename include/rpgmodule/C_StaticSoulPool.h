#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "C_SoulPoolBase.h"

namespace wh::rpgmodule {

class C_StaticSoulPool : public C_SoulPoolBase {
public:
    struct S_Element {
        CryStringT<char> m_soulName;                      // +0x00 RTTR "SoulName"
    };
    static_assert(sizeof(S_Element) == 0x08,
                  "C_StaticSoulPool::S_Element size mismatch");

    ~C_StaticSoulPool() override;
    void unk_01() override;
    void unk_02() override;
    RTTR_ENABLE(C_SoulPoolBase)
    std::vector<S_Element> m_elements;                    // +0x18 RTTR "Elements"
};

static_assert(offsetof(C_StaticSoulPool, m_elements) == 0x18,
              "C_StaticSoulPool::m_elements offset mismatch");
static_assert(sizeof(C_StaticSoulPool) == 0x30,
              "C_StaticSoulPool size mismatch");

}  // namespace wh::rpgmodule
