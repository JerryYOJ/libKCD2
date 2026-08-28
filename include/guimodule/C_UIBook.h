#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "C_UIFlashBase.h"
#include "C_UIFlashDynTextureHelper.h"
#include "framework/I_UIBook.h"

namespace wh::guimodule {

class C_UIBook : public C_UIFlashBase,
                 public wh::framework::I_UIBook {
public:
    C_UIBook();                                       // 0x180BC8F10
    ~C_UIBook() override;                             // primary [0] 0x182BB8664
    void Init(C_GUIModule* module) override;          // [1] 0x180C3C3F8
    void Deinit() override;                           // [2] 0x182BB8DCC
    RTTR_ENABLE(C_UIBase)                             // primary [7..9], secondary [13..15]
    const char* GetElementName() const override;      // [11] 0x18079EB80

    void SetFullBook(
        entitymodule::S_DocumentContent const& content,
        float dyslexiaLevel,
        std::int32_t documentType,
        std::int32_t visualCategory) override;
    void NextPageBegin() override;
    void PreviousPageBegin() override;
    void NextPageEnd() override;
    void PreviousPageEnd() override;
    void SetRecipe(
        CryStringT<char> const& id,
        CryStringT<char> const& name,
        CryStringT<char> const& description,
        std::vector<playermodule::I_AlchemyRecipeStep const*> const& steps,
        bool isOnRight,
        float dyslexiaLevel) override;
    void SetEmptyRecipe(bool isOnRight) override;
    void SetHerb(
        CryStringT<char> const& name,
        CryStringT<char> const& latinName,
        CryStringT<char> const& description,
        CryStringT<char> const& effect,
        CryStringT<char> const& occurrence,
        bool isOnRight,
        float dyslexiaLevel) override;
    void CopyContentFromRightSideToLeftSide() override;
    void CopyContentFromLeftSideToRightSide() override;
    void _vf11(
        CryStringT<char> gfxName,
        Offsets::IEntity* entity,
        std::uint32_t textureSlot) override;
    void _vf12(Offsets::IEntity* entity) override;

    CryStringT<char> m_bookName;                      // +0x60, ctor "GeneralBook"
    C_UIFlashDynTextureHelper m_textureHelper;        // +0x68..+0x8F
    std::uint32_t m_unknown90;                        // +0x90, ctor 0
    std::uint8_t m_unknown94[4];
    void* m_unknown98;                                // +0x98, ctor null
    void* m_unknownA0;                                // +0xA0, ctor null
};

static_assert(offsetof(C_UIBook, m_bookName) == 0x60,
              "C_UIBook::m_bookName offset mismatch");
static_assert(offsetof(C_UIBook, m_textureHelper) == 0x68,
              "C_UIBook::m_textureHelper offset mismatch");
static_assert(sizeof(C_UIBook) == 0xA8,
              "C_UIBook size mismatch");

}  // namespace wh::guimodule
