#include "combatmodule/C_CombatModule.h"
#include "Offsets/Offsets.h"

// combatmodule singleton accessor (KCD2 WHGame.dll 1.5.6 RVA, verified in kd7u).

wh::combatmodule::C_CombatModule* wh::combatmodule::C_CombatModule::GetInstance() {
    // qword_185482210: written (undisplaced) by the ctor sub_180A4602C and cleared to 0 by the
    // dtor sub_182776D54. Read by e.g. sub_181A7E390 (module+0x30 poke) and the soul query sub_1809D43FC.
    static REL::Relocation<C_CombatModule**> p{ REL::Offset(0x5482210) };
    return *p;
}
