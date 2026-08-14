#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "C_LinkableObject.h"
#include "C_Ownership.h"
#include "I_Area.h"

namespace wh::xgenaimodule {

// Runtime union of borrowed I_Area constituents. Membership comes from the
// area_union_member relation; Label text produces separate interned label IDs.
class C_AreaUnion
    : public C_LinkableObject,
      public I_Area {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AreaUnion;
    ~C_AreaUnion() override;                // [0] 0x1811A4CC4
    I_Ownership* GetOwnership() override;   // [11] 0x181AA49D0
    void _vf16() override;                  // [16] 0x181694CE8
    void _vf18() override;                  // [18] 0x18158F9C8

    bool Overlaps(const Vec3& pos) override; // I_Area [0] 0x1805CCF2C
    void ArVf1() override;  void ArVf2() override;
    AABB GetAABB() override;                 // [3] sub_180873BD4
    void ArVf4() override;  void ArVf5() override;  void ArVf6() override;
    void ArVf7() override;  void ArVf8() override;  void ArVf9() override;
    void ArVf10() override; void ArVf11() override; void ArVf12() override;
    void ArVf13() override; void ArVf14() override; void ArVf15() override;
    void ArVf16() override;

    std::vector<I_Area*> m_memberAreas;          // +0x68, borrowed relation targets
    std::vector<std::uint32_t> m_labelIds;       // +0x80, ordered unique interned Label tokens
    std::uint8_t _unknown98[0x30];               // +0x98, two vector-layout area-state members; element types OPEN
    I_Area* m_areaBackPtr;                       // +0xC8, borrowed self-pointer to the I_Area subobject
    std::uint8_t _flagD0;                        // +0xD0, area-state input; exact source role OPEN
    bool m_registered;                           // +0xD1, registered with the area subsystem
    std::uint8_t _padD2[6];                      // +0xD2
    C_Ownership m_ownership;                     // +0xD8
};
static_assert(sizeof(C_AreaUnion) == 0x108,
              "C_AreaUnion must be 0x108");
static_assert(offsetof(C_AreaUnion, m_memberAreas) == 0x68,
              "member-area vector must be at 0x68");
static_assert(offsetof(C_AreaUnion, m_labelIds) == 0x80,
              "label-ID vector must be at 0x80");
static_assert(offsetof(C_AreaUnion, m_areaBackPtr) == 0xC8,
              "I_Area back-pointer must be at 0xC8");
static_assert(offsetof(C_AreaUnion, m_ownership) == 0xD8,
              "ownership component must be at 0xD8");

}  // namespace wh::xgenaimodule
