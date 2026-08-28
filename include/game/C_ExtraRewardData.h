#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::game {

class C_ExtraRewardData {
public:
    virtual CryStringT<char>* unk_00();                     // [0] returns +0x08
    virtual CryStringT<char>* unk_01();                     // [1] returns +0x10
    virtual CryStringT<char>* unk_02();                     // [2] returns +0x18
    virtual CryStringT<char>* unk_03();                     // [3] returns +0x20
    virtual ~C_ExtraRewardData();                            // [4]
    RTTR_ENABLE()                                           // [5..7]

    CryStringT<char> m_name;                                // +0x08 RTTR "Name"
    CryStringT<char> m_uiName;                              // +0x10 RTTR "UiName"
    CryStringT<char> m_uiInfo;                              // +0x18 RTTR "UiInfo"
    CryStringT<char> m_iconId;                              // +0x20 RTTR "IconId"
    int m_uiOrder;                                          // +0x28 RTTR "UiOrder"
    int m_dlcId;                                            // +0x2C RTTR "DlcId"
    CryStringT<char> m_prosId;                              // +0x30 RTTR "ProsId"
    CryGUID m_itemId;                                       // +0x38 RTTR "ItemId"
    int m_itemCount;                                        // +0x48 RTTR "ItemCount"
    std::uint8_t _pad4C[4];                                 // +0x4C
};

static_assert(offsetof(C_ExtraRewardData, m_name) == 0x08,
              "C_ExtraRewardData::m_name offset mismatch");
static_assert(offsetof(C_ExtraRewardData, m_prosId) == 0x30,
              "C_ExtraRewardData::m_prosId offset mismatch");
static_assert(offsetof(C_ExtraRewardData, m_itemId) == 0x38,
              "C_ExtraRewardData::m_itemId offset mismatch");
static_assert(offsetof(C_ExtraRewardData, m_itemCount) == 0x48,
              "C_ExtraRewardData::m_itemCount offset mismatch");
static_assert(sizeof(C_ExtraRewardData) == 0x50,
              "C_ExtraRewardData size mismatch");

}  // namespace wh::game
