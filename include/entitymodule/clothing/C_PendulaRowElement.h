#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

#include "../../CryEngine/CryCommon/RowSimulationParams.h"
#include "C_JointElementBase.h"

namespace wh::entitymodule::clothing {

class C_PendulaRowElement : public C_JointElementBase {
public:
    ~C_PendulaRowElement() override;                                    // [0] 0x18295C4FC
    std::uint32_t GetElementType() const override;                       // [1] 0x181A72500
    void ApplyToAttachment(IAttachment* target) const override; // [3] 0x18295E710
    bool IsComplete() const override; // [4] 0x18295E7A4
    CryStringT<char> GetMissingAttributes() const override; // [5] 0x18295E534
    void MergeFrom(const C_ElementBase* source) override; // [21] 0x18295EA18
    bool IsEquivalentTo(const C_ElementBase* other) const override; // [22] 0x18295D014
    bool CanMergeWith(const C_ElementBase* other) const override; // [23] 0x18295CF68
    RTTR_ENABLE(C_JointElementBase)                                      // [25..27], vtable 0x184711AB0

    std::shared_ptr<RowSimulationParams> m_rowSimulationParams;          // +0x28 RTTR "RowSimulationParams"
};

static_assert(offsetof(C_PendulaRowElement, m_rowSimulationParams) == 0x28,
              "C_PendulaRowElement::m_rowSimulationParams offset mismatch");
static_assert(sizeof(C_PendulaRowElement) == 0x38,
              "C_PendulaRowElement size mismatch");

} // namespace wh::entitymodule::clothing
