#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/type.h"
#include "../rttr/variant.h"
#include "E_PortConnectionType.h"
#include "E_PortDirection.h"
#include "E_PortVisibility.h"
#include "E_TemplateTypename.h"

namespace wh::conceptmodule::definition {

class I_PortDefinition {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_PortDefinition;

    virtual ~I_PortDefinition();                              // [0]
    virtual CryStringT<char> GetName() const = 0;             // [1]
    virtual std::int32_t GetValueOriginConstraint() const = 0; // [2] metadata key 10
    virtual E_PortDirection GetDirection() const = 0;         // [3] metadata key 0
    virtual E_PortVisibility GetVisibility() const = 0;       // [4] metadata key 15
    virtual E_PortConnectionType GetConnectionType() const = 0; // [5] metadata key 1
    virtual rttr::type GetValueType() const = 0;              // [6]
    virtual E_TemplateTypename GetTemplate() const = 0;       // [7] metadata key 2
    virtual rttr::variant GetDefaultValue() const = 0;        // [8] metadata key 7
    virtual bool IsHidden() const = 0;                         // [9] metadata key 4
    virtual bool unk_10() const = 0;                           // [10] metadata key 5
    virtual bool IsVariadic() const = 0;                       // [11] metadata key 9
    virtual bool IsSequential() const = 0;                     // [12] metadata key 11
    virtual bool IsOptional() const = 0;                       // [13] metadata key 3
    virtual bool unk_14() const = 0;                           // [14] metadata key 6
    virtual bool IsAutoTriggerable() const = 0;                // [15] metadata key 12
    virtual bool IsTriggerableWhenHibernated() const = 0;      // [16] metadata key 13
    virtual bool IsInterface() const = 0;                      // [17] visibility is Internal/External
    virtual std::vector<CryStringT<char>>
        GetLinkedTriggerPorts() const = 0;                     // [18] metadata key 14
    virtual std::vector<CryStringT<char>> unk_19() const = 0;  // [19] metadata key 16
    virtual std::shared_ptr<I_PortDefinition> unk_20() const = 0; // [20] cached/copy/null by implementation
};

static_assert(sizeof(I_PortDefinition) == 0x08,
              "I_PortDefinition size mismatch");

}  // namespace wh::conceptmodule::definition
