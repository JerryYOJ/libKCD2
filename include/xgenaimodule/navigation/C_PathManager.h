#pragma once

namespace wh::xgenaimodule::navigation {

class C_PredefinedPathManager;

// Partial primary-vtable replica; data layout remains unrecovered.
class C_PathManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PathManager;
    virtual void PathVf0() = 0;
    virtual void PathVf1() = 0;
    virtual void PathVf2() = 0;
    virtual void PathVf3() = 0;
    virtual void PathVf4() = 0;
    virtual void PathVf5() = 0;
    virtual void PathVf6() = 0;
    virtual C_PredefinedPathManager* GetPredefinedPathManager() = 0; // [7] sub_181A72EB0
};

}  // namespace wh::xgenaimodule::navigation
