#pragma once
#include <boost/container/vector.hpp>
#include <cstddef>
#include <utility>
#include "../CryEngine/CryCommon/CryString.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "S_ShopDBData.h"

namespace wh::shopmodule {

class C_Shop;

class C_ShopsDatabase
    : public wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<S_ShopDBData>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_ShopDBData>> {
public:
    ~C_ShopsDatabase() override;                             // [0] 0x182EF30C0
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)   // [18..20]

    boost::container::vector<std::pair<CryStringT<char>, C_Shop*>> m_shopsByName; // +0x78
};

static_assert(offsetof(C_ShopsDatabase, m_shopsByName) == 0x78,
              "C_ShopsDatabase::m_shopsByName offset mismatch");
static_assert(sizeof(C_ShopsDatabase) == 0x90,
              "C_ShopsDatabase size mismatch");

}  // namespace wh::shopmodule
