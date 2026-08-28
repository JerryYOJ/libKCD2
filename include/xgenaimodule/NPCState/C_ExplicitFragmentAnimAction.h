#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "C_AnimActionBase.h"
#include "E_DataSource.h"
#include "E_ExplicitFragmentEventReference.h"

namespace wh::xgenaimodule::NPCState {

class C_ExplicitFragmentAnimAction : public C_AnimActionBase {
public:
    ~C_ExplicitFragmentAnimAction() override;
    RTTR_ENABLE(C_AnimActionBase)                                            // [24..26], vtable 0x183B5B910

    CryStringT<char> m_fragment;                                             // +0x1A0 RTTR "Fragment"
    std::vector<CryStringT<char>> m_tags;                                    // +0x1A8 RTTR "Tags"
    E_ExplicitFragmentEventReference::Type m_eventReference;                 // +0x1C0 RTTR "EventReference"
    std::uint8_t m_padding1C1[3];                                            // +0x1C1
    E_DataSource m_dataSource;                                               // +0x1C4 RTTR "DataSource"
    std::uint8_t m_unknown1C8[8];                                            // +0x1C8
};

static_assert(offsetof(C_ExplicitFragmentAnimAction, m_fragment) == 0x1A0,
              "C_ExplicitFragmentAnimAction::m_fragment offset mismatch");
static_assert(offsetof(C_ExplicitFragmentAnimAction, m_tags) == 0x1A8,
              "C_ExplicitFragmentAnimAction::m_tags offset mismatch");
static_assert(offsetof(C_ExplicitFragmentAnimAction, m_dataSource) == 0x1C4,
              "C_ExplicitFragmentAnimAction::m_dataSource offset mismatch");
static_assert(sizeof(C_ExplicitFragmentAnimAction) == 0x1D0,
              "C_ExplicitFragmentAnimAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
