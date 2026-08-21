#pragma once
#include "I_ItemDescriptor.h"

// -----------------------------------------------
// wh::entitymodule::C_HomogenousItemDescriptor -- mid-chain descriptor base (KCD2 1.5.6, kd7u).
// sizeof 0x08 (adds nothing).
// -----------------------------------------------
// RTTI .?AVC_HomogenousItemDescriptor@entitymodule@wh@@ (RTTR "HomogenousItemDescriptor",
// sizeof 8; type_data 0x1817B4C58). Never instantiated most-derived; contributes no data and
// no new vtable slots between I_ItemDescriptor and C_ItemPropertyDescriptor.

namespace wh::entitymodule {

class C_HomogenousItemDescriptor : public I_ItemDescriptor {
public:
    // No own data; abstract mid-class.
};

}  // namespace wh::entitymodule
