#pragma once
#include <cstddef>
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../framework/C_LocalizedString.h"
#include "../framework/E_AutoSaveType.h"
#include "../questmodule/S_ObjectiveName.h"

namespace wh::playermodule {

class C_SaveGameBase {
public:
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger> m_enqueueSave; // +0x00 RTTR "EnqueueSave"
    wh::conceptmodule::C_TypedPortRef<wh::framework::E_AutoSaveType::Type> m_type; // +0x40 RTTR "Type"
    wh::conceptmodule::C_TypedPortRef<wh::questmodule::S_ObjectiveName> m_objectiveName; // +0x80
    wh::conceptmodule::C_TypedPortRef<wh::framework::C_LocalizedString> m_notification; // +0xC0
};

static_assert(offsetof(C_SaveGameBase, m_enqueueSave) == 0x00,
              "C_SaveGameBase::m_enqueueSave offset mismatch");
static_assert(offsetof(C_SaveGameBase, m_type) == 0x40,
              "C_SaveGameBase::m_type offset mismatch");
static_assert(offsetof(C_SaveGameBase, m_objectiveName) == 0x80,
              "C_SaveGameBase::m_objectiveName offset mismatch");
static_assert(offsetof(C_SaveGameBase, m_notification) == 0xC0,
              "C_SaveGameBase::m_notification offset mismatch");
static_assert(sizeof(C_SaveGameBase) == 0x100,
              "C_SaveGameBase size mismatch");

}  // namespace wh::playermodule
