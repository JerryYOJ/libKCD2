#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <optional>
#include <vector>

#include "../conceptmodule/C_ModuleBase.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../framework/C_NumberWrapper.h"
#include "../framework/S_TimeSpan.h"
#include "../rpgmodule/E_RandomEventOption.h"
#include "E_RandomEventOptionResult.h"
#include "S_RandomEventFastTravelData.h"

namespace wh::playermodule {

struct S_RandomEventOption;

using C_RandomEventDifficultyValue = wh::framework::C_NumberWrapper<
    wh::framework::NumberWrapperPolicy::Clamp<
        0, 1, float, std::true_type, std::true_type>>;
using C_RandomEventNonNegativeValue = wh::framework::C_NumberWrapper<
    wh::framework::NumberWrapperPolicy::LowerBounded<
        0, float, std::false_type, std::true_type, std::true_type>>;

class C_RandomEventVariantBase : public wh::conceptmodule::C_ModuleBase {
public:
    struct S_NpcGroup;
    using NpcGroupSink = std::function<void(S_NpcGroup const&)>;

    C_RandomEventVariantBase();
    ~C_RandomEventVariantBase() override;                     // [0] 0x181979988
    RTTR_ENABLE(wh::conceptmodule::C_ModuleBase) // [5..7]
    rttr::variant GetPortValue(
        _smart_ptr<wh::conceptmodule::I_Port> const& port) override; // [12] 0x18147764C
    void Wake(
        std::vector<_smart_ptr<wh::conceptmodule::C_Node>>& changed,
        wh::conceptmodule::E_NodeWakeReason reason) override; // [21] 0x1817EF65C
    void Reset() override;                                    // [37] 0x1804C51BC
    std::uint8_t GetModuleKind() const override;              // [44] 0x181A74A40

    virtual CryStringT<char> GetProfile() const;              // [55] 0x181437814
    virtual bool GetDespawnOnTimeskip() const;                // [56] false
    virtual void EnumerateNpcGroups(NpcGroupSink sink) const; // [57] 0x18061DF80
    virtual std::shared_ptr<S_RandomEventFastTravelData>
        GetFastTravelData(float direction, bool requireOptions) const; // [58] 0x182ECD6C8
    virtual std::vector<S_RandomEventOption*>
        GetFastTravelOptions() const;                         // [59] 0x182ECD558
    virtual void InitializeVariant();                         // [60] 0x181421AF0
    virtual bool IsAvailable() const;                         // [61] 0x18142D338
    virtual bool HasTag(CryStringT<char> const& tag) const;   // [62] false
    virtual bool HasFastTravelOptions() const;                // [63] 0x182ECE060

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onSpawn;              // +0xA0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onDespawn;            // +0xE0
    wh::conceptmodule::C_TypedPortRef<bool> m_isSpawned;     // +0x120
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::E_RandomEventOption::Type> m_randomEventOption; // +0x160
    wh::conceptmodule::C_TypedPortRef<
        E_RandomEventOptionResult::Type> m_randomEventOptionResult; // +0x1A0
    wh::conceptmodule::C_TypedPortRef<bool> m_isEnabled;     // +0x1E0
    std::shared_ptr<S_RandomEventFastTravelData>
        m_eventInitiatedFastTravelData;                       // +0x220
    bool m_initialized;                                       // +0x230
    std::uint8_t m_padding231[3];
    std::optional<float> m_weight;                            // +0x234
    std::optional<C_RandomEventDifficultyValue> m_difficultyMean; // +0x23C
    std::optional<C_RandomEventNonNegativeValue>
        m_difficultyStandardDeviation;                        // +0x244
    std::uint8_t m_padding24C[4];
    std::optional<wh::framework::S_TimeSpan> m_cooldownOverride; // +0x250
    std::optional<bool> m_isAbstract;                         // +0x260
    std::optional<bool> m_isGuaranteed;                       // +0x262
    std::uint8_t m_padding264[4];
    std::optional<wh::framework::S_TimeSpan> m_mapTimeout;   // +0x268
    std::optional<float> m_viewRadius;                        // +0x278
};

static_assert(sizeof(C_RandomEventVariantBase) == 0x280,
              "C_RandomEventVariantBase size mismatch");
static_assert(offsetof(C_RandomEventVariantBase, m_onSpawn) == 0xA0,
              "C_RandomEventVariantBase spawn offset mismatch");
static_assert(offsetof(C_RandomEventVariantBase, m_isEnabled) == 0x1E0,
              "C_RandomEventVariantBase enabled offset mismatch");
static_assert(offsetof(C_RandomEventVariantBase,
                       m_eventInitiatedFastTravelData) == 0x220,
              "C_RandomEventVariantBase fast-travel data offset mismatch");
static_assert(offsetof(C_RandomEventVariantBase, m_weight) == 0x234,
              "C_RandomEventVariantBase weight offset mismatch");
static_assert(offsetof(C_RandomEventVariantBase, m_mapTimeout) == 0x268,
              "C_RandomEventVariantBase map timeout offset mismatch");
static_assert(offsetof(C_RandomEventVariantBase, m_viewRadius) == 0x278,
              "C_RandomEventVariantBase view radius offset mismatch");

} // namespace wh::playermodule
