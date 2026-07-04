#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::questmodule::E_QuestProgress -- quest progress state (KCD2 1.5.6, kd7u).
// -----------------------------------------------
// TD .?AW4E_QuestProgress@questmodule@wh@@. Payload type of the C_Quest +0xB0 progress
// port (C_TypedPortRef<E_QuestProgress>) -- the quest-state cheat lever. Enumerator VALUES
// and the underlying width are UNVERIFIED (int32 modeled; TypedPortRef does not embed the
// payload, so no layout depends on it) -- enumerate from the progress-port writers before
// setting states.

namespace wh::questmodule {

enum class E_QuestProgress : int32_t {};   // values not yet enumerated (see header note)

}  // namespace wh::questmodule
