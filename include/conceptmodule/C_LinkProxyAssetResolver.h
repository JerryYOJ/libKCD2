#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include "C_BaseAsset.h"
#include "C_SharedResource.h"
#include "I_ConceptScopeHelper.h"
#include "I_LinkAssetResolver.h"
#include "CryEngine/CryCommon/CryString.h"
#include "framework/C_Signal.h"
#include "rttr/type.h"

namespace wh::conceptmodule {

class C_LinkProxyAssetResolver : public I_LinkAssetResolver,       // +0x00
                                 public I_ConceptScopeHelper {      // +0x08
public:
    using S_ScopeBinding = std::pair<_smart_ptr<C_SharedResource>, void*>;
    using AssetList = std::vector<C_BaseAsset*>;
    using S_NamedAssetList = std::pair<CryStringT<char>, AssetList>;
    using AssetCache = std::map<rttr::type, std::set<S_NamedAssetList>>;

    C_LinkProxyAssetResolver();                                  // 0x1807CE92C
    ~C_LinkProxyAssetResolver() override;                        // primary [0] 0x182627320
    rttr::variant ResolveAssets(
        rttr::type type,
        _smart_ptr<C_SharedResource> resource) override;         // primary [1] 0x1804C47E8
    RTTR_ENABLE(I_LinkAssetResolver, I_ConceptScopeHelper)       // primary [2..4], secondary [5..7]
    void AddScope(_smart_ptr<C_SharedResource> resource) override;       // secondary [1] 0x180A6D084
    void* ResolveScope(_smart_ptr<C_SharedResource> resource) override; // secondary [2] 0x1804C4528
    bool HasScope(_smart_ptr<C_SharedResource> resource) override;      // secondary [3] 0x18270A5B8
    bool IsScopeActive(
        _smart_ptr<C_SharedResource> const& resource) override;          // secondary [4] 0x18270A5EC

    wh::shared::C_Signal<> m_scopeAdded;                        // +0x10, argument family unresolved
    wh::shared::C_Signal<> m_scopeRemoved;                      // +0x20, same family
    std::set<S_ScopeBinding> m_scopeBindings;                   // +0x30
    AssetCache m_assets;                                       // +0x40
    bool m_subscribed;                                         // +0x50
    std::uint8_t m_unknown51[7];
};

static_assert(offsetof(C_LinkProxyAssetResolver, m_scopeAdded) == 0x10,
              "C_LinkProxyAssetResolver::m_scopeAdded offset mismatch");
static_assert(offsetof(C_LinkProxyAssetResolver, m_scopeBindings) == 0x30,
              "C_LinkProxyAssetResolver::m_scopeBindings offset mismatch");
static_assert(offsetof(C_LinkProxyAssetResolver, m_assets) == 0x40,
              "C_LinkProxyAssetResolver::m_assets offset mismatch");
static_assert(offsetof(C_LinkProxyAssetResolver, m_subscribed) == 0x50,
              "C_LinkProxyAssetResolver::m_subscribed offset mismatch");
static_assert(sizeof(C_LinkProxyAssetResolver) == 0x58,
              "C_LinkProxyAssetResolver size mismatch");

}  // namespace wh::conceptmodule
