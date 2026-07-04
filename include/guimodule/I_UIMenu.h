#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::I_UIMenu -- KCD2 WHGame.dll 1.5.6 (kd7u).  Pure interface (vtable only).
// -----------------------------------------------
// RTTI .?AVI_UIMenu@wh@@ -- note the namespace is plain `wh`, NOT wh::guimodule (the
// menu facade is consumed from outside the module); the header lives in guimodule/
// because its only implementer does.
//
// 19-slot interface implemented by C_UIMenu at subobject +0x58 (COL 0x4381D08, vtable
// 0x183EF5958). NEW vs KCD1 (no TD there). Slot roles below are derived from the
// C_UIMenu implementation bodies; names are behavior-coined and individually flagged.
// [10..15] are C_Signal connect/disconnect pairs -- the KCD2 idiom of exposing signal
// subscription through owner vtable thunks (see framework/C_Signal.h): each takes the
// 0x10 {instance, invoke} S_Delegate by pointer/value.

namespace wh {

struct S_UIDelegate;   // 0x10 {void* instance, void* invoke} -- see wh::shared::S_Delegate

class I_UIMenu {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_UIMenu;
    virtual ~I_UIMenu();                                  // [0]  thunk sub_18213A6F8
    virtual void Open(char mode) = 0;                     // [1]  0x180C04B38  (name UNVERIFIED; [3] re-enters it with mode 3)
    virtual void Close() = 0;                             // [2]  0x180C04780  (name UNVERIFIED)
    virtual void _vf3() = 0;                              // [3]  0x181F8D450  Open(3) + saveload-substruct op (UNVERIFIED)
    virtual void _vf4() = 0;                              // [4]  0x181F8C0D0  Close() unless GetState() in {1,4} (UNVERIFIED)
    virtual void SetPhotomodeVisibility(bool bVisible) = 0; // [5] 0x181F8DB40  flash CallFunction("SetPhotomodeVisibility", b) -- name from the flash literal
    virtual void _vf6(bool) = 0;                          // [6]  0x182BA8CF8  forwards bool to a module-resolved object (sub_180ED5038 -> sub_180C09E44) (UNVERIFIED)
    virtual bool _vf7() = 0;                              // [7]  0x182BAAEAC  gate check: open-state byte + player-profile queries (UNVERIFIED)
    virtual void _vf8(uint16_t id) = 0;                   // [8]  0x182BAAF50  framework vf[+0x70](id) check then vf[+0x68](0,id,0,0) (UNVERIFIED)
    virtual bool GetState() const = 0;                    // [9]  0x181A7F740  returns the +0xA0 state byte (name UNVERIFIED)
    // Three C_Signal subscription points (pairs; which of each pair is Connect vs
    // Disconnect is UNVERIFIED -- helpers sub_180615B40 / sub_180615ABC):
    virtual void ConnectSignalA(const S_UIDelegate&) = 0;     // [10] 0x1806159F4  signal @+0x70
    virtual void DisconnectSignalA(const S_UIDelegate&) = 0;  // [11] 0x1806159CC
    virtual void ConnectSignalB(const S_UIDelegate&) = 0;     // [12] 0x180615120  signal @+0x80
    virtual void DisconnectSignalB(const S_UIDelegate&) = 0;  // [13] 0x1806150F8
    virtual void ConnectSignalC(const S_UIDelegate&) = 0;     // [14] 0x182BA6C08  signal @+0x90 (helper pair sub_1804CD938/sub_1804CD6C8)
    virtual void DisconnectSignalC(const S_UIDelegate&) = 0;  // [15] 0x182BA6DF0
    virtual void _vf16() = 0;                             // [16] thunk sub_18213A7D0 (UNVERIFIED)
    virtual void _vf17() = 0;                             // [17] thunk sub_18213A5FC (UNVERIFIED)
    virtual void _vf18() = 0;                             // [18] thunk sub_18213A7B8 (UNVERIFIED)
};
static_assert(sizeof(I_UIMenu) == 8);

}  // namespace wh
