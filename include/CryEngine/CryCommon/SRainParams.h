#pragma once
#include <cstddef>
#include <cstdint>

// KCD2 1.5.6 scene-rain parameters. The checked-in stock I3DEngine.h carries
// an older, smaller revision; this layout follows the retail binary.
struct alignas(16) SRainParams {
    Matrix44 matOccTrans = IDENTITY;       // +0x00
    Matrix44 matOccTransRender = IDENTITY; // +0x40
    Quat qRainRotation = IDENTITY;         // +0x80
    AABB areaAABB = AABB::RESET;           // +0x90
    Vec3 vWorldPos{};                      // +0xA8
    Vec3 vColor{};                         // +0xB4

    float fAmount{};                       // +0xC0
    float fCurrentAmount{};                // +0xC4
    float fRadius{};                       // +0xC8
    std::uint32_t _unknownCC;              // +0xCC, role OPEN; native ctor leaves untouched
    float fFakeGlossiness{};               // +0xD0
    float fFakeReflectionAmount{};         // +0xD4
    float fDiffuseDarkening{};             // +0xD8
    float fRainDropsAmount{};              // +0xDC
    float fRainDropsSpeed{};               // +0xE0
    float fPreviousRainDropsSpeed{};       // +0xE4, canonical spelling OPEN
    float fRainDropsLighting{};            // +0xE8
    float fMistAmount{};                   // +0xEC
    float fMistHeight{};                   // +0xF0
    float fPuddlesAmount{};                 // +0xF4
    float fPuddlesMaskAmount{};             // +0xF8
    float fPuddlesRippleAmount{};           // +0xFC
    float fSplashesAmount{};                // +0x100

    std::int32_t nUpdateFrameID{-1};        // +0x104
    bool bApplyOcclusion{};                 // +0x108
    bool bIgnoreVisareas{};                 // +0x109
    bool bDisableOcclusion{};               // +0x10A
    bool bApplySkyColor{};                  // +0x10B
    float fSkyColorWeight{0.5F};            // +0x10C
    std::int32_t _unknown110{-1};           // +0x110, KCD2-private role OPEN
    float _unknown114{32.0F};               // +0x114, KCD2-private role OPEN
    // +0x118..+0x11F is implicit 16-byte-alignment tail padding. The native
    // constructor leaves those bytes untouched.
};

static_assert(sizeof(SRainParams) == 0x120,
              "KCD2 binary SRainParams must be 0x120");
static_assert(alignof(SRainParams) == 0x10,
              "SRainParams must remain 16-byte aligned");
static_assert(offsetof(SRainParams, vWorldPos) == 0xA8,
              "rain world position must be at 0xA8");
static_assert(offsetof(SRainParams, fAmount) == 0xC0,
              "rain amount must be at 0xC0");
static_assert(offsetof(SRainParams, fFakeGlossiness) == 0xD0,
              "fake glossiness must be at 0xD0");
static_assert(offsetof(SRainParams, fRainDropsLighting) == 0xE8,
              "rain-drop lighting must be at 0xE8");
static_assert(offsetof(SRainParams, nUpdateFrameID) == 0x104,
              "rain update frame must be at 0x104");
static_assert(offsetof(SRainParams, fSkyColorWeight) == 0x10C,
              "sky-color weight must be at 0x10C");
static_assert(offsetof(SRainParams, _unknown110) == 0x110,
              "KCD2 rain extension fields must begin at 0x110");
