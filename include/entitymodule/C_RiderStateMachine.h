#pragma once
#include <cstdint>
#include <cstddef>
#include <functional>
#include <vector>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "S_RiderSMNode.h"

// -----------------------------------------------
// wh::entitymodule::C_RiderStateMachine -- KCD2 WHGame.dll.  sizeof 0x930.  No RTTI.
// -----------------------------------------------
// Embedded at C_RiderPlayerInput+0x30 (ctor 0x180A4D370 / 0x180A4D24C).
// Gait lives on S_RiderSMInput, NOT here. +0 is binder-allocator SSO.

namespace wh::entitymodule {

class C_Player;

class C_RiderStateMachine {
public:
    uint64_t            m_binderAllocSso;     // +0x00  8-byte SSO, NOT gait
    uint8_t             m_binderSlack[0xB8];  // +0x08  no ctor writer
    uint8_t             m_binderSsoUsed;      // +0xC0
    uint8_t             _padC1[7];            // +0xC1
    C_RiderStateMachine* m_pSelf;             // +0xC8
    C_RiderStateMachine* m_pBinderOwner;      // +0xD0
    std::vector<uint8_t> m_binders;           // +0xD8  24-byte elems (begin/end/cap)
    S_RiderSMNode       m_nodes[8];           // +0xF0  0x740
    uint8_t             m_nodeSsoUsed;        // +0x830
    uint8_t             _pad831[7];           // +0x831
    S_RiderSMNode*      m_pNodeBuf;           // +0x838  = this+0xF0
    S_RiderSMNode*      m_pNodeAlloc;         // +0x840  = this+0xF0
    S_RiderSMNode*      m_pNodeBegin;         // +0x848
    S_RiderSMNode*      m_pNodeEnd;           // +0x850
    S_RiderSMNode*      m_pNodeCap;           // +0x858
    float               m_float860;           // +0x860  1.0
    float               m_float864;           // +0x864  1.0
    std::function<float()> m_floatFn;         // +0x868  0x40
    int32_t             m_fnCache0;           // +0x8A8
    int32_t             m_fnCache1;           // +0x8AC
    float               m_floatFnScale;       // +0x8B0  0.3
    uint32_t            _pad8B4;              // +0x8B4
    C_Player*           m_pOwner;             // +0x8B8
    float               m_centerAge;          // +0x8C0
    float               m_blendIn;            // +0x8C4  0.2
    float               m_blendOut;           // +0x8C8  0.4
    float               m_centerDuration;     // +0x8CC
    float               m_quatA[4];           // +0x8D0
    float               m_quatB[4];           // +0x8E0
    float               m_quatC[4];           // +0x8F0
    float               m_quatD[4];           // +0x900
    float               m_centerBlend;        // +0x910
    float               m_centerStamp;        // +0x914
    float               m_headingTarget;      // +0x918
    float               m_headingVel;         // +0x91C
    float               m_heading;            // +0x920
    float               m_headingAux;         // +0x924
    uint8_t             m_camFlag928;         // +0x928
    uint8_t             m_magnetLatched;      // +0x929  S_HorseData+0x138
    uint8_t             m_centerLock;         // +0x92A  Input+0x95A
    uint8_t             _pad92B[5];           // +0x92B
};
static_assert(sizeof(C_RiderStateMachine) == 0x930, "C_RiderStateMachine must be 0x930");
static_assert(offsetof(C_RiderStateMachine, m_nodes) == 0xF0, "node pool");
static_assert(offsetof(C_RiderStateMachine, m_floatFn) == 0x868, "float fn");
static_assert(offsetof(C_RiderStateMachine, m_pOwner) == 0x8B8, "owner");
static_assert(offsetof(C_RiderStateMachine, m_centerLock) == 0x92A, "center lock");

}  // namespace wh::entitymodule
