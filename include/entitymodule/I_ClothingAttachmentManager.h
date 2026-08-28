#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

struct ICharacterInstance;
struct SEntityEvent;

namespace wh::entitymodule {

class I_ClothingAttachmentOwner;

class I_ClothingAttachmentManager {
public:
    virtual ~I_ClothingAttachmentManager();                              // [0] 0x1829174A0
    virtual void unk_01() = 0;                                          // [1]
    virtual void* GetClothingConfig() const = 0;                         // [2]
    virtual void unk_03() = 0;                                          // [3]
    virtual void unk_04(bool value) = 0;                                // [4]
    virtual bool unk_05() const = 0;                                    // [5]
    virtual void unk_06() = 0;                                          // [6]
    virtual ICharacterInstance* GetCharacterInstance() const = 0;        // [7]
    virtual const char* GetOwnerName() const = 0;                        // [8]
    virtual I_ClothingAttachmentOwner* GetOwner() const = 0;             // [9]
    virtual void unk_10(bool value) = 0;                                // [10]
    virtual bool unk_11() const = 0;                                    // [11]
    virtual void* unk_12() const = 0;                                   // [12]
    virtual void unk_13(const I_ClothingAttachmentManager* source) = 0;  // [13]
    virtual bool unk_14() const = 0;                                    // [14]
    virtual bool unk_15() const = 0;                                    // [15]
    virtual bool unk_16() const = 0;                                    // [16]
    virtual void ProcessEvent(SEntityEvent& event) = 0;                  // [17]
    virtual void unk_18(std::uint32_t value) = 0;                        // [18]
    virtual void unk_19() = 0;                                          // [19]
    virtual void unk_20() = 0;                                          // [20]
    virtual std::uint32_t GetLoadedAttachmentCount() const = 0;          // [21]
    virtual bool unk_22() = 0;                                          // [22]
    virtual void unk_23() = 0;                                          // [23]
    virtual void unk_24() = 0;                                          // [24]
    virtual bool unk_25(void* value) = 0;                               // [25]
    virtual bool unk_26(void* value) = 0;                               // [26]
    virtual void unk_27() = 0;                                          // [27]
    virtual void unk_28() = 0;                                          // [28]
    virtual void unk_29() = 0;                                          // [29]
    virtual void unk_30(void* value, bool enabled) = 0;                  // [30]
    virtual void* unk_31(const CryStringT<char>& name, void* value) = 0; // [31]
    virtual const void* unk_32() const = 0;                              // [32]
    virtual const void* unk_33() const = 0;                              // [33]
    virtual std::vector<void*> unk_34(std::int32_t key,
                                      void* predicate) const = 0;        // [34]
    RTTR_ENABLE()                                                        // [35..37], vtable 0x183E8B9A8
};

static_assert(sizeof(I_ClothingAttachmentManager) == 0x08,
              "I_ClothingAttachmentManager size mismatch");

} // namespace wh::entitymodule
