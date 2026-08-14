#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryListenerSet.h"
#include "../framework/I_UIBook.h"
#include "C_PickableItem.h"
#include "E_DocumentBookKind.h"
#include "I_DocumentActionListener.h"

// -----------------------------------------------
// wh::entitymodule::C_DocumentItem -- readable-document item extension
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x178.
// -----------------------------------------------
// Creator 0x1812765B0 allocates 0x178 and calls ctor 0x181276680. The primary
// table extends C_PickableItem's 130 slots with slot [130]. Only the eight
// proved differences are redeclared below; every other slot is inherited.
// The document tail uses Warhorse's 4-byte member packing, which places the
// genuine CryGUID at +0x134. CListenerSet is the retail 0x28 representation.

namespace wh::entitymodule {

#pragma pack(push, 4)
class C_DocumentItem : public C_PickableItem {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DocumentItem;

    ~C_DocumentItem() override;                                  // [0] 0x1814C4BC4
    void ProcessEvent(SEntityEvent& event) override;             // [1] 0x180EC4290
    void PostInit(Offsets::IGameObject* gameObject) override;    // [8] 0x1808FD06C
    void Reset() override;                                       // [72] 0x1808FD120
    void _vf108() override;                                      // [108] 0x1808FD18C
    void _vf116() override;                                      // [116] 0x182A6A274, document close
    std::uint32_t _vf129() const override;                       // [129] 0x181A72480, Document=2
    virtual void _vf130();                                       // [130] nullsub_1, signature OPEN

    framework::I_UIBook* m_uiBook;                // +0xD8, borrowed
    std::uint32_t m_userId;                       // +0xE0, exact typedef OPEN
    std::uint32_t _padE4;                         // +0xE4
    CryStringT<char> m_unknownE8;                 // +0xE8, role OPEN

    bool m_nextPageAnimationActive;               // +0xF0
    bool m_previousPageAnimationActive;           // +0xF1
    bool m_pendingNextPageTurn;                   // +0xF2
    bool m_pendingPreviousPageTurn;               // +0xF3
    std::int32_t m_remainingPageDelta;            // +0xF4
    float m_pageTurnSpeedMultiplier;              // +0xF8
    bool m_openAnimationActive;                   // +0xFC
    bool m_closeAnimationActive;                  // +0xFD
    bool m_pendingClose;                          // +0xFE
    bool m_canTurnNextPage;                       // +0xFF
    bool m_canTurnPreviousPage;                   // +0x100
    bool m_viewModeTransitionActive;              // +0x101
    bool m_deferredViewModeToggle;                // +0x102
    std::uint8_t _pad103[5];                      // +0x103

    CryStringT<char> m_animPageNext;              // +0x108
    CryStringT<char> m_animPagePrevious;          // +0x110
    CryStringT<char> m_animOpen;                  // +0x118
    CryStringT<char> m_animClose;                 // +0x120
    float m_pageAnimationTransitionTime;          // +0x128
    bool m_suppressResetAfterClose;               // +0x12C
    bool m_useGuidPageNavigation;                 // +0x12D; false=numeric page, true=GUID page
    std::uint8_t _pad12E[2];                      // +0x12E
    std::uint32_t m_currentNumericPageId;         // +0x130
    CryGUID m_currentPageGuid;                    // +0x134
    std::uint32_t _pad144;                        // +0x144
    CListenerSet<I_DocumentActionListener*> m_documentActionListeners; // +0x148
    E_DocumentBookKind m_bookKind;                // +0x170
    std::uint8_t _pad171[7];                      // +0x171
};
#pragma pack(pop)

static_assert(sizeof(CListenerSet<I_DocumentActionListener*>) == 0x28,
              "retail CListenerSet must be 0x28");
static_assert(sizeof(C_DocumentItem) == 0x178,
              "C_DocumentItem must be 0x178");
static_assert(offsetof(C_DocumentItem, m_uiBook) == 0xD8,
              "UI book pointer must be at 0xD8");
static_assert(offsetof(C_DocumentItem, m_animPageNext) == 0x108,
              "page animation names must begin at 0x108");
static_assert(offsetof(C_DocumentItem, m_currentNumericPageId) == 0x130,
              "numeric page id must be at 0x130");
static_assert(offsetof(C_DocumentItem, m_currentPageGuid) == 0x134,
              "GUID page id must be at 0x134");
static_assert(offsetof(C_DocumentItem, m_documentActionListeners) == 0x148,
              "document listeners must be at 0x148");
static_assert(offsetof(C_DocumentItem, m_bookKind) == 0x170,
              "book kind byte must be at 0x170");

}  // namespace wh::entitymodule
