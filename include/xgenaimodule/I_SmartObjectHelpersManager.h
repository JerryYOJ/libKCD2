#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::xgenaimodule {

class C_SmartHelper;
struct S_SmartHelperClassDefinition;

class I_SmartObjectHelpersManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_SmartObjectHelpersManager;
    virtual ~I_SmartObjectHelpersManager() = default; // [0]
    virtual bool LoadDefinitions(const CryStringT<char>& path) = 0; // [1]
    virtual C_SmartHelper* FindHelper(
        const CryStringT<char>& className,
        const CryStringT<char>& helperName) = 0; // [2]
    virtual S_SmartHelperClassDefinition* FindClassDefinition(
        const CryStringT<char>& className) = 0; // [3]
    virtual void Activate() = 0; // [4]
};
static_assert(sizeof(I_SmartObjectHelpersManager) == 0x08,
              "I_SmartObjectHelpersManager must be 0x08");

}  // namespace wh::xgenaimodule
