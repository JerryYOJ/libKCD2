#pragma once
#include <cstddef>
#include <cstdint>
#include <set>
#include <vector>
#include "C_ConceptStreamingThread.h"
#include "S_ConceptStreamingWork.h"
#include "S_RandomEventStreamingState.h"
#include "CryEngine/CryCommon/CryString.h"
#include "framework/C_Signal.h"
#include "rttr/rttr_enable.h"

namespace wh::conceptmodule {

class C_RandomEventConceptStreaming {
public:
    C_RandomEventConceptStreaming();   // 0x1807CE9E0
    ~C_RandomEventConceptStreaming();  // 0x182626F88
    RTTR_ENABLE() // [0..2]

    wh::shared::C_Signal<> m_changed;             // +0x08, argument family unresolved
    S_RandomEventStreamingState m_states[2];      // +0x18
    std::uint32_t m_unknownB8;                    // +0xB8
    std::uint8_t m_unknownBC[4];
    void* m_streamingObject;                      // +0xC0, intrusive ownership
    bool m_unknownC8;                             // +0xC8
    std::uint8_t m_unknownC9[7];
    C_ConceptStreamingThread m_thread;            // +0xD0
    std::uint8_t m_runtimeEntries[0x28];          // +0x1C8, custom hash container
    std::vector<S_ConceptStreamingWork> m_pendingWork; // +0x1F0
    std::set<CryStringT<char>> m_names;           // +0x208
    bool m_unknown218;                            // +0x218
    std::uint8_t m_unknown219[7];
    void* m_lock;                                 // +0x220, SRWLOCK storage
    bool m_unknown228;                            // +0x228
    std::uint8_t m_unknown229[7];
};

static_assert(offsetof(C_RandomEventConceptStreaming, m_changed) == 0x08,
              "C_RandomEventConceptStreaming::m_changed offset mismatch");
static_assert(offsetof(C_RandomEventConceptStreaming, m_states) == 0x18,
              "C_RandomEventConceptStreaming::m_states offset mismatch");
static_assert(offsetof(C_RandomEventConceptStreaming, m_thread) == 0xD0,
              "C_RandomEventConceptStreaming::m_thread offset mismatch");
static_assert(offsetof(C_RandomEventConceptStreaming, m_pendingWork) == 0x1F0,
              "C_RandomEventConceptStreaming::m_pendingWork offset mismatch");
static_assert(offsetof(C_RandomEventConceptStreaming, m_names) == 0x208,
              "C_RandomEventConceptStreaming::m_names offset mismatch");
static_assert(sizeof(C_RandomEventConceptStreaming) == 0x230,
              "C_RandomEventConceptStreaming size mismatch");

}  // namespace wh::conceptmodule
