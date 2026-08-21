#pragma once

#include <map>
#include "../../crysystem/IEntitySystemSink.h"
#include "../../framework/I_WUIDMappingProvider.h"

namespace wh::xgenaimodule::navigation {

class C_PredefinedPath;

class C_PredefinedPathManager
    : public IEntitySystemSink,
      public framework::I_WUIDMappingProvider {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PredefinedPathManager;
    static C_PredefinedPathManager* GetInstance();
    C_PredefinedPath* FindByWuid(const framework::WUID& wuid);

    ~C_PredefinedPathManager() override;
    framework::WUID GetWuidForKey(const CryGUID& key) const override; // provider [0] sub_1834171EC
    CryGUID GetValueForWuid(framework::WUID wuid) const override;     // provider [1] sub_183417184

    std::uint8_t _unknown10[0x08];
    std::map<framework::WUID, C_PredefinedPath*> m_pathsByWuid; // +0x18
    std::uint8_t _unknown28[0x48];
};
static_assert(sizeof(C_PredefinedPathManager) == 0x70, "C_PredefinedPathManager must be 0x70");

}  // namespace wh::xgenaimodule::navigation
