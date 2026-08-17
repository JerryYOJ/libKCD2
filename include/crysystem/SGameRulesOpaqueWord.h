#pragma once
#include <cstddef>

struct alignas(4) SGameRulesOpaqueWord {
    std::byte data[0x04];
};
static_assert(sizeof(SGameRulesOpaqueWord) == 0x04,
              "SGameRulesOpaqueWord must be 0x04");
static_assert(alignof(SGameRulesOpaqueWord) == 0x04,
              "SGameRulesOpaqueWord alignment must be 0x04");
