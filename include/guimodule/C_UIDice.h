#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "playermodule/I_UIDice.h"

namespace wh::guimodule {

class C_UIDice : public C_UIFlashBase,
                 public wh::playermodule::I_UIDice {
public:
    C_UIDice();                                       // construction path 0x18188D5EC
    ~C_UIDice() override;                             // primary [0] 0x182BB86DC
    void Init(C_GUIModule* module) override;          // [1] 0x180C3C5B0
    void Deinit() override;                           // [2] 0x182BB8F14
    RTTR_ENABLE(C_UIBase)                             // primary [7..9], secondary [9..11]
    const char* GetElementName() const override;      // [11] 0x181A8E8F0

    void HideDiceScore() override;                    // secondary [1] 0x182BB9B6C
    void AddDiceSelector(std::int32_t id, void const* data) override; // [2] 0x182BB8A5C
    void RemoveDiceSelector(std::uint32_t id) override; // [3] 0x182BBAAEC
    void ShowDiceCursor(void* cursor) override;       // [4] 0x182BBB4B0
    void HideDiceCursor(void* cursor) override;       // [5] 0x182BB9AC0
    void ShowDiceProperties(
        CryStringT<char> const& name, std::int32_t value) override; // [6] 0x182BBB53C
    void HideDiceProperties() override;               // [7] 0x182BB9B34
    void SetCurrentPlayer(bool firstPlayer) override; // [8] 0x181A7CD10

    bool m_firstPlayer;                               // +0x60, ctor true
    std::uint8_t m_unknown61[7];
};

static_assert(offsetof(C_UIDice, m_firstPlayer) == 0x60,
              "C_UIDice::m_firstPlayer offset mismatch");
static_assert(sizeof(C_UIDice) == 0x68,
              "C_UIDice size mismatch");

}  // namespace wh::guimodule
