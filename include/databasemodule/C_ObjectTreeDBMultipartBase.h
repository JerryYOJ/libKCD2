#pragma once

namespace wh::databasemodule {

// Empty marker inherited by multipart row/object types, not by their databases.
class C_ObjectTreeDBMultipartBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ObjectTreeDBMultipartBase;
};
static_assert(sizeof(C_ObjectTreeDBMultipartBase) == 0x01,
              "empty multipart marker must have language-minimum size");

}  // namespace wh::databasemodule
