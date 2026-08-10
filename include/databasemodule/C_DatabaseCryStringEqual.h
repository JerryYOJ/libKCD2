#pragma once

template <typename T>
class CryStringT;

namespace wh::databasemodule {

// Stateless equality functor used by the database string pools. [SYNTHETIC NAME]
class C_DatabaseCryStringEqual {
public:
    bool operator()(const CryStringT<char>& lhs,
                    const CryStringT<char>& rhs) const noexcept;
};
static_assert(sizeof(C_DatabaseCryStringEqual) == 0x01,
              "database string equality must be stateless");

}  // namespace wh::databasemodule
