#pragma once

namespace wh::xgenaimodule::navigation {

class C_PathManager;
class C_ReplanMoveAreaRegistry;

// Partial primary-vtable replica; data layout remains unrecovered.
class C_Navigation {
public:
    virtual void NavigationVf0() = 0;
    virtual C_PathManager* GetPathManager() = 0; // [1] sub_181A76BE0
    virtual void NavigationVf2() = 0;
    virtual void NavigationVf3() = 0;
    virtual void NavigationVf4() = 0;
    virtual void NavigationVf5() = 0;
    virtual void NavigationVf6() = 0;
    virtual void NavigationVf7() = 0;
    virtual void NavigationVf8() = 0;
    virtual void NavigationVf9() = 0;
    virtual void NavigationVf10() = 0;
    virtual void NavigationVf11() = 0;
    virtual C_ReplanMoveAreaRegistry* GetReplanMoveAreaRegistry() = 0; // [12] sub_181A77FA0
};

}  // namespace wh::xgenaimodule::navigation
