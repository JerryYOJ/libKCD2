#pragma once
#include <cstddef>
#include <cstdint>
#include "CryEngine/CryCommon/CryString.h"

namespace wh::playermodule {

class I_UIDice {
public:
    virtual ~I_UIDice();
    virtual void HideDiceScore() = 0;                                  // [1]
    virtual void AddDiceSelector(std::int32_t id, void const* data) = 0; // [2]
    virtual void RemoveDiceSelector(std::uint32_t id) = 0;             // [3]
    virtual void ShowDiceCursor(void* cursor) = 0;                     // [4]
    virtual void HideDiceCursor(void* cursor) = 0;                     // [5]
    virtual void ShowDiceProperties(
        CryStringT<char> const& name, std::int32_t value) = 0;         // [6]
    virtual void HideDiceProperties() = 0;                             // [7]
    virtual void SetCurrentPlayer(bool firstPlayer) = 0;               // [8]
};

static_assert(sizeof(I_UIDice) == 0x08, "I_UIDice size mismatch");

}  // namespace wh::playermodule
