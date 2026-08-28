#pragma once
#include <cstddef>
#include <vector>
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "C_FactionRelationBase.h"

namespace wh::rpgmodule {

class I_Soul;

class C_AddFactionRelationWithinArray : public C_FactionRelationBase {
public:
    C_AddFactionRelationWithinArray();
    ~C_AddFactionRelationWithinArray() override;                // [0]
    RTTR_ENABLE(C_FactionRelationBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27]
    void OnEffectActivate() override;                           // [43]

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_Soul*>> m_soulArray;                     // +0x100
};

static_assert(sizeof(C_AddFactionRelationWithinArray) == 0x140,
              "C_AddFactionRelationWithinArray size mismatch");
static_assert(offsetof(C_AddFactionRelationWithinArray, m_soulArray) == 0x100,
              "C_AddFactionRelationWithinArray soul array offset mismatch");

} // namespace wh::rpgmodule
