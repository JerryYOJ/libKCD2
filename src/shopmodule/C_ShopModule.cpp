#include "shopmodule/C_ShopModule.h"
#include "game/S_GameContext.h"

namespace wh::shopmodule {

C_ShopModule* C_ShopModule::GetInstance()
{
    auto* context = game::S_GameContext::GetInstance();
    return context ? context->m_pShopModule : nullptr;
}

}  // namespace wh::shopmodule
