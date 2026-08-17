#pragma once
#include <cstdint>
#include <vector>

// -----------------------------------------------
// wh::xgenaimodule::navigation::I_NavigationElement -- one leg of a found path
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x20.
// -----------------------------------------------
// RTTI .?AVI_NavigationElement@navigation@xgenaimodule@wh@@.  Interface vtable
// 0x183A6AC10, 11 slots (0-10). Not vptr-only: ctor sub_18059D004 writes the
// vector at +0x08. GetPoints [1] is `return this + 8` on every walk-derived
// implementor (WalkBase / MNM / Path / Smart).

namespace wh::xgenaimodule::navigation {

class I_NavigationElement {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_NavigationElement;
    virtual ~I_NavigationElement() = default;               // [0]
    virtual std::vector<Vec3>* GetPoints() = 0;             // [1] 0x181A71D30  this+8
    virtual float unk_2() = 0;                              // [2] 0x181A730F0  returns 0.0
    virtual float GetLength() = 0;                          // [3] 0x1809FF5E0  polyline length
    virtual void unk_4() = 0;                               // [4] pure on the interface
    virtual float unk_5() = 0;                              // [5] 0x181A730F0  returns 0.0
    virtual int32_t GetType() = 0;                          // [6] [name INFERRED]
    virtual void unk_7() = 0;                               // [7]
    virtual void unk_8() = 0;                               // [8]
    virtual void unk_9() = 0;                               // [9]
    virtual void unk_10() = 0;                              // [10]

    std::vector<Vec3> m_points;                             // +0x08
};
static_assert(sizeof(I_NavigationElement) == 0x20, "I_NavigationElement is vptr + Vec3 vector");
static_assert(offsetof(I_NavigationElement, m_points) == 0x08, "point list at +0x08");

}  // namespace wh::xgenaimodule::navigation
