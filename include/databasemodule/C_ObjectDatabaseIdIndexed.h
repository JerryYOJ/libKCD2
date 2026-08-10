#pragma once
#include <vector>

// wh::databasemodule::C_ObjectDatabaseIdIndexed<TBase, TId> -- dense ID index.
// The stored first ID uses the exact TId width; missing IDs remain null vector holes.

namespace wh::databasemodule {

template <typename TBase, typename TId>
class C_ObjectDatabaseIdIndexed : public TBase {
public:
    using object_type = typename TBase::object_type;
    using index_pointer = const object_type*;

    bool RebuildIndices() override;                // [16] dense range rebuild

    std::vector<index_pointer> m_idIndex;          // sizeof(TBase) + 0x00
    TId m_firstId;                                 // sizeof(TBase) + 0x18
};

}  // namespace wh::databasemodule
