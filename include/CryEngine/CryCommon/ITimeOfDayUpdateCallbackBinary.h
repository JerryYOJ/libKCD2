#pragma once
#include <cstddef>
#include <cstdint>

struct ITimeOfDayUpdateCallback {
    virtual ~ITimeOfDayUpdateCallback() = default;             // [0]
    virtual void BeginUpdate() = 0;                             // [1]
    virtual bool GetCustomValue(
        std::int32_t paramId,
        int dimension,
        float* values,
        float& blendWeight) = 0;                               // [2]
    virtual void EndUpdate() = 0;                               // [3]
};

static_assert(sizeof(ITimeOfDayUpdateCallback) == 0x08,
              "ITimeOfDayUpdateCallback size mismatch");
