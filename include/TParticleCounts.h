#pragma once
#include <cstddef>
#include "TContainerCountsBase.h"
#include "CryEngine/CryCommon/CryMath/INumberVector.h"

template <typename F>
struct TParticleCounts : INumberVector<float, 28, TParticleCounts<F>>,
                         TContainerCountsBase<F> {
    TElementCounts<F> emitters;                               // +0x54 for float

    struct VolumeStats {
        F stat{};                                             // +0x00
        F dyn{};                                              // +0x04 for float
        F error{};                                            // +0x08 for float
    } volume;                                                 // +0x64 in parent
};

static_assert(sizeof(TParticleCounts<float>::VolumeStats) == 0x0C,
              "TParticleCounts<float>::VolumeStats size mismatch");
static_assert(offsetof(TParticleCounts<float>, emitters) == 0x54,
              "TParticleCounts<float>::emitters offset mismatch");
static_assert(offsetof(TParticleCounts<float>, volume) == 0x64,
              "TParticleCounts<float>::volume offset mismatch");
static_assert(sizeof(TParticleCounts<float>) == 0x70,
              "TParticleCounts<float> size mismatch");
