#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include "../CryEngine/CryCommon/Cry_Color.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"
#include "E_EnumExample.h"

namespace wh::framework {

class C_SimpleTypesExample {
public:
    virtual ~C_SimpleTypesExample();                        // [0]
    RTTR_ENABLE()                                           // [1..3]

    bool m_bool;                                            // +0x08 RTTR "Bool"
    std::uint8_t _pad09[3];                                 // +0x09
    int m_int;                                              // +0x0C RTTR "Int"
    std::uint32_t m_unsignedInt;                            // +0x10 RTTR "UnsignedInt"
    float m_float;                                          // +0x14 RTTR "Float"
    double m_double;                                        // +0x18 RTTR "Double"
    CryStringT<char> m_string;                              // +0x20 RTTR "String"
    std::string m_stdString;                                // +0x28 RTTR "StdString"
    E_EnumExample::Type m_enum;                             // +0x48 RTTR "Enum"
    std::uint8_t _pad49[3];                                 // +0x49
    Vec3_tpl<float> m_vector3;                              // +0x4C RTTR "Vector3"
    Color_tpl<float> m_color;                               // +0x58 RTTR "Color"
};

static_assert(offsetof(C_SimpleTypesExample, m_bool) == 0x08,
              "C_SimpleTypesExample::m_bool offset mismatch");
static_assert(offsetof(C_SimpleTypesExample, m_double) == 0x18,
              "C_SimpleTypesExample::m_double offset mismatch");
static_assert(offsetof(C_SimpleTypesExample, m_stdString) == 0x28,
              "C_SimpleTypesExample::m_stdString offset mismatch");
static_assert(offsetof(C_SimpleTypesExample, m_vector3) == 0x4C,
              "C_SimpleTypesExample::m_vector3 offset mismatch");
static_assert(sizeof(C_SimpleTypesExample) == 0x68,
              "C_SimpleTypesExample size mismatch");

}  // namespace wh::framework
