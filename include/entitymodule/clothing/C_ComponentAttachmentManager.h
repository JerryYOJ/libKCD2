#pragma once

#include <array>
#include <boost/container/vector.hpp>
#include <cstddef>
#include <cstdint>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "../../framework/WUID.h"
#include "../C_ClothingAttachmentManager.h"
#include "C_ClothingFeature.h"
#include "C_ClothingHidingGroup.h"
#include "S_ClothingMorph.h"
#include "S_ComponentAttachmentBinding.h"
#include "S_Uberlod.h"
#include "S_UberlodQuery.h"

namespace wh::entitymodule::clothing {

class C_Component;

class C_ComponentAttachmentManager : public C_ClothingAttachmentManager {
public:
    explicit C_ComponentAttachmentManager(I_ClothingAttachmentOwner* owner); // 0x180754870
    ~C_ComponentAttachmentManager() override;                           // [0] 0x1809DEBFC
    void unk_01() override;                                             // [1] 0x181E96A00
    void unk_04(bool value) override;                                   // [4] 0x180897FF4
    void unk_13(const I_ClothingAttachmentManager* source) override;     // [13] 0x180AB0C00
    bool unk_14() const override;                                       // [14] 0x181E96630
    bool unk_15() const override;                                       // [15] 0x181E96520
    bool unk_16() const override;                                       // [16] 0x181E96650
    void unk_18(std::uint32_t value) override;                          // [18] 0x182917E00
    void unk_19() override;                                             // [19] 0x182917DAC
    void unk_20() override;                                             // [20] 0x18291758C
    void unk_24() override;                                             // [24] 0x1809DE388
    bool unk_25(void* value) override;                                  // [25] 0x1809DDB58
    bool unk_26(void* value) override;                                  // [26] 0x1809DD5B4
    void unk_27() override;                                             // [27] 0x1809DD4AC
    void unk_28() override;                                             // [28] 0x1829185BC
    void unk_29() override;                                             // [29] 0x182918564
    void unk_30(void* value, bool enabled) override;                    // [30] 0x18068C7C8
    void* unk_31(const CryStringT<char>& name, void* value) override;    // [31] 0x181E96E30
    const void* unk_32() const override;                                // [32] 0x181A9E5C0
    const void* unk_33() const override;                                // [33] 0x181A84670
    std::vector<void*> unk_34(std::int32_t key,
                              void* predicate) const override;          // [34] 0x180F1EF94
    RTTR_ENABLE(C_ClothingAttachmentManager)                            // [35..37], vtable 0x183E8B740

    void unk_38() override;                                             // [38] 0x180666CEC

    const S_Uberlod& GetUberlodQueryResult() const;                     // 0x180E72068, global cache result
    S_UberlodQuery GetUberlodQuery() const;                             // 0x180973A18
    std::string GetMorphs() const;                                      // 0x182917A4C
    std::string GetHidingGroups() const;                                // 0x18291794C
    const std::vector<C_ClothingFeature>& GetFeatures() const;          // 0x1809CBA50

    boost::container::vector<S_ComponentAttachmentBinding> m_bindings; // +0xD0
    boost::container::vector<framework::WUID> m_componentWuids;        // +0xE8
    std::map<std::uint32_t, std::set<const C_Component*>> m_componentsByEquipmentPart; // +0x100
    std::shared_ptr<void> m_unknown110;                                 // +0x110
    std::shared_ptr<void> m_unknown120;                                 // +0x120
    std::shared_ptr<void> m_unknown130;                                 // +0x130
    std::vector<C_ClothingFeature> m_features;                          // +0x140 accessor-backed "Features"
    std::uint8_t m_state;                                               // +0x158
    std::uint8_t m_padding159[3];                                       // +0x159
    std::int32_t m_requestedState;                                      // +0x15C, initialized -1
    std::array<std::shared_ptr<void>, 6> m_componentHandles;            // +0x160
    std::set<std::shared_ptr<C_ClothingHidingGroup>> m_hidingGroups;    // +0x1C0 accessor source
    boost::container::vector<S_ClothingMorph> m_morphs;                 // +0x1D0 accessor source
    std::uint32_t m_morphState;                                         // +0x1E8
    std::uint32_t m_padding1EC;                                        // +0x1EC
    std::uint8_t m_unknownCryStringLookup[0x10];                        // +0x1F0 map-like tree, value type unresolved
    S_Uberlod m_uberlod;                                                // +0x200
};

static_assert(offsetof(C_ComponentAttachmentManager, m_bindings) == 0xD0,
              "C_ComponentAttachmentManager::m_bindings offset mismatch");
static_assert(offsetof(C_ComponentAttachmentManager, m_componentWuids) == 0xE8,
              "C_ComponentAttachmentManager::m_componentWuids offset mismatch");
static_assert(offsetof(C_ComponentAttachmentManager, m_componentsByEquipmentPart) == 0x100,
              "C_ComponentAttachmentManager::m_componentsByEquipmentPart offset mismatch");
static_assert(offsetof(C_ComponentAttachmentManager, m_features) == 0x140,
              "C_ComponentAttachmentManager::m_features offset mismatch");
static_assert(offsetof(C_ComponentAttachmentManager, m_componentHandles) == 0x160,
              "C_ComponentAttachmentManager::m_componentHandles offset mismatch");
static_assert(offsetof(C_ComponentAttachmentManager, m_hidingGroups) == 0x1C0,
              "C_ComponentAttachmentManager::m_hidingGroups offset mismatch");
static_assert(offsetof(C_ComponentAttachmentManager, m_morphs) == 0x1D0,
              "C_ComponentAttachmentManager::m_morphs offset mismatch");
static_assert(offsetof(C_ComponentAttachmentManager, m_uberlod) == 0x200,
              "C_ComponentAttachmentManager::m_uberlod offset mismatch");
static_assert(sizeof(C_ComponentAttachmentManager) == 0x238,
              "C_ComponentAttachmentManager size mismatch");

} // namespace wh::entitymodule::clothing
