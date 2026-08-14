#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::xgenaimodule {

class S_MessageHandle {
public:
    S_MessageHandle(const S_MessageHandle& other);
    S_MessageHandle& operator=(const S_MessageHandle& other); // 0x18070DA2C
    ~S_MessageHandle();                                      // 0x18070DAF4

    void* m_pMessage;                     // +0x00, exact message class OPEN
    std::uint32_t* m_pReferenceCount;     // +0x08
};
static_assert(sizeof(S_MessageHandle) == 0x10,
              "S_MessageHandle must be 0x10");

}  // namespace wh::xgenaimodule
