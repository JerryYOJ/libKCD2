#pragma once
#include <cstdint>
#include "C_ObjectDatabaseBase.h"
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::databasemodule::C_ObjectTreeDatabaseList<TObject> -- MIRROR of the
// binary's C_ObjectTreeDatabase<TObject, std::list> instantiation (KCD2
// WHGame.dll 1.5.6, kd7u).  Subobject size 0x70 (list variant is 8 smaller
// than the vector variant's 0x78).
// -----------------------------------------------
// NOT a distinct binary class: the real template is
// C_ObjectTreeDatabase<Row, Container>; this repo's C_ObjectTreeDatabase.h
// mirror collapsed the container parameter to the std::vector shape, so the
// std::list instantiation (sole user: xgenaimodule::C_SmartEntityDatabase,
// base ctor sub_181977C80) gets this sibling mirror.  Row store @+0x30 is a
// std::list (0x10: _Myhead sentinel node = 0x10 + sizeof(TObject), _Mysize);
// the tree strings/flags shift down 8 vs the vector variant.

namespace wh::databasemodule {

template <typename TObject>
class C_ObjectTreeDatabaseList : public C_ObjectDatabaseBase {
public:
    void*            m_rowsHead;    // +0x30  std::list _Myhead (node = 0x10 + sizeof(TObject))
    uint64_t         m_rowsSize;    // +0x38  std::list _Mysize
    CryStringT<char> m_namespace;   // +0x40
    CryStringT<char> m_name;        // +0x48
    CryStringT<char> m_group;       // +0x50
    uint8_t          m_loaded;      // +0x58  vtable slot [6] returns it
    uint8_t          _pad59[7];     // +0x59
    void*            m_pRoot;       // +0x60  reg handle (sub_1803F7FAC)
    uint64_t         m_unk68;       // +0x68  ctor 0 [role UNVERIFIED]
};
static_assert(sizeof(C_ObjectTreeDatabaseList<int>) == 0x70,
              "list-variant tree DB subobject must be 0x70");

}  // namespace wh::databasemodule
