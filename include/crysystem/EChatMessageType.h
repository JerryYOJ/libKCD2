#pragma once
#include <cstdint>

enum EChatMessageType : std::int32_t {
    eChatToTarget = 0,
    eChatToTeam,
    eChatToAll,
};
static_assert(sizeof(EChatMessageType) == 0x04,
              "EChatMessageType must be 0x04");
