#include "xgenaimodule/C_PerceptibleVolumeManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_PerceptibleVolume* C_PerceptibleVolumeManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_PerceptibleVolume* (__fastcall*)(C_PerceptibleVolumeManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(71170) }; // sub_180D45BA4
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule
