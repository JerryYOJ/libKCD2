#pragma once

#include <cstddef>

#include "../CryEngine/CryCommon/Cry_Color.h"
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::entitymodule {

class I_CommonEditorProperties {
public:
    virtual void GetString08(CryStringT<char>* output) const = 0; // [0]
    virtual void GetColor(ColorF* output) const = 0;              // [1]
    virtual void GetString20(CryStringT<char>* output) const = 0; // [2]
    virtual void GetString28(CryStringT<char>* output) const = 0; // [3]
};

static_assert(sizeof(I_CommonEditorProperties) == 0x08,
              "I_CommonEditorProperties size mismatch");

}  // namespace wh::entitymodule
