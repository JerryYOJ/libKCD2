#pragma once
#include <cstdint>
#include "REL.h"   // REL::Offset / REL::Relocation / REL::Module (address resolution)
#include "vtables/IGameFramework.h"

// -----------------------------------------------
// Global singleton offsets (KCD2 / WHGame.dll 1.5.6)
// -----------------------------------------------
// KCD2 has no address library yet -- every getter resolves via REL::Offset(RVA),
// where RVA is the image-relative address (VA - 0x180000000) read off IDA "kd7u".
// As more singletons are RE'd, add their GetInstance() to the owning class header
// (mirroring libKCD1); the raw ones the SDK glue needs live here.

namespace Offsets {

// WHGame.dll base address helper (== REL::Module::base()).
uintptr_t GetBase();

// CCryAction (IGameFramework). No RE'd concrete header yet -- getter stays here.
IGameFramework* GetCCryAction();

}  // namespace Offsets
