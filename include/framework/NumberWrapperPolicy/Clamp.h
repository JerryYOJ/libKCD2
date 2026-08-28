#pragma once

namespace wh::framework::NumberWrapperPolicy {

template <int Lower, int Upper, typename TValue,
          typename TLowerOption, typename TUpperOption>
struct Clamp {
    using value_type = TValue;
};

}  // namespace wh::framework::NumberWrapperPolicy
