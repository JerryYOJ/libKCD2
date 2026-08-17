#pragma once
#include <cstddef>
#include <cstdint>

namespace Offsets {

// ABI-width surrogate only; canonical source type and semantics remain open.
using LipSyncProviderContextArg = std::uintptr_t;

class ILipSyncProvider {
public:
    virtual ~ILipSyncProvider() = default; // [0]
    virtual void _vf1(LipSyncProviderContextArg context,
                      std::uint32_t value,
                      bool condition) = 0; // [1]
    virtual void _vf2(LipSyncProviderContextArg context,
                      std::uint32_t soundId,
                      bool active) = 0; // [2]
    virtual void _vf3(LipSyncProviderContextArg context,
                      std::uint32_t soundId,
                      bool active) = 0; // [3]
    virtual void _vf4(LipSyncProviderContextArg context,
                      std::uint32_t soundId,
                      bool active) = 0; // [4]
    virtual void _vf5(LipSyncProviderContextArg context,
                      std::uint32_t soundId,
                      bool active) = 0; // [5]
    virtual void _vf6(LipSyncProviderContextArg context,
                      std::uint32_t value,
                      bool condition) = 0; // [6]
};
static_assert(sizeof(ILipSyncProvider) == 0x08,
              "ILipSyncProvider must be vptr-only");

}  // namespace Offsets
