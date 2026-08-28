#pragma once
#include <cstddef>
#include "S_PathFindingRequestDefault.h"

namespace wh::xgenaimodule::navigation {

struct S_PathFindingRequestPathsOnly : S_PathFindingRequestDefault {
    ~S_PathFindingRequestPathsOnly() override;
    void unk_1() override;
    S_PathFindingRequest* Clone() override;
    RTTR_ENABLE(S_PathFindingRequestDefault)
};

static_assert(sizeof(S_PathFindingRequestPathsOnly) == 0x98,
              "S_PathFindingRequestPathsOnly size mismatch");

}  // namespace wh::xgenaimodule::navigation
