#pragma once
#include <cstddef>
#include <cstdint>
#include "E_SubBrainType.h"
#include "S_DatabaseIDTemplate.h"

namespace wh::xgenaimodule {

class S_SubBrainTemplate : public S_DatabaseIDTemplate {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_SubBrainTemplate;

    ~S_SubBrainTemplate() override;  // [0] 0x183208918
    RTTR_ENABLE(S_DatabaseIDTemplate)
    virtual S_SubBrainTemplate* Clone() = 0;                  // [4] pure
    virtual E_SubBrainType::Type GetSubbrainType() = 0;       // [5] pure
    virtual bool IsSubbrainType(E_SubBrainType::Type type);    // [6] 0x180418A4C
    virtual bool _vf7();                                      // [7] 0x180838AE0

    CryStringT<char> m_name;      // +0x18, authored subbrain name
    CryStringT<char> m_typeName;  // +0x20, concrete runtime factory selector
    std::int32_t m_timeout;       // +0x28, negative authored values clamp to zero
    bool m_alwaysActive;          // +0x2C
    std::uint8_t _pad2D[3];       // +0x2D
};
static_assert(sizeof(S_SubBrainTemplate) == 0x30,
              "S_SubBrainTemplate must be 0x30");
static_assert(offsetof(S_SubBrainTemplate, m_name) == 0x18,
              "subbrain name must be at 0x18");
static_assert(offsetof(S_SubBrainTemplate, m_typeName) == 0x20,
              "subbrain factory type must be at 0x20");
static_assert(offsetof(S_SubBrainTemplate, m_timeout) == 0x28,
              "subbrain timeout must be at 0x28");
static_assert(offsetof(S_SubBrainTemplate, m_alwaysActive) == 0x2C,
              "always-active flag must be at 0x2C");

}  // namespace wh::xgenaimodule
