#pragma once
#include <cstddef>
#include <cstdint>
#include "CryArray.h"
#include "CCryName.h"
#include "Cry_Math.h"

// -----------------------------------------------
// RowSimulationParams -- CryEngine attachment-row simulation parameters
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x70.
// -----------------------------------------------
// Layout is reconciled from KCD2 RTTR member pointers, ProxyNames accessor
// disassembly, constructor size, and the public CryEngine IAttachment.h source.

struct RowSimulationParams {
    enum ClampMode : std::uint8_t {
        PENDULUM_CONE            = 0,
        PENDULUM_HINGE_PLANE     = 1,
        PENDULUM_HALF_CONE       = 2,
        TRANSLATIONAL_PROJECTION = 3,
    };

    CCryName m_dirTransJoint;            // +0x00 RTTR "DirTransJoint"
    ClampMode m_clampMode;               // +0x08 RTTR "ClampMode"
    bool m_lodA;                         // +0x09 RTTR "LodA"
    bool m_lodB;                         // +0x0A RTTR "LodB"
    bool m_activateSimulation;           // +0x0B RTTR typo "ActivateSimuation"
    bool m_cycle;                        // +0x0C RTTR "Cycle"
    std::uint8_t m_simFPS;               // +0x0D RTTR "SimFPS"
    std::uint8_t m_blendControlAxis;     // +0x0E RTTR "BlendControlAxis"
    std::uint8_t _pad0F;                 // +0x0F
    float m_coneAngle;                   // +0x10 public source; RTTR name was misbound
    Vec3 m_coneRotation;                 // +0x14 RTTR "ConeRotation"
    float m_mass;                        // +0x20 RTTR "Mass"
    float m_gravity;                     // +0x24 RTTR "Gravity"
    float m_damping;                     // +0x28 RTTR "Damping"
    float m_jointSpring;                 // +0x2C RTTR "JointSpring"
    float m_rodLength;                   // +0x30 RTTR "RodLength"
    Vec2 m_stiffnessTarget;              // +0x34 RTTR "StiffnessTarget"
    Vec2 m_turbulence;                   // +0x3C RTTR "Turbulence"
    float m_maxVelocity;                 // +0x44 RTTR "MaxVelocity"
    float m_stretch;                     // +0x48 RTTR "Stretch"
    std::uint32_t m_relaxationLoops;     // +0x4C RTTR "RelaxationLoops"
    Vec3 m_translationAxis;              // +0x50 local registrar string + public source
    Vec2 m_capsule;                      // +0x5C public source; RTTR name was misbound
    std::int32_t m_projectionType;       // +0x64 public source; closes accessor-proven tail
    DynArray<CCryName> m_proxyNames;     // +0x68 ProxyNames getter/setter target this field
};

static_assert(sizeof(RowSimulationParams::ClampMode) == 1,
              "RowSimulationParams::ClampMode size mismatch");
static_assert(offsetof(RowSimulationParams, m_clampMode) == 0x08,
              "RowSimulationParams::m_clampMode offset mismatch");
static_assert(offsetof(RowSimulationParams, m_coneAngle) == 0x10,
              "RowSimulationParams::m_coneAngle offset mismatch");
static_assert(offsetof(RowSimulationParams, m_translationAxis) == 0x50,
              "RowSimulationParams::m_translationAxis offset mismatch");
static_assert(offsetof(RowSimulationParams, m_proxyNames) == 0x68,
              "RowSimulationParams::m_proxyNames offset mismatch");
static_assert(sizeof(RowSimulationParams) == 0x70,
              "RowSimulationParams size mismatch");
