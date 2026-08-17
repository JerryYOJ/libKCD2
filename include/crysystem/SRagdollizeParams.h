#pragma once
#include <cstddef>
#include <cstdint>

struct SRagdollizeParams {
    float mass;          // +0x00
    float stiffness;     // +0x04
    bool sleep;          // +0x08, stock-order name inferred
    bool unknown09;      // +0x09, meaning OPEN
    bool unknown0A;      // +0x0A, meaning OPEN
    std::uint8_t _pad0B; // +0x0B
};
static_assert(sizeof(SRagdollizeParams) == 0x0C,
              "SRagdollizeParams must be 0x0C");
