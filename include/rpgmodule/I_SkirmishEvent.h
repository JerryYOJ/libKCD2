#pragma once
#include <cstddef>
#include <cstdint>
#include "E_SkirmishEventType.h"

namespace wh::rpgmodule {

class I_Soul;

class I_SkirmishEvent {
public:
    virtual ~I_SkirmishEvent() = default;                           // [0]
    virtual E_SkirmishEventType::Type GetType() const = 0;          // [1]
    virtual I_Soul* GetSoul() const = 0;                            // [2]
    virtual std::uint32_t GetRoleOrState() const = 0;               // [3]
    virtual I_Soul* GetTargetSoul() const = 0;                      // [4]
    virtual void* GetPayload() const = 0;                           // [5]
};

static_assert(sizeof(I_SkirmishEvent) == 0x08,
              "I_SkirmishEvent size mismatch");

} // namespace wh::rpgmodule
