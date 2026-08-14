#pragma once

#include "WUID.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::framework::I_WUIDMappingProvider -- CryGUID <-> WUID mapping interface.
// -----------------------------------------------
// Exactly two virtual slots and no virtual destructor.

namespace wh::framework {

class I_WUIDMappingProvider {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_WUIDMappingProvider;

    virtual WUID GetWuidForKey(const CryGUID& key) const = 0; // [0]
    virtual CryGUID GetValueForWuid(WUID wuid) const = 0;     // [1]
};
static_assert(sizeof(I_WUIDMappingProvider) == 0x08);

}  // namespace wh::framework
