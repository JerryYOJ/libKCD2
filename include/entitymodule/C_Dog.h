#pragma once
#include <cstddef>
#include <cstdint>
#include "C_Animal.h"
#include "../CryEngine/CryCommon/smartptr.h"

namespace wh::entitymodule {

class C_BaseAction;

class C_Dog : public C_Animal {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Dog;

    ~C_Dog() override;                                           // [0] 0x18167E32C
    bool Init(Offsets::IGameObject* gameObject) override;        // [7] 0x180AE4038
    const char* GetActorClassName() override;                    // [83] 0x1818C92F0
    int GetActorClass() override;                                // [84] 0x181A83AC0, returns 0x12
    void _vf145() override;                                      // [145] 0x1806CFDC4
    void _vf151() override;                                      // [151] 0x181636190
    void _vf154(bool enabled) override;                          // [154] 0x180BDFEF0
    void* _vf192() override;                                     // [192] 0x1829E129C
    void _vf196() override;                                      // [196] 0x1813619B0
    bool _vf257() override;                                      // [257] 0x18041A6A0
    void _vf270() override;                                      // [270] 0x181646708
    void _vf275(void* argument) override;                        // [275] nullsub, suppresses Animal hook
    virtual void _vf280();                                       // [280] 0x1829E2240

    _smart_ptr<C_BaseAction> m_pBaseAction;                      // +0x9E8, owning shape; exact wrapper typedef OPEN
    std::uint32_t m_dogStaminaId;                               // +0x9F0
    float m_dogCompStamina;                                      // +0x9F4, init -1.0f
};

static_assert(sizeof(_smart_ptr<C_BaseAction>) == 0x08,
              "Dog action smart pointer must be 0x08");
static_assert(sizeof(C_Dog) == 0x9F8,
              "C_Dog must be 0x9F8");
static_assert(offsetof(C_Dog, m_pBaseAction) == 0x9E8,
              "Dog base action must be at 0x9E8");
static_assert(offsetof(C_Dog, m_dogStaminaId) == 0x9F0,
              "Dog stamina id must be at 0x9F0");
static_assert(offsetof(C_Dog, m_dogCompStamina) == 0x9F4,
              "Dog companion stamina must be at 0x9F4");

}  // namespace wh::entitymodule
