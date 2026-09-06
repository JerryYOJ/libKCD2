#pragma once
#include <cstdint>
#include "../Offsets/Offsets_VTABLE.h"
#include "../Offsets/vtables/IMovieSystem.h"
#include "SCameraParams.h"

// 0x10 recursive SRW lock {void* Ptr; uint32 ownerTid; uint32 recursion} (ctor InitializeSRWLock)
struct S_RecursiveSRWLock { void* Ptr; uint32_t ownerTid; uint32_t recursion; };
struct IMovieListener;

// Capture-key blob embedded at +0x140 (sizeof 0xA20; ctor 0x180D620AC, defaults from
// capture_folder / capture_file_prefix / capture_file_format CVars; "tga" default).
struct ICaptureKey {
    float    time;                 // +0x000  IKey
    int      flags;                // +0x004  IKey
    int      duration;             // +0x008
    float    timeStep;             // +0x00C  default 0.0333 (0x3D072B02)
    char     folder[0x800];        // +0x010
    bool     once;                 // +0x810
    char     prefix[0x200];        // +0x811
    uint8_t  _padA11[3];           // +0xA11
    int      captureBufferIndex;   // +0xA14
    const char* captureFileFormat; // +0xA18  points at format CVar string
};
static_assert(sizeof(ICaptureKey) == 0xA20, "ICaptureKey size mismatch");


// -----------------------------------------------
// CMovieSystem : IMovieSystem  (CryMovie / TrackView) -- KCD2 WHGame.dll 1.5.6 (kd7u)
// -----------------------------------------------
// RTTI ??_7CMovieSystem@@6B@   primary vtable 0x18407E648   ctor sub_180D61DA4
// sizeof 0xBC8 (scalar-deleting dtor slot0 @0x18387B080 -> operator delete(this,3016)).
// Single base (IMovieSystem @ +0x00). GetCameraParams=slot59, SetCameraParams=slot60.
//
// [FUNDAMENTAL vs KCD1] primary vtable RVA 0x279FD10 -> 0x407E648, and the get/set
// camera-params pair shifted +2 (vtable grew 92->93 slots): SetCameraParams slot 58 -> 60.
// [MODERATE vs KCD1] m_pUser +0x70->+0x40, m_pCallback +0x78->+0x48, m_cameraParams +0xE4->+0x118.

namespace Offsets { struct ISystem; struct IMovieUser; struct IMovieCallback; }

// forward decls for not-yet-RE'd pointee types (stage-2 auto)
class IAnimSequence;

struct CMovieSystem : Offsets::IMovieSystem {   // vtable @ +0x00
    inline static constexpr auto VTABLE = Offsets::VTABLE_CMovieSystem;  // primary vtable @ 0x407E648 (slot 60 = SetCameraParams)

    CryStringT<char>     m_str08;            // +0x08  CryStringT<char> (ctor stores shared-empty &unk_185676010)
    int16_t              m_id08_10;          // +0x10  ctor -1 (sentinel index)
    int16_t              m_id08_12;          // +0x12  ctor -1 (sentinel index)
    uint8_t _pad14[4]; // +0x14
    CryStringT<char>     m_str18;            // +0x18  CryStringT<char> (ctor = shared empty)
    int16_t              m_id18_20;          // +0x20  ctor -1
    int16_t              m_id18_22;          // +0x22  ctor -1
    uint8_t _pad24[4]; // +0x24
    CryStringT<char>     m_str28;            // +0x28  CryStringT<char> (ctor = shared empty)
    int16_t              m_id28_30;          // +0x30  ctor -1
    int16_t              m_id28_32;          // +0x32  ctor -1
    uint8_t _pad34[4]; // +0x34
    Offsets::ISystem*    m_pSystem;          // +0x38  ctor arg                                    VERIFIED
    Offsets::IMovieUser* m_pUser;            // +0x40  notified by SetCameraParams (user-vtbl+0x08) VERIFIED
    Offsets::IMovieCallback* m_pCallback;    // +0x48  notified by SetCameraParams (cb-vtbl+0x10 = OnSetCamera) VERIFIED
    CTimeValue m_lastUpdateTime; // +0x50  ctor 0; not freed in dtor (non-owning ptr / handle)
    std::vector<void*>   m_vec58;            // +0x58  std::vector, 8-byte _smart_ptr elems (dtor sub_180FB8E30 Releases each) -- inferred m_sequences
    std::vector<void*>   m_vec70;            // +0x70  std::vector, 8-byte _smart_ptr elems (dtor sub_180FB8E30 Releases each) -- inferred m_movieSequences
    std::vector<void*>   m_vec88;            // +0x88  std::vector, 0x20-byte POD elems (dtor frees buffer only; stride mask ~0x1F)
    std::vector<void*>   m_vecA0;            // +0xA0  std::vector, 8-byte POD elems (dtor frees buffer only)
    S_RecursiveSRWLock m_lockVecA0;     // +0xB8..0xC7 recursive SRW (recursion@+0x8, tid@+0xC) guarding m_vecA0
    S_RecursiveSRWLock m_lockPlaying;   // +0xC8..0xD7 guards m_vecE8 playing sequences
    S_RecursiveSRWLock m_lockPlayQueue; // +0xD8..0xE7 guards the pending-play vector at +0x88
    std::vector<void*>   m_vecE8;            // +0xE8  std::vector, 0x20-byte elems (dtor sub_181793768 virtual-Releases elem[0]) -- inferred m_playingSequences
    std::map<IAnimSequence*, std::vector<IMovieListener*>> m_movieListenerMap; // +0x100..0x10F {_Myhead,_Mysize} (64-byte nodes)
    uint32_t             m_field110;         // +0x110 ctor 0x01000000 (packed flags/defaults)
    bool m_bUpdating; // +0x114 ctor 0
    uint8_t _pad115[3]; // +0x115
    SCameraParams        m_cameraParams;     // +0x118 GetCameraParams returns &this                VERIFIED
    uint16_t             m_field13C;         // +0x13C ctor 0
    uint8_t _pad13E[2]; // +0x13E
    // +0x140  capture/recording context (constructed by sub_180D620AC); sizeof 0xA20 -> ends +0xB60
    ICaptureKey m_captureKey; // +0x140..0xB5F embedded capture key (ctor 0x180D620AC; StartCapture memcpys 0xA20 onto it)
    // +0xB60  tail state / cvar cache
    IAnimSequence* m_captureSeq; // +0xB60 ctor-zeroed (9 QWORDs; internals unresolved)
    uint8_t _padB68[0x40]; // +0xB68 residual of former _pad_B60[0x48]
    ICVar* m_mov_overrideCam; // +0xBA8 ICVar* "mov_overrideCam" (sub_180B95258)
    int32_t              m_cvar_fakeProjection; // +0xBB0 int backing cvar "mov_enableFakeProjection" (default 0)
    float                m_cvar_maxTimeStep; // +0xBB4 float backing cvar "mov_maxTimeStepForMovieSystem"
    uint16_t             m_fieldBB8;         // +0xBB8 ctor 1
    uint8_t              _pad_BBA[2];        // +0xBBA
    uint32_t m_nextSequenceId; // +0xBBC ctor 1
    void*                m_fieldBC0;         // +0xBC0 ctor 0
};
static_assert(sizeof(CMovieSystem) == 0xBC8, "CMovieSystem must be 0xBC8");
