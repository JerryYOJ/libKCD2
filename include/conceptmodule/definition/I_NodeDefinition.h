#pragma once
#include <cstddef>
#include <functional>
#include <memory>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/variant.h"
#include "../E_NodeStyle.h"

namespace wh::conceptmodule {

class C_BaseAsset;

namespace definition {

class I_NodeDefinition;
class I_PortDefinition;

using NodeDefinitionSink = std::function<void(
    std::shared_ptr<I_NodeDefinition> const&)>;
using PortDefinitionSink = std::function<void(
    std::shared_ptr<I_PortDefinition> const&)>;

class I_NodeDefinition {
public:
    struct S_PropertyDef;

    virtual ~I_NodeDefinition();                              // [0]
    virtual void GetPortDefinitions(
        PortDefinitionSink sink, bool includeAll) = 0;        // [1]
    virtual bool Validate() const = 0;                        // [2]
    virtual std::shared_ptr<I_NodeDefinition> Clone() const = 0; // [3]
    virtual CryStringT<char> const& GetName() const = 0;      // [4]
    virtual CryStringT<char> const& GetDescription() const = 0; // [5]
    virtual CryStringT<char> const& GetCategory() const = 0;  // [6]
    virtual E_NodeStyle GetStyle() const = 0;                 // [7]
    virtual bool SupportsAutoTrigger() const = 0;             // [8]
    virtual bool AffectsGameSave() const = 0;                 // [9]
    virtual rttr::variant GetPropertyValue(
        CryStringT<char> const& name) const = 0;              // [10]
    virtual std::shared_ptr<C_BaseAsset> FindAsset(
        CryStringT<char> const& name) const = 0;              // [11]
};

static_assert(sizeof(I_NodeDefinition) == 0x08,
              "I_NodeDefinition size mismatch");

}  // namespace definition
}  // namespace wh::conceptmodule
