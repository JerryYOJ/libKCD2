#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "playermodule/I_UIShootingContest.h"

namespace wh::guimodule {

class C_UIShootingContest : public C_UIFlashBase,
                            public wh::playermodule::I_UIShootingContest {
public:
    C_UIShootingContest();                            // construction path 0x18188E2AC
    ~C_UIShootingContest() override;                  // primary [0] 0x182BB8880
    void Init(C_GUIModule* module) override;          // [1] 0x180C3CF9C
    void Deinit() override;                           // [2] 0x182BB941C
    RTTR_ENABLE(C_UIBase)                             // primary [7..9], secondary [7..9]
    const char* GetElementName() const override;      // [11] 0x181A8E8F0

    void HideShootingContestTable() override;         // secondary [1] 0x182BB9C88
    void UpdateShootingContestTable(
        std::int32_t value0, std::int32_t value1,
        std::int32_t value2, std::int32_t value3,
        std::int32_t value4, std::int32_t value5) override; // [2] 0x182BBBA40
    void ShowShootingHit(float x, float y) override;  // [3] 0x182BBB91C
    void ShowHorseShootingContestTable(
        CryStringT<char> const& name,
        CryStringT<char> const& horse,
        std::int32_t value, std::int32_t state,
        CryStringT<char> const& score) override;      // [4] 0x182BBB774
    void HideHorseShootingContestTable() override;    // [5] 0x182BB9C4C
    void UpdateHorseShootingContestTable(
        std::int32_t value) override;                 // [6] 0x182BBB9FC
};

static_assert(sizeof(C_UIShootingContest) == 0x60,
              "C_UIShootingContest size mismatch");

}  // namespace wh::guimodule
