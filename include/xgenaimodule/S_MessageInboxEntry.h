#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "S_MessageHandle.h"

namespace wh::xgenaimodule {

class S_MessageInboxEntry {
public:
    std::uint64_t m_key;                    // +0x00, exact key domain OPEN
    std::vector<S_MessageHandle> m_messages; // +0x08
};
static_assert(sizeof(S_MessageInboxEntry) == 0x20,
              "S_MessageInboxEntry must be 0x20");
static_assert(offsetof(S_MessageInboxEntry, m_messages) == 0x08,
              "message-handle vector must be at 0x08");

}  // namespace wh::xgenaimodule
