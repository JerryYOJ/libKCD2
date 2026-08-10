#pragma once

namespace wh::databasemodule {

// Stateless compile-time policy. The inlined callable spelling is not emitted.
template <typename TObject>
class C_ObjectDatabaseDefaultKeyExtractor {
};

}  // namespace wh::databasemodule
