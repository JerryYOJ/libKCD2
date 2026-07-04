#pragma once
#include <cstdint>
#include "../framework/C_BaseModule.h"
#include "../REL.h"

// -----------------------------------------------
// wh::conceptmodule::C_ConceptModule -- module root (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x48.
// -----------------------------------------------
// NEW module in KCD2 (hosts the rttr node-graph effect system -- see C_SharedResource/C_Node/
// C_Effect in this dir). RTTI .?AVC_ConceptModule@conceptmodule@wh@@  ctor sub_180BE88E8
// (alloc 0x48 == sizeof, module bootstrap sub_180C9DA44, registry slot [36] @+0x120).
// Publishes the undisplaced instance to global qword_185480280.
//
// Owned sub-objects (all heap, released via the module dtor):
//   C_ResourceRegistry   (0x48, ctor sub_180BE97D8: float 1.0 @+0x08, intrusive dlist @+0x10,
//                          bucket array @+0x20, 7/8 counters @+0x38/+0x40)
//   C_ConceptManager     (0x380, ctor sub_1807CE780: embeds C_ConceptResourceResolver<
//                          _smart_ptr<C_SharedResource>, unsigned int> @+0x10, SRWLOCK @+0x18,
//                          800000 budget, listener registration via registry service +0x148)
//   C_CallbackScenePlayer(0x40, intrusive-list node @+0x18)

namespace wh::conceptmodule {

class C_ResourceRegistry;      // 0x48 (layout unresolved beyond ctor writes)
class C_ConceptManager;        // 0x380 (layout unresolved beyond ctor writes)
class C_CallbackScenePlayer;   // 0x40

class C_ConceptModule : public wh::framework::C_BaseModule {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ConceptModule;
    [[nodiscard]] static C_ConceptModule* GetInstance()
    {
        // qword_185480280 -- written by the ctor.
        return *reinterpret_cast<C_ConceptModule**>(REL::Offset(0x5480280).address());
    }

    C_ResourceRegistry*    m_pResourceRegistry;   // +0x10
    C_ConceptManager*      m_pConceptManager;     // +0x18
    void*                  m_pByte20;             // +0x20  heap 1-byte raw alloc (tag/flag cell; role unresolved)
    void*                  m_pBlock28;            // +0x28  heap 0x40 zero-filled block (no vtable; role unresolved)
    int32_t                m_int30;               // +0x30  ctor 0 (role unresolved)
    uint32_t               _pad34;                // +0x34
    void*                  m_pByte38;             // +0x38  heap 1-byte raw alloc (role unresolved)
    C_CallbackScenePlayer* m_pScenePlayer;        // +0x40
};
static_assert(sizeof(C_ConceptModule) == 0x48, "C_ConceptModule must be 0x48");

}  // namespace wh::conceptmodule
