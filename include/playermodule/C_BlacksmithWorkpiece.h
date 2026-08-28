#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::playermodule {

class C_BlacksmithWorkpiece {
public:
    RTTR_ENABLE()                                           // [0..2]

    CryStringT<char> m_id;                                  // +0x08 RTTR "Id"
    CryStringT<char> m_model;                               // +0x10 RTTR "Model"
    CryStringT<char> m_tag;                                 // +0x18 RTTR "Tag"
    CryStringT<char> m_audioSwitch;                         // +0x20 RTTR "AudioSwitch"
    std::uint32_t m_zones;                                  // +0x28 RTTR "Zones"
    bool m_useTongs;                                        // +0x2C RTTR "UseTongs"
    std::uint8_t _pad2D[3];                                 // +0x2D
    CryStringT<char> m_raycastAttachment;                   // +0x30 RTTR "RaycastAttachment"
    Vec2_tpl<float> m_initialPosition;                      // +0x38 RTTR "InitialPosition"
    Vec2_tpl<float> m_mapSize;                              // +0x40 RTTR "MapSize"
    Vec2_tpl<float> m_mapOffset;                            // +0x48 RTTR "MapOffset"
    Ang3_tpl<float> m_mapRotation;                          // +0x50 RTTR "MapRotation"
    Vec2_tpl<float> m_startMinPosition;                     // +0x5C RTTR "StartMinPosition"
    Vec2_tpl<float> m_endMinPosition;                       // +0x64 RTTR "EndMinPosition"
    Vec2_tpl<float> m_startMaxPosition;                     // +0x6C RTTR "StartMaxPosition"
    Vec2_tpl<float> m_endMaxPosition;                       // +0x74 RTTR "EndMaxPosition"
    std::uint8_t _pad7C[4];                                 // +0x7C
};

static_assert(offsetof(C_BlacksmithWorkpiece, m_id) == 0x08,
              "C_BlacksmithWorkpiece::m_id offset mismatch");
static_assert(offsetof(C_BlacksmithWorkpiece, m_initialPosition) == 0x38,
              "C_BlacksmithWorkpiece::m_initialPosition offset mismatch");
static_assert(offsetof(C_BlacksmithWorkpiece, m_mapRotation) == 0x50,
              "C_BlacksmithWorkpiece::m_mapRotation offset mismatch");
static_assert(offsetof(C_BlacksmithWorkpiece, m_endMaxPosition) == 0x74,
              "C_BlacksmithWorkpiece::m_endMaxPosition offset mismatch");
static_assert(sizeof(C_BlacksmithWorkpiece) == 0x80,
              "C_BlacksmithWorkpiece size mismatch");

}  // namespace wh::playermodule
