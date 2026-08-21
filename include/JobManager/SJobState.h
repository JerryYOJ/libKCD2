#pragma once
#include <cstddef>

namespace JobManager {

struct SJobState {
    struct SJobStateImpl;
    SJobStateImpl* m_pImpl; // +0x00, intrusive-owned implementation
};
static_assert(sizeof(SJobState) == 0x08);
static_assert(offsetof(SJobState, m_pImpl) == 0x00);

}  // namespace JobManager
