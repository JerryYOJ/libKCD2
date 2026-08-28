#pragma once
#include <cstdint>
#include "../framework/WUID.h"
#include "../rpgmodule/I_RPGShop.h"

namespace wh::entitymodule { class C_Item; }

namespace wh::shopmodule {

class I_Shop : public wh::rpgmodule::I_RPGShop {
public:
    ~I_Shop() override = default;                             // [0] 0x182EF3100
    virtual void unk_03(wh::framework::WUID* result) const = 0; // [3]
    virtual const wh::framework::WUID& unk_04() const = 0;    // [4]
    virtual bool unk_05(const wh::framework::WUID& value) const = 0; // [5]
    virtual void unk_06(const wh::framework::WUID& value) = 0; // [6]
    virtual void unk_07(void* a2, void* a3, void* a4) = 0;    // [7]
    virtual wh::entitymodule::C_Item* unk_08(
        wh::entitymodule::C_Item* item,
        std::uint32_t amount) = 0;                            // [8]
    virtual void unk_09(std::uint32_t* result) const = 0;     // [9]
    virtual void SetHagglingEnabled(bool enabled) = 0;        // [10]
    virtual bool CanHaggle() const = 0;                       // [11]
    virtual const char* GetHagglingDisabledReason() const = 0; // [12]
};

static_assert(sizeof(I_Shop) == 0x08, "I_Shop size mismatch");

}  // namespace wh::shopmodule
