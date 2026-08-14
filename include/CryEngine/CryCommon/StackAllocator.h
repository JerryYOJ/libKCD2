#pragma once
#include <cstddef>
#include <memory>

namespace std {

// KCD2/Chromium stack allocator. The namespace is binary-mangled and intentional.
template <typename T, std::size_t StackCapacity>
class StackAllocator : public std::allocator<T> {
public:
    using Base = std::allocator<T>;
    using value_type = T;
    using pointer = typename std::allocator_traits<Base>::pointer;
    using size_type = typename std::allocator_traits<Base>::size_type;

    struct Source {
        Source() noexcept : used_stack_buffer_(false) {}

        alignas(T) unsigned char stack_buffer_[sizeof(T) * StackCapacity];
        bool used_stack_buffer_;
    };

    template <typename U>
    struct rebind {
        using other = StackAllocator<U, StackCapacity>;
    };

    StackAllocator() noexcept : source_(nullptr) {}
    explicit StackAllocator(Source* source) noexcept : source_(source) {}

    pointer allocate(size_type count) {
        if (source_ && !source_->used_stack_buffer_ && count <= StackCapacity) {
            source_->used_stack_buffer_ = true;
            return reinterpret_cast<pointer>(source_->stack_buffer_);
        }
        return Base::allocate(count);
    }

    void deallocate(pointer memory, size_type count) noexcept {
        if (source_ && memory == reinterpret_cast<pointer>(source_->stack_buffer_)) {
            source_->used_stack_buffer_ = false;
            return;
        }
        Base::deallocate(memory, count);
    }

    Source* source() const noexcept { return source_; }

private:
    Source* source_;
};

template <typename T, std::size_t N, typename U, std::size_t M>
bool operator==(const StackAllocator<T, N>& lhs,
                const StackAllocator<U, M>& rhs) noexcept {
    return lhs.source() == rhs.source();
}

template <typename T, std::size_t N, typename U, std::size_t M>
bool operator!=(const StackAllocator<T, N>& lhs,
                const StackAllocator<U, M>& rhs) noexcept {
    return !(lhs == rhs);
}

}  // namespace std
