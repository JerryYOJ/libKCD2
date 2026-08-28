#pragma once
#include <cstddef>
#include "TElementCounts.h"

template <typename F>
struct TContainerCountsBase {
    TElementCounts<F> components;                             // +0x00
    TElementCounts<F> spawners;                               // +0x10 for float

    struct ParticleCounts : TElementCounts<F> {
        F reiterate{};                                        // +0x10 for float
        F reject{};                                           // +0x14
        F clip{};                                             // +0x18
        F collideTest{};                                      // +0x1C
        F collideHit{};                                       // +0x20
    } particles;                                              // +0x20 in parent

    TElementCounts<F> pixels;                                 // +0x44 for float
};

static_assert(sizeof(TContainerCountsBase<float>::ParticleCounts) == 0x24,
              "TContainerCountsBase<float>::ParticleCounts size mismatch");
static_assert(offsetof(TContainerCountsBase<float>, particles) == 0x20,
              "TContainerCountsBase<float>::particles offset mismatch");
static_assert(offsetof(TContainerCountsBase<float>, pixels) == 0x44,
              "TContainerCountsBase<float>::pixels offset mismatch");
static_assert(sizeof(TContainerCountsBase<float>) == 0x54,
              "TContainerCountsBase<float> size mismatch");
