#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::framework::E_SaveGameType -- KCD2 WHGame.dll 1.5.6 (kd7u).  uint8 (SYNTHETIC enum name).
// -----------------------------------------------
// The save-type discriminator stored at C_SaveGameDescription+0x08 and passed to
// C_SaveGameManager::CreateSaveGame (0x180794928). Values proven by the per-type filename
// templates selected in the description populate (sub_181E21850) and the type==6 module-message
// branch; also the index of the manager's m_slotsByType[5] mapping and the key of the per-slot
// m_countsBySaveType[10] histogram. Values 4 and 7 were NOT observed (gap flagged, not invented).

namespace wh::framework {

enum class E_SaveGameType : uint8_t {
    permanent        = 0,   // "permanent%03d.whs"
    autosave         = 1,   // "autosave%03d.whs"
    save             = 2,   // "save%03d.whs" (default / manual save)
    quicksave        = 3,   // "quicksave%03d.whs"
    // 4 unobserved
    exitSave         = 5,   // "exit.whs"
    moduleMessage    = 6,   // checkpoint via queued module message (manager +0x210 branch)
    // 7 unobserved
    crucialDecision  = 8,   // "crucialdecision%03d.whs"
    none             = 9,   // idle / no pending save
};

}  // namespace wh::framework
