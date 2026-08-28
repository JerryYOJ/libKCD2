#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::shared {

template <typename T, typename Id>
class I_WeakPtrResolver {
public:
    virtual Id Register(void* value) = 0;             // [0]
    virtual Id Unregister(Id id) = 0;                 // [1]
    virtual T Resolve(Id id) = 0;                     // [2]
    virtual Id GetInvalidId() const = 0;              // [3]
    virtual std::uint8_t GetGeneration(Id id) const = 0; // [4]
};

static_assert(sizeof(I_WeakPtrResolver<void*, std::uint32_t>) == 0x08,
              "I_WeakPtrResolver size mismatch");

}  // namespace wh::shared
