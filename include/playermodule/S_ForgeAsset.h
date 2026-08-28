#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "E_ForgeAssetDefault.h"
#include "E_ForgeAssetSlot.h"

namespace wh::playermodule {

struct S_ForgeAsset {
    CryStringT<char> m_name;                                // +0x00 RTTR "name"
    CryStringT<char> m_uiNameStringName;                    // +0x08 RTTR "_ui_name_string_name"
    CryStringT<char> m_uiLongNameStringName;                // +0x10 RTTR "_ui_long_name_string_name"
    CryStringT<char> m_uiDescriptionStringName;             // +0x18 RTTR "_ui_description_string_name"
    CryStringT<char> m_uiLoreDescriptionStringName;         // +0x20 RTTR "_ui_lore_description_string_name"
    std::uint32_t m_unknown28;                              // +0x28
    E_ForgeAssetDefault::Type m_default;                    // +0x2C
    bool m_unknown2D;                                       // +0x2D
    std::uint8_t _pad2E[2];                                 // +0x2E
    float m_unknown30;                                      // +0x30
    std::uint8_t _pad34[4];                                 // +0x34
    CryStringT<char> m_profileName;                         // +0x38
    E_ForgeAssetSlot::Type m_slot;                          // +0x40
    std::uint8_t _pad41[3];                                 // +0x41
    int m_unknown44;                                        // +0x44
    CryGUID m_profileId;                                    // +0x48
};

static_assert(offsetof(S_ForgeAsset, m_uiNameStringName) == 0x08,
              "S_ForgeAsset::m_uiNameStringName offset mismatch");
static_assert(offsetof(S_ForgeAsset, m_default) == 0x2C,
              "S_ForgeAsset::m_default offset mismatch");
static_assert(offsetof(S_ForgeAsset, m_profileName) == 0x38,
              "S_ForgeAsset::m_profileName offset mismatch");
static_assert(offsetof(S_ForgeAsset, m_profileId) == 0x48,
              "S_ForgeAsset::m_profileId offset mismatch");
static_assert(sizeof(S_ForgeAsset) == 0x58,
              "S_ForgeAsset size mismatch");

}  // namespace wh::playermodule
