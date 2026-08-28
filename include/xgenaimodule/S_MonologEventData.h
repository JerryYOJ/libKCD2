#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"
#include "I_EventData.h"

namespace wh::xgenaimodule {

class S_MonologEventData : public I_EventData {
public:
    ~S_MonologEventData() override;
    void unk_01() override;
    void unk_03() override;
    void unk_04() override;
    RTTR_ENABLE(I_EventData)
    CryStringT<char> m_name;                              // +0x08
};

static_assert(offsetof(S_MonologEventData, m_name) == 0x08,
              "S_MonologEventData::m_name offset mismatch");
static_assert(sizeof(S_MonologEventData) == 0x10,
              "S_MonologEventData size mismatch");

}  // namespace wh::xgenaimodule
