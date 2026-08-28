#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"
#include "E_SmartBehaviorState.h"
#include "S_TreeLocation.h"

namespace wh::xgenaimodule {

class S_SmartBehaviorTemplate {
public:
    class S_SerializedInboxTemplate {
    public:
        virtual ~S_SerializedInboxTemplate();                            // [0]
        RTTR_ENABLE()                                                    // [1..3], vtable 0x183B879B0

        CryGUID m_inboxId;                                               // +0x08 RTTR "InboxId"
        std::int32_t m_priority;                                         // +0x18 RTTR "Priority"
        std::uint8_t m_padding1C[4];                                     // +0x1C
    };

    class S_NavigationInfo {
    public:
        virtual ~S_NavigationInfo();                                     // [0]
        RTTR_ENABLE()                                                    // [1..3], vtable 0x183B099B8

        std::uint8_t m_unknown08[8];                                     // +0x08
        CryStringT<char> m_startHelper;                                  // +0x10 RTTR "StartHelper"
        CryStringT<char> m_endHelper;                                    // +0x18 RTTR "EndHelper"
    };

    virtual ~S_SmartBehaviorTemplate();                                  // [0]
    RTTR_ENABLE()                                                        // [1..3], vtable 0x183B09990

    S_TreeLocation m_treeLocation;                                       // +0x08 RTTR "TreeLocation"
    std::int32_t m_maxInstances;                                         // +0x18 RTTR "MaxInstances"
    E_SmartBehaviorState::Type m_initialState;                           // +0x1C RTTR "InitialState"
    std::uint8_t m_unknown1D[0x43];                                      // +0x1D
    CryStringT<char> m_name;                                             // +0x60 RTTR "Name"
};

static_assert(offsetof(S_SmartBehaviorTemplate::S_SerializedInboxTemplate, m_inboxId) == 0x08,
              "S_SerializedInboxTemplate::m_inboxId offset mismatch");
static_assert(offsetof(S_SmartBehaviorTemplate::S_SerializedInboxTemplate, m_priority) == 0x18,
              "S_SerializedInboxTemplate::m_priority offset mismatch");
static_assert(sizeof(S_SmartBehaviorTemplate::S_SerializedInboxTemplate) == 0x20,
              "S_SerializedInboxTemplate size mismatch");
static_assert(offsetof(S_SmartBehaviorTemplate::S_NavigationInfo, m_startHelper) == 0x10,
              "S_NavigationInfo::m_startHelper offset mismatch");
static_assert(offsetof(S_SmartBehaviorTemplate::S_NavigationInfo, m_endHelper) == 0x18,
              "S_NavigationInfo::m_endHelper offset mismatch");
static_assert(sizeof(S_SmartBehaviorTemplate::S_NavigationInfo) == 0x20,
              "S_NavigationInfo size mismatch");
static_assert(offsetof(S_SmartBehaviorTemplate, m_treeLocation) == 0x08,
              "S_SmartBehaviorTemplate::m_treeLocation offset mismatch");
static_assert(offsetof(S_SmartBehaviorTemplate, m_maxInstances) == 0x18,
              "S_SmartBehaviorTemplate::m_maxInstances offset mismatch");
static_assert(offsetof(S_SmartBehaviorTemplate, m_name) == 0x60,
              "S_SmartBehaviorTemplate::m_name offset mismatch");
static_assert(sizeof(S_SmartBehaviorTemplate) == 0x68,
              "S_SmartBehaviorTemplate size mismatch");

} // namespace wh::xgenaimodule
