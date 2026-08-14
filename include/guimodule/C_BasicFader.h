#pragma once
#include <cstddef>

// -----------------------------------------------
// wh::guimodule::C_BasicFader<TController> -- keyed fade-operation worker
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x20 for C_FaderController.
// -----------------------------------------------
// Specialization RTTI .?AV?$C_BasicFader@VC_FaderController@guimodule@wh@@@guimodule@wh@@;
// ctor sub_1808DD5C0, non-virtual dtor sub_1808DD128, deleting helper sub_18194B6E0.
// The two-slot vtable is 0x183A5CFE8; neither slot is a destructor.

namespace wh::guimodule {

class C_FaderController;

template <typename TController>
class C_BasicFader {
public:
    ~C_BasicFader();                    // sub_1808DD128
    virtual void unk_00(void* pSink); // [0] sub_180A59358
    virtual void unk_01(void* pSink); // [1] sub_1827FE4C8

    TController*      m_pController; // +0x08
    CryStringT<char>  m_name;        // +0x10
    void*             m_pDetails;    // +0x18  optional polymorphic detail object; type OPEN
};
static_assert(sizeof(C_BasicFader<C_FaderController>) == 0x20,
              "C_BasicFader<C_FaderController> must be 0x20");
static_assert(offsetof(C_BasicFader<C_FaderController>, m_name) == 0x10,
              "C_BasicFader name must be at +0x10");

}  // namespace wh::guimodule
