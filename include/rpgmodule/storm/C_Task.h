#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include <vector>
#include "C_Source.h"
#include "E_TaskClass.h"

namespace wh::rpgmodule::storm {
class C_Task {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_name;  // +0x8 RTTR "name"
    E_TaskClass m_class;  // +0x10 RTTR "class"
    std::uint8_t m_unknown12[0x6];                  // +0x12
    std::vector<C_Source> m_sources;  // +0x18 RTTR "sources"
};

static_assert(offsetof(C_Task, m_sources) == 0x18, "C_Task::m_sources offset mismatch");
static_assert(offsetof(C_Task, m_class) == 0x10, "C_Task::m_class offset mismatch");
static_assert(offsetof(C_Task, m_name) == 0x8, "C_Task::m_name offset mismatch");
static_assert(sizeof(C_Task) == 0x30, "C_Task size mismatch");

}  // namespace wh::rpgmodule::storm
