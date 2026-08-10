#pragma once

// wh::databasemodule::S_DatabaseModuleSelfCell -- module-owned self-reference cell
// returned by I_DatabaseModule slot 26. [SYNTHETIC NAME]

namespace wh::databasemodule {

class C_DatabaseModule;

struct S_DatabaseModuleSelfCell {
    C_DatabaseModule* m_pModule;  // +0x00
};
static_assert(sizeof(S_DatabaseModuleSelfCell) == 0x08, "S_DatabaseModuleSelfCell must be 0x08");

}  // namespace wh::databasemodule
