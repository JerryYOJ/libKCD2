#pragma once
#include <cstdint>

// -----------------------------------------------
// EntityEventListenerWithCleanup -- KCD2 WHGame.dll 1.5.6 (kd7u)
// -----------------------------------------------
// KCD2 wrapper around the engine IEntityEventListener that auto-unsubscribes on
// destruction. Secondary base of C_CombatActor at +0x08 (secondary vtable
// 0x183E3FAB0, 2 slots). It REPLACES KCD1's two separate C_CombatActor bases
// I_ItemAttachmentListener(+0x08) and IEntityEventListener(+0x10).

namespace Offsets {

struct EntityEventListenerWithCleanup {
    virtual void Dtor(char flags) = 0;                          // [0]
    virtual void OnEntityEvent(void* pEntity, void* event) = 0; // [1]
};

}  // namespace Offsets
