#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::playermodule {

class I_DiceGameModelDelegate;

class C_DiceGameModel;
class C_DiceGamePlayerModel;

class I_DiceGameModelState
    : public std::enable_shared_from_this<I_DiceGameModelState> {
public:
    explicit I_DiceGameModelState(C_DiceGameModel* model);
    virtual ~I_DiceGameModelState();                            // [0]
    virtual const char* GetStateName() const = 0;               // [1]
    virtual CryStringT<char> GetDebugName() const;              // [2]
    virtual C_DiceGameModel* GetModel();                        // [3]
    virtual const C_DiceGameModel* GetModelConst() const;       // [4]
    virtual void OnEnter(I_DiceGameModelDelegate* delegate); // [5]
    virtual void OnExit(I_DiceGameModelDelegate* delegate); // [6]
    virtual bool AdvanceState(I_DiceGameModelDelegate* delegate) = 0; // [7]
    virtual bool IsForPlayerModel(const C_DiceGamePlayerModel* model) const; // [8]
    virtual bool unk_09() const;                                // [9]
    virtual bool GiveUp(I_DiceGameModelDelegate* delegate, C_DiceGamePlayerModel* model); // [10]
    virtual bool unk_11(void* context, void* event);            // [11]
    virtual bool HoldDie(I_DiceGameModelDelegate* delegate, std::uint32_t dieId, bool hold); // [12]
    virtual bool unk_13();                                      // [13]
    virtual bool ContinueAfterBustProtection(I_DiceGameModelDelegate* delegate); // [14]
    virtual bool UseExtraRollBadge(I_DiceGameModelDelegate* delegate); // [15]
    virtual bool UseRerollBadge(I_DiceGameModelDelegate* delegate); // [16]
    virtual bool unk_17();                                      // [17]
    virtual bool CanScore(I_DiceGameModelDelegate* delegate, C_DiceGamePlayerModel* model); // [18]
    virtual bool Score(I_DiceGameModelDelegate* delegate); // [19]
    virtual bool unk_20();                                      // [20]
    virtual bool unk_21();                                      // [21]
    virtual bool Pass(I_DiceGameModelDelegate* delegate, bool fromBadge); // [22]
    virtual bool unk_23();                                      // [23]
    virtual bool unk_24();                                      // [24]
    virtual bool unk_25(void* context);                         // [25]
    virtual bool BeginBadgeDiceSelection(I_DiceGameModelDelegate* delegate); // [26]
    virtual bool ApplyBadgeEffect(I_DiceGameModelDelegate* delegate); // [27]
    virtual bool ExitBadgeEffect(I_DiceGameModelDelegate* delegate); // [28]
    virtual bool IsNullState(); // [29]
    virtual bool IsInitialState(); // [30]
    virtual bool IsPlayerTurnState(); // [31]
    virtual bool IsHoldingState(); // [32]
    virtual bool IsScoringState(); // [33]
    virtual bool IsRollingState(); // [34]
    virtual bool IsBustState(); // [35]
    virtual bool IsPassingState(); // [36]
    virtual bool IsPlayerChangeState(); // [37]
    virtual bool IsEndingState(); // [38]
    virtual bool IsEndState(); // [39]
    virtual bool unk_40();                                      // [40]
    virtual bool IsCheckBustBadgeState(); // [41]
    virtual bool IsBadgeDiceSelectingState(); // [42]
    virtual bool IsChangingDieValueState(); // [43]
    virtual bool IsExtraRollingState(); // [44]
    virtual bool IsReRollingState(); // [45]
    virtual bool IsGameEnding(); // [46]
    virtual std::uint32_t GetGameResultCode(); // [47]
    RTTR_ENABLE() // [48..50]

    C_DiceGameModel* m_model;                                  // +0x18
};

static_assert(sizeof(I_DiceGameModelState) == 0x20,
              "I_DiceGameModelState size mismatch");
static_assert(offsetof(I_DiceGameModelState, m_model) == 0x18,
              "I_DiceGameModelState model offset mismatch");

} // namespace wh::playermodule
