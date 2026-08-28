#pragma once
#include <cstddef>
#include "../rttr/rttr_enable.h"

namespace wh::musicmodule {

class I_MusicManager {
public:
    virtual void Initialize() = 0;                             // [0]
    virtual void Update(float frameTime) = 0;                  // [1]
    virtual void unk_02() = 0;                                 // [2]
    virtual void unk_03() = 0;                                 // [3]
    virtual void unk_04() = 0;                                 // [4]
    virtual void unk_05() = 0;                                 // [5]
    virtual void unk_06() = 0;                                 // [6]
    virtual void unk_07() = 0;                                 // [7]
    virtual void unk_08() = 0;                                 // [8]
    virtual ~I_MusicManager();                                 // [9] 0x182F230F4
    RTTR_ENABLE()                                               // [10..12]
};

static_assert(sizeof(I_MusicManager) == 0x08,
              "I_MusicManager size mismatch");

}  // namespace wh::musicmodule
