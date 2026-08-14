#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>
#include "I_PositionAndOrientation.h"
#include "S_SmartHelperLink.h"
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::xgenaimodule {

// Shared helper definition loaded from Libs/SmartObjects.xml.
class C_SmartHelper : public I_PositionAndOrientation {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SmartHelper;
    Vec3* GetPosition() override;       // [0] 0x181A72EB0
    Quat* GetOrientation() override;    // [1] 0x181A7FB20
    ~C_SmartHelper() override;          // [2] 0x183442294

    std::int32_t m_ordinal;                            // +0x08, class-local
    std::uint32_t _pad0C;                              // +0x0C
    CryStringT<char> m_name;                           // +0x10
    Vec3 m_position;                                   // +0x18
    Quat m_orientation;                                // +0x24
    std::uint32_t _pad34;                              // +0x34
    std::vector<CryStringT<char>> m_userDataValues;    // +0x38
    std::int32_t m_specialValueIndex50;                // +0x50, initialized -1
    std::int32_t m_specialValueIndex54;                // +0x54, initialized -1
    std::unordered_map<CryStringT<char>, std::size_t>
        m_userDataIndices;                             // +0x58
    std::vector<S_SmartHelperLink> m_links;            // +0x98
    std::uint8_t _unknownB0[0x88];                     // +0xB0, runtime caches
    bool m_flag138;                                    // +0x138
    std::uint8_t _pad139[7];                           // +0x139
};
static_assert(sizeof(C_SmartHelper) == 0x140,
              "C_SmartHelper must be 0x140");
static_assert(offsetof(C_SmartHelper, m_name) == 0x10,
              "helper name must be at 0x10");
static_assert(offsetof(C_SmartHelper, m_userDataIndices) == 0x58,
              "user-data index must be at 0x58");
static_assert(offsetof(C_SmartHelper, m_links) == 0x98,
              "helper links must be at 0x98");

}  // namespace wh::xgenaimodule
