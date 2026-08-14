#pragma once
#include <cstdint>
#include "C_ObjectManagerProxyStorage.h"
#include "../crysystem/IEntitySystemSink.h"
#include "../framework/I_WUIDMappingProvider.h"

// -----------------------------------------------
// wh::xgenaimodule::C_DynamicLinkablesManager -- registry of all
// C_DynamicLinkableObject instances (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0xB0
// (MSVC layout-dump certified; create site not pinned).
// -----------------------------------------------
// RTTI TD rva 0x4FF5840; THREE COLs.  Primary vtable 0x184014058, 3 slots
// ([0] deleting dtor sub_18341F834, [1] nullsub_1, [2] sub_18047B660).  MI bases:
//   +0x00  C_ObjectManagerProxyStorage<C_DynamicLinkableObject,
//          C_DynamicLinkablesManager, C_AIObjectManager>  (0x68)
//   +0x68  ::IEntitySystemSink -- subobject vtable 0x184014010 has 8 SLOTS vs the
//          7-slot stock declaration ([0] sub_18213D730, [1] sub_18041A6A0 ret 1,
//          [3] sub_18047E8D0, [7] sub_181AABE10, rest nullsub).  Interfuscator-
//          shuffled + extra slot => layout-only base; pures intentionally NOT
//          overridden here (class stays abstract in this mirror, pointer-only use),
//          same policy as C_NPCManager.
//   +0x70  framework::I_WUIDMappingProvider -- exactly 2 slots, no destructor:
//          [0] sub_1832A96F0 GetWuidForKey, [1] sub_1834432F0 GetValueForWuid.
// Dynamic objects register in q_1854961A0 (C_DynamicLinkableObject ctor
// sub_18047BCFC). Identity generation uses +0x78/+0x80/+0x88; the remaining
// +0x89..+0xAF tail stays OPEN.
// WUID tag E_WUIDTag::DynamicLinkableObject (0x0A) -- stamped sub_180A2F418 from
// the counter at q_1854961A0+0x78. FindByWuid uses the DynamicLinkable capability
// gate over C_AIObjectManager's broad WUID map.

namespace wh::xgenaimodule {

class C_DynamicLinkableObject;
class C_AIObjectManager;

class C_DynamicLinkablesManager
    : public C_ObjectManagerProxyStorage<C_DynamicLinkableObject, C_DynamicLinkablesManager, C_AIObjectManager>,
      public IEntitySystemSink,
      public framework::I_WUIDMappingProvider {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DynamicLinkablesManager;

    static C_DynamicLinkablesManager* GetInstance();
    C_DynamicLinkableObject* FindByWuid(const framework::WUID& wuid);

    ~C_DynamicLinkablesManager() override;   // [0] deleting dtor sub_18341F834
    void _vf2() override;                    // [2] sub_18047B660 -- remove/unregister object [U role]
    // framework::I_WUIDMappingProvider impls
    framework::WUID GetWuidForKey(const CryGUID& key) const override; // [0] sub_1832A96F0
    CryGUID GetValueForWuid(framework::WUID wuid) const override;     // [1] sub_1834432F0
    // IEntitySystemSink pures NOT overridden (see banner) -- abstract mirror.

    std::uint64_t m_currentIdentity;  // +0x78, incremented for generated dynamic WUIDs
    std::uint64_t m_reservedIdentity; // +0x80, exact role OPEN
    bool m_skipReservedIdentity;      // +0x88, skips m_reservedIdentity when set
    std::uint8_t _unknown89[0x27];    // +0x89
};
static_assert(sizeof(C_DynamicLinkablesManager) == 0xB0, "C_DynamicLinkablesManager must be 0xB0");
static_assert(offsetof(C_DynamicLinkablesManager, m_currentIdentity) == 0x78,
              "current dynamic identity must be at 0x78");
static_assert(offsetof(C_DynamicLinkablesManager, m_reservedIdentity) == 0x80,
              "reserved dynamic identity must be at 0x80");
static_assert(offsetof(C_DynamicLinkablesManager, m_skipReservedIdentity) == 0x88,
              "reserved-identity gate must be at 0x88");

}  // namespace wh::xgenaimodule
