#pragma once
#include <cstdint>

enum EWeaponRaisedPose : std::int32_t {
    eWeaponRaisedPose_None = 0x00,
    eWeaponRaisedPose_Fists = 0x10,
    eWeaponRaisedPose_Rifle = 0x20,
    eWeaponRaisedPose_Pistol = 0x30,
    eWeaponRaisedPose_Rocket = 0x40,
    eWeaponRaisedPose_MG = 0x50,
    eWeaponRaisedPose_DualLft = 0x01,
    eWeaponRaisedPose_DualRgt = 0x02,
    eWeaponRaisedPose_PistolLft = eWeaponRaisedPose_Pistol | eWeaponRaisedPose_DualLft,
    eWeaponRaisedPose_PistolRgt = eWeaponRaisedPose_Pistol | eWeaponRaisedPose_DualRgt,
    eWeaponRaisedPose_PistolBoth =
        eWeaponRaisedPose_Pistol | eWeaponRaisedPose_DualLft | eWeaponRaisedPose_DualRgt,
};
static_assert(sizeof(EWeaponRaisedPose) == 0x04,
              "EWeaponRaisedPose must be 0x04");
