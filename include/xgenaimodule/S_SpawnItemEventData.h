#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"
#include "I_EventData.h"

namespace wh::xgenaimodule {

class S_SpawnItemEventData : public I_EventData {
public:
    ~S_SpawnItemEventData() override;
    void unk_01() override;
    void unk_03() override;
    void unk_04() override;
    RTTR_ENABLE(I_EventData)
    CryStringT<char> m_itemClassId;                       // +0x08 RTTR "ItemClassId"
};

static_assert(offsetof(S_SpawnItemEventData, m_itemClassId) == 0x08,
              "S_SpawnItemEventData::m_itemClassId offset mismatch");
static_assert(sizeof(S_SpawnItemEventData) == 0x10,
              "S_SpawnItemEventData size mismatch");

}  // namespace wh::xgenaimodule
