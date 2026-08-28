#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/IEntityProxy.h"

namespace wh::entitymodule {

class I_GameObjectLight : public Offsets::IEntityProxy {
public:
    ~I_GameObjectLight() override;                           // [0] 0x182878DB0
    void ProcessEvent(SEntityEvent& event) override;         // [1]
    bool _vf2() override;                                    // [2]
    int GetEventPriority(int eventId) override;              // [3]
    void _vf4() override;                                    // [4]
    Offsets::IEntity* GetEntity() override;                  // [5]
    void _vf6() override;                                    // [6]
    void _vf7() override;                                    // [7]
    void _vf8() override;                                    // [8]
    void _vf9() override;                                    // [9]
    void _vf10() override;                                   // [10]
    // [11] remains pure in the standalone interface.
    void _vf12() override;                                   // [12]
    void _vf13(std::uint64_t* value) override;               // [13]
    void _vf14() override;                                   // [14]
    void _vf15() override;                                   // [15]
    virtual bool _vf16();                                    // [16] 0x18041A6A0
    virtual void _vf17();                                    // [17] 0x1803B6E80
    virtual void _vf18();                                    // [18] 0x1803B6E80
    virtual void GetRuntimeTypeToken(std::uint64_t* output) const; // [19] 0x181A88180
    virtual void* QueryInterfaceMutable(const void* type);   // [20] 0x18047E2C8
    virtual const void* QueryInterfaceConst(const void* type) const; // [21] 0x18047E2C8

    Offsets::IEntity* m_entity;                              // +0x28
};

static_assert(offsetof(I_GameObjectLight, m_entity) == 0x28,
              "I_GameObjectLight::m_entity offset mismatch");
static_assert(sizeof(I_GameObjectLight) == 0x30,
              "I_GameObjectLight size mismatch");

}  // namespace wh::entitymodule
