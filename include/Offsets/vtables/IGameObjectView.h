#pragma once
#include <cstddef>

struct SViewParams;

namespace Offsets {

class IGameObjectView {
public:
    virtual ~IGameObjectView() = default;                  // [0]
    virtual void UpdateView(SViewParams& params) = 0;      // [1]
    virtual void PostUpdateView(SViewParams& params) = 0;  // [2]
};
static_assert(sizeof(IGameObjectView) == 0x08,
              "IGameObjectView must be 0x08");

}  // namespace Offsets
