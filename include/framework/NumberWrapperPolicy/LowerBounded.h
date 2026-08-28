#pragma once

namespace wh::framework::NumberWrapperPolicy {

template <int Lower, typename TValue, typename TOption0,
          typename TOption1, typename TOption2>
struct LowerBounded {
    using value_type = TValue;
};

}  // namespace wh::framework::NumberWrapperPolicy
