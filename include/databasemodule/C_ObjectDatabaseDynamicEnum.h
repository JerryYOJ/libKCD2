#pragma once
#include <cstddef>
#include <cstdint>

#include "I_DynamicEnum.h"

namespace wh::databasemodule {

template <typename TBase>
class C_ObjectDatabaseDynamicEnum
    : public TBase,
      public I_DynamicEnum {
public:
    std::uint32_t GetCount() const override;                       // secondary [0]
    std::uint32_t GetValue(std::uint32_t index) const override;    // secondary [1]
    const char* GetName(std::uint32_t index) const override;       // secondary [2]
    std::uint32_t GetValueByName(const char* name) const override; // secondary [3]
    const char* GetNameByValue(std::uint32_t value) const override; // secondary [4]
};

} // namespace wh::databasemodule
