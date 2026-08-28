#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "S_ActionAdditiveAnimRequest.h"

namespace wh::entitymodule {

class S_ActorAdditiveAnimRequest : public S_ActionAdditiveAnimRequest {
public:
    ~S_ActorAdditiveAnimRequest() override;                    // [0] 0x182895554
    RTTR_ENABLE(S_ActionAdditiveAnimRequest)                    // [4..6], vtable 0x184707E48

    std::int32_t m_unknownE8;                                  // +0xE8, initialized -1
    std::uint32_t m_paddingEC;                                 // +0xEC
    CryStringT<char> m_stringF0;                               // +0xF0
    CryStringT<char> m_stringF8;                               // +0xF8
};

static_assert(offsetof(S_ActorAdditiveAnimRequest, m_unknownE8) == 0xE8,
              "S_ActorAdditiveAnimRequest::m_unknownE8 offset mismatch");
static_assert(offsetof(S_ActorAdditiveAnimRequest, m_stringF0) == 0xF0,
              "S_ActorAdditiveAnimRequest::m_stringF0 offset mismatch");
static_assert(sizeof(S_ActorAdditiveAnimRequest) == 0x100,
              "S_ActorAdditiveAnimRequest size mismatch");

}  // namespace wh::entitymodule
