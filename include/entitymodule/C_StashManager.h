#pragma once
#include <cstddef>
#include <set>

#include "C_SaveExtensionManager.h"
#include "C_Stash.h"

namespace wh::entitymodule {

class C_StashManager : public C_SaveExtensionManager<C_Stash> {
public:
    ~C_StashManager() override;                    // [0] 0x1829DF168
    void Reset() override;                         // [4] 0x181F278B0
    void BeforeUnregister(C_Stash* stash) override; // [5] 0x180965900

    std::set<C_Stash*> m_stashes;                  // +0x98
};

static_assert(offsetof(C_StashManager, m_stashes) == 0x98,
              "C_StashManager::m_stashes offset mismatch");
static_assert(sizeof(C_StashManager) == 0xA8,
              "C_StashManager size mismatch");

} // namespace wh::entitymodule
