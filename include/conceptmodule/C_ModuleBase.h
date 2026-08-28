#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include <boost/optional.hpp>

#include "C_AutoTriggerable.h"
#include "C_BaseAsset.h"
#include "C_Node.h"
#include "E_HibernateMode.h"
#include "shared/E_DLC.h"

namespace wh::conceptmodule {

namespace runtime { class C_RuntimeType; }

class C_ModuleBase : public C_AutoTriggerable<C_Node> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ModuleBase;

    C_ModuleBase();                                          // default construction path 0x180C38DDC
    explicit C_ModuleBase(CryStringT<char> const& name);     // named construction path 0x180C0DAB0
    ~C_ModuleBase() override;                                // [0] 0x1806B3C18
    void Activate() override;                                // [4] 0x180ACFDB0
    RTTR_ENABLE(C_AutoTriggerable<C_Node>)                   // [5..7]
    XmlNodeRef Save() override;                              // [8] 0x1808D7DD0
    _smart_ptr<C_Node> FindChildByName(
        CryStringT<char> const& name) override;              // [9] 0x180ACFF7C
    bool Load(XmlNodeRef node) override;                     // [11] 0x1826DD0E4
    void unk14() override;                                   // [14] 0x1808D5934
    void DispatchLifecycleEvent(
        std::int32_t event, std::int32_t expectedPhase) override; // [15] 0x1806B0A88
    void unk16() override;                                   // [16] 0x18051AA94
    void ActivateNode() override;                            // [17] 0x18069551C
    void Rebind(void* arg) override;                         // [18] 0x181E30D90
    void DetachOrDeactivate() override;                      // [19] 0x1806952E0
    void Hibernate(std::vector<_smart_ptr<C_Node>>& changed,
                   E_NodeHibernateReason reason) override;  // [20] 0x180ACFE78
    void Wake(std::vector<_smart_ptr<C_Node>>& changed,
              E_NodeWakeReason reason) override;             // [21] 0x180ACFC14
    bool unk22() override;                                   // [22] returns true
    void EnumerateNodes(
        NodeSink sink, bool recursive) override;             // [26] 0x180ACFFC4
    void GetPortDefinitions(
        definition::PortDefinitionSink sink,
        bool includeAll) override;                           // [28] 0x1804F13B0
    bool unk29() override;                                   // [29] 0x180ACFF3C
    void Serialize(TSerialize serializer) override;          // [30] 0x1808B0F84
    std::uint8_t unk31() override;                           // [31] 0x1826DD5CC
    bool unk32() override;                                   // [32] 0x181469610
    void OnExecute(S_NodeExecuteContext const& context) override; // [33] 0x180ACEEF4
    void OnLifecycleEvent(std::int32_t event) override;      // [34] 0x1806B0BA8
    std::int32_t MapEventToPhase(std::int32_t event) override; // [35] 0x1806B0B70
    void Reset() override;                                   // [37] 0x181E30EF0
    void UnregisterAutoTrigger() override;                   // [38] 0x181E30F10
    void ConfigurePortDefinition(
        std::shared_ptr<definition::C_RunTimePortDefinition> const& definition,
        CryStringT<char> const& name) override;              // [42] 0x1811CA874

    virtual E_HibernateMode::Type GetHibernateMode() const;  // [43] 0x181A7AED0
    virtual std::uint8_t GetModuleKind() const;              // [44] 0x181A78EB0, base kind 3
    virtual bool GetVoiceNamespace() const;                  // [45] 0x180AD0178
    virtual void SetScopedName(CryStringT<char> const& name); // [46] 0x180690450
    virtual void* unk47();                                   // [47] 0x1804C4390
    virtual bool unk48();                                    // [48] 0x1826DD088
    virtual bool unk49(void* value);                         // [49] base true
    virtual std::vector<CryStringT<char>> GetScopedNameParts() const; // [50] 0x18070EE14
    virtual _smart_ptr<C_ModuleBase> GetParentModule() const; // [51] 0x180AD018C
    virtual std::int32_t GetRuntimeOrder() const;            // [52] 0x181623518
    virtual void SetRuntimeOrder(std::int32_t order);        // [53] 0x1806B0C64
    virtual bool CanActivate() const;                        // [54] 0x181E30E60

    std::vector<_smart_ptr<C_Node>> m_nodes;                         // +0x40 RTTR "Nodes"
    std::vector<std::shared_ptr<runtime::C_RuntimeType>> m_types;    // +0x58
    std::vector<std::shared_ptr<C_BaseAsset>> m_assets;              // +0x70 RTTR "Assets"
    CryStringT<char> m_scopedName;                                  // +0x88
    CryStringT<char> m_localName;                                   // +0x90
    E_HibernateMode::Type m_hibernateMode;                           // +0x98 RTTR "HibernateMode"
    boost::optional<bool> m_voiceNamespace;                          // +0x99 RTTR "VoiceNamespace"
    wh::shared::E_DLC::Type m_requiredDLC;                           // +0x9B RTTR "RequiredDLC"
    std::int32_t m_runtimeOrder;                                    // +0x9C, ctor INT_MAX
};

static_assert(offsetof(C_ModuleBase, m_nodes) == 0x40,
              "C_ModuleBase::m_nodes offset mismatch");
static_assert(offsetof(C_ModuleBase, m_types) == 0x58,
              "C_ModuleBase::m_types offset mismatch");
static_assert(offsetof(C_ModuleBase, m_assets) == 0x70,
              "C_ModuleBase::m_assets offset mismatch");
static_assert(offsetof(C_ModuleBase, m_scopedName) == 0x88,
              "C_ModuleBase::m_scopedName offset mismatch");
static_assert(offsetof(C_ModuleBase, m_hibernateMode) == 0x98,
              "C_ModuleBase::m_hibernateMode offset mismatch");
static_assert(offsetof(C_ModuleBase, m_requiredDLC) == 0x9B,
              "C_ModuleBase::m_requiredDLC offset mismatch");
static_assert(offsetof(C_ModuleBase, m_runtimeOrder) == 0x9C,
              "C_ModuleBase::m_runtimeOrder offset mismatch");
static_assert(sizeof(C_ModuleBase) == 0xA0,
              "C_ModuleBase size mismatch");

void AttachChild(_smart_ptr<C_Node> child, _smart_ptr<C_ModuleBase> parent);  // 0x180C2481C
void EraseChild(std::vector<_smart_ptr<C_Node>>& nodes,
                _smart_ptr<C_Node> const& child);                            // 0x1808D7410
void SetParent(C_Node* child, _smart_ptr<C_ModuleBase> parent);               // 0x18270ABA8
void StartGraph(C_ModuleBase* module);                                        // 0x180ACF990, REL::ID(58536)

}  // namespace wh::conceptmodule
