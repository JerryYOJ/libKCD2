#pragma once
#include <cstddef>

namespace wh::entitymodule {

class C_AnimDoor;
struct S_DoorAnimSet;

class I_DoorAnimSetDatabase {
public:
    virtual const S_DoorAnimSet* FindByTags(const char* tags) const = 0; // [0] 0x1804CF834
    virtual const S_DoorAnimSet* FindForDoor(const C_AnimDoor* door) const = 0; // [1] 0x1804CF7EC; reads esDoorAnimSet
};

static_assert(sizeof(I_DoorAnimSetDatabase) == 0x08,
              "I_DoorAnimSetDatabase size mismatch");

} // namespace wh::entitymodule
