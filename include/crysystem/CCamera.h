#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// CCamera -- KCD2 WHGame.dll.  sizeof 0x310.  No vptr.
// -----------------------------------------------
// Ctor sub_180584004(this, const char* debugName), dtor sub_180426DD4,
// operator= sub_180426E80 (copies through +0x30C). SetFrustum 0x18053909C.
// sizeof: ShadowRenderer[6] stride 0x310; ViewCamera +0x288..+0x598.
// Not the in-tree CE3 Cry_Camera.h layout (m_Width is +0x38 here, not +0x34;
// debug CryStringT at +0x2C8; tail to 0x310).

class CCamera {
public:
    Vec3 GetViewdir() const { return m_Matrix.GetColumn1(); }
    float GetFov() const { return m_fov; }

    Matrix34        m_Matrix;              // +0x00
    float           m_fov;                 // +0x30  SetFrustum / GetViewCameraFov
    float           m_fovIn;               // +0x34  SetFrustum first store; name UNVERIFIED
    int32_t         m_Width;               // +0x38
    int32_t         m_Height;              // +0x3C
    float           m_ProjectionRatio;     // +0x40
    float           m_PixelAspectRatio;    // +0x44
    bool            m_constrainAspect;     // +0x48  copy of SViewParams+0x34
    uint8_t         _pad49[3];             // +0x49
    float           m_aspect;              // +0x4C  copy of SViewParams+0x38
    Vec3            m_edge_nlt;            // +0x50
    Vec3            m_edge_plt;            // +0x5C
    Vec3            m_edge_flt;            // +0x68
    uint8_t         _pad74[0xA0];          // +0x74
    float           m_fp[6][4];            // +0x114  Plane[6]
    uint8_t         _pad174[0x154];        // +0x174  extra matrices / state
    CryStringT<char> m_debugName;          // +0x2C8
    uint8_t         _pad2D0[0x30];         // +0x2D0
    uint64_t        m_q300;                // +0x300  ctor 0
    uint64_t        m_q308;                // +0x308  ctor 0; operator= splits +0x30C
};
static_assert(sizeof(CCamera) == 0x310, "CCamera must be 0x310");
static_assert(offsetof(CCamera, m_fov) == 0x30, "fov");
static_assert(offsetof(CCamera, m_Width) == 0x38, "width");
static_assert(offsetof(CCamera, m_constrainAspect) == 0x48, "constrain");
static_assert(offsetof(CCamera, m_fp) == 0x114, "frustum planes");
static_assert(offsetof(CCamera, m_debugName) == 0x2C8, "debug name");
