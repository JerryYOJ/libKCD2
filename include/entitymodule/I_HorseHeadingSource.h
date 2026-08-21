#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::I_HorseHeadingSource -- KCD2 WHGame.dll.  sizeof 8.
// -----------------------------------------------
// [SYNTHETIC] no RTTI name recovered. Pointer at S_HorseData+0x100.
// Slots 2/3/5 are call-site certified. Slots 1/4 have no recovered implementor.

namespace wh::entitymodule {

class S_HorseData;

class I_HorseHeadingSource {
public:
    virtual ~I_HorseHeadingSource() = default;                  // [0]
    virtual void vf08() = 0;                                    // [1]  impl unrecovered
    virtual bool IsLive() const = 0;                            // [2]  0x1806CEE1C
    virtual void GetHeading(float* forward, float* yawRad) = 0; // [3]  0x180A4E82A
    virtual void vf20() = 0;                                    // [4]  impl unrecovered
    virtual void Sync(S_HorseData* horseData) = 0;              // [5]  0x1806CEBB2
};
static_assert(sizeof(I_HorseHeadingSource) == 8, "I_HorseHeadingSource is vtable-only");

}  // namespace wh::entitymodule
