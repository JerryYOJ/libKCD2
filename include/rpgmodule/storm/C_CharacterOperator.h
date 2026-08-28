#pragma once
#include <cstddef>
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"
#include "operation/Add.h"
#include "CryEngine/CryCommon/CryString.h"

namespace wh::rpgmodule::storm {

template <typename TOperation>
class C_CharacterOperator : public I_Operator {
public:
    C_CharacterOperator();
    ~C_CharacterOperator() override;                       // [0], Add 0x18178BC04
    void unk_01(C_Soul* soul, C_Rule* rule) override;     // [1], Add 0x182D4DE10
    bool unk_02() override;                                // [2], Add false
    E_TaskClass unk_03() override;                         // [3], Add 0x181A94E10
    void DebugDraw(wh::C_DebugDraw& draw) const override; // [4], Add 0x182D4E268
    RTTR_ENABLE(I_Operator)                                // [5..7]
    virtual CryStringT<char> unk_08(
        C_Soul* soul,
        void const* context);                              // [8], Add 0x182D4E934
    virtual CryStringT<char> unk_09(C_Soul* soul);        // [9], Add 0x182D4ECE4

    CryStringT<char> const& GetPattern() const;            // 0x181A71D30, RTTR "pattern"
    void SetPattern(CryStringT<char> const& pattern);      // 0x182D4F728

    CryStringT<char> m_pattern;                            // +0x08, original pattern
    CryStringT<char> m_wildcardPrefix;                    // +0x10, trailing-'*' form without '*'
    CryStringT<char> m_exactPattern;                      // +0x18, non-wildcard fallback
};

static_assert(offsetof(C_CharacterOperator<operation::Add>, m_pattern) == 0x08,
              "C_CharacterOperator<Add>::m_pattern offset mismatch");
static_assert(sizeof(C_CharacterOperator<operation::Add>) == 0x20,
              "C_CharacterOperator<Add> size mismatch");

}  // namespace wh::rpgmodule::storm
