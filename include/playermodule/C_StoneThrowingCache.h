#pragma once
#include <cstddef>
#include <memory>
#include <vector>
#include "S_StoneThrowingCacheEntry.h"
#include "../Offsets/Offsets_RTTI.h"
#include "../crysystem/IEntitySystemSink.h"

namespace wh::playermodule {

class C_StoneThrowingCache : public IEntitySystemSink {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_StoneThrowingCache;

    static C_StoneThrowingCache* GetInstance();                    // 0x1807D1B80

    ~C_StoneThrowingCache() override;                              // [0] 0x182EA7E08
    bool OnBeforeSpawn(SEntitySpawnParams& params) override;       // [1] true stub
    void OnSpawn(IEntity* entity, SEntitySpawnParams& params) override; // [2] nullsub
    bool OnRemove(IEntity* entity) override;                       // [3] 0x18047F17C
    void OnReused(IEntity* entity, SEntitySpawnParams& params) override; // [4] nullsub
    void OnEvent(IEntity* entity, SEntityEvent& event) override;   // [5] nullsub
    void GetMemoryUsage(ICrySizer* sizer) const override;          // [6] nullsub
    const char* GetName() const override;                          // [7] 0x181A9AD00

    std::vector<std::shared_ptr<S_StoneThrowingCacheEntry>> m_entries; // +0x08
};

static_assert(sizeof(C_StoneThrowingCache) == 0x20,
              "C_StoneThrowingCache must be 0x20");
static_assert(offsetof(C_StoneThrowingCache, m_entries) == 0x08,
              "stone cache entries must be at 0x08");

}  // namespace wh::playermodule
