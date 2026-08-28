#pragma once
#include <cstddef>
#include <cstdint>
#include "S_PathFindingRequest.h"

namespace wh::xgenaimodule::navigation {

struct S_PathFindingRequestFlee : S_PathFindingRequest {
    ~S_PathFindingRequestFlee() override;
    void unk_1() override;
    S_PathFindingRequest* Clone() override;
    void unk_3() override;
    void unk_4() override;
    RTTR_ENABLE(S_PathFindingRequest)

    std::uint8_t m_unknown78[0x18];                         // +0x78
};

static_assert(sizeof(S_PathFindingRequestFlee) == 0x90,
              "S_PathFindingRequestFlee size mismatch");

}  // namespace wh::xgenaimodule::navigation
