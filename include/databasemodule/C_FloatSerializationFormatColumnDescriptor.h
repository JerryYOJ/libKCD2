#pragma once
#include <cstddef>
#include "C_ColumnDescriptor.h"

namespace wh::databasemodule {

class C_FloatSerializationFormatColumnDescriptor : public C_ColumnDescriptor {
public:
    inline static constexpr auto RTTI =
        Offsets::RTTI_C_FloatSerializationFormatColumnDescriptor;

    ~C_FloatSerializationFormatColumnDescriptor() override;  // [0] 0x1827E0E68
    const char* GetFloatSerializationFormat() const override;  // [16] reads +0x38

    CryStringT<char> m_serializationFormat;  // +0x38, owned
};
static_assert(sizeof(C_FloatSerializationFormatColumnDescriptor) == 0x40,
              "C_FloatSerializationFormatColumnDescriptor must be 0x40");
static_assert(offsetof(C_FloatSerializationFormatColumnDescriptor,
                       m_serializationFormat) == 0x38,
              "float serialization format at 0x38");

}  // namespace wh::databasemodule
