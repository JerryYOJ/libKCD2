#pragma once
#include <cstddef>
#include <memory>
#include <vector>
#include "../rttr/rttr_enable.h"
#include "definition/C_TypeDefinition.h"
#include "definition/I_NodeDefinition.h"

namespace wh::conceptmodule {

class C_ConceptDefinitionsSerializationRoot {
public:
    RTTR_ENABLE()                                             // [0..2]

    std::vector<std::shared_ptr<definition::I_NodeDefinition>>
        GetNodes() const;                                     // 0x182735440
    void SetNodes(std::vector<std::shared_ptr<
        definition::I_NodeDefinition>> value);                // 0x18262771C, consumes value only

    std::vector<std::shared_ptr<definition::C_TypeDefinition>>
        GetTypes() const;                                     // 0x182735640
    void SetTypes(std::vector<std::shared_ptr<
        definition::C_TypeDefinition>> value);                // 0x18262771C, consumes value only
};

static_assert(sizeof(C_ConceptDefinitionsSerializationRoot) == 0x08,
              "C_ConceptDefinitionsSerializationRoot size mismatch");

}  // namespace wh::conceptmodule
