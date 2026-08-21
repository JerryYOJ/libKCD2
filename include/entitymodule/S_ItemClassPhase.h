#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::S_ItemClassPhase -- element of S_PickableItemClass::m_phases.
// sizeof 0x28. vtable 0x183B3D320. KCD2 1.5.6 (kd7u).
// -----------------------------------------------
// RTTI .?AUS_ItemClassPhase@entitymodule@wh@@; RTTR "wh::entitymodule::Phase" (element
// registrar 0x1801417B0 names all four fields; dual-verifier 2026-08-21). No scalar ctor --
// MSVC inlined the default into the vector construct-n 0x1812383D0 (empty strings,
// KeepModelLoaded = TRUE). copy 0x182A1C978, dtor 0x182A1CF30 / deleting 0x182A1E2A0.
// XML <Phase Order=".."> is a 1-based serializer index with NO slot in this record
// (sort-on-load vs document order UNVERIFIED).

namespace wh::entitymodule {

class S_ItemClassPhase {
public:
    virtual ~S_ItemClassPhase() = default;       // [0]  vtable 0x183B3D320 (then RTTR trio [1..3])

    CryStringT<char> m_model;                    // +0x08  RTTR "Model"
    CryStringT<char> m_material;                 // +0x10  RTTR "Material" (optional; e.g. burned MTL, editor/nodraw)
    CryStringT<char> m_attachmentName;           // +0x18  RTTR "AttachmentName" (optional)
    bool             m_keepModelLoaded;          // +0x20  RTTR "KeepModelLoaded"  default TRUE (XML only ever sets false)
    std::uint8_t     _pad21[7];                  // +0x21
};
static_assert(sizeof(S_ItemClassPhase) == 0x28, "S_ItemClassPhase must be 0x28");
static_assert(offsetof(S_ItemClassPhase, m_model) == 0x08, "phase model at 0x08");
static_assert(offsetof(S_ItemClassPhase, m_keepModelLoaded) == 0x20, "keep-model-loaded at 0x20");

}  // namespace wh::entitymodule
