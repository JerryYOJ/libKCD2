#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include "I_SmartObjectHelpersManager.h"
#include "S_SmartHelperClassDefinition.h"
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::xgenaimodule {

// Shared SmartObject helper-definition repository owned by C_SmartObjectsManager.
class C_SmartObjectHelpersManager : public I_SmartObjectHelpersManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SmartObjectHelpersManager;
    ~C_SmartObjectHelpersManager() override; // [0] 0x1832EE060
    bool LoadDefinitions(const CryStringT<char>& path) override; // [1] 0x181096C08
    C_SmartHelper* FindHelper(
        const CryStringT<char>& className,
        const CryStringT<char>& helperName) override; // [2] 0x1832EF8C0
    S_SmartHelperClassDefinition* FindClassDefinition(
        const CryStringT<char>& className) override; // [3] 0x18067CAB8
    void Activate() override; // [4] 0x181096CA4

    std::unordered_map<CryStringT<char>, S_SmartHelperClassDefinition*>
        m_definitions;          // +0x08, owns values on full clear
    bool m_active;              // +0x48
    std::uint8_t _pad49[7];     // +0x49
};
static_assert(sizeof(C_SmartObjectHelpersManager) == 0x50,
              "C_SmartObjectHelpersManager must be 0x50");
static_assert(offsetof(C_SmartObjectHelpersManager, m_definitions) == 0x08,
              "definition map must be at 0x08");
static_assert(offsetof(C_SmartObjectHelpersManager, m_active) == 0x48,
              "activation flag must be at 0x48");

}  // namespace wh::xgenaimodule
