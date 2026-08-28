#pragma once
#include "INumberArray.h"

// Storage-free CryEngine numeric-vector CRTP base. Arithmetic helpers are omitted
// here because the RE headers use only its source inheritance and contiguous view.
template <typename T, int N, typename Final>
struct INumberVector : INumberArray<T, N> {
    using Base = INumberArray<T, N>;
    using Base::begin;
    using Base::end;
    using Base::operator[];

    using value_type = T;
    enum { component_count = N };

    Final& final() { return *static_cast<Final*>(this); }
    Final const& final() const { return *static_cast<Final const*>(this); }
};
