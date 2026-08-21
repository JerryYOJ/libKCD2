#pragma once
#include <cstddef>
#include "../../crysystem/SViewParams.h"

namespace Offsets {

class IGameObjectView {
public:
    virtual ~IGameObjectView() = default;                  // [0] 0x182139D48 this-0x40 on C_Player
    virtual void UpdateView(SViewParams& params) = 0;      // [1] 0x1807F22FC C_Player
    virtual void PostUpdateView(SViewParams& params) = 0;  // [2] 0x1803B6E80 nullsub
};
static_assert(sizeof(IGameObjectView) == 0x08,
              "IGameObjectView must be 0x08");

}  // namespace Offsets
