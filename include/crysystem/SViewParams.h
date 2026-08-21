#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// SViewParams -- Cry IGameObjectView::UpdateView blob.  KCD2 WHGame.dll.  sizeof 0xD4.
// -----------------------------------------------
// SYNTHETIC SDK name (no RTTI). Ctor sub_1807F24CC. Embed CView+0x14..+0xE8
// (next is CCamera "CView"). SetCurrentParams 0x1807F0B10 copies 0xD4.
// SDK prefix through fov; KCD2 inserts constrainAspect+aspect at +0x34/+0x38
// (letterbox). viewID is +0x3C, not +0x34.

struct SViewParams {
    Vec3     position;            // +0x00
    Quat     rotation;            // +0x0C
    Quat     localRotationLast;   // +0x1C  INFERRED name; identity quat VERIFIED
    float    nearplane;           // +0x2C
    float    fov;                 // +0x30
    uint8_t  constrainAspect;     // +0x34  WH letterbox gate; dialog writes 1
    uint8_t  _pad35[3];           // +0x35
    float    aspect;              // +0x38  ctor 1.0; dialog 2.35
    uint8_t  viewID;              // +0x3C
    bool     groundOnly;          // +0x3D
    uint8_t  _pad3E[2];           // +0x3E
    float    shakingRatio;        // +0x40
    Quat     currentShakeQuat;    // +0x44
    Vec3     currentShakeShift;   // +0x54
    uint32_t idTarget;            // +0x60  INFERRED name
    Vec3     targetPos;           // +0x64  INFERRED name
    float    frameTime;           // +0x70
    float    angleVel;            // +0x74  INFERRED name
    float    vel;                 // +0x78  INFERRED name
    float    dist;                // +0x7C  INFERRED name
    bool     blend;               // +0x80  ctor 1
    uint8_t  _pad81[3];           // +0x81
    float    blendPosSpeed;       // +0x84  ctor 5
    float    blendRotSpeed;       // +0x88  ctor 10
    float    blendFOVSpeed;       // +0x8C  ctor 5
    Vec3     blendPosOffset;      // +0x90
    Quat     blendRotOffset;      // +0x9C
    float    blendFOVOffset;      // +0xAC
    bool     justActivated;       // +0xB0
    uint8_t  viewIDLast;          // +0xB1
    uint8_t  _padB2[2];           // +0xB2
    Vec3     positionLast;        // +0xB4
    Quat     rotationLast;        // +0xC0
    float    FOVLast;             // +0xD0
};
static_assert(sizeof(SViewParams) == 0xD4, "SViewParams must be 0xD4");
static_assert(offsetof(SViewParams, fov) == 0x30, "fov");
static_assert(offsetof(SViewParams, constrainAspect) == 0x34, "constrain");
static_assert(offsetof(SViewParams, aspect) == 0x38, "aspect");
static_assert(offsetof(SViewParams, viewID) == 0x3C, "viewID");
static_assert(offsetof(SViewParams, blend) == 0x80, "blend");
static_assert(offsetof(SViewParams, justActivated) == 0xB0, "justActivated");
static_assert(offsetof(SViewParams, FOVLast) == 0xD0, "FOVLast");
