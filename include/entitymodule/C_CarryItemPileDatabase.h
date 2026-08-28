#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../rttr/rttr_enable.h"
#include "S_CarryItemPileGeom.h"

namespace wh::entitymodule {

using C_CarryItemPileDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<
        S_CarryItemPileGeom,
        std::vector>;

class C_CarryItemPileDatabase : public C_CarryItemPileDatabaseBase {
public:
    ~C_CarryItemPileDatabase() override; // [0] 0x1828D479C
    std::int32_t unk_01() const override; // [1] 0x181A72500; returns 4
    void OnLoaded() override;             // [17] 0x181850690
    RTTR_ENABLE(C_CarryItemPileDatabaseBase) // [18..20]

    const void* m_connectionTable;       // +0x78, exact registry type unresolved
    std::uint16_t m_connectionIndices[2];// +0x80, initialized 0xFFFF
    std::uint32_t m_padding84;           // +0x84
    std::unordered_map<
        CryGUID,
        S_CarryItemPileGeom*> m_geometriesById; // +0x88
};

static_assert(offsetof(C_CarryItemPileDatabase, m_connectionTable) == 0x78,
              "C_CarryItemPileDatabase::m_connectionTable offset mismatch");
static_assert(offsetof(C_CarryItemPileDatabase, m_geometriesById) == 0x88,
              "C_CarryItemPileDatabase::m_geometriesById offset mismatch");
static_assert(sizeof(C_CarryItemPileDatabase) == 0xC8,
              "C_CarryItemPileDatabase size mismatch");

} // namespace wh::entitymodule
