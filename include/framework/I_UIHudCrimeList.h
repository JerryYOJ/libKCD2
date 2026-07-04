#pragma once

// -----------------------------------------------
// wh::framework::I_UIHudCrimeList -- KCD2 WHGame.dll 1.5.6 (kd7u).  Pure interface, 6 slots.
// -----------------------------------------------
// RTTI .?AVI_UIHudCrimeList@framework@wh@@ (TD 0x184CD0B00). Framework-side face of the
// dialogue crime-list overlay; C_UIHudCrimeList implements it @+0x58 (vtable 0x183C336B8)
// and registers the subobject with the crime feedback object reached via
// *(ctx+0x160)+0xA8 -> vf[+0x1A8]() -> vf[1](this+0x58) (Init sub_1819278A0).
// Slot bodies (C_UIHudCrimeList impls):
//   [0] deleting-dtor thunk 0x18213A458 (-0x58 -> 0x182B8BDA4)
//   [1] 0x182B8EB30  builds the entry array from a {begin,end} list of 72-byte crime
//       records and flash-calls "CrimeListData"(array) + "ShowCrimeList"(duration*0.1)
//   [2] 0x182B8DA68  flash "HideCrimeList"()
//   [3..5] RTTR_ENABLE() trio thunks (0x18213A62C/0x18213A5FC/0x18213A578)
// Method names coined from the flash call names; a2 element type UNVERIFIED.

namespace rttr {
class type;
namespace detail { struct derived_info; }
}  // namespace rttr

namespace wh::framework {

class I_UIHudCrimeList {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_UIHudCrimeList;
    virtual ~I_UIHudCrimeList();                                 // [0]
    virtual void ShowCrimeList(const void* pCrimeData) = 0;      // [1] 0x182B8EB30 flash "CrimeListData"+"ShowCrimeList"
    virtual void HideCrimeList() = 0;                            // [2] 0x182B8DA68 flash "HideCrimeList"
    // RTTR_ENABLE() trio.
    virtual rttr::type get_type() const;                         // [3]
    virtual void* get_ptr();                                     // [4]
    virtual rttr::detail::derived_info get_derived_info();       // [5]
};
static_assert(sizeof(I_UIHudCrimeList) == 8);

}  // namespace wh::framework
