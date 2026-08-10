#pragma once
#include <cstddef>

struct CryGUID;

namespace wh::databasemodule {

// Stateless GUID hasher emitted in database multi-index RTTI.
class CryGUIDHasher {
public:
    std::size_t operator()(const CryGUID& value) const noexcept;
};
static_assert(sizeof(CryGUIDHasher) == 0x01, "CryGUIDHasher must be stateless");

}  // namespace wh::databasemodule
