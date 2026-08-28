#pragma once
#include <cstddef>
#include "../conceptmodule/C_Node.h"
#include "C_SaveGameBase.h"

namespace wh::playermodule {

class C_SaveGame
    : public wh::conceptmodule::C_Node,
      public C_SaveGameBase {
public:
    C_SaveGame();
    ~C_SaveGame() override;                                    // [0] 0x1813CDEA8
    RTTR_ENABLE(wh::conceptmodule::C_Node) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE0764
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // [33] 0x182DDF058
};

static_assert(sizeof(C_SaveGame) == 0x140,
              "C_SaveGame size mismatch");

} // namespace wh::playermodule
