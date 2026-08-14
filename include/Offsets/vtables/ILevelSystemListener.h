#pragma once
#include <cstddef>

namespace Offsets {

// KCD2 binary-facing level-system listener. Signatures remain OPEN.
class ILevelSystemListener {
public:
    virtual ~ILevelSystemListener() = default; // [0]
    virtual void _vf1() = 0;                  // [1]
    virtual void _vf2() = 0;                  // [2]
    virtual void _vf3() = 0;                  // [3]
    virtual void _vf4() = 0;                  // [4]
    virtual void _vf5() = 0;                  // [5]
    virtual void _vf6() = 0;                  // [6]
    virtual void _vf7() = 0;                  // [7]
    virtual void _vf8() = 0;                  // [8]
    virtual void _vf9() = 0;                  // [9]
};
static_assert(sizeof(ILevelSystemListener) == 0x08,
              "ILevelSystemListener must be 0x08");

}  // namespace Offsets
