#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::NPCState::S_AnimItemAttachmentRecord -- element of
// C_AnimActionBase::m_itemAttachmentRecords (+0x168). stride 0x24.
// (KCD2 WHGame.dll Steam 1.5.6.) [UNKNOWN spelling; stride + lead dwords proven]
// -----------------------------------------------
// Cleanup 0x18186472C consumes (id, slotKind); payload forwarded to 0x1820BF1F0.
// slotKind mapping 0x1808FA2AC: 0->0, 1->1, else 2.

namespace wh::xgenaimodule::NPCState {

struct S_AnimItemAttachmentRecord {
    std::uint32_t id;              // +0x00
    std::uint32_t slotKind;        // +0x04
    std::uint8_t  payload[0x1C];   // +0x08 pending field tracing
};
static_assert(sizeof(S_AnimItemAttachmentRecord) == 0x24,
              "S_AnimItemAttachmentRecord size mismatch");

}  // namespace wh::xgenaimodule::NPCState
