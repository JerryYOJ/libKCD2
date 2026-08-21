#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../conceptmodule/C_AutoTriggerable.h"
#include "../conceptmodule/C_Node.h"
#include "../conceptmodule/C_PortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"

// -----------------------------------------------
// wh::animationmodule::C_FocusCameraNode -- concept-graph node that focuses the
// player view on a target (KCD2 WHGame.dll Steam 1.5.6, sjw7).  Vtable 0x183b75990;
// sizeof UNKNOWN (>= 0x250).  rttr type "wh::animationmodule::FocusCamera".
// -----------------------------------------------
// One of only TWO installers of C_FocusCamera setups in the image (the other is the
// combat lock path sub_1808B8548).  Camera/animation asset graphs instantiate it --
// the mounted riding rig runs one targeting the HORSE, which is what makes the view
// turn with the horse (see game/C_FocusCamera.h).
// [43] InstallSetup_1827DBE94: resolves the target port (sub_1823D372C on +0x88;
// tag-9 WUID id provider sub_1827D7E80 or direct-object provider sub_1827D7F28),
// builds an S_FocusCameraSetup from the ports below and installs it on the local
// player's C_FocusCamera (client actor +0xCF0); removal id stored at +0x24C.
// Own members start at +0x40 (C_AutoTriggerable<C_Node> adds no data over C_Node's
// 0x40); ports are embedded at the usual 0x40 stride.  +0x48 is assumed to be a
// port purely from the stride (UNVERIFIED); untyped ports are declared as the
// C_PortRef base (C_TypedPortRef<T> adds nothing).

namespace wh::animationmodule {

class C_FocusCameraNode : public conceptmodule::C_AutoTriggerable<conceptmodule::C_Node> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FocusCameraNode;
    RTTR_ENABLE(conceptmodule::C_AutoTriggerable<conceptmodule::C_Node>)  // trio; rttr type "wh::animationmodule::FocusCamera"
    virtual int64_t InstallSetup();                        // [43] 0x1827DBE94 build + install S_FocusCameraSetup (name descriptive; may be an On*-style handler)

    uint64_t m_unk40;                                      // +0x40
    conceptmodule::C_PortRef m_port48;                     // +0x48  assumed port slot (stride); value type UNIDENTIFIED
    conceptmodule::C_PortRef m_targetPort;                 // +0x88  focus target (object/WUID; resolved by sub_1823D372C)
    conceptmodule::C_TypedPortRef<Vec2> m_limitPairPortB;  // +0xC8  optional angle-limit pair -> setup+0x24 group
    conceptmodule::C_TypedPortRef<Vec2> m_limitPairPortA;  // +0x108 optional angle-limit pair -> setup+0x18 group
    conceptmodule::C_TypedPortRef<float> m_stiffnessPort;  // +0x148 -> setup+0x30 (via sub_181202F10)
    conceptmodule::C_PortRef m_modePort;                   // +0x188 -> setup+0x04 mode byte (via sub_1827D9008 on +0x188)
    uint8_t  _pad1C8[0x84];                                // +0x1C8
    int32_t  m_setupId;                                    // +0x24C removal id returned by C_FocusCamera::Install_1808B811C
    // trailing members UNRECOVERED -- no sizeof assert
};
static_assert(offsetof(C_FocusCameraNode, m_targetPort) == 0x88);
static_assert(offsetof(C_FocusCameraNode, m_limitPairPortB) == 0xC8);
static_assert(offsetof(C_FocusCameraNode, m_stiffnessPort) == 0x148);
static_assert(offsetof(C_FocusCameraNode, m_setupId) == 0x24C);

}  // namespace wh::animationmodule
