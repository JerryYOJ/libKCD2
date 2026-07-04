#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::databasemodule::C_DynamicEnumManager -- registry of I_DynamicEnum providers
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Not heap-created: lives EMBEDDED inside C_DatabaseModule at +0x98 (ctor sub_18192BBB4
// writes its vftable there; dtor chain destroys it via sub_182740C5C(this+0x98)).
// Body: 7 zeroed qwords + a byte set to 1 [container roles UNVERIFIED -- the databases'
// I_DynamicEnum subobjects (@+0xB8 of each concrete DB) register here].

namespace wh::databasemodule {

class C_DynamicEnumManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DynamicEnumManager;
    virtual ~C_DynamicEnumManager();   // slot layout not yet mapped

    uint64_t m_unk08;    // +0x08  ctor 0 [role UNVERIFIED]
    uint64_t m_unk10;    // +0x10  ctor 0
    uint64_t m_unk18;    // +0x18  ctor 0
    uint64_t m_unk20;    // +0x20  ctor 0
    uint64_t m_unk28;    // +0x28  ctor 0
    uint64_t m_unk30;    // +0x30  ctor 0
    uint64_t m_unk38;    // +0x38  ctor 0
    uint8_t  m_flag40;   // +0x40  ctor 1 [role UNVERIFIED]
    uint8_t  _pad41[7];  // +0x41
};
static_assert(sizeof(C_DynamicEnumManager) == 0x48,
              "C_DynamicEnumManager must be 0x48 (embedded at C_DatabaseModule+0x98..0xDF)");

}  // namespace wh::databasemodule
