#pragma once
#include <cstddef>
#include <cstdint>
#include "S_PathFindingRequestDefault.h"

namespace wh::xgenaimodule::navigation {

struct S_PathFindingRequestTargetOnLadder : S_PathFindingRequestDefault {
    ~S_PathFindingRequestTargetOnLadder() override;
    void unk_1() override;
    S_PathFindingRequest* Clone() override;
    RTTR_ENABLE(S_PathFindingRequestDefault)

    std::uint8_t m_unknown98[8];                            // +0x98
};

static_assert(sizeof(S_PathFindingRequestTargetOnLadder) == 0xA0,
              "S_PathFindingRequestTargetOnLadder size mismatch");

}  // namespace wh::xgenaimodule::navigation
