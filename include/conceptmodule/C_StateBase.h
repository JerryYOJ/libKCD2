#pragma once
#include "C_TemplatedNode.h"

namespace wh::conceptmodule {

template <typename T>
class C_StateBase : public C_TemplatedNode {
public:
    RTTR_ENABLE(C_TemplatedNode) // [5..7]
    rttr::variant GetPortValue(
        _smart_ptr<I_Port> const& port) override;              // [12], current state and enum-state pins
    void GetPortDefinitions(
        definition::PortDefinitionSink sink,
        bool includeAll) override;                             // [28], state and per-enumerator ports
    bool unk29() override;                                    // [29], true for every specialization
    void OnExecute(
        S_NodeExecuteContext const& context) override;         // [33], apply a fired enum-state input

    virtual void OnStateChanged(
        T const& oldValue, T const& newValue, bool changed);   // [42]
    virtual bool IsAtDefaultValue();                          // [43]

    T m_value;                                                // +0x48
};

}  // namespace wh::conceptmodule
