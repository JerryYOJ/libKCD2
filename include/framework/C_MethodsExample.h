#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"
#include "E_EnumExample.h"

namespace wh::framework {

class C_MethodsExample {
public:
    virtual ~C_MethodsExample();                            // [0]
    RTTR_ENABLE()                                           // [1..3]

    CryStringT<char> SayHello();
    CryStringT<char> SayHelloTo(const CryStringT<char>& name);
    float MultiplyNumbers(float a, float b);
    CryStringT<char> DefaultArguments(
        CryStringT<char> name, int age, E_EnumExample::Type place);
    void DoNothing();
};

static_assert(sizeof(C_MethodsExample) == 0x08,
              "C_MethodsExample size mismatch");

}  // namespace wh::framework
