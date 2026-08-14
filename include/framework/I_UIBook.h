#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../Offsets/Offsets_RTTI.h"
#include "../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::framework::I_UIBook -- reflected book UI interface
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x08.
// -----------------------------------------------
// Standalone abstract vtable 0x183EF7EC8 and C_UIBook's +0x58 secondary table
// 0x183D2BE08 both have exactly 16 slots. Slots [13..15] are RTTR_ENABLE.

namespace Offsets {
class IEntity;
}

namespace wh::entitymodule {
struct S_DocumentContent;
}

namespace wh::playermodule {
class I_AlchemyRecipeStep;
}

namespace wh::framework {

class I_UIBook {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_UIBook;

    virtual ~I_UIBook() = default;                                      // [0] 0x18213A7F4
    virtual void SetFullBook(
        const entitymodule::S_DocumentContent& content,
        float dyslexiaLevel,
        std::int32_t documentType,
        std::int32_t visualCategory) = 0;                               // [1] 0x182BBAE84
    virtual void NextPageBegin() = 0;                                  // [2] 0x182BB9CC0
    virtual void PreviousPageBegin() = 0;                              // [3] 0x182BBAA74
    virtual void NextPageEnd() = 0;                                    // [4] 0x182BB9CF8
    virtual void PreviousPageEnd() = 0;                                // [5] 0x182BBAAB0
    virtual void SetRecipe(
        const CryStringT<char>& id,
        const CryStringT<char>& name,
        const CryStringT<char>& description,
        const std::vector<const playermodule::I_AlchemyRecipeStep*>& steps,
        bool isOnRight,
        float dyslexiaLevel) = 0;                                      // [6] 0x1808C3E30
    virtual void SetEmptyRecipe(bool isOnRight) = 0;                   // [7] 0x182BBAE44
    virtual void SetHerb(
        const CryStringT<char>& name,
        const CryStringT<char>& latinName,
        const CryStringT<char>& description,
        const CryStringT<char>& effect,
        const CryStringT<char>& occurrence,
        bool isOnRight,
        float dyslexiaLevel) = 0;                                      // [8] 0x182BBAFD0
    virtual void CopyContentFromRightSideToLeftSide() = 0;             // [9] 0x180A96F00
    virtual void CopyContentFromLeftSideToRightSide() = 0;             // [10] 0x182BB8C54
    virtual void _vf11(CryStringT<char> gfxName,
                       Offsets::IEntity* entity,
                       std::uint32_t textureSlot) = 0;                  // [11] 0x180A964A8, source name OPEN
    virtual void _vf12(Offsets::IEntity* entity) = 0;                  // [12] 0x1819CA4AC, source name OPEN

    RTTR_ENABLE()                                                       // [13..15]
};
static_assert(sizeof(I_UIBook) == 0x08,
              "I_UIBook must contain only its vptr");

}  // namespace wh::framework
