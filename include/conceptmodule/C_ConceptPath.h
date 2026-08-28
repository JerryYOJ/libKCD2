#pragma once
#include <cstddef>
#include <deque>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::conceptmodule {

class C_ConceptPath {
public:
    C_ConceptPath();                                         // 0x18265033C
    explicit C_ConceptPath(CryStringT<char> const& path);     // 0x1808D9558
    C_ConceptPath(C_ConceptPath const& other);                // 0x1808D9494
    virtual ~C_ConceptPath();                                 // [0] 0x1813F7230
    RTTR_ENABLE()                                             // [1..3]

    CryStringT<char> GetPath() const;                         // 0x1826506F8
    void SetPath(CryStringT<char> path);                      // 0x1808D95A4

    std::deque<CryStringT<char>> m_segments;                  // +0x08 accessor backing "Path"
};

static_assert(offsetof(C_ConceptPath, m_segments) == 0x08,
              "C_ConceptPath::m_segments offset mismatch");
static_assert(sizeof(C_ConceptPath) == 0x30,
              "C_ConceptPath size mismatch");

}  // namespace wh::conceptmodule
