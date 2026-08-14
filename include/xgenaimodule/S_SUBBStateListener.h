#pragma once
#include <cstdint>

namespace wh::xgenaimodule {

class C_SUBBBase;
struct S_SUBBStateListener;
using SUBBStateCallback = void (__fastcall*)(
    S_SUBBStateListener*, C_SUBBBase*, std::uint32_t, std::uint32_t);

struct S_SUBBStateListener {
    void* m_pDispatch;               // +0x00, dispatch thunk; exact signature OPEN
    void* _unknown08;                // +0x08
    C_SUBBBase* m_pContext;          // +0x10
    SUBBStateCallback m_pCallback;   // +0x18
};
static_assert(sizeof(S_SUBBStateListener) == 0x20,
              "S_SUBBStateListener must be 0x20");

}  // namespace wh::xgenaimodule
