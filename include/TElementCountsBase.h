#pragma once
#include <cstddef>

template <typename F>
struct TElementCountsBase {
    F alloc{};                                                // +0x00
    F alive{};                                                // +0x04 for float
    F updated{};                                              // +0x08 for float
    F rendered{};                                             // +0x0C for float
};

static_assert(offsetof(TElementCountsBase<float>, rendered) == 0x0C,
              "TElementCountsBase<float>::rendered offset mismatch");
static_assert(sizeof(TElementCountsBase<float>) == 0x10,
              "TElementCountsBase<float> size mismatch");
