#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryAction/GameObjectTypes.h"
#include "../Offsets/Offsets_RTTI.h"
#include "../crysystem/IEntitySystemSink.h"

namespace wh::playermodule {

class C_StoneThrowingNodes : public IEntitySystemSink {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_StoneThrowingNodes;

    static C_StoneThrowingNodes* GetInstance();                    // 0x180D7DD14

    ~C_StoneThrowingNodes() override;                              // [0] 0x182EA7E80
    bool OnBeforeSpawn(SEntitySpawnParams& params) override;       // [1] true stub
    void OnSpawn(IEntity* entity, SEntitySpawnParams& params) override; // [2] 0x1805CB048
    bool OnRemove(IEntity* entity) override;                       // [3] 0x18047EAD4
    void OnReused(IEntity* entity, SEntitySpawnParams& params) override; // [4] nullsub
    void OnEvent(IEntity* entity, SEntityEvent& event) override;   // [5] nullsub
    void GetMemoryUsage(ICrySizer* sizer) const override;          // [6] nullsub
    const char* GetName() const override;                          // [7] 0x181A9AD10

    std::vector<EntityId> m_entityIds;                             // +0x08
    std::uint32_t m_nodeClassId;                                  // +0x20
    std::uint32_t _pad24;                                         // +0x24
};

static_assert(sizeof(C_StoneThrowingNodes) == 0x28,
              "C_StoneThrowingNodes must be 0x28");
static_assert(offsetof(C_StoneThrowingNodes, m_entityIds) == 0x08,
              "stone node entity ids must be at 0x08");
static_assert(offsetof(C_StoneThrowingNodes, m_nodeClassId) == 0x20,
              "stone node class id must be at 0x20");

}  // namespace wh::playermodule
