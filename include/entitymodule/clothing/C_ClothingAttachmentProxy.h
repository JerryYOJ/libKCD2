#pragma once
#include <cstddef>
#include <cstdint>
#include "S_ClothingAttachmentDesc.h"
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/rttr_enable.h"

struct IAttachment;

// -----------------------------------------------
// wh::entitymodule::clothing::C_ClothingAttachmentProxy -- streamed character
// attachment proxy (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x78,
// vtable 0x183E8B910 (7 slots).
// -----------------------------------------------
// Accessor disassembly proves Description at +0x08, StreamingState at +0x58,
// GameState at +0x59, and the setter behaviors. Remaining pointer roles are kept
// explicit but untyped where the pointee identity is not yet binary-certified.

namespace wh::entitymodule::clothing {

class C_ClothingAttachmentProxy {
public:
    struct E_GameState {
        enum Type : std::uint8_t {
            Show                = 0,
            Delete              = 1,
            DeleteIfNotReplaced = 2,
        };
    };

    struct E_StreamingState {
        enum Type : std::uint8_t {
            Init                     = 0,
            Loading                  = 1,
            Streaming                = 2,
            WaitingForSwapToStreamed = 3,
            Error                    = 4,
        };
    };

    virtual ~C_ClothingAttachmentProxy();             // [0] 0x180975960
    virtual bool IsLoaded() const;                     // [1] 0x182917B74, behavior-derived name
    virtual CryStringT<char> GetMaterialPath() const;  // [2] 0x180AB97D8, behavior-derived name
    virtual void Reset();                              // [3] 0x1829186EC -> 0x180975A88, behavior-derived name
    RTTR_ENABLE()                                      // [4..6], get_type 0x18291FB34

    S_ClothingAttachmentDesc m_description;           // +0x08 RTTR getter returns this+0x08
    void* m_streamingContext;                          // +0x40 owning pointer, custom destruction
    void* m_ownerContext;                              // +0x48 constructor arg; exact pointee unverified
    IAttachment* m_attachment;                         // +0x50 AddRef/Release slot pattern
    E_StreamingState::Type m_streamingState;           // +0x58 RTTR getter/setter
    E_GameState::Type m_gameState;                     // +0x59 RTTR getter/setter
    std::uint8_t _pad5A[6];                           // +0x5A
    void* m_streamRequest;                             // +0x60 released through vslot 2; pointee unverified
    std::uint64_t m_stateHandles[2];                   // +0x68 two 8-byte elements, low word zero-initialized
};

static_assert(sizeof(C_ClothingAttachmentProxy::E_GameState::Type) == 1,
              "C_ClothingAttachmentProxy::E_GameState::Type size mismatch");
static_assert(sizeof(C_ClothingAttachmentProxy::E_StreamingState::Type) == 1,
              "C_ClothingAttachmentProxy::E_StreamingState::Type size mismatch");
static_assert(offsetof(C_ClothingAttachmentProxy, m_description) == 0x08,
              "C_ClothingAttachmentProxy::m_description offset mismatch");
static_assert(offsetof(C_ClothingAttachmentProxy, m_streamingState) == 0x58,
              "C_ClothingAttachmentProxy::m_streamingState offset mismatch");
static_assert(offsetof(C_ClothingAttachmentProxy, m_streamRequest) == 0x60,
              "C_ClothingAttachmentProxy::m_streamRequest offset mismatch");
static_assert(sizeof(C_ClothingAttachmentProxy) == 0x78,
              "C_ClothingAttachmentProxy size mismatch");

}  // namespace wh::entitymodule::clothing
