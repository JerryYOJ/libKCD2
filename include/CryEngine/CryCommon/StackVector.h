#pragma once
#include <cstddef>
#include <utility>
#include <vector>
#include "StdStackContainer.h"

namespace std {

template <typename T, std::size_t StackCapacity>
class StackVector
    : public StackContainer<
          std::vector<T, StackAllocator<T, StackCapacity>>,
          static_cast<int>(StackCapacity)> {
public:
    using Vector = std::vector<T, StackAllocator<T, StackCapacity>>;
    using Base = StackContainer<Vector, static_cast<int>(StackCapacity)>;
    using value_type = T;
    using size_type = typename Vector::size_type;
    using iterator = typename Vector::iterator;
    using const_iterator = typename Vector::const_iterator;

    StackVector() = default;
    StackVector(const StackVector& other) : Base(other) {}

    StackVector& operator=(const StackVector& other) {
        Base::operator=(other);
        return *this;
    }

    bool empty() const noexcept { return this->container_.empty(); }
    size_type size() const noexcept { return this->container_.size(); }
    size_type capacity() const noexcept { return this->container_.capacity(); }

    iterator begin() noexcept { return this->container_.begin(); }
    const_iterator begin() const noexcept { return this->container_.begin(); }
    iterator end() noexcept { return this->container_.end(); }
    const_iterator end() const noexcept { return this->container_.end(); }

    T& operator[](size_type index) noexcept { return this->container_[index]; }
    const T& operator[](size_type index) const noexcept { return this->container_[index]; }

    T& front() noexcept { return this->container_.front(); }
    const T& front() const noexcept { return this->container_.front(); }
    T& back() noexcept { return this->container_.back(); }
    const T& back() const noexcept { return this->container_.back(); }

    void clear() noexcept { this->container_.clear(); }
    void push_back(const T& value) { this->container_.push_back(value); }
    void push_back(T&& value) { this->container_.push_back(std::move(value)); }

    template <typename... Args>
    T& emplace_back(Args&&... args) {
        return this->container_.emplace_back(std::forward<Args>(args)...);
    }
};

}  // namespace std
