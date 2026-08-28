#pragma once
#include <cstddef>
#include <cstdint>

struct I3DEngine;
struct ISystem;

namespace wh {
namespace conceptmodule { class C_ConceptModule; }
namespace databasemodule { class I_DatabaseModule; }
namespace dialogmodule { class C_DialogModule; }
namespace entitymodule { class C_EntityModule; }
namespace framework { class C_Framework; class I_RestApiExample; }
namespace guimodule { class C_GUIModule; }
namespace musicmodule { class C_MusicModule; }
namespace playermodule { class C_PlayerModule; }
namespace rpgmodule { class C_RPGModule; }
namespace xbehaviormodule { class C_XBehaviorModule; }
namespace xgenaimodule { class C_XGenAIModule; }

namespace shared {

class C_GameInterface {
public:
    framework::C_Framework* m_framework;                    // +0x000 getter 0x181A76030
    std::uint8_t m_unknown008[0x090 - 0x008];               // +0x008 unreflected
    framework::I_RestApiExample* m_example;                 // +0x090 getter 0x1808CE8D0
    std::uint8_t m_unknown098[0x0E0 - 0x098];               // +0x098 unreflected
    entitymodule::C_EntityModule* m_entityModule;            // +0x0E0 getter 0x181A76100
    guimodule::C_GUIModule* m_guiModule;                    // +0x0E8 getter 0x181A72EA0
    std::uint8_t m_unknown0F0[0x108 - 0x0F0];               // +0x0F0 unreflected
    musicmodule::C_MusicModule* m_musicModule;               // +0x108 getter 0x181A77FD0
    std::uint8_t m_unknown110[0x120 - 0x110];               // +0x110 unreflected
    conceptmodule::C_ConceptModule* m_conceptModule;         // +0x120 getter 0x181A77FB0
    playermodule::C_PlayerModule* m_playerModule;            // +0x128 getter 0x181A74220
    rpgmodule::C_RPGModule* m_rpgModule;                     // +0x130 getter 0x181A76BF0
    std::uint8_t m_unknown138[0x148 - 0x138];               // +0x138 unreflected
    databasemodule::I_DatabaseModule* m_databaseModule;      // +0x148 getter 0x181A76BE0
    dialogmodule::C_DialogModule* m_dialogModule;            // +0x150 getter 0x181A77FC0
    xbehaviormodule::C_XBehaviorModule* m_xBehaviorModule;   // +0x158 getter 0x181A77FE0
    xgenaimodule::C_XGenAIModule* m_xGenAIModule;            // +0x160 getter 0x181A73DF0
    std::uint8_t m_unknown168[0x170 - 0x168];               // +0x168 unreflected
    ISystem* m_system;                                       // +0x170 getter 0x181A75270
    I3DEngine* m_3DEngine;                                  // +0x178 getter 0x181A77FA0
    std::uint8_t m_unknown180[0x1F0 - 0x180];               // +0x180 unreflected
};

static_assert(offsetof(C_GameInterface, m_framework) == 0x000,
              "C_GameInterface::m_framework offset mismatch");
static_assert(offsetof(C_GameInterface, m_example) == 0x090,
              "C_GameInterface::m_example offset mismatch");
static_assert(offsetof(C_GameInterface, m_entityModule) == 0x0E0,
              "C_GameInterface::m_entityModule offset mismatch");
static_assert(offsetof(C_GameInterface, m_musicModule) == 0x108,
              "C_GameInterface::m_musicModule offset mismatch");
static_assert(offsetof(C_GameInterface, m_conceptModule) == 0x120,
              "C_GameInterface::m_conceptModule offset mismatch");
static_assert(offsetof(C_GameInterface, m_databaseModule) == 0x148,
              "C_GameInterface::m_databaseModule offset mismatch");
static_assert(offsetof(C_GameInterface, m_xBehaviorModule) == 0x158,
              "C_GameInterface::m_xBehaviorModule offset mismatch");
static_assert(offsetof(C_GameInterface, m_xGenAIModule) == 0x160,
              "C_GameInterface::m_xGenAIModule offset mismatch");
static_assert(offsetof(C_GameInterface, m_system) == 0x170,
              "C_GameInterface::m_system offset mismatch");
static_assert(offsetof(C_GameInterface, m_3DEngine) == 0x178,
              "C_GameInterface::m_3DEngine offset mismatch");
static_assert(sizeof(C_GameInterface) == 0x1F0,
              "C_GameInterface size mismatch");

}  // namespace shared
}  // namespace wh
