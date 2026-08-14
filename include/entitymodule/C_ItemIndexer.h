#pragma once

#include "C_ItemCollection.h"

namespace wh::entitymodule {

class C_ItemIndexer : public C_ItemCollection {
public:
    virtual void ItemIndexerVf1();
    virtual void ItemIndexerVf2();
    virtual void ItemIndexerVf3();
    virtual void ItemIndexerVf4();
    virtual void ItemIndexerVf5();
    virtual void ItemIndexerVf6();
    virtual void ItemIndexerVf7();
    virtual void ItemIndexerVf8();
    virtual void ItemIndexerVf9();

    framework::WUID m_wuid; // +0x70
    std::uint64_t m_value78;
    std::uint64_t m_value80;
    std::uint64_t m_value88;
};
static_assert(sizeof(C_ItemIndexer) == 0x90, "C_ItemIndexer must be 0x90");

}  // namespace wh::entitymodule
