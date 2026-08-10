#pragma once

// wh::databasemodule::C_ObjectDatabaseKeyMultiIndexed<TBase, TIndexContainer> -- multi-key index.

namespace wh::databasemodule {

template <typename TBase, typename TIndexContainer>
class C_ObjectDatabaseKeyMultiIndexed : public TBase {
public:
    bool RebuildIndices() override;  // [16] clears and repopulates every key/value pair

    TIndexContainer m_index;
};

}  // namespace wh::databasemodule
