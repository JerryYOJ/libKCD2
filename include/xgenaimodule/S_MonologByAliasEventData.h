#pragma once
#include <cstddef>
#include "S_MonologEventData.h"

namespace wh::xgenaimodule {

class S_MonologByAliasEventData : public S_MonologEventData {
public:
    ~S_MonologByAliasEventData() override;
    RTTR_ENABLE(S_MonologEventData)
};

static_assert(sizeof(S_MonologByAliasEventData) == 0x10,
              "S_MonologByAliasEventData size mismatch");

}  // namespace wh::xgenaimodule
