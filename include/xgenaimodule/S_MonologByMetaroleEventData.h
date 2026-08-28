#pragma once
#include <cstddef>
#include "S_MonologEventData.h"

namespace wh::xgenaimodule {

class S_MonologByMetaroleEventData : public S_MonologEventData {
public:
    ~S_MonologByMetaroleEventData() override;
    RTTR_ENABLE(S_MonologEventData)
};

static_assert(sizeof(S_MonologByMetaroleEventData) == 0x10,
              "S_MonologByMetaroleEventData size mismatch");

}  // namespace wh::xgenaimodule
