#pragma once

// wh::databasemodule::C_ObjectTreeDatabaseKeyIndexed<TBase, TIndexContainer> -- unique tree index.

namespace wh::databasemodule {

template <typename TBase, typename TIndexContainer>
class C_ObjectTreeDatabaseKeyIndexed : public TBase {
public:
    bool RebuildIndices() override;  // [16] later duplicate keys overwrite the mapped value

    TIndexContainer m_index;
};

}  // namespace wh::databasemodule
