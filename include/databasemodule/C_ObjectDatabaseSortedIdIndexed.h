#pragma once
#include <vector>

// wh::databasemodule::C_ObjectDatabaseSortedIdIndexed<TBase, TId> -- sorted pointer index.

namespace wh::databasemodule {

template <typename TBase, typename TId>
class C_ObjectDatabaseSortedIdIndexed : public TBase {
public:
    using object_type = typename TBase::object_type;
    using index_pointer = const object_type*;

    bool RebuildIndices() override;                // [16] sort by TId

    std::vector<index_pointer> m_sortedIdIndex;
};

}  // namespace wh::databasemodule
