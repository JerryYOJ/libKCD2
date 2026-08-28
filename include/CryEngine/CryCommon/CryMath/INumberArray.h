#pragma once

// Storage-free CryEngine numeric-array CRTP base. The concrete derived type
// supplies N contiguous T values at the same address through empty-base optimization.
template <typename T, int N>
struct INumberArray {
protected:
    INumberArray() = default;

public:
    T* begin() { return reinterpret_cast<T*>(this); }
    T const* begin() const { return reinterpret_cast<T const*>(this); }
    T* end() { return begin() + N; }
    T const* end() const { return begin() + N; }

    T& operator[](int index) { return begin()[index]; }
    T const& operator[](int index) const { return begin()[index]; }
};
