#pragma once
#include <cstddef>
#include <cstdint>

#include "C_RandomEventBase.h"
#include "E_GenericRandomEventType.h"

namespace wh::playermodule {

class C_GenericRandomEvent : public C_RandomEventBase {
public:
    C_GenericRandomEvent();
    ~C_GenericRandomEvent() override;                       // [0] 0x181533184
    RTTR_ENABLE(C_RandomEventBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                         // [27] 0x182EAD728
    std::uint8_t GetModuleKind() const override;            // [44] false

    void Start(S_RandomEventEncounter const& encounter) override; // [57] 0x182EAF160
    std::uint32_t GetSpawnEntityId() const override;       // [62] 0x181A9AD20
    void unk63() override;                                  // [63] 0x182EA9D84
    void StartInternal(
        S_RandomEventEncounter const& encounter) override;  // [65] 0x182EB0EE8
    void unk66() override;                                  // [66] 0x182EA9C5C
    Vec3 GetSpawnPosition() const override;                 // [67] 0x182EAB5D0
    Quat GetSpawnRotation() const override;                 // [68] 0x182EAB65C

    E_GenericRandomEventType::Type m_genericEventType;     // +0x1F0 RTTR "GenericEventType"
    std::uint8_t m_padding1F1[7];
};

static_assert(sizeof(C_GenericRandomEvent) == 0x1F8,
              "C_GenericRandomEvent size mismatch");
static_assert(offsetof(C_GenericRandomEvent, m_genericEventType) == 0x1F0,
              "C_GenericRandomEvent type offset mismatch");

} // namespace wh::playermodule
