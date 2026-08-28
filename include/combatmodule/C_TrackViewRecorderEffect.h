#pragma once
#include <cstddef>
#include <utility>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"

namespace wh::xgenaimodule { class C_SmartObject; }

namespace wh::combatmodule {

class C_TrackViewRecorderEffect : public wh::conceptmodule::C_Effect {
public:
    ~C_TrackViewRecorderEffect() override;                      // [0] 0x1815C7A98
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                    // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                      // [27] 0x18277DABC
    void OnEffectActivate() override;                           // [43] nullsub
    void OnEffectDeactivate() override;                         // [44] nullsub

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::xgenaimodule::C_SmartObject*>> m_smartObjects; // +0x88 RTTR "SmartObjects"
    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_sequenceName; // +0xC8 RTTR "SequenceName"
    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_linkFilter;   // +0x108 RTTR "LinkFilter"
    std::vector<std::pair<CryStringT<char>, CryStringT<char>>*>
        m_recordings;                                          // +0x148 owned {object, sequence} records
};

static_assert(offsetof(C_TrackViewRecorderEffect, m_smartObjects) == 0x88,
              "C_TrackViewRecorderEffect::m_smartObjects offset mismatch");
static_assert(offsetof(C_TrackViewRecorderEffect, m_sequenceName) == 0xC8,
              "C_TrackViewRecorderEffect::m_sequenceName offset mismatch");
static_assert(offsetof(C_TrackViewRecorderEffect, m_linkFilter) == 0x108,
              "C_TrackViewRecorderEffect::m_linkFilter offset mismatch");
static_assert(offsetof(C_TrackViewRecorderEffect, m_recordings) == 0x148,
              "C_TrackViewRecorderEffect::m_recordings offset mismatch");
static_assert(sizeof(C_TrackViewRecorderEffect) == 0x160,
              "C_TrackViewRecorderEffect size mismatch");

}  // namespace wh::combatmodule
