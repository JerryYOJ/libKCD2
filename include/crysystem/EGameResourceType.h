#pragma once
#include <cstdint>

enum EGameResourceType : std::int32_t {
    eGameResourceType_Loadout = 0,
    eGameResourceType_Item,
};
static_assert(sizeof(EGameResourceType) == 0x04,
              "EGameResourceType must be 0x04");
