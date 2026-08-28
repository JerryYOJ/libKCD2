#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Counter.h"

// -----------------------------------------------
// wh::rpgmodule::C_Counter : I_Counter
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20; vtable 0x183A7AC68 (22 slots).
// -----------------------------------------------
// MSVC CHD 0x184404B08: public I_Counter at mdisp=0. RTTR base builder is
// empty; the destructor still installs I_Counter vtable 0x183F4D388 after
// tearing down +0x08. RTTR_ENABLE(I_Counter) overrides the trio at [12..14].
// Slot 7 stays pure. +0x18 pointee type is unverified.

namespace wh::rpgmodule {

class C_Counter : public I_Counter {
public:
    struct S_NotifyStack {
        void* m_pairsTable;                               // +0x00 DynArray-style pairs
        std::uint16_t m_cursors[2];                       // +0x08
        std::uint8_t _pad0C[4];                           // +0x0C
    };
    static_assert(sizeof(S_NotifyStack) == 0x10,
                  "C_Counter::S_NotifyStack size mismatch");

    ~C_Counter() override;                                // [0] 0x182D4DA74
    std::uint32_t unk_01() override;                      // [1] 0x181A94E40
    void* unk_02() override;                              // [2] 0x1809DC250
    void* unk_03() override;                              // [3] 0x180C58C60
    void* unk_04() override;                              // [4] 0x181A94F00
    std::uint32_t unk_05() override;                      // [5] 0x181A94F10
    std::uint32_t unk_06() override;                      // [6] 0x180EFA590
    double unk_08() override;                             // [8] 0x180EFA580
    bool unk_09() override;                               // [9] 0x18041A6A0
    void unk_10(void* pair) override;                     // [10] 0x180EF9E54
    void unk_11(void* pair) override;                     // [11] 0x180EF9DD0
    RTTR_ENABLE(I_Counter)                                // [12..14]
    virtual void unk_15() = 0;                            // [15]
    virtual void unk_16();                                // [16] nullsub_1
    virtual void unk_17();                                // [17] nullsub_1
    virtual void unk_18();                                // [18] nullsub_1
    virtual void unk_19() = 0;                            // [19]
    virtual void unk_20();                                // [20] 0x182D4F600 notify walk
    virtual void unk_21(void* out);                       // [21] 0x182D4E4BC debug format

    S_NotifyStack m_changedNotify;                        // +0x08
    void* m_unknown18;                                    // +0x18 descriptor; type unverified
};

static_assert(offsetof(C_Counter, m_changedNotify) == 0x08,
              "C_Counter::m_changedNotify offset mismatch");
static_assert(offsetof(C_Counter, m_unknown18) == 0x18,
              "C_Counter::m_unknown18 offset mismatch");
static_assert(sizeof(C_Counter) == 0x20,
              "C_Counter size mismatch");

}  // namespace wh::rpgmodule
