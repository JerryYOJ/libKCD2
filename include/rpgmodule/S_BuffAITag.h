#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::rpgmodule::S_BuffAITag
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------

namespace wh::rpgmodule {

struct S_BuffAITag {
    std::int32_t m_buff_ai_tag_id;                        // +0x00 RTTR "buff_ai_tag_id"
    std::uint8_t _pad04[4];                               // +0x04
    CryStringT<char> m_buff_ai_tag_name;                  // +0x08 RTTR "buff_ai_tag_name"
};

static_assert(offsetof(S_BuffAITag, m_buff_ai_tag_id) == 0x00,
              "S_BuffAITag::m_buff_ai_tag_id offset mismatch");
static_assert(sizeof(S_BuffAITag) == 0x10,
              "S_BuffAITag size mismatch");

}  // namespace wh::rpgmodule
