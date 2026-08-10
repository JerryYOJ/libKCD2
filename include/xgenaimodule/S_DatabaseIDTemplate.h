#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// wh::xgenaimodule::S_DatabaseIDTemplate -- polymorphic database-row identity base.
// sizeof 0x18; vtable 0x183A8CDC0, deleting destructor plus RTTR trio.

namespace wh::xgenaimodule {

struct S_DatabaseIDTemplate {
    inline static constexpr auto RTTI = Offsets::RTTI_S_DatabaseIDTemplate;

    virtual ~S_DatabaseIDTemplate();  // [0] 0x1832088B8
    RTTR_ENABLE()                     // [1..3]

    CryGUID m_databaseId;  // +0x08, RTTR property "DatabaseId"
};
static_assert(sizeof(S_DatabaseIDTemplate) == 0x18,
              "S_DatabaseIDTemplate must be 0x18");
static_assert(offsetof(S_DatabaseIDTemplate, m_databaseId) == 0x08,
              "database row id at 0x08");

}  // namespace wh::xgenaimodule
