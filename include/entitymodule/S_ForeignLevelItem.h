#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "S_ActiveQuestItem.h"

namespace wh::entitymodule {

class S_ForeignLevelItem : public S_ActiveQuestItem {
public:
    ~S_ForeignLevelItem() override;                         // [0] 0x182A87D14
    RTTR_ENABLE(S_ActiveQuestItem)                          // [1..3], vtable 0x183A3D470

    CryStringT<char> m_levelName;                           // +0x108
    bool m_useBackupLocation;                               // +0x110
    std::uint8_t m_padding111[7];                           // +0x111
};

static_assert(offsetof(S_ForeignLevelItem, m_levelName) == 0x108,
              "S_ForeignLevelItem::m_levelName offset mismatch");
static_assert(offsetof(S_ForeignLevelItem, m_useBackupLocation) == 0x110,
              "S_ForeignLevelItem::m_useBackupLocation offset mismatch");
static_assert(sizeof(S_ForeignLevelItem) == 0x118,
              "S_ForeignLevelItem size mismatch");

}  // namespace wh::entitymodule
