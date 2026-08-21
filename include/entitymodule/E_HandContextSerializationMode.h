#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_HandContextSerializationMode::Type -- KCD2 1.5.6 (kd7u).
// -----------------------------------------------
// Return of S_ItemClass vf[22]. Values from the RTTR registrar immediates
// (Serialized=0, NotSerialized=1, MoveToLinkedSlot=2). Player+ override is
// *(this+0xA9)==0 → 0 or 1; Pickable/NPCTool/AlchemyBase keep 2.

namespace wh::entitymodule::E_HandContextSerializationMode {

enum Type : std::uint8_t {
    Serialized         = 0,
    NotSerialized      = 1,
    MoveToLinkedSlot   = 2,
};

}  // namespace wh::entitymodule::E_HandContextSerializationMode
