#pragma once
#include <boost/optional.hpp>
#include <cstddef>
#include <functional>
#include <memory>
#include "../rttr/rttr_enable.h"

namespace wh::framework {

class C_WrappersExample {
public:
    virtual ~C_WrappersExample();                           // [0]
    RTTR_ENABLE()                                           // [1..3]

    std::shared_ptr<int> m_sharedPtr;                       // +0x08 RTTR "SharedPtr"
    std::shared_ptr<int> m_emptySharedPtr;                  // +0x18 RTTR "EmptySharedPtr"
    std::weak_ptr<int> m_weakPtr;                           // +0x28 RTTR "WeakPtr"
    std::weak_ptr<int> m_emptyWeakPtr;                      // +0x38 RTTR "EmptyWeakPtr"
    std::reference_wrapper<int> m_refWrapper;               // +0x48 RTTR "RefWrapper"
    boost::optional<int> m_boostOptional;                   // +0x50 RTTR "BoostOptional"
    boost::optional<int> m_emptyBoostOptional;              // +0x58 RTTR "EmptyBoostOptional"
};

static_assert(offsetof(C_WrappersExample, m_sharedPtr) == 0x08,
              "C_WrappersExample::m_sharedPtr offset mismatch");
static_assert(offsetof(C_WrappersExample, m_refWrapper) == 0x48,
              "C_WrappersExample::m_refWrapper offset mismatch");
static_assert(offsetof(C_WrappersExample, m_emptyBoostOptional) == 0x58,
              "C_WrappersExample::m_emptyBoostOptional offset mismatch");
static_assert(sizeof(C_WrappersExample) == 0x60,
              "C_WrappersExample size mismatch");

}  // namespace wh::framework
