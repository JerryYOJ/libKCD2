#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::clothing::S_ClothingAttachmentDesc -- clothing attachment
// descriptor (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x38.
// -----------------------------------------------
// AttachmentName is an exact RTTR member. Copy/destructor disassembly proves two
// shared-pointer-shaped fields; their pointee types and the remaining scalar roles
// are not yet identified and are named honestly.

namespace wh::entitymodule::clothing {

struct S_ClothingAttachmentDesc {
    CryStringT<char> m_attachmentName;    // +0x00 RTTR "AttachmentName"
    std::uint64_t m_unknown08;            // +0x08 copied as one qword
    std::shared_ptr<void> m_unknown10;    // +0x10 copied/released as shared pointer
    std::shared_ptr<void> m_unknown20;    // +0x20 copied/released as shared pointer
    std::uint32_t m_unknown30;            // +0x30 copied as one dword
    std::uint8_t _pad34[4];              // +0x34
};

static_assert(offsetof(S_ClothingAttachmentDesc, m_attachmentName) == 0x00,
              "S_ClothingAttachmentDesc::m_attachmentName offset mismatch");
static_assert(offsetof(S_ClothingAttachmentDesc, m_unknown20) == 0x20,
              "S_ClothingAttachmentDesc::m_unknown20 offset mismatch");
static_assert(sizeof(S_ClothingAttachmentDesc) == 0x38,
              "S_ClothingAttachmentDesc size mismatch");

}  // namespace wh::entitymodule::clothing
