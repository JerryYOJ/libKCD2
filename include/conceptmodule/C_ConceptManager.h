#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "C_ConceptGraphDeserializer.h"
#include "C_ConceptResourceResolver.h"
#include "C_LinkProxyAssetResolver.h"
#include "C_Project.h"
#include "C_RandomEventConceptStreaming.h"
#include "CryEngine/CryCommon/CryString.h"
#include "framework/C_Signal.h"
#include "rttr/rttr_enable.h"

namespace wh::conceptmodule {

class C_ConceptManager {
public:
    C_ConceptManager();              // 0x1807CE780
    virtual ~C_ConceptManager();     // [0] 0x182627284
    RTTR_ENABLE() // [1..3]

    std::map<std::string, _smart_ptr<C_Project>>
        GetRootsView() const;        // 0x182627C10, synthesized from m_roots

    void* m_unknown08;               // +0x08, owned heap object
    C_SharedResourceResolver m_resourceResolver; // +0x10
    std::vector<_smart_ptr<C_Project>> m_roots;   // +0x48 RTTR "Roots"
    wh::shared::C_Signal<> m_signal60;            // +0x60, argument family unresolved
    wh::shared::C_Signal<> m_signal70;            // +0x70, same family
    void* m_unknown80;                            // +0x80, released through pointee slot 4
    std::set<CryStringT<char>> m_databaseNames;   // +0x88
    std::vector<C_ConceptGraphDeserializer*> m_deserializers; // +0x98
    C_RandomEventConceptStreaming m_randomEventStreaming;      // +0xB0
    void* m_unknown2E0;                           // +0x2E0
    void* m_unknown2E8;                           // +0x2E8
    C_LinkProxyAssetResolver m_linkAssetResolver; // +0x2F0
    std::int32_t m_unknown348;                    // +0x348, ctor INT_MAX
    std::uint8_t m_unknown34C[4];
    std::uint8_t m_runtimeEntries[0x28];          // +0x350, custom hash container
    std::uint64_t m_unknown378;                   // +0x378, uninitialized by the constructor
};

static_assert(offsetof(C_ConceptManager, m_resourceResolver) == 0x10,
              "C_ConceptManager::m_resourceResolver offset mismatch");
static_assert(offsetof(C_ConceptManager, m_roots) == 0x48,
              "C_ConceptManager::m_roots offset mismatch");
static_assert(offsetof(C_ConceptManager, m_deserializers) == 0x98,
              "C_ConceptManager::m_deserializers offset mismatch");
static_assert(offsetof(C_ConceptManager, m_randomEventStreaming) == 0xB0,
              "C_ConceptManager::m_randomEventStreaming offset mismatch");
static_assert(offsetof(C_ConceptManager, m_linkAssetResolver) == 0x2F0,
              "C_ConceptManager::m_linkAssetResolver offset mismatch");
static_assert(offsetof(C_ConceptManager, m_runtimeEntries) == 0x350,
              "C_ConceptManager::m_runtimeEntries offset mismatch");
static_assert(sizeof(C_ConceptManager) == 0x380,
              "C_ConceptManager size mismatch");

}  // namespace wh::conceptmodule
