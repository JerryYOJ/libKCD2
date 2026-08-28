#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::guimodule::E_ChoiceName -- KCD2 WHGame.dll 1.5.6 (kd7u).  Enum wrapper, Type : uint8.
// -----------------------------------------------
// Nested-Type enum wrapper (rttr property mangling `W4Type@E_ChoiceName@guimodule@wh@@`).
// Identity key of C_UIMenuChoice (byte @element+0x08; C_MenuChoiceDatabase's
// DefaultKeyExtractor keys on it; runtime sorted-vector DB @0x185326760, 0x20 rows,
// lookup sub_181569B00 -- consumed by AddChoiceOption-by-label sub_181F8BA20).
// Exact 39-entry label/value table and unsigned-byte underlying type are
// recovered from the RTTR registration. The shipped typo Unvailable is preserved.

namespace wh::guimodule {

struct E_ChoiceName {
    enum Type : std::uint8_t {
        Invalid                   = 0,
        Yes                       = 1,
        No                        = 2,
        Off                       = 3,
        On                        = 4,
        Unvailable                = 5,
        Custom                    = 6,
        Low                       = 7,
        Medium                    = 8,
        High                      = 9,
        VeryHigh                  = 10,
        UltraHigh                 = 11,
        Camera                    = 12,
        CameraObject              = 13,
        Fullscreen                = 14,
        Window                    = 15,
        Fsr                       = 16,
        Sgsr                      = 17,
        Dlss                      = 18,
        DlssConvolutional         = 19,
        DlssTransformer           = 20,
        XeSS                      = 21,
        ConsoleModeFidelity       = 22,
        ConsoleModePerformance    = 23,
        Quality                   = 24,
        Balanced                  = 25,
        Performance               = 26,
        NativeAA                  = 27,
        Small                     = 28,
        Default                   = 29,
        Large                     = 30,
        UltraLarge                = 31,
        InvertNever               = 32,
        InvertAlways              = 33,
        InvertExceptCombat        = 34,
        Automatic                 = 35,
        Manual                    = 36,
        PS                        = 37,
        XBOX                      = 38,
    };
};
static_assert(sizeof(E_ChoiceName::Type) == 1,
              "E_ChoiceName::Type size mismatch");

}  // namespace wh::guimodule
