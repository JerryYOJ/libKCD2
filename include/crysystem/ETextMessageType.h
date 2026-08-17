#pragma once
#include <cstdint>

enum ETextMessageType : std::int32_t {
    eTextMessageCenter = 0,
    eTextMessageConsole,
    eTextMessageError,
    eTextMessageInfo,
    eTextMessageServer,
    eTextMessageAnnouncement,
};
static_assert(sizeof(ETextMessageType) == 0x04,
              "ETextMessageType must be 0x04");
