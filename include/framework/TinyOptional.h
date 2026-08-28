#pragma once
#include <cstdint>
#include <cstring>
#include <type_traits>

#include "UseDefaultType.h"

namespace tiny {

template <typename T,
          auto EmptyValue = UseDefaultType::UseDefault,
          auto DefaultValue = UseDefaultType::UseDefault>
class optional {
public:
    using value_type = T;
    using storage_type = std::conditional_t<
        std::is_same_v<T, float>,
        std::uint32_t,
        std::conditional_t<std::is_same_v<T, bool>, std::uint8_t, T>>;

    constexpr optional() noexcept
        : m_storage(EmptyStorage()) {}

    optional(T value) noexcept
        : m_storage(Encode(value)) {}

    constexpr bool has_value() const noexcept {
        return m_storage != EmptyStorage();
    }

    constexpr explicit operator bool() const noexcept {
        return has_value();
    }

    T value() const noexcept {
        return Decode(m_storage);
    }

    T value_or(T fallback) const noexcept {
        return has_value() ? value() : fallback;
    }

    optional& operator=(T value) noexcept {
        m_storage = Encode(value);
        return *this;
    }

    constexpr void reset() noexcept {
        m_storage = EmptyStorage();
    }

private:
    static constexpr storage_type EmptyStorage() noexcept {
        if constexpr (std::is_same_v<
                          std::remove_cv_t<decltype(EmptyValue)>,
                          UseDefaultType>) {
            if constexpr (std::is_same_v<T, float>) {
                return 0x7FEDCBA9u;
            } else if constexpr (std::is_same_v<T, bool>) {
                return 0xFEu;
            } else {
                return storage_type{};
            }
        } else {
            return static_cast<storage_type>(EmptyValue);
        }
    }

    static storage_type Encode(T value) noexcept {
        if constexpr (std::is_same_v<T, float>) {
            storage_type result;
            std::memcpy(&result, &value, sizeof(result));
            return result;
        } else {
            return static_cast<storage_type>(value);
        }
    }

    static T Decode(storage_type value) noexcept {
        if constexpr (std::is_same_v<T, float>) {
            T result;
            std::memcpy(&result, &value, sizeof(result));
            return result;
        } else {
            return static_cast<T>(value);
        }
    }

    storage_type m_storage;
};

static_assert(sizeof(optional<float>) == 0x04,
              "tiny::optional<float> size mismatch");
static_assert(sizeof(optional<int, -2147483647 - 1>) == 0x04,
              "tiny::optional<int> size mismatch");
static_assert(sizeof(optional<bool>) == 0x01,
              "tiny::optional<bool> size mismatch");

} // namespace tiny
