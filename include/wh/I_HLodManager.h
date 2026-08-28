#pragma once
#include <cstdint>
#include <memory>
#include "../rttr/rttr_enable.h"

namespace wh {
namespace engine3d {
class C_HLod;
}

class I_HLodManager {
public:
    virtual bool IsEnabled() const = 0;                       // [0]
    virtual bool IsEnabledForLevel() const = 0;               // [1]
    virtual void SetLevelHash(std::uint32_t levelHash) = 0;   // [2]
    virtual std::shared_ptr<engine3d::C_HLod> GetHLodTree() const = 0; // [3]
    virtual std::uint32_t unk_04() = 0;                       // [4]
    virtual std::uint32_t unk_05() = 0;                       // [5]
    virtual std::uintptr_t unk_06(
        std::uint32_t* data,
        int size,
        std::uintptr_t* a4,
        std::uintptr_t* a5,
        std::uintptr_t* a6) = 0;                              // [6]
    virtual void unk_07(void* context) = 0;                   // [7]
    virtual void unk_08(void* context) = 0;                   // [8]
    virtual void UpdateStreaming(bool force) = 0;             // [9]
    RTTR_ENABLE()                                              // [10..12]
    virtual std::uintptr_t unk_13(
        std::uintptr_t a2,
        std::uintptr_t a3,
        std::uintptr_t a4) = 0;                               // [13]
    virtual void Clear() = 0;                                 // [14]
    virtual std::shared_ptr<engine3d::C_HLod>& GetHLodTreeRef() = 0; // [15]
};

static_assert(sizeof(I_HLodManager) == 0x08,
              "I_HLodManager size mismatch");

}  // namespace wh
