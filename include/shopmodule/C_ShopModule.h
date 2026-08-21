#pragma once

#include "C_ShopRegistry.h"
#include "../framework/C_BaseModule.h"

namespace wh::shopmodule {

class C_ShopModule : public framework::C_BaseModule {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ShopModule;
    static C_ShopModule* GetInstance();

    C_ShopRegistry* m_pShopRegistry; // +0x10
};

}  // namespace wh::shopmodule
