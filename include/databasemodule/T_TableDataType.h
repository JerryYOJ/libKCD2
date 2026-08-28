#pragma once
#include <cstddef>

namespace wh::databasemodule {

template <class T>
class T_TableDataType {
public:
    T m_value;                                                // +0x00
};

static_assert(sizeof(T_TableDataType<float>) == 0x04,
              "T_TableDataType<float> size mismatch");

} // namespace wh::databasemodule
