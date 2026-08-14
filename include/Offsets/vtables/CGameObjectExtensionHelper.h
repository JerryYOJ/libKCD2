#pragma once
#include <cstddef>

namespace Offsets {

// CryEngine CRTP extension helper. RmiCapacity is static message capacity, not sizeof(T).
template <class T, class I, std::size_t RmiCapacity = 64>
class CGameObjectExtensionHelper : public I {
public:
    const void* GetRMIBase() const override;
};

}  // namespace Offsets
