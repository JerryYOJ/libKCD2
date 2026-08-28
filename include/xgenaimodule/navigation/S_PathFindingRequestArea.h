#pragma once
#include <cstddef>
#include <cstdint>
#include "S_PathFindingRequest.h"

namespace wh::xgenaimodule::navigation {

struct S_PathFindingRequestArea : S_PathFindingRequest {
    ~S_PathFindingRequestArea() override;
    void unk_1() override;
    S_PathFindingRequest* Clone() override;
    void unk_3() override;
    void unk_4() override;
    RTTR_ENABLE(S_PathFindingRequest)

    std::uint8_t m_unknown78[8];                            // +0x78
};

static_assert(sizeof(S_PathFindingRequestArea) == 0x80,
              "S_PathFindingRequestArea size mismatch");

}  // namespace wh::xgenaimodule::navigation
