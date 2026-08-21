#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include "../JobManager/SJobState.h"

namespace wh::framework {

// Reconstructed generic wrapper. For the spatial job, T is C_SpatialGrid*
// and U is C_SpatialGrid*&, yielding std::function<void(C_SpatialGrid*&)>.
template<class T, class U = T&>
class C_CryJobWrap {
public:
    C_CryJobWrap();
    ~C_CryJobWrap();

    JobManager::SJobState m_jobState; // +0x00
    T m_data;                         // +0x08, borrowed for the grid specialization
    std::function<void(U)> m_fn;      // +0x10
    volatile std::int32_t m_status;   // +0x50, 0 idle / 1 submitted / 2 executing / 3 finished
    std::uint32_t _pad54;             // +0x54
};
static_assert(sizeof(C_CryJobWrap<void*, void*&>) == 0x58);

}  // namespace wh::framework
