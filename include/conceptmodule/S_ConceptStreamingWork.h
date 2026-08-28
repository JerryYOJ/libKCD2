#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "C_SharedResource.h"
#include "CryEngine/CryCommon/CryString.h"

namespace wh::conceptmodule {

struct S_ConceptStreamingWork {
    S_ConceptStreamingWork();   // 0x1804C3F5C
    ~S_ConceptStreamingWork();  // 0x1804C4458

    _smart_ptr<C_SharedResource> m_resource; // +0x00
    std::vector<std::uint8_t> m_data;        // +0x08
    std::uint64_t m_unknown20;               // +0x20
    CryStringT<char> m_name;                 // +0x28
    std::uint64_t m_unknown30;               // +0x30
};

static_assert(offsetof(S_ConceptStreamingWork, m_data) == 0x08,
              "S_ConceptStreamingWork::m_data offset mismatch");
static_assert(offsetof(S_ConceptStreamingWork, m_name) == 0x28,
              "S_ConceptStreamingWork::m_name offset mismatch");
static_assert(sizeof(S_ConceptStreamingWork) == 0x38,
              "S_ConceptStreamingWork size mismatch");

}  // namespace wh::conceptmodule
