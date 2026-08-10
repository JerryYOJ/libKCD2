#pragma once
#include <memory>
#include <vector>
#include "C_ObjectDatabaseBase.h"

// wh::databasemodule::C_ObjectDatabase<TObject, TContainer> -- owned object storage.
// RTTI proves TContainer is the container template itself (std::vector or std::list).

namespace wh::databasemodule {

template <typename TObject,
          template <typename, typename> class TContainer = std::vector>
class C_ObjectDatabase : public C_ObjectDatabaseBase {
public:
    using object_type = TObject;
    using container_type = TContainer<TObject, std::allocator<TObject>>;

    container_type m_objects;  // +0x30
};

static_assert(sizeof(C_ObjectDatabase<int, std::vector>) == 0x48,
              "vector object database must be 0x48");

}  // namespace wh::databasemodule
