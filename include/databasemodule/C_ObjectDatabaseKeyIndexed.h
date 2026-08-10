#pragma once

// wh::databasemodule::C_ObjectDatabaseKeyIndexed<TBase, TExtractor> -- in-place key sort.
// TExtractor is stateless and is neither a base nor a stored member.

namespace wh::databasemodule {

template <typename TBase, typename TExtractor>
class C_ObjectDatabaseKeyIndexed : public TBase {
public:
    bool RebuildIndices() override;  // [16] sorts TBase::m_objects in place
};

}  // namespace wh::databasemodule
