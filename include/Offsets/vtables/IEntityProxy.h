#pragma once
#include <cstdint>
#include "IComponent.h"

namespace Offsets {

class IEntityProxy : public IComponent {
public:
    ~IEntityProxy() override = default;                       // [0]
    virtual void _vf6() = 0;                                 // [6]
    virtual void _vf7() = 0;                                 // [7]
    virtual void _vf8() = 0;                                 // [8]
    virtual void _vf9() = 0;                                 // [9]
    virtual void _vf10() = 0;                                // [10]
    virtual void _vf11() = 0;                                // [11]
    virtual void _vf12() = 0;                                // [12]
    virtual void _vf13(std::uint64_t* value) = 0;             // [13]
    virtual void _vf14() = 0;                                // [14]
    virtual void _vf15() = 0;                                // [15]
};

static_assert(sizeof(IEntityProxy) == 0x28,
              "IEntityProxy size mismatch");

}  // namespace Offsets
