#pragma once

#include <cstddef>
#include <cstdint>

#include "I_CommonEditorProperties.h"

namespace wh::entitymodule {

class C_LightCommonEditorProperties : public I_CommonEditorProperties {
public:
    ~C_LightCommonEditorProperties();                       // Non-virtual 0x1803A5774
    void GetString08(CryStringT<char>* output) const override; // [0] 0x181A88160
    void GetColor(ColorF* output) const override;           // [1] 0x181285FB0
    void GetString20(CryStringT<char>* output) const override; // [2] 0x1816093C0
    void GetString28(CryStringT<char>* output) const override; // [3] 0x181A88150
    virtual void GetRuntimeTypeToken(std::uint64_t* output) const; // [4] 0x181A88170
    virtual void* QueryInterfaceMutable(const void* type);  // [5] 0x18047E2F4
    virtual const void* QueryInterfaceConst(const void* type) const; // [6] 0x18047E2F4

    CryStringT<char> m_string08;                            // +0x08
    ColorF m_color;                                         // +0x10
    CryStringT<char> m_string20;                            // +0x20
    CryStringT<char> m_string28;                            // +0x28
};

static_assert(offsetof(C_LightCommonEditorProperties, m_string08) == 0x08,
              "C_LightCommonEditorProperties::m_string08 offset mismatch");
static_assert(offsetof(C_LightCommonEditorProperties, m_color) == 0x10,
              "C_LightCommonEditorProperties::m_color offset mismatch");
static_assert(offsetof(C_LightCommonEditorProperties, m_string20) == 0x20,
              "C_LightCommonEditorProperties::m_string20 offset mismatch");
static_assert(sizeof(C_LightCommonEditorProperties) == 0x30,
              "C_LightCommonEditorProperties size mismatch");

}  // namespace wh::entitymodule
