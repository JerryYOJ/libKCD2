#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "S_LODAnimationRuntimeState.h"
#include "S_LODScope.h"

namespace wh::animationmodule {

class C_LODAnimationController;

// Source-reconstructed name; exact object returned by primary slots 10 and 11.
struct S_LODAnimationControllerData {
    C_LODAnimationController* m_pController; // +0x00
    std::vector<S_LODScope> m_scopes;         // +0x08
    std::uint32_t m_unknown20;                // +0x20, only zero-writes proved
    std::uint32_t _pad24;                     // +0x24
    bool m_enabled;                           // +0x28
    std::uint8_t _pad29[7];                   // +0x29
    S_LODAnimationRuntimeState m_runtimeState; // +0x30
};
static_assert(sizeof(S_LODAnimationControllerData) == 0xF0,
              "LOD animation-controller data must be 0xF0");
static_assert(offsetof(S_LODAnimationControllerData, m_scopes) == 0x08,
              "LOD scopes must be at 0x08");
static_assert(offsetof(S_LODAnimationControllerData, m_enabled) == 0x28,
              "LOD enabled flag must be at 0x28");
static_assert(offsetof(S_LODAnimationControllerData, m_runtimeState) == 0x30,
              "LOD runtime state must be at 0x30");

}  // namespace wh::animationmodule
