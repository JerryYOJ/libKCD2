#pragma once
#include <cstddef>

#ifndef _STL_UTILS_HEADER_
namespace stl {

template <class T>
class intrusive_linked_list_node {
public:
    intrusive_linked_list_node();
    ~intrusive_linked_list_node();

    T* m_next_intrusive;                                      // +0x00
    T* m_prev_intrusive;                                      // +0x08

private:
    static T* m_root_intrusive;
};

} // namespace stl
#endif
