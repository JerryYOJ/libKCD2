#pragma once
#include <cstddef>
#include "../conceptmodule/C_TypedPortRef.h"
#include "C_FactionRelationBase.h"

namespace wh::rpgmodule {

class C_AddFactionRelation : public C_FactionRelationBase {
public:
    C_AddFactionRelation();
    ~C_AddFactionRelation() override;                           // [0]
    RTTR_ENABLE(C_FactionRelationBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                            // [27]
    void OnEffectActivate() override;                          // [43]

    wh::conceptmodule::C_TypedPortRef<C_FactionBase*> m_faction; // +0x100
    wh::conceptmodule::C_TypedPortRef<
        C_FactionBase*> m_relationTarget;                      // +0x140
};

static_assert(sizeof(C_AddFactionRelation) == 0x180,
              "C_AddFactionRelation size mismatch");
static_assert(offsetof(C_AddFactionRelation, m_faction) == 0x100,
              "C_AddFactionRelation faction offset mismatch");
static_assert(offsetof(C_AddFactionRelation, m_relationTarget) == 0x140,
              "C_AddFactionRelation target offset mismatch");

} // namespace wh::rpgmodule
