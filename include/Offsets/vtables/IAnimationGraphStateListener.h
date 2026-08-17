#pragma once
#include <cstddef>
#include <cstdint>

struct IAnimationGraphState;
using TAnimationGraphQueryID = std::uint32_t;

namespace Offsets {

class IAnimationGraphStateListener {
public:
    virtual ~IAnimationGraphStateListener() = default; // [0]
    virtual void SetOutput(const char* output, const char* value) = 0; // [1]
    virtual void QueryComplete(TAnimationGraphQueryID queryId,
                               bool succeeded) = 0; // [2]
    virtual void DestroyedState(IAnimationGraphState* state) = 0; // [3]
};
static_assert(sizeof(IAnimationGraphStateListener) == 0x08,
              "IAnimationGraphStateListener must be vptr-only");

}  // namespace Offsets
