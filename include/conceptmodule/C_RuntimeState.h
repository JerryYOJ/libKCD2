#pragma once
#include <cstdint>
#include "C_Node.h"

namespace wh::conceptmodule {

class C_RuntimeState : public C_Node {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RuntimeState;

    void OnLifecycleEvent(std::int32_t event) override; // [34] 0x1811523C8, event 5 dispatches slot 41
    virtual void OnDeserializationComplete() = 0;       // [41], clears non-serialized runtime state
};

static_assert(sizeof(C_RuntimeState) == 0x40,
              "C_RuntimeState size mismatch");

}  // namespace wh::conceptmodule
