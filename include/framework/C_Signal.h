#pragma once
#include <cstdint>
#include "../REL/Relocation.h"

// -----------------------------------------------
// wh::shared::C_Signal<...> -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x10 (non-polymorphic POD).
// -----------------------------------------------
// A signal head embedded by value in its owner (e.g. ~22 heads inside C_CombatActor from +0x38).
//
// [FUNDAMENTAL vs KCD1] De-virtualized and shrunk. KCD1 C_Signal was polymorphic (0x30: virtual
// dtor + inline std::vector<S_Delegate> + a sorted S_SortedConnectionEntry list). KCD2 is a 0x10
// POD: a single pointer to a header-prefixed relocatable delegate array plus two int16 cursors.
//
// [FAMILY MODEL] The original was a header-inline template; each Args-signature instantiation
// family references its OWN statics (empty sentinel, reserve/erase helpers), so ICF cannot fold
// the per-family Connect/Disconnect bodies -- every family keeps its own twin addresses. Emit
// MAY still fold across marshal-identical families (extra emit xrefs observed on the <unsigned>
// twin); calling a folded Emit is safe since the marshaling is identical by construction. Only
// the Args-agnostic store helper 0x182420480 (pair[0]->entry+0, pair[1]->entry+8) is shared by
// ALL families. The engine calls below therefore go through S_SignalFamily<Args...>, an RE
// bookkeeping traits table (NOT original source) holding the certified per-family REL::IDs;
// its primary template is intentionally undefined, so using a twin on an uncertified family is
// a compile error, never a wrong-family call. NOTE: many headers type placeholder members as
// C_Signal<> ("Args unknown") -- layout-safe (the head is Args-independent), but twins must
// never be reached through placeholder typing; certify the true Args first.
//
// [EMIT WALK -- brew twin instruction-verified 2026-07-18; re-verified 2026-08-23 on the
// <unsigned> twin 0x1806C3338] Emit claims the FIRST idle cursor (0xFFFF scan over +0x08/+0x0A;
// a THIRD nested emit falls through to slot 0 and clobbers cursor0 -- the engine contract is
// max 2 nested emits), then walks NEWEST -> OLDEST: at index i it stores i-1 into the claimed
// cursor BEFORE invoking entry[i] and RE-READS that cursor after the callback returns as the
// next index (negative stops; the cursor is released to 0xFFFF on exit). The re-read makes
// mid-emit Disconnect safe and lets a callback stop the remaining walk by writing -1. The
// entry-array BASE is re-loaded from the head on every iteration (0x1806C33A6 `mov rcx,[rbx]`
// inside the loop) -- a Connect that reallocates the array mid-emit is equally safe, and
// entries appended during a walk are NOT invoked by it (the walk follows the stored i-1 and
// never re-reads count).
//
// [ERASE IS PER-FAMILY] The brew family's erase 0x18173238C shrinks strictly in place; the
// <unsigned> family's erase 0x1809F736C may REALLOCATE on shrink (grow 0x1809F75C0). "Shrink
// never reallocates" was a brew-family observation, not a class invariant.
//
// [CORRECTED ATTRIBUTIONS 2026-08-23] sub_180C57A1C is the Connect twin of the
// <I_CombatActor&,I_CombatActor&,bool> family (reached by C_CombatActor's per-signal vtable
// Connect thunks, slots ~109-174), NOT a universal Connect. sub_18119E00C is a bespoke
// C_Player recipe-GUI cleanup (hardcoded heads +0xA70/+0xA80 and invoke thunks; 1-arg family),
// NOT a generic Disconnect twin -- it only evidences the 2-cursor decrement rule. Owner dtors
// tear lists down by resize(0) + free of the old pool (e.g. C_Alchemy dtor 0x180FC0BA8).

namespace wh::entitymodule { class C_Item; }
namespace wh::combatmodule { class I_CombatActor; }

namespace wh::shared {

// One subscriber: an instance ("this") plus its bound free-function pointer. Field ORDER
// {instance @+0, invoke @+8} is proven by the delegate index-writer sub_182420480 (stores a3[0]
// -> entry+0, a3[1] -> entry+8) and the subscribe helper sub_180EC8510 (round-3 verify pass).
template<typename... Args>
struct S_Delegate {
    void*  m_pInstance;                  // +0x00
    void (*m_pInvoke)(void*, Args...);   // +0x08

    void operator()(Args... args) const { m_pInvoke(m_pInstance, args...); }
    bool operator==(const S_Delegate& o) const { return m_pInstance == o.m_pInstance && m_pInvoke == o.m_pInvoke; }
    bool operator!=(const S_Delegate& o) const { return !(*this == o); }
};
static_assert(sizeof(S_Delegate<>) == 0x10);

// Certified per-family engine twins (see the certified block after C_Signal). Intentionally
// UNDEFINED primary: specialize only with instruction-verified IDs.
template<typename... Args>
struct S_SignalFamily;

// The subscriber list: a single pointer to Entry[] whose 8-byte header sits BEFORE the data --
//   [m_connections-8] uint32 capacity   [m_connections-4] uint32 count   [m_connections+0] Entry[]
// with Entry stride 0x10. While empty, m_connections points at the family's zero-filled static
// sentinel (capacity == count == 0). This is CryEngine-style header-prefixed relocatable
// storage -- NOT a std::vector, boost container, or the KCD1 {begin,end,cap} triple.
template<typename... Args>
struct C_Signal {
    using Entry = S_Delegate<Args...>;

    // The two int16 cursors are in-flight emit iterators supporting up to 2 NESTED emits
    // (see the emit-walk banner). Both init -1 (idle).
    Entry*   m_connections;   // +0x00  -> Entry[] (header-prefixed; family empty sentinel while idle)
    int16_t  m_emitCursor0;   // +0x08  outer emit cursor, -1 == idle
    int16_t  m_emitCursor1;   // +0x0A  nested emit cursor, -1 == idle
    uint8_t  _pad0C[4];       // +0x0C  alignment to 0x10

    // Header reads: valid for the empty sentinel too (its header is zero-filled).
    uint32_t Count() const    { return reinterpret_cast<const uint32_t*>(m_connections)[-1]; }
    uint32_t Capacity() const { return reinterpret_cast<const uint32_t*>(m_connections)[-2]; }

    // Linear scan by invoke fn (the entries have no index -- Disconnect scans exactly like this).
    Entry* Find(void (*pInvoke)(void*, Args...)) {
        for (uint32_t i = 0, n = Count(); i < n; ++i)
            if (m_connections[i].m_pInvoke == pInvoke)
                return &m_connections[i];
        return nullptr;
    }

    // ---- engine calls through the family twins. Lazy instantiation is the certification
    // gate: an uncertified family (or a family missing that twin) fails to COMPILE only when
    // the method is actually used. ----

    // De-dups by {instance, invoke}, then appends a BY-VALUE copy (empty list: reserve 5
    // first). Safe mid-emit: the walk re-reads the array base and never visits new entries.
    void Connect(const Entry& entry) {
        using Fn = void (*)(C_Signal*, const Entry*);
        static REL::Relocation<Fn> fn{ S_SignalFamily<Args...>::kConnect };
        fn(this, &entry);
    }

    // Typed subscriber: engine still stores {void*, invoke}; T* is ABI-identical to void*.
    template<typename T>
    void Connect(T* instance, void (*invoke)(T*, Args...)) {
        Connect(Entry{ instance, reinterpret_cast<void (*)(void*, Args...)>(invoke) });
    }

    // Linear {instance, invoke} find; fixes BOTH emit cursors (idx <= cursor -> --cursor)
    // before erasing. Safe mid-emit.
    void Disconnect(const Entry& entry) {
        using Fn = void (*)(C_Signal*, const Entry*);
        static REL::Relocation<Fn> fn{ S_SignalFamily<Args...>::kDisconnect };
        fn(this, &entry);
    }

    template<typename T>
    void Disconnect(T* instance, void (*invoke)(T*, Args...)) {
        Disconnect(Entry{ instance, reinterpret_cast<void (*)(void*, Args...)>(invoke) });
    }

    // Fires newest -> oldest under the nested-emit cursor protocol (max 2 nested emits).
    void Emit(Args... args) {
        using Fn = void (*)(C_Signal*, Args...);
        static REL::Relocation<Fn> fn{ S_SignalFamily<Args...>::kEmit };
        fn(this, args...);
    }
};
static_assert(sizeof(C_Signal<>) == 0x10);

// -----------------------------------------------
// Certified families (every ID cross-checked against the address library, 2026-08-23).
// -----------------------------------------------

// C_Signal<unsigned> -- the activity-objective family (C_ActivityObjective::m_onComplete +0x08,
// fired with the objective result code by the completion funnel 0x1809F62F4; by type identity
// every C_Signal<uint32_t> head resolves here too, e.g. C_Hole::m_diggingEventSignal +0x40).
// Empty sentinel 0x18566C040 (planted by the C_DogObjective ctor 0x1806265D8).
template<>
struct S_SignalFamily<unsigned> {
    static constexpr REL::ID kConnect{54736};     // 0x1809F740C  dedup+reserve+append (store 0x182420480)
    static constexpr REL::ID kDisconnect{54737};  // 0x1809F74B0  find + 2-cursor fixup + erase 0x1809F736C
    static constexpr REL::ID kEmit{37742};        // 0x1806C3338  cursor-claim walk; fn(instance, unsigned)
};

// C_Signal<char, C_Item*, uint32_t> -- the brew-result family (C_Alchemy::m_onBrewResult
// +0x68). Args register-proven at the invoke site 0x182E15492 (RCX=instance DL=char R8=C_Item*
// R9D=u32). Empty sentinel 0x185669440. NO kDisconnect: the engine's 0x181732108 (id 134142)
// is not the generic (head, entry) ABI -- it takes the raw C_Alchemy* with +0x68 baked in and
// decodes the delegate through 0x1805F5DA0; it must not be called through this surface.
template<>
struct S_SignalFamily<char, entitymodule::C_Item*, uint32_t> {
    static constexpr REL::ID kConnect{134144};    // 0x1817321AC  reserve 0x1817322DC, alloc 0x180396724
    static constexpr REL::ID kEmit{375516};       // 0x182E15404  raised by GradeBrew 0x182E16680
};

// C_Signal<I_CombatActor&, I_CombatActor&, bool> -- combat mode/zone-change family
// (C_CombatActor::m_onCombatModeChange +0x58, m_onCombatZoneChange +0x68). [MED confidence:
// family pinned by 4/4 sampled invoke targets (instance + ref + ref + bool) plus the member
// typing. Disconnect/Emit twins not yet located.]
template<>
struct S_SignalFamily<combatmodule::I_CombatActor&, combatmodule::I_CombatActor&, bool> {
    static constexpr REL::ID kConnect{66316};     // 0x180C57A1C  reserve 0x180C57AC0, shared store 0x182420480
};

}  // namespace wh::shared
