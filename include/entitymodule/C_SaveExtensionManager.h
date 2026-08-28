#pragma once
#include <cstddef>
#include <memory>
#include <unordered_map>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../framework/S_ResourceHandle.h"
#include "S_SaveExtensionData.h"

namespace wh::entitymodule {

template <typename T>
class C_SaveExtensionManager {
public:
    virtual ~C_SaveExtensionManager();                 // [0]
    virtual void Register(T* extension);               // [1]
    virtual void Unregister(T* extension);             // [2]
    virtual void Deserialize(void* input);             // [3], exact archive type unresolved
    virtual void Reset();                              // [4]
    virtual void BeforeUnregister(T* extension);       // [5]

    wh::framework::S_ResourceHandle m_resource;        // +0x08
    std::unordered_map<CryGUID, T*> m_extensions;      // +0x18
    std::unordered_map<
        CryGUID,
        std::unique_ptr<S_SaveExtensionData>> m_pendingData; // +0x58
};

static_assert(sizeof(C_SaveExtensionManager<void>) == 0x98,
              "C_SaveExtensionManager size mismatch");

} // namespace wh::entitymodule
