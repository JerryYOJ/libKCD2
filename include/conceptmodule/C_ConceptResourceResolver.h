#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "C_SharedResource.h"
#include "S_ConceptResourceResolverEntry.h"
#include "shared/I_WeakPtrResolver.h"

namespace wh::conceptmodule {

template <typename T, typename Id>
class C_ConceptResourceResolver : public wh::shared::I_WeakPtrResolver<T, Id> {
public:
    C_ConceptResourceResolver();
    ~C_ConceptResourceResolver();

    Id Register(void* value) override;                  // [0] 0x1807CEC40
    Id Unregister(Id id) override;                      // [1] 0x1807CEBEC
    T Resolve(Id id) override;                          // [2] 0x18042C3B8
    Id GetInvalidId() const override;                   // [3] 0x181A72600
    std::uint8_t GetGeneration(Id id) const override;   // [4] 0x1806991D0

    SRWLOCK m_lock; // +0x08, SRWLOCK storage
    std::uint32_t m_lockDepth;                         // +0x10
    std::uint32_t m_lockOwnerThreadId;                 // +0x14
    std::vector<S_ConceptResourceResolverEntry> m_entries; // +0x18
    Id m_nextId;                                       // +0x30
    bool m_unknown34;                                  // +0x34
    std::uint8_t m_unknown35[3];
};

using C_SharedResourceResolver = C_ConceptResourceResolver<
    _smart_ptr<C_SharedResource>, std::uint32_t>;

static_assert(offsetof(C_SharedResourceResolver, m_lock) == 0x08,
              "C_SharedResourceResolver::m_lock offset mismatch");
static_assert(offsetof(C_SharedResourceResolver, m_entries) == 0x18,
              "C_SharedResourceResolver::m_entries offset mismatch");
static_assert(offsetof(C_SharedResourceResolver, m_nextId) == 0x30,
              "C_SharedResourceResolver::m_nextId offset mismatch");
static_assert(sizeof(C_SharedResourceResolver) == 0x38,
              "C_SharedResourceResolver size mismatch");

}  // namespace wh::conceptmodule
