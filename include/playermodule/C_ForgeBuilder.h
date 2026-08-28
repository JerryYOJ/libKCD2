#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

#include <boost/optional.hpp>

#include "../framework/C_ModelProperty.h"
#include "../framework/I_UIForgeBuilder.h"
#include "C_Minigame.h"
#include "E_ForgeAssetScope.h"
#include "E_ForgeBuilderState.h"
#include "S_ForgeAsset.h"
#include "S_ForgeBuilderRuntime.h"
#include "S_ForgeSlot.h"

namespace wh::playermodule {

class C_ForgeBuilder : public C_Minigame {
public:
    using AssetScopeProperty = wh::shared::C_ModelProperty<
        E_ForgeAssetScope::Type,
        wh::shared::traits::C_StandardDefaultValueTrait<E_ForgeAssetScope::Type>,
        wh::shared::traits::C_SignalWithNewValueTrait<E_ForgeAssetScope::Type>,
        wh::shared::traits::C_DebugNoTrace,
        wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty>;
    using StateProperty = wh::shared::C_ModelProperty<
        E_ForgeBuilderState::Type,
        wh::shared::traits::C_StandardDefaultValueTrait<E_ForgeBuilderState::Type>,
        wh::shared::traits::C_SignalWithNewValueTrait<E_ForgeBuilderState::Type>,
        wh::shared::traits::C_DebugNoTrace,
        wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty>;

    C_ForgeBuilder(entitymodule::C_Actor* playerActor);
    E_MinigameType::Type GetMinigameType() const override; // [0] 13
    ~C_ForgeBuilder() override;                            // [5] 0x182027AF0
    bool IsFinished() const override;                      // [7] state == 7
    boost::optional<std::uint8_t> unk_13() override;       // [13] engaged value 4
    RTTR_ENABLE(C_Minigame) // [15..17]
    void Update(float deltaTime) override;                 // [19] 0x182027EE0
    void Reset() override;                                 // [21] null
    std::uint8_t unk_32() override;                        // [32] 0x1D

    bool camera_unk_00() const override;                   // camera [0] 0x182024770
    void camera_unk_02() override;                         // camera [2] 0x182028630
    bool camera_unk_03() const override;                   // camera [3] true
    float camera_unk_04() const override;                  // camera [4] 0x182024050

    AssetScopeProperty m_assetScope;                       // +0x68
    StateProperty m_state;                                 // +0x90
    C_ForgeBuilder* m_self;                                // +0xB8
    S_ForgeBuilderRuntime m_runtime;                       // +0xC0
    wh::framework::I_UIForgeBuilder* m_ui;                 // +0x210
    std::vector<S_ForgeSlot*> m_slots;                     // +0x218
    std::vector<S_ForgeAsset*> m_assets;                   // +0x230
    std::int32_t m_slotIndex;                              // +0x248
    std::int32_t m_assetIndex;                             // +0x24C
    std::vector<std::pair<CryStringT<char>, std::int32_t>>
        m_uiEventCounts;                                   // +0x250
};

static_assert(sizeof(C_ForgeBuilder::AssetScopeProperty) == 0x28,
              "C_ForgeBuilder asset-scope property size mismatch");
static_assert(sizeof(C_ForgeBuilder::StateProperty) == 0x28,
              "C_ForgeBuilder state property size mismatch");
static_assert(sizeof(C_ForgeBuilder) == 0x268,
              "C_ForgeBuilder size mismatch");
static_assert(offsetof(C_ForgeBuilder, m_assetScope) == 0x68,
              "C_ForgeBuilder asset-scope offset mismatch");
static_assert(offsetof(C_ForgeBuilder, m_state) == 0x90,
              "C_ForgeBuilder state offset mismatch");
static_assert(offsetof(C_ForgeBuilder, m_runtime) == 0xC0,
              "C_ForgeBuilder runtime offset mismatch");
static_assert(offsetof(C_ForgeBuilder, m_ui) == 0x210,
              "C_ForgeBuilder UI offset mismatch");
static_assert(offsetof(C_ForgeBuilder, m_slots) == 0x218,
              "C_ForgeBuilder slots offset mismatch");
static_assert(offsetof(C_ForgeBuilder, m_assets) == 0x230,
              "C_ForgeBuilder assets offset mismatch");
static_assert(offsetof(C_ForgeBuilder, m_slotIndex) == 0x248,
              "C_ForgeBuilder slot index offset mismatch");
static_assert(offsetof(C_ForgeBuilder, m_uiEventCounts) == 0x250,
              "C_ForgeBuilder UI event table offset mismatch");

} // namespace wh::playermodule
