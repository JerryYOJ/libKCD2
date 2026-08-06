#pragma once
#include <string>
#include "C_Node.h"
#include "CryEngine/CryCommon/CryString.h"
#include "rttr/type.h"

// -----------------------------------------------
// wh::conceptmodule::C_ObjectProperties -- generic "read an object's properties"
// node (KCD2 WHGame.dll Steam 1.5.6).
// -----------------------------------------------
// One node class that adapts to whatever type it is pointed at: the reflected
// property "DeclaringType" (rttr name "wh::conceptmodule::ObjectProperties",
// registered by sub_1800895D0) selects the type, and the node then exposes that
// type's properties as data output pins. The editor's authored instance
// I_SoulProperties is just this class with DeclaringType = wh::rpgmodule::I_Soul;
// the definition builder 0x18106FD84 forms that display name by appending
// "Properties" to m_declaringTypeName.
//
// Base is C_Node [PROVEN]: rttr registers _smart_ptr<C_ObjectProperties> <->
// _smart_ptr<C_Node> converters (0x184ABAEE0 / 0x184ABAF90) and no
// C_TemplatedNode converter, matching that the node takes no TypeT.
//
// DeclaringType is registered with BOTH a getter and a setter -- the property
// wrapper's own decorated name (0x184ABE090) spells the pair out:
//   std::string (C_ObjectProperties::*)(void)      getter 0x1826B9DD4
//   void       (C_ObjectProperties::*)(std::string) setter 0x18106FFF4
// The getter is the SAME function C_TemplatedNode uses for TypeT, because both
// classes hold their rttr::type at +0x40.
//
// [UNVERIFIED] sizeof and any members past +0x48 -- only the two the setter and
// the definition builder touch are established, so no size assert is made here.
// No Offsets::RTTI_* constant exists for this class yet, so RTTI is not declared.

namespace wh::conceptmodule {

class C_ObjectProperties : public C_Node {
public:
    // 0x18106FFF4 = REL::ID(90074). Resolves `name` via the same registry lookup
    // SetTypeT uses (sub_1806A589C), stores it in m_declaringType, and derives
    // m_declaringTypeName from it. Unlike SetTypeT there is NO validity check and
    // NO OnTypeTSet-style callback -- an unknown name stores an invalid type
    // silently.
    void SetDeclaringType(std::string name);

    rttr::type       m_declaringType;      // +0x40  the type whose properties this node exposes
    CryStringT<char> m_declaringTypeName;  // +0x48  derived from m_declaringType by the setter
};
static_assert(offsetof(C_ObjectProperties, m_declaringType) == 0x40,
              "m_declaringType at 0x40 (setter 0x18107004D writes this+0x40)");
static_assert(offsetof(C_ObjectProperties, m_declaringTypeName) == 0x48,
              "m_declaringTypeName at 0x48 (setter 0x18107005D assigns this+0x48)");

}  // namespace wh::conceptmodule
