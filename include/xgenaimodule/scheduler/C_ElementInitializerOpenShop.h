#pragma once
#include <cstddef>
#include "C_ElementInitializerBase.h"

namespace wh::xgenaimodule::scheduler {

class C_ElementInitializerOpenShop : public C_ElementInitializerBase {
public:
    ~C_ElementInitializerOpenShop() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
};

static_assert(sizeof(C_ElementInitializerOpenShop) == 0x18,
              "C_ElementInitializerOpenShop size mismatch");

}  // namespace wh::xgenaimodule::scheduler
