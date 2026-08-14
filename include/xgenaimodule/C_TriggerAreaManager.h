#pragma once

#include <unordered_map>
#include "../crysystem/IEntitySystemSink.h"
#include "../framework/HashPrimitives.h"
#include "../framework/I_WUIDMappingProvider.h"

namespace wh::xgenaimodule {

class C_TriggerArea;

class C_TriggerAreaManager
    : public IEntitySystemSink,
      public framework::I_WUIDMappingProvider {
public:
    static C_TriggerAreaManager* GetInstance();
    C_TriggerArea* FindByWuid(const framework::WUID& wuid);

    ~C_TriggerAreaManager() override;
    framework::WUID GetWuidForKey(const CryGUID& key) const override; // provider [0] sub_1832EFFE8
    CryGUID GetValueForWuid(framework::WUID wuid) const override;     // provider [1] sub_1832EFF88

    std::uint8_t _unknown10[0x08];
    std::unordered_map<framework::WUID, C_TriggerArea*,
                       shared::S_DefaultHash<framework::WUID>> m_areasByWuid; // +0x18
    std::uint8_t _unknown58[0x98];
};
static_assert(sizeof(C_TriggerAreaManager) == 0xF0, "C_TriggerAreaManager must be 0xF0");

}  // namespace wh::xgenaimodule
