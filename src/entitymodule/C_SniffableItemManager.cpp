#include "entitymodule/C_SniffableItemManager.h"
#include "Offsets/Offsets.h"

namespace wh::entitymodule {

C_SniffableItemManager* C_SniffableItemManager::GetInstance()
{
    using Fn = C_SniffableItemManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(31035) };  // 0x18055E9A4
    return fn();
}

}  // namespace wh::entitymodule
