#pragma once
#include <cstddef>
#include <cstdint>

namespace wh {

class I_LoadingProgressListener {
public:
    virtual ~I_LoadingProgressListener();       // [0]
    virtual void SetDebug(std::int32_t value) = 0; // [1]
};

static_assert(sizeof(I_LoadingProgressListener) == 0x08,
              "I_LoadingProgressListener size mismatch");

}  // namespace wh
