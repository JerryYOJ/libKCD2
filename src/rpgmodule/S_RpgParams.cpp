#include "rpgmodule/S_RpgParams.h"
#include "REL/Offset.h"

// KCD2 WHGame.dll 1.5.6 (kd7u). Out-of-line accessors for the two RPG-parameter globals.
namespace wh::rpgmodule {

// Live value store @ 0x1855E63D0 (RVA 0x55E63D0).
S_Constants* S_Constants::Get() {
    return reinterpret_cast<S_Constants*>(REL::Offset(0x55E63D0).address());
}

// 1025 metadata entries @ 0x1849327C0 (RVA 0x49327C0), stride 0x28.
S_RpgParamDefs* S_RpgParamDefs::Get() {
    return reinterpret_cast<S_RpgParamDefs*>(REL::Offset(0x49327C0).address());
}

}  // namespace wh::rpgmodule
