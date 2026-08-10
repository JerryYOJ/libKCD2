#pragma once

// wh::databasemodule::I_DatabaseListener -- destructor-only marker interface.
// Vtable 0x183E3D230, exactly one slot.

namespace wh::databasemodule {

class I_DatabaseListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_DatabaseListener;
    virtual ~I_DatabaseListener();  // [0] 0x182740E30
};
static_assert(sizeof(I_DatabaseListener) == 0x08,
              "I_DatabaseListener must contain one vtable pointer");

}  // namespace wh::databasemodule
