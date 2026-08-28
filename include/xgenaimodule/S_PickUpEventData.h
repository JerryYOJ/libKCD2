#pragma once
#include <cstddef>
#include "../framework/WUID.h"
#include "I_EventData.h"

namespace wh::xgenaimodule {

class S_PickUpEventData : public I_EventData {
public:
    ~S_PickUpEventData() override;
    void unk_01() override;
    void unk_03() override;
    void unk_04() override;
    RTTR_ENABLE(I_EventData)
    wh::framework::WUID m_slot;                           // +0x08 RTTR "Slot"
};

static_assert(offsetof(S_PickUpEventData, m_slot) == 0x08,
              "S_PickUpEventData::m_slot offset mismatch");
static_assert(sizeof(S_PickUpEventData) == 0x10,
              "S_PickUpEventData size mismatch");

}  // namespace wh::xgenaimodule
