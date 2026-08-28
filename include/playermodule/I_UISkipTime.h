#pragma once
#include <cstddef>

namespace wh::playermodule {

class I_UISkipTime {
public:
    virtual ~I_UISkipTime();
    virtual void StartAction() = 0;          // [1]
    virtual void SetInterval(float interval) = 0; // [2]
    virtual void SetTime(float time) = 0;    // [3]
    virtual void ShowDialog() = 0;           // [4]
    virtual void HideDialog() = 0;           // [5]
    virtual void RemoveDialog() = 0;         // [6]
};

static_assert(sizeof(I_UISkipTime) == 0x08,
              "I_UISkipTime size mismatch");

}  // namespace wh::playermodule
