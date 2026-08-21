#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryArray.h"

namespace wh::combatmodule {
struct S_SpatialGridNode;
}

namespace NArray {

// The generic retail policy eagerly evaluates alignof(T), which prevents a
// recursive declaration. This specialization keeps the exact WHDynStorage ABI
// and operation surface while deferring implementations to the game's node
// special members.
template<>
struct WHDynStorage<wh::combatmodule::S_SpatialGridNode, int>
    : RawStorage<wh::combatmodule::S_SpatialGridNode> {
    using value_type = wh::combatmodule::S_SpatialGridNode;
    using size_type = int;
    using self_type = WHDynStorage<value_type, size_type>;

    WHDynStorage();
    ~WHDynStorage();

    void swap(self_type& rhs);
    value_type* begin();
    const value_type* begin() const;
    size_type size() const;
    size_type capacity() const;
    size_type get_alloc_size() const;
    void resize_raw(size_type newSize, size_type newCapacity,
                    bool allowSlack = false);
    void resize_raw(size_type newSize);

protected:
    value_type* m_aElems;
};
static_assert(sizeof(WHDynStorage<wh::combatmodule::S_SpatialGridNode, int>) == 0x08);

}  // namespace NArray
