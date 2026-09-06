#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include <vector>
#include "C_SharedResource.h"
#include "CryEngine/CryCommon/CryString.h"

namespace wh::conceptmodule {

// forward decls for not-yet-RE'd pointee types (stage-2 auto)
class C_ConceptGraphDeserializer;

struct S_RandomEventStreamingState {
    S_RandomEventStreamingState();   // 0x1807CEAE0
    ~S_RandomEventStreamingState();  // 0x182627090

    _smart_ptr<C_SharedResource> m_resource; // +0x00
    CryStringT<char> m_name;                 // +0x08
    std::map<CryStringT<char>, std::vector<void*>>
        m_assetsByName;                      // +0x10
    std::vector<_smart_ptr<C_SharedResource>>
        m_resources;                         // +0x20
    _smart_ptr<C_SharedResource> m_owner;    // +0x38
    C_ConceptGraphDeserializer* m_stream; // +0x40, owned polymorphic object
    bool m_active;                           // +0x48
    std::uint8_t m_unknown49[7];
};

static_assert(offsetof(S_RandomEventStreamingState, m_assetsByName) == 0x10,
              "S_RandomEventStreamingState::m_assetsByName offset mismatch");
static_assert(offsetof(S_RandomEventStreamingState, m_resources) == 0x20,
              "S_RandomEventStreamingState::m_resources offset mismatch");
static_assert(offsetof(S_RandomEventStreamingState, m_stream) == 0x40,
              "S_RandomEventStreamingState::m_stream offset mismatch");
static_assert(sizeof(S_RandomEventStreamingState) == 0x50,
              "S_RandomEventStreamingState size mismatch");

}  // namespace wh::conceptmodule
