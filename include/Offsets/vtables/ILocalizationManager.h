#pragma once
#include "CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// ILocalizationManager — KCD2 binary vtable order
// -----------------------------------------------
// Target: WHGame.dll 1.5.6 (build "release_1_5_1308617_856"), base 0x180000000.
// RTTI: .?AUILocalizationManager@@. Concrete CLocalizedStringsManager primary vtable
// 0x183DBDFA0; abstract interface vtable 0x183DBE0F8; 42 slots.
//
// The vendored CryCommon interface is not ABI-compatible with this build: KCD2 uses
// narrow CryStringT<char> outputs and a different binary slot order. The two
// LocalizeString overloads are deliberately de-overloaded here because MSVC reverses
// adjacent same-name virtual overloads.

namespace Offsets {

class ILocalizationManager {
public:
    virtual void _vf0(char flags) = 0;                                  // [0]   0x000  scalar-deleting dtor
    virtual void _vf1() = 0;                                             // [1]   0x008
    virtual void _vf2() = 0;                                             // [2]   0x010
    virtual void _vf3() = 0;                                             // [3]   0x018
    virtual void _vf4() = 0;                                             // [4]   0x020
    virtual void _vf5() = 0;                                             // [5]   0x028
    virtual void _vf6() = 0;                                             // [6]   0x030
    virtual void _vf7() = 0;                                             // [7]   0x038
    virtual void _vf8() = 0;                                             // [8]   0x040
    virtual void _vf9() = 0;                                             // [9]   0x048
    virtual bool SetLanguage(const char* language) = 0;                  // [10]  0x050  0x1809EB330
    virtual const char* GetLanguage() = 0;                               // [11]  0x058  0x1809EAF50
    virtual void _vf12() = 0;                                            // [12]  0x060
    virtual void _vf13() = 0;                                            // [13]  0x068
    virtual void _vf14() = 0;                                            // [14]  0x070
    virtual void _vf15() = 0;                                            // [15]  0x078
    virtual void _vf16() = 0;                                            // [16]  0x080
    virtual void _vf17() = 0;                                            // [17]  0x088
    virtual void _vf18() = 0;                                            // [18]  0x090
    virtual void _vf19() = 0;                                            // [19]  0x098
    virtual void _vf20() = 0;                                            // [20]  0x0A0
    virtual bool LocalizeCryString(const CryStringT<char>& text,
                                   CryStringT<char>& output,
                                   bool english = false) = 0;             // [21]  0x0A8  0x18051D2B4
    virtual bool LocalizeString(const char* text, CryStringT<char>& output,
                                bool english = false) = 0;                // [22]  0x0B0  0x18242F230
    virtual bool LocalizeLabel(const char* label, CryStringT<char>& output,
                               bool english = false) = 0;                 // [23]  0x0B8  0x18051D468
    virtual void _vf24() = 0;                                            // [24]  0x0C0
    virtual void _vf25() = 0;                                            // [25]  0x0C8
    virtual void _vf26() = 0;                                            // [26]  0x0D0
    virtual void _vf27() = 0;                                            // [27]  0x0D8
    virtual void _vf28() = 0;                                            // [28]  0x0E0
    virtual void _vf29() = 0;                                            // [29]  0x0E8
    virtual void _vf30() = 0;                                            // [30]  0x0F0
    virtual void _vf31() = 0;                                            // [31]  0x0F8
    virtual void _vf32() = 0;                                            // [32]  0x100
    virtual void _vf33() = 0;                                            // [33]  0x108
    virtual void _vf34() = 0;                                            // [34]  0x110
    virtual void _vf35() = 0;                                            // [35]  0x118
    virtual void _vf36() = 0;                                            // [36]  0x120
    virtual void _vf37() = 0;                                            // [37]  0x128
    virtual void _vf38() = 0;                                            // [38]  0x130
    virtual void _vf39() = 0;                                            // [39]  0x138
    virtual void _vf40() = 0;                                            // [40]  0x140
    virtual void _vf41() = 0;                                            // [41]  0x148
};
static_assert(sizeof(ILocalizationManager) == 0x8);

}  // namespace Offsets
