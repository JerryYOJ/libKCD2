#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::shared::C_Signal<...> -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x10 (non-polymorphic POD).
// -----------------------------------------------
// A signal head embedded by value in its owner (e.g. ~22 heads inside C_CombatActor from +0x38).
//
// [FUNDAMENTAL vs KCD1] De-virtualized and shrunk. KCD1 C_Signal was polymorphic (0x30: virtual
// dtor + inline std::vector<S_Delegate> + a sorted S_SortedConnectionEntry list). KCD2 is a 0x10
// POD: a single pointer to a header-prefixed relocatable delegate array plus two int16 guards.
// [FUNDAMENTAL vs KCD1] Connections are bare S_Delegate (0x10, no per-entry slot); Connect
// (sub_180C57A1C) de-dups by {instance, invoke} and appends. Per-signal Connect thunks now live in
// the owner's vtable (e.g. C_CombatActor slots ~109-174), forwarding into C_Signal::Connect.

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

// The subscriber list: a single pointer to Entry[] whose 8-byte header sits BEFORE the data --
//   [m_connections-8] uint32 capacity   [m_connections-4] uint32 count   [m_connections+0] Entry[]
// with Entry stride 0x10. While empty, m_connections points at a shared zero-filled static sentinel
// (capacity == count == 0). This is CryEngine-style header-prefixed relocatable storage -- NOT a
// std::vector, boost container, or the KCD1 {begin,end,cap} triple.
template<typename... Args>
struct C_Signal {
    using Entry = S_Delegate<Args...>;

    // The two int16 cursors are in-flight emit iterators supporting up to 2 NESTED emits:
    // disconnect (sub_18119E00C) decrements a run of exactly 2 int16 slots at +0x08 when a
    // listener below the cursor is erased mid-emit. Both init -1 (idle).
    Entry*   m_connections;   // +0x00  -> Entry[] (header-prefixed; shared empty sentinel while idle)
    int16_t  m_emitCursor0;   // +0x08  outer emit cursor, -1 == idle
    int16_t  m_emitCursor1;   // +0x0A  nested emit cursor, -1 == idle
    uint8_t  _pad0C[4];       // +0x0C  alignment to 0x10
};
static_assert(sizeof(C_Signal<>) == 0x10);

}  // namespace wh::shared
