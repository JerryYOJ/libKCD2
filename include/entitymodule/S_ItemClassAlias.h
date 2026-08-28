#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "S_ItemClass.h"

namespace wh::entitymodule {

class S_ItemClassAlias : public S_ItemClass {
public:
    CryGUID m_sourceItemId;                                              // +0x38 RTTR "SourceItemId"
    CryStringT<char> m_iconId;                                           // +0x48 RTTR "IconId"
    CryStringT<char> m_uiInfo;                                           // +0x50 RTTR "UIInfo"
    CryStringT<char> m_uiName;                                           // +0x58 RTTR "UIName"
    float m_weight;                                                      // +0x60 RTTR "Weight"
    bool m_isQuestItem;                                                  // +0x64 RTTR "IsQuestItem"
    std::uint8_t m_padding65[3];                                         // +0x65
    std::uint8_t m_unknown68[8];                                         // +0x68
};

static_assert(offsetof(S_ItemClassAlias, m_sourceItemId) == 0x38,
              "S_ItemClassAlias::m_sourceItemId offset mismatch");
static_assert(offsetof(S_ItemClassAlias, m_iconId) == 0x48,
              "S_ItemClassAlias::m_iconId offset mismatch");
static_assert(offsetof(S_ItemClassAlias, m_uiInfo) == 0x50,
              "S_ItemClassAlias::m_uiInfo offset mismatch");
static_assert(offsetof(S_ItemClassAlias, m_uiName) == 0x58,
              "S_ItemClassAlias::m_uiName offset mismatch");
static_assert(offsetof(S_ItemClassAlias, m_weight) == 0x60,
              "S_ItemClassAlias::m_weight offset mismatch");
static_assert(offsetof(S_ItemClassAlias, m_isQuestItem) == 0x64,
              "S_ItemClassAlias::m_isQuestItem offset mismatch");
static_assert(sizeof(S_ItemClassAlias) == 0x70,
              "S_ItemClassAlias size mismatch");

} // namespace wh::entitymodule
