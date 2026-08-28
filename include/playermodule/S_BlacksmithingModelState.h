#pragma once
#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../framework/C_ModelEnumProperty.h"
#include "../framework/C_ModelProperty.h"
#include "E_BlacksmithHardening.h"
#include "E_BlacksmithInspecting.h"
#include "E_BlacksmithState.h"

namespace wh::playermodule {

template <class T>
using C_BlacksmithingModelProperty = wh::shared::C_ModelProperty<
    T,
    wh::shared::traits::C_StandardDefaultValueTrait<T>,
    wh::shared::traits::C_SignalWithNewValueTrait<T>,
    wh::shared::traits::C_DebugNoTrace,
    wh::shared::traits::C_NoSaveLoad,
    wh::shared::traits::C_OwnershipEmpty>;

struct S_BlacksmithingModelState {
    C_BlacksmithingModelProperty<CryStringT<char>> m_name; // +0x000
    C_BlacksmithingModelProperty<float> m_float30;         // +0x030
    C_BlacksmithingModelProperty<float> m_float58;         // +0x058
    wh::shared::C_ModelEnumProperty<E_BlacksmithState> m_state; // +0x080
    wh::shared::C_ModelEnumProperty<E_BlacksmithHardening> m_hardening; // +0x0A8
    wh::shared::C_ModelEnumProperty<E_BlacksmithInspecting> m_inspecting; // +0x0D0
    C_BlacksmithingModelProperty<bool> m_boolF8;            // +0x0F8
    C_BlacksmithingModelProperty<float> m_float120;         // +0x120
    C_BlacksmithingModelProperty<std::int32_t> m_int148;   // +0x148
    C_BlacksmithingModelProperty<bool> m_bool170;           // +0x170
    C_BlacksmithingModelProperty<Vec2> m_vec198;            // +0x198
    C_BlacksmithingModelProperty<bool> m_bool1C8;           // +0x1C8
    C_BlacksmithingModelProperty<bool> m_bool1F0;           // +0x1F0
    C_BlacksmithingModelProperty<float> m_float218;         // +0x218
    C_BlacksmithingModelProperty<float> m_float240;         // +0x240
    C_BlacksmithingModelProperty<float> m_float268;         // +0x268
    C_BlacksmithingModelProperty<bool> m_bool290;           // +0x290
    C_BlacksmithingModelProperty<bool> m_bool2B8;           // +0x2B8
    void* m_callbacks[4];                                    // +0x2E0
};

static_assert(sizeof(C_BlacksmithingModelProperty<CryStringT<char>>) == 0x30,
              "Blacksmithing string model property size mismatch");
static_assert(sizeof(C_BlacksmithingModelProperty<float>) == 0x28,
              "Blacksmithing scalar model property size mismatch");
static_assert(sizeof(wh::shared::C_ModelEnumProperty<E_BlacksmithState>) == 0x28,
              "Blacksmithing enum model property size mismatch");
static_assert(sizeof(S_BlacksmithingModelState) == 0x300,
              "S_BlacksmithingModelState size mismatch");
static_assert(offsetof(S_BlacksmithingModelState, m_state) == 0x80,
              "S_BlacksmithingModelState state offset mismatch");
static_assert(offsetof(S_BlacksmithingModelState, m_vec198) == 0x198,
              "S_BlacksmithingModelState Vec2 offset mismatch");
static_assert(offsetof(S_BlacksmithingModelState, m_callbacks) == 0x2E0,
              "S_BlacksmithingModelState callbacks offset mismatch");

} // namespace wh::playermodule
