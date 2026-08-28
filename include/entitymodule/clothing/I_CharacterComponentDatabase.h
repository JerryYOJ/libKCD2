#pragma once
#include <array>
#include <cstddef>
#include <cstdint>

#include "S_CharacterComponentName.h"

namespace wh::entitymodule::clothing {

class I_CharacterComponentDatabase {
public:
    virtual const S_CharacterComponentName& SelectBody(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) = 0; // [0] 0x180973420
    virtual const S_CharacterComponentName& SelectHead(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) = 0; // [1] 0x180972E68
    virtual const S_CharacterComponentName& SelectHair(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) = 0; // [2] 0x18097310C
    virtual const S_CharacterComponentName& SelectBeard(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) = 0; // [3] 0x1811A535C
    virtual const S_CharacterComponentName& SelectClothing(
        void* context,
        const std::array<CryStringT<char>, 3>& names,
        std::uint64_t* randomState) = 0; // [4] 0x181184220
    virtual bool IsLoaded() const = 0;   // [5] 0x180973380
    virtual std::uint32_t UpdateFrameId() = 0; // [6] 0x180973390
};

static_assert(sizeof(I_CharacterComponentDatabase) == 0x08,
              "I_CharacterComponentDatabase size mismatch");

} // namespace wh::entitymodule::clothing
