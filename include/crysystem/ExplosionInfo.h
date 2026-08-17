#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

struct ExplosionInfo {
    std::byte m_opaque00[0x58];       // +0x00, stock semantics not current-certified
    CryStringT<char> m_effectName;    // +0x58, canonical name OPEN
    CryStringT<char> m_effectClass;   // +0x60, canonical name OPEN
    std::byte m_opaque68[0x40];       // +0x68
};
static_assert(sizeof(ExplosionInfo) == 0xA8,
              "ExplosionInfo must be 0xA8");
static_assert(offsetof(ExplosionInfo, m_effectName) == 0x58,
              "explosion effect name must be at 0x58");
static_assert(offsetof(ExplosionInfo, m_effectClass) == 0x60,
              "explosion effect class must be at 0x60");
