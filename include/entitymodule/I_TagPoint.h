#pragma once
#include <cstddef>
#include "../Offsets/Offsets_RTTI.h"
#include "../Offsets/vtables/IEntity.h"
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

// Native vptr-only interface. It has no virtual destructor in the KCD2 table.
class I_TagPoint {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_TagPoint;

    virtual Offsets::IEntity* GetTagPointEntity() = 0; // [0], source spelling/constness OPEN
    RTTR_ENABLE() // [1..3]
};
static_assert(sizeof(I_TagPoint) == 0x08,
              "I_TagPoint must contain only its vptr");

}  // namespace wh::entitymodule
