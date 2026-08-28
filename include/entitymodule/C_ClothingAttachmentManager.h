#pragma once

#include <boost/container/vector.hpp>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "I_ClothingAttachmentManager.h"

namespace wh::entitymodule {

namespace clothing {
class C_ClothingAttachmentProxy;
}

class C_ClothingAttachmentManager : public I_ClothingAttachmentManager {
public:
    explicit C_ClothingAttachmentManager(I_ClothingAttachmentOwner* owner); // 0x1807540C4
    ~C_ClothingAttachmentManager() override;                             // [0] 0x18291735C
    void unk_01() override;                                             // [1] 0x18064072C
    void* GetClothingConfig() const override;                            // [2] 0x1809DD2D0
    void unk_03() override;                                             // [3] 0x181E95F30
    void unk_04(bool value) override;                                   // [4] 0x1803B6E80
    bool unk_05() const override;                                       // [5] 0x18090F5B8
    void unk_06() override;                                             // [6] 0x1809115E0
    ICharacterInstance* GetCharacterInstance() const override;           // [7] 0x180638480
    const char* GetOwnerName() const override;                           // [8] 0x181350034
    I_ClothingAttachmentOwner* GetOwner() const override;                // [9] 0x180947210
    void unk_10(bool value) override;                                   // [10] 0x181E96290
    bool unk_11() const override;                                       // [11] 0x18060D9F0
    void* unk_12() const override;                                      // [12] 0x180753EA8
    void unk_13(const I_ClothingAttachmentManager* source) override;     // [13] 0x1803B6E80
    bool unk_14() const override = 0;                                   // [14] purecall
    bool unk_15() const override = 0;                                   // [15] purecall
    bool unk_16() const override = 0;                                   // [16] purecall
    void ProcessEvent(SEntityEvent& event) override;                     // [17] 0x1804A92A0
    void unk_18(std::uint32_t value) override = 0;                       // [18] purecall
    void unk_19() override = 0;                                         // [19] purecall
    void unk_20() override = 0;                                         // [20] purecall
    std::uint32_t GetLoadedAttachmentCount() const override;             // [21] 0x1809DF938
    bool unk_22() override;                                             // [22] 0x1809DF974
    void unk_23() override;                                             // [23] 0x181E96D10
    void unk_24() override = 0;                                         // [24] purecall
    bool unk_25(void* value) override = 0;                              // [25] purecall
    bool unk_26(void* value) override = 0;                              // [26] purecall
    void unk_27() override = 0;                                         // [27] purecall
    void unk_28() override = 0;                                         // [28] purecall
    void unk_29() override = 0;                                         // [29] purecall
    void unk_30(void* value, bool enabled) override = 0;                 // [30] purecall
    void* unk_31(const CryStringT<char>& name, void* value) override = 0;// [31] purecall
    const void* unk_32() const override = 0;                             // [32] purecall
    const void* unk_33() const override = 0;                             // [33] purecall
    std::vector<void*> unk_34(std::int32_t key,
                              void* predicate) const override = 0;       // [34] purecall
    RTTR_ENABLE(I_ClothingAttachmentManager)                             // [35..37], vtable 0x183A4EA98

    virtual void unk_38();                                              // [38] 0x180666D24
    virtual bool unk_39();                                              // [39] 0x1809DF704
    virtual void unk_40(bool value);                                    // [40] 0x1809DF774
    virtual void unk_41(bool value);                                    // [41] 0x1819CBC28
    virtual void unk_42();                                              // [42] 0x1809DF87C
    virtual void unk_43();                                              // [43] 0x1809DF8E0

    I_ClothingAttachmentOwner* m_owner;                                 // +0x08 borrowed constructor argument
    ICharacterInstance* m_characterInstance;                            // +0x10 owner slot [0]
    void* m_clothingConfig;                                             // +0x18 resolved esClothingConfig record
    boost::container::vector<clothing::C_ClothingAttachmentProxy*> m_attachmentProxies; // +0x20 owning pointers
    std::uint32_t m_attachmentGeneration;                               // +0x38
    std::uint32_t m_padding3C;                                          // +0x3C
    std::shared_ptr<void> m_unknown40;                                  // +0x40
    std::shared_ptr<void> m_unknown50;                                  // +0x50
    std::shared_ptr<void> m_unknown60;                                  // +0x60
    std::uint64_t m_updateToken;                                        // +0x70
    std::uint8_t m_schedulerStorage[0x18];                              // +0x78, self-link at +0x88
    std::shared_ptr<void> m_unknown90;                                  // +0x90
    std::shared_ptr<void> m_unknownA0;                                  // +0xA0
    std::uint32_t m_characterDetail;                                    // +0xB0 XML "characterDetail"
    float m_updateOffset;                                               // +0xB4 derived from state flags
    float m_updateBias;                                                 // +0xB8
    std::uint8_t m_flagBC;                                              // +0xBC
    bool m_flagBD;                                                      // +0xBD slot [40]
    bool m_flagBE;                                                      // +0xBE slot [41]
    bool m_isCinematicOwner;                                            // +0xBF owner name starts with "cin_"
    bool m_enabled;                                                      // +0xC0 slot [10]
    bool m_pendingReset;                                                 // +0xC1 slot [11]
    std::uint8_t m_paddingC2[2];                                        // +0xC2
    float m_updateDelay;                                                 // +0xC4
    bool m_dirty;                                                        // +0xC8 slots [42..43]
    std::uint8_t m_paddingC9[7];                                        // +0xC9
};

static_assert(offsetof(C_ClothingAttachmentManager, m_owner) == 0x08,
              "C_ClothingAttachmentManager::m_owner offset mismatch");
static_assert(offsetof(C_ClothingAttachmentManager, m_attachmentProxies) == 0x20,
              "C_ClothingAttachmentManager::m_attachmentProxies offset mismatch");
static_assert(offsetof(C_ClothingAttachmentManager, m_unknown40) == 0x40,
              "C_ClothingAttachmentManager::m_unknown40 offset mismatch");
static_assert(offsetof(C_ClothingAttachmentManager, m_characterDetail) == 0xB0,
              "C_ClothingAttachmentManager::m_characterDetail offset mismatch");
static_assert(offsetof(C_ClothingAttachmentManager, m_dirty) == 0xC8,
              "C_ClothingAttachmentManager::m_dirty offset mismatch");
static_assert(sizeof(C_ClothingAttachmentManager) == 0xD0,
              "C_ClothingAttachmentManager size mismatch");

} // namespace wh::entitymodule
