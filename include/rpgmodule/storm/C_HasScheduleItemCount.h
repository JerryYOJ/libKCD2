#pragma once
#include <cstddef>
#include "I_ValueComparatorSelector.h"

namespace wh::rpgmodule::storm {

class C_HasScheduleItemCount : public I_ValueComparatorSelector {
public:
    ~C_HasScheduleItemCount() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_ValueComparatorSelector)
    virtual void unk_05();                                // [5] 0x181A964B0
};

static_assert(sizeof(C_HasScheduleItemCount) == 0x18,
              "C_HasScheduleItemCount size mismatch");

}  // namespace wh::rpgmodule::storm
