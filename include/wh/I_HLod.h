#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../E_HLodType.h"
#include "../rttr/rttr_enable.h"

struct IRenderNode;

namespace wh {

class I_HLod {
public:
    virtual const CryStringT<char>& GetPath() const = 0;       // [0]
    virtual void SetPath(const CryStringT<char>& path) = 0;    // [1]
    virtual E_HLodType::Type GetType() const = 0;              // [2]
    virtual void SetType(E_HLodType::Type type) = 0;           // [3]
    virtual void SetPosition(const Vec3& position) = 0;        // [4]
    virtual float GetRadius() const = 0;                       // [5]
    virtual void SetRadius(float radius) = 0;                  // [6]
    virtual std::uint16_t GetLayerId() = 0;                    // [7]
    virtual void SetLayerId(std::uint16_t layerId) = 0;        // [8]
    virtual IRenderNode* GetProxyMesh() const = 0;             // [9]
    virtual void SetProxyMesh(IRenderNode* proxyMesh) = 0;     // [10]
    virtual void* unk_11() = 0;                               // [11]
    virtual std::size_t AddObject(IRenderNode* object) = 0;    // [12]
    virtual void RemoveObject(IRenderNode* object) = 0;        // [13]
    virtual IRenderNode* GetObject(int index) = 0;             // [14]
    virtual std::shared_ptr<I_HLod> unk_15() = 0;              // [15]
    virtual void* unk_16() const = 0;                          // [16]
    virtual void unk_17() = 0;                                // [17]
    virtual void SetSelectedForDebug(bool selected) = 0;       // [18]
    virtual float GetSwitchingDistance() const = 0;            // [19]
    virtual bool unk_20() const = 0;                           // [20]
    RTTR_ENABLE()                                               // [21..23]
    virtual std::uintptr_t unk_24(
        std::uint32_t** cursor,
        int* remaining,
        int* offset,
        std::uintptr_t a5,
        std::uintptr_t a6,
        std::uintptr_t a7,
        bool flag) = 0;                                        // [24]
    virtual void unk_25(void* a2, void* a3, void* a4) = 0;     // [25]
    virtual void unk_26(void* output) = 0;                      // [26]
    virtual float GetNearestObserverDistance() const = 0;       // [27]
};

static_assert(sizeof(I_HLod) == 0x08, "I_HLod size mismatch");

}  // namespace wh
