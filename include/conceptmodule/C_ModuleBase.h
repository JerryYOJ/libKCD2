#pragma once
#include <cstddef>
#include <memory>
#include <vector>

#include <boost/optional.hpp>

#include "C_AutoTriggerable.h"
#include "C_Node.h"
#include "E_HibernateMode.h"
#include "shared/E_DLC.h"

// wh::conceptmodule::C_ModuleBase -- concept-graph module node base
// (KCD2 WHGame.dll Steam 1.5.6).  sizeof 0xA0.

namespace wh::conceptmodule {

class C_BaseAsset;
namespace runtime { class C_RuntimeType; }

class C_ModuleBase : public C_AutoTriggerable<C_Node> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ModuleBase;

    void Activate() override;                              // [4] 0x180ACFDB0, recursive structural activation
    void ActivateNode() override;                          // [17] 0x18069551C, recursive runtime activation
    void DetachOrDeactivate() override;                    // [19] 0x1806952E0, recursive detach/deactivation
    void Hibernate(std::vector<_smart_ptr<C_Node>>& changed,
                   E_NodeHibernateReason reason) override; // [20] 0x180ACFE78
    void Wake(std::vector<_smart_ptr<C_Node>>& changed,
              E_NodeWakeReason reason) override;           // [21] 0x180ACFC14

    std::vector<_smart_ptr<C_Node>> m_nodes;                         // +0x40, rttr "Nodes"
    std::vector<std::shared_ptr<runtime::C_RuntimeType>> m_types;    // +0x58, rttr "Types"
    std::vector<std::shared_ptr<C_BaseAsset>> m_assets;              // +0x70, rttr "Assets"
    CryStringT<char> m_scopedName;                                  // +0x88, descriptive name
    CryStringT<char> m_localName;                                   // +0x90, descriptive name
    E_HibernateMode::Type m_hibernateMode;                           // +0x98, rttr "HibernateMode"
    boost::optional<bool> m_voiceNamespace;                          // +0x99, rttr "VoiceNamespace"
    wh::shared::E_DLC::Type m_requiredDLC;                           // +0x9B, rttr "RequiredDLC"
    int32_t m_unk9C;                                                 // +0x9C, ctor INT_MAX; role unverified
};
static_assert(sizeof(C_ModuleBase) == 0xA0, "C_ModuleBase must be 0xA0");
static_assert(offsetof(C_ModuleBase, m_nodes) == 0x40, "C_ModuleBase nodes offset");
static_assert(offsetof(C_ModuleBase, m_types) == 0x58, "C_ModuleBase types offset");
static_assert(offsetof(C_ModuleBase, m_assets) == 0x70, "C_ModuleBase assets offset");
static_assert(offsetof(C_ModuleBase, m_hibernateMode) == 0x98, "C_ModuleBase hibernate mode offset");
static_assert(offsetof(C_ModuleBase, m_requiredDLC) == 0x9B, "C_ModuleBase DLC offset");

void AttachChild(_smart_ptr<C_Node> child, _smart_ptr<C_ModuleBase> parent);  // 0x180C2481C
void EraseChild(std::vector<_smart_ptr<C_Node>>& nodes,
                _smart_ptr<C_Node> const& child);                            // 0x1808D7410
void SetParent(C_Node* child, _smart_ptr<C_ModuleBase> parent);               // 0x18270ABA8; descriptive name

// 0x180ACF990, REL::ID(58536). Fires the module's synthesized "OnWake" input
// pin (authored-graph entry point) and recurses into not-yet-started child
// modules; self-idempotent (0x180ACFC90 gate) so safe to call once per
// project. NOT what arms C_Effect/AutoTriggerable nodes -- see WakeGraph.
void StartGraph(C_ModuleBase* module);

}  // namespace wh::conceptmodule
