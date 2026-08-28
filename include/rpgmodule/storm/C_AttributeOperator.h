#pragma once
#include <cstddef>
#include <cstdint>
#include <boost/optional.hpp>
#include "../../rttr/rttr_enable.h"
#include "../E_SoulProperty.h"
#include "I_Operator.h"
#include "operation/Modify.h"
#include "operation/Remove.h"
#include "operation/Set.h"

namespace wh::rpgmodule::storm {

template <typename TOp>
class C_AttributeOperator : public I_Operator {
public:
    ~C_AttributeOperator() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    wh::rpgmodule::E_SoulProperty::Type m_stat;           // +0x08 RTTR "stat"/"skill"
    boost::optional<float> m_mod;                         // +0x0C RTTR "mod"/"value"
    boost::optional<float> m_minMod;                      // +0x14 RTTR "minMod"/"minValue"
    boost::optional<float> m_maxMod;                      // +0x1C RTTR "maxMod"/"maxValue"
    boost::optional<wh::rpgmodule::E_SoulProperty::Type> m_scaleWith; // +0x24 RTTR "scaleWith"
};

static_assert(offsetof(C_AttributeOperator<operation::Modify>, m_stat) == 0x08,
              "C_AttributeOperator::m_stat offset mismatch");
static_assert(offsetof(C_AttributeOperator<operation::Modify>, m_mod) == 0x0C,
              "C_AttributeOperator::m_mod offset mismatch");
static_assert(offsetof(C_AttributeOperator<operation::Modify>, m_scaleWith) == 0x24,
              "C_AttributeOperator::m_scaleWith offset mismatch");
static_assert(sizeof(C_AttributeOperator<operation::Modify>) == 0x30,
              "C_AttributeOperator<Modify> size mismatch");
static_assert(sizeof(C_AttributeOperator<operation::Set>) == 0x30,
              "C_AttributeOperator<Set> size mismatch");
static_assert(sizeof(C_AttributeOperator<operation::Remove>) == 0x30,
              "C_AttributeOperator<Remove> size mismatch");

}  // namespace wh::rpgmodule::storm
