#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::I_LockPickingAction -- Mannequin lockpicking action
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x90.
// -----------------------------------------------
// RTTI .?AVI_LockPickingAction@playermodule@wh@@ (TD 0x184DF9C98).
// vtable 0x183A5A928, 30 slots; object layout is the 0x90-byte body filled by
// sub_180899CB0. Not framework::I_Action (different slot map).

// Signature types mirrored from stock ICryMannequin.h (SDK header deliberately NOT
// bound -- KCD2 engine IAction diverges from stock; see C_CallbackAction.h banner).
// Global scope on purpose: these are engine types; a namespaced fwd would shadow
// the ::SGameObjectEvent etc. used by IGameObjectExtension overrides in the umbrella TU.
class IAction;                 // engine Mannequin action, opaque here
class SAnimationContext;
struct SGameObjectEvent;

namespace wh::playermodule {

struct S_TagState16 { uint8_t bytes[16]; };                    // Mannequin TagState block
enum class E_ActionStatus : int32_t { None, Pending, Installed, Exiting, Finished }; // stock IAction::EStatus
enum class E_ActionFailure : int32_t { AF_QueueFull, AF_InvalidContext };            // stock EActionFailure
enum class E_PriorityComparison : int32_t { Lower, Equal, Higher };                  // stock EPriorityComparison
using FragmentID = int32_t;    // stock: typedef TagID FragmentID

class I_LockPickingAction {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_LockPickingAction;
    virtual ~I_LockPickingAction();                         // [0]
    virtual void Install()= 0; // [1] 0x18126AC90
    virtual void Enter()= 0; // [2]
    virtual void Fail(E_ActionFailure actionFailure)= 0; // [3]
    virtual void OnActionStart() = 0;                       // [4] leave -> Destroy / fail-idle -> fail
    virtual E_ActionStatus UpdatePending(float timePassed)= 0; // [5]
    virtual E_ActionStatus Update(float timePassed)= 0; // [6]
    virtual void CancelInstall()= 0; // [7]
    virtual bool Interrupt()= 0; // [8]
    virtual E_PriorityComparison ComparePriority(const IAction& actionCurrent) const= 0; // [9]
    virtual void OnRequestBlendOut(E_PriorityComparison priorityComp)= 0; // [10]
    virtual void OnSequenceFinished(int layer, std::uint32_t scopeId)= 0; // [11]
    virtual IAction* CreateSlaveAction(FragmentID slaveFragID, const S_TagState16& fragTags, SAnimationContext& context)= 0; // [12]
    virtual void OnTransitionStarted()= 0; // [13]
    virtual void OnActionUpdate() = 0;                      // [14] 0x180897C60, state==Ready
    virtual void OnTransitionOutStarted()= 0; // [15]
    virtual void OnInitialise()= 0; // [16]
    virtual void OnActionFinished()= 0; // [17]
    virtual void unk_18()= 0; // [18]
    virtual void OnEvent(const SGameObjectEvent& event)= 0; // [19]
    virtual void OnAnimEvent(int32_t eventCrc) = 0;         // [20] 0x180897CAC
    virtual void OnActionEvent(const std::uint32_t eventCRC)= 0; // [21]
    virtual const char* GetName() const= 0; // [22]
    virtual void DoDelete()= 0; // [23]
    virtual void unk_24()= 0; // [24]
    virtual void unk_25()= 0; // [25]
    virtual void unk_26()= 0; // [26]
    virtual int unk_27()= 0; // [27]
    virtual int unk_28()= 0; // [28]
    virtual int32_t GetActionType() const= 0; // [29]

    uint8_t _opaque08[0x88];                                // +0x08  sub_180899CB0 body
};
static_assert(sizeof(I_LockPickingAction) == 0x90,
              "I_LockPickingAction must match sub_180899CB0 extent");

}  // namespace wh::playermodule
