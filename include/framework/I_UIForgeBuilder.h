#pragma once
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::framework {

class I_UIForgeBuilder {
public:
    virtual ~I_UIForgeBuilder();                             // [0] 0x181F78280
    virtual void* unk_01() = 0;                              // [1]
    virtual void* unk_02() = 0;                              // [2]
    virtual void unk_03(const void* slots) = 0;              // [3]
    virtual void unk_04(const void* assets) = 0;             // [4]
    virtual void unk_05() = 0;                               // [5]
    virtual void unk_06(
        int activeSequence,
        std::int64_t value,
        std::uint8_t selection) = 0;                         // [6]
    virtual void unk_07(
        int activeSequence,
        std::int64_t value,
        std::uint8_t selection,
        std::int64_t slot) = 0;                              // [7]
    virtual void unk_08(float strength, float duration) = 0; // [8]
    virtual void unk_09(float duration) = 0;                 // [9]
    virtual void unk_10() = 0;                               // [10]
    virtual void unk_11() = 0;                               // [11]
    RTTR_ENABLE()                                             // [12..14]
};

static_assert(sizeof(I_UIForgeBuilder) == 0x08,
              "I_UIForgeBuilder size mismatch");

}  // namespace wh::framework
