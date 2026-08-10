#pragma once
#include <cstddef>
#include "C_FileTableSerializer.h"
#include "S_SerializationStringPoolBuilder.h"

namespace wh::databasemodule {

class C_XMLTableSerializer : public C_FileTableSerializer {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_XMLTableSerializer;

    bool IsBinary() const override;                    // [1] false
    const char* GetName() const override;              // [2] "XML"
    bool Load(S_DatabaseTableRecord& table) override;  // [6] 0x180D1A11C
    const char* GetFileExtension() const override;     // [9] "xml"

    S_SerializationStringPoolBuilder* m_stringPoolBuilder; // +0x18, borrowed
};
static_assert(sizeof(C_XMLTableSerializer) == 0x20,
              "C_XMLTableSerializer must be 0x20");
static_assert(offsetof(C_XMLTableSerializer, m_stringPoolBuilder) == 0x18,
              "XML string-pool builder at 0x18");

}  // namespace wh::databasemodule
