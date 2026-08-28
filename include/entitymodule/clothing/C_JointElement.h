#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>

#include "../../CryEngine/CryCommon/Cry_Math.h"
#include "../../CryEngine/CryCommon/SimulationParams.h"
#include "../../framework/TinyOptional.h"
#include "C_JointElementBase.h"

namespace wh::entitymodule::clothing {

class C_JointElement : public C_JointElementBase {
public:
    ~C_JointElement() override;                                         // [0] 0x18295C494
    std::uint32_t GetElementType() const override;                       // [1] 0x18066CD10
    void unk_03(void* target) const override;                            // [3] 0x1809731A4
    bool unk_04() const override;                                       // [4] 0x1809753F4
    CryStringT<char> unk_05() const override;                            // [5] 0x18295E4A8
    void unk_21(const C_ElementBase* source) override;                   // [21] 0x18074D224
    bool unk_22(const C_ElementBase* other) const override;              // [22] 0x18119BBE8
    bool unk_23(const C_ElementBase* other) const override;              // [23] 0x180FF3FD0
    RTTR_ENABLE(C_JointElementBase)                                      // [25..27], vtable 0x183B090D0

    std::optional<Vec3> m_position;                                     // +0x28 RTTR "Position"
    std::optional<Quat> m_rotation;                                     // +0x38 RTTR "Rotation"
    tiny::optional<bool> m_usesRelativePosition;                        // +0x4C RTTR "UsesRelativePosition"
    tiny::optional<bool> m_usesRelativeRotation;                        // +0x4D RTTR "UsesRelativeRotation"
    std::uint8_t m_padding4E[2];                                        // +0x4E
    std::shared_ptr<SimulationParams> m_simulationParams;                // +0x50 RTTR "SimulationParams"
};

static_assert(offsetof(C_JointElement, m_position) == 0x28,
              "C_JointElement::m_position offset mismatch");
static_assert(offsetof(C_JointElement, m_rotation) == 0x38,
              "C_JointElement::m_rotation offset mismatch");
static_assert(offsetof(C_JointElement, m_usesRelativePosition) == 0x4C,
              "C_JointElement::m_usesRelativePosition offset mismatch");
static_assert(offsetof(C_JointElement, m_simulationParams) == 0x50,
              "C_JointElement::m_simulationParams offset mismatch");
static_assert(sizeof(C_JointElement) == 0x60,
              "C_JointElement size mismatch");

} // namespace wh::entitymodule::clothing
