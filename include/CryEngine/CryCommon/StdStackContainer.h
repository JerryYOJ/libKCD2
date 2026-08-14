#pragma once
#include <cstddef>
#include "StackAllocator.h"

namespace std {

// KCD2/Chromium fixed-capacity container base. The namespace is binary-mangled.
template <typename Container, int StackCapacity>
class StackContainer {
    static_assert(StackCapacity > 0, "StackCapacity must be positive");

public:
    using container_type = Container;
    using allocator_type = typename Container::allocator_type;

    StackContainer()
        : stack_data_(), allocator_(&stack_data_), container_(allocator_) {
        container_.reserve(StackCapacity);
    }

    StackContainer(const StackContainer& other)
        : stack_data_(), allocator_(&stack_data_), container_(allocator_) {
        container_.assign(other.container_.begin(), other.container_.end());
    }

    StackContainer& operator=(const StackContainer& other) {
        if (this != &other) {
            container_.assign(other.container_.begin(), other.container_.end());
        }
        return *this;
    }

    Container& container() noexcept { return container_; }
    const Container& container() const noexcept { return container_; }

    Container* operator->() noexcept { return &container_; }
    const Container* operator->() const noexcept { return &container_; }

    Container& operator*() noexcept { return container_; }
    const Container& operator*() const noexcept { return container_; }

protected:
    typename allocator_type::Source stack_data_;
    allocator_type allocator_;
    Container container_;
};

}  // namespace std
