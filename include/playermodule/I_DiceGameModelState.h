#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::playermodule {

class C_DiceGameModel;

class I_DiceGameModelState
    : public std::enable_shared_from_this<I_DiceGameModelState> {
public:
    explicit I_DiceGameModelState(C_DiceGameModel* model);
    virtual ~I_DiceGameModelState();                            // [0]
    virtual const char* GetStateName() const = 0;               // [1]
    virtual CryStringT<char> GetDebugName() const;              // [2]
    virtual C_DiceGameModel* GetModel();                        // [3]
    virtual const C_DiceGameModel* GetModelConst() const;       // [4]
    virtual void unk_05(void* context);                         // [5]
    virtual void unk_06(void* context);                         // [6]
    virtual bool unk_07(void* context) = 0;                     // [7]
    virtual bool unk_08(const void* value) const;               // [8]
    virtual bool unk_09() const;                                // [9]
    virtual bool unk_10(void* context, void* event);            // [10]
    virtual bool unk_11(void* context, void* event);            // [11]
    virtual bool unk_12(
        void* context,
        std::uint32_t value,
        bool flag);                                             // [12]
    virtual bool unk_13();                                      // [13]
    virtual bool unk_14(void* context);                         // [14]
    virtual bool unk_15(void* context);                         // [15]
    virtual bool unk_16(void* context);                         // [16]
    virtual bool unk_17();                                      // [17]
    virtual bool unk_18(void* context);                         // [18]
    virtual bool unk_19(void* context);                         // [19]
    virtual bool unk_20();                                      // [20]
    virtual bool unk_21();                                      // [21]
    virtual bool unk_22(void* context, bool flag);              // [22]
    virtual bool unk_23();                                      // [23]
    virtual bool unk_24();                                      // [24]
    virtual bool unk_25(void* context);                         // [25]
    virtual bool unk_26(void* context);                         // [26]
    virtual bool unk_27(void* context);                         // [27]
    virtual bool unk_28(void* context);                         // [28]
    virtual bool unk_29();                                      // [29]
    virtual bool unk_30();                                      // [30]
    virtual bool unk_31();                                      // [31]
    virtual bool unk_32();                                      // [32]
    virtual bool unk_33();                                      // [33]
    virtual bool unk_34();                                      // [34]
    virtual bool unk_35();                                      // [35]
    virtual bool unk_36();                                      // [36]
    virtual bool unk_37();                                      // [37]
    virtual bool unk_38();                                      // [38]
    virtual bool unk_39();                                      // [39]
    virtual bool unk_40();                                      // [40]
    virtual bool unk_41();                                      // [41]
    virtual bool unk_42();                                      // [42]
    virtual bool unk_43();                                      // [43]
    virtual bool unk_44();                                      // [44]
    virtual bool unk_45();                                      // [45]
    virtual bool unk_46();                                      // [46]
    virtual void* unk_47();                                     // [47]
    RTTR_ENABLE() // [48..50]

    C_DiceGameModel* m_model;                                  // +0x18
};

static_assert(sizeof(I_DiceGameModelState) == 0x20,
              "I_DiceGameModelState size mismatch");
static_assert(offsetof(I_DiceGameModelState, m_model) == 0x18,
              "I_DiceGameModelState model offset mismatch");

} // namespace wh::playermodule
