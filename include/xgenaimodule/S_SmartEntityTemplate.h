#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>
#include <boost/container/vector.hpp>
#include "S_DatabaseIDTemplate.h"
#include "S_SmartEntityUnstanceResourceIndex.h"
#include "../databasemodule/C_ObjectTreeDBMultipartBase.h"

// wh::xgenaimodule::S_SmartEntityTemplate -- multipart smart-entity database row.
// sizeof 0xC8; vtable 0x183A8CE10, deleting destructor plus RTTR trio.

namespace wh::xgenaimodule {

struct S_SmartBehaviorTemplate;
struct S_SmartResource;

class S_SmartEntityTemplate
    : public S_DatabaseIDTemplate
    , public wh::databasemodule::C_ObjectTreeDBMultipartBase
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_SmartEntityTemplate;

    ~S_SmartEntityTemplate() override;  // [0] 0x1832C28E0
    RTTR_ENABLE()                       // [1..3]

    CryGUID m_brainId;                                // +0x18, RTTR "BrainId"
    bool m_updatePriority;                            // +0x28
    bool m_expectedOnNavigationMesh;                  // +0x29
    uint8_t _pad2A[6];                                // +0x2A
    std::vector<S_SmartResource> m_resources;         // +0x30, RTTR "Resources"
    CryStringT<char> m_name;                          // +0x48, RTTR "Name"
    std::vector<S_SmartBehaviorTemplate>
        m_behaviorTemplates;                          // +0x50, RTTR "BehaviorTemplates"
    std::unordered_map<int32_t, int32_t>
        m_resourceIndex;                              // +0x68 [SYNTHETIC NAME]
    uint16_t m_defaultUnstanceResource;               // +0xA8
    uint16_t m_defaultStanceResource;                 // +0xAA
    uint16_t m_defaultOneshotResource;                // +0xAC
    uint16_t _padAE;                                  // +0xAE
    boost::container::vector<S_SmartEntityUnstanceResourceIndex>
        m_unstanceResourceIndex;                      // +0xB0 [SYNTHETIC NAME]
};
static_assert(sizeof(S_SmartEntityTemplate) == 0xC8,
              "S_SmartEntityTemplate must be 0xC8");
static_assert(offsetof(S_SmartEntityTemplate, m_brainId) == 0x18,
              "smart-entity brain id at 0x18");
static_assert(offsetof(S_SmartEntityTemplate, m_updatePriority) == 0x28,
              "smart-entity update priority at 0x28");
static_assert(offsetof(S_SmartEntityTemplate, m_resources) == 0x30,
              "smart-entity resources at 0x30");
static_assert(offsetof(S_SmartEntityTemplate, m_name) == 0x48,
              "smart-entity name at 0x48");
static_assert(offsetof(S_SmartEntityTemplate, m_behaviorTemplates) == 0x50,
              "smart-entity behavior templates at 0x50");
static_assert(offsetof(S_SmartEntityTemplate, m_resourceIndex) == 0x68,
              "smart-entity resource index at 0x68");
static_assert(offsetof(S_SmartEntityTemplate, m_defaultUnstanceResource) == 0xA8,
              "default unstance resource at 0xA8");
static_assert(offsetof(S_SmartEntityTemplate, m_unstanceResourceIndex) == 0xB0,
              "unstance-resource index at 0xB0");

}  // namespace wh::xgenaimodule
