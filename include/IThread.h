#pragma once
#include <cstddef>

class IThread {
public:
    virtual ~IThread();              // [0] 0x1823F2EB8
    virtual void ThreadEntry() = 0;  // [1]
};

static_assert(sizeof(IThread) == 0x08, "IThread size mismatch");
