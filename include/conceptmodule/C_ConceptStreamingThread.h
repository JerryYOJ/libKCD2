#pragma once
#include <condition_variable>
#include <cstddef>
#include <cstdint>
#include <mutex>
#include "IThread.h"
#include "S_ConceptStreamingWork.h"

namespace wh::conceptmodule {

class C_ConceptStreamingThread : public ::IThread {
public:
    C_ConceptStreamingThread();                 // 0x1807CEB4C
    ~C_ConceptStreamingThread() override;       // [0] 0x1826272EC
    void ThreadEntry() override;                // [1] 0x180519DE0

    std::mutex m_mutex;                         // +0x08
    std::condition_variable m_condition;        // +0x58
    void* m_currentRequest;                     // +0xA0
    bool m_hasWork;                             // +0xA8
    std::uint8_t m_unknownA9[7];
    bool m_processing;                          // +0xB0
    std::uint8_t m_unknownB1[7];
    S_ConceptStreamingWork m_work;              // +0xB8
    bool m_stopRequested;                       // +0xF0
    bool m_wakePending;                         // +0xF1
    std::uint8_t m_unknownF2[6];
};

static_assert(offsetof(C_ConceptStreamingThread, m_mutex) == 0x08,
              "C_ConceptStreamingThread::m_mutex offset mismatch");
static_assert(offsetof(C_ConceptStreamingThread, m_condition) == 0x58,
              "C_ConceptStreamingThread::m_condition offset mismatch");
static_assert(offsetof(C_ConceptStreamingThread, m_work) == 0xB8,
              "C_ConceptStreamingThread::m_work offset mismatch");
static_assert(offsetof(C_ConceptStreamingThread, m_stopRequested) == 0xF0,
              "C_ConceptStreamingThread::m_stopRequested offset mismatch");
static_assert(sizeof(C_ConceptStreamingThread) == 0xF8,
              "C_ConceptStreamingThread size mismatch");

}  // namespace wh::conceptmodule
