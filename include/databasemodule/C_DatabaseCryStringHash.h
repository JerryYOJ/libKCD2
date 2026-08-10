#pragma once
#include <cstddef>

template <typename T>
class CryStringT;

namespace wh::databasemodule {

// Stateless hash functor used by the database string pools. [SYNTHETIC NAME]
class C_DatabaseCryStringHash {
public:
    std::size_t operator()(const CryStringT<char>& value) const noexcept;
};
static_assert(sizeof(C_DatabaseCryStringHash) == 0x01,
              "database string hash must be stateless");

}  // namespace wh::databasemodule
