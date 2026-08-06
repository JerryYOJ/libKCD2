#pragma once

#include <functional>
#include <string>
#include <string_view>
#include <vector>

#include "conceptmodule/C_ConceptNodeFactory.h"
#include "conceptmodule/C_ModuleBase.h"
#include "conceptmodule/C_Node.h"
#include "conceptmodule/C_Project.h"
#include "conceptmodule/E_PortDirection.h"
#include "conceptmodule/I_PortDefinition.h"
#include "rttr/variant.h"

namespace luautils::skald {

struct SkaldCreatedNode
{
    rttr::variant value;
    wh::conceptmodule::C_Node* node = nullptr;
};

// Invoked once per INPUT DATA port definition the freshly constructed node
// declares (enumerated live via GetPortDefinitions, after TypeT is applied
// so dynamic pins are visible -- never for trigger-kind defs). Returning
// `install=true` installs a constant: `isObject` selects between the
// literal-string path (the game's own text->value conversion, exactly what
// authored XML uses) and the object-handle path (`object` overwrites the
// constant's value directly, for handle-backed inputs no string can carry).
// Returning `install=false` leaves the port unwired (its own default
// applies). Returning false fails node creation with `error` set.
using SkaldPortResolver = std::function<bool(
    wh::conceptmodule::definition::I_PortDefinition& definition,
    std::string_view portName,
    bool& install,
    std::string& literal,
    rttr::variant& object,
    bool& isObject,
    std::string& error)>;

// Invoked once, after the node is constructed and its TypeT applied but BEFORE
// port enumeration, to set RTTR value properties (e.g. C_Switch ValueTypes /
// SwitchValues, C_Select InputPortGroups) whose contents drive GetPortDefinitions'
// dynamic pin synthesis. `nodeValue` is the node's own rttr variant (for building
// the target instance). May be empty for nodes with no config properties.
using SkaldPropertyApplier = std::function<bool(
    wh::conceptmodule::C_Node* node,
    const rttr::variant& nodeValue,
    std::string& error)>;

// A constant port installed by NAME with no matching port definition -- the
// variadic pins authored XML declares inline, e.g. MakeArray's
// <Constant Name="A"/><Constant Name="B"/> value list. AddPort (0x180697390)
// only rejects duplicates: its validator 0x180697E78 looks the name up in the
// node's definition table, binds whatever it finds (null included) and always
// returns 1, so an undeclared name installs fine.
struct SkaldExtraPort
{
    std::string name;
    std::string literal;
    rttr::variant object;
    bool isObject = false;
};

// One live port definition as reported by the node itself.
struct SkaldPortInfo
{
    std::string name;
    std::string valueType;                                  // rttr type name ("" when invalid)
    wh::conceptmodule::E_PortDirection direction =
        wh::conceptmodule::E_PortDirection::None;
    bool isTrigger = false;
};

class SkaldNodeHost
{
public:
    SkaldNodeHost() = default;
    ~SkaldNodeHost();

    SkaldNodeHost(const SkaldNodeHost&) = delete;
    SkaldNodeHost& operator=(const SkaldNodeHost&) = delete;

    // className: the node's registered rttr name or short factory tag (the
    // factory's own lookup, 0x1806A5798, resolves either -- e.g. "State" and
    // "wh::conceptmodule::State" both work). typeParameter: the TypeT value
    // for C_TemplatedNode leaves; must be empty for non-templated classes
    // and non-empty for templated ones (checked against the constructed
    // node's own rttr type, not caller-declared). resolver: see
    // SkaldPortResolver.
    bool CreateNode(std::string_view className,
                    std::string_view typeParameter,
                    const SkaldPropertyApplier& applier,
                    const SkaldPortResolver& resolver,
                    const std::vector<SkaldExtraPort>& extraPorts,
                    SkaldCreatedNode& result,
                    std::string& error);
    // Construct a node, apply TypeT, report its live port definitions, then drop
    // it WITHOUT attaching or activating -- introspection must never run gameplay
    // effects. Abandoning the node here is the same scope-exit release the
    // ApplyTypeParameter failure path already takes.
    bool DescribeNode(std::string_view className,
                      std::string_view typeParameter,
                      std::vector<SkaldPortInfo>& ports,
                      std::string& error);
    void DestroyNode(wh::conceptmodule::C_Node* node) noexcept;
    void Clear() noexcept;

private:
    bool EnsureHost(std::string& error);
    bool CreateModule(std::string& error);
    bool CreateFactoryNode(std::string_view className,
                           rttr::variant& value,
                           wh::conceptmodule::C_Node*& node,
                           std::string& error);
    bool ApplyTypeParameter(wh::conceptmodule::C_Node* node,
                            std::string_view typeParameter,
                            std::string& error);
    bool InstallConstants(wh::conceptmodule::C_Node* node,
                          const SkaldPortResolver& resolver,
                          std::string& error);
    bool InstallExtraPorts(wh::conceptmodule::C_Node* node,
                           const std::vector<SkaldExtraPort>& extraPorts,
                           std::string& error);
    void ActivateAttachedNode(wh::conceptmodule::C_Node* node,
                              std::string& error);
    void RemoveAttachedNode(wh::conceptmodule::C_Node* node) noexcept;
    void DestroyFactory() noexcept;

    wh::conceptmodule::C_ConceptNodeFactory* m_factory = nullptr;
    _smart_ptr<wh::conceptmodule::C_Project> m_project;
    _smart_ptr<wh::conceptmodule::C_ModuleBase> m_module;
    bool m_projectActivated = false;
};

}  // namespace luautils::skald
