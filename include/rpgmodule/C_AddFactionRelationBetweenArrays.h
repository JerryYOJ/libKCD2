#pragma once
#include <cstddef>
#include <vector>
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "C_FactionRelationBase.h"

namespace wh::rpgmodule {

class I_Soul;

class C_AddFactionRelationBetweenArrays : public C_FactionRelationBase {
public:
    C_AddFactionRelationBetweenArrays();
    ~C_AddFactionRelationBetweenArrays() override;             // [0]
    RTTR_ENABLE(C_FactionRelationBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                            // [27]
    void OnEffectActivate() override;                          // [43]

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_Soul*>> m_soulArray0;                   // +0x100
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_Soul*>> m_soulArray1;                   // +0x140
};

static_assert(sizeof(C_AddFactionRelationBetweenArrays) == 0x180,
              "C_AddFactionRelationBetweenArrays size mismatch");
static_assert(offsetof(C_AddFactionRelationBetweenArrays, m_soulArray0) == 0x100,
              "C_AddFactionRelationBetweenArrays first array offset mismatch");
static_assert(offsetof(C_AddFactionRelationBetweenArrays, m_soulArray1) == 0x140,
              "C_AddFactionRelationBetweenArrays second array offset mismatch");

} // namespace wh::rpgmodule
