#pragma once
#include "TElementCountsBase.h"
#include "CryEngine/CryCommon/CryMath/INumberVector.h"

template <typename F>
struct TElementCounts : INumberVector<F, 4, TElementCounts<F>>,
                        TElementCountsBase<F> {
};

static_assert(sizeof(TElementCounts<float>) == 0x10,
              "TElementCounts<float> size mismatch");
