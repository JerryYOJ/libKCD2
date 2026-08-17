#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace Offsets { class IAnimatedCharacterListener; }

struct SAnimatedCharacterListenerSet {
    std::vector<Offsets::IAnimatedCharacterListener*> listeners; // +0x00, borrowed elements
    std::size_t emissionDepth;                                   // +0x18
    bool needsCompaction;                                        // +0x20
    bool releaseStorageWhenEmpty;                                // +0x21
    std::uint8_t _pad22[6];                                      // +0x22
};
static_assert(sizeof(SAnimatedCharacterListenerSet) == 0x28,
              "SAnimatedCharacterListenerSet must be 0x28");
static_assert(offsetof(SAnimatedCharacterListenerSet, emissionDepth) == 0x18);
static_assert(offsetof(SAnimatedCharacterListenerSet, needsCompaction) == 0x20);
