#pragma once
#include <cstddef>
#include <vector>
#include "S_DocumentContentImage.h"

// -----------------------------------------------
// wh::entitymodule::S_DocumentContent -- reflected full-book content
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x30.
// -----------------------------------------------
// SetFullBook consumes two contiguous MSVC std::vectors. RTTR exposes the
// storage through Parts and Images; GeneralBook forwards m_parts as its Texts array.

namespace wh::entitymodule {

struct S_DocumentContent {
    std::vector<CryStringT<char>> m_parts;             // +0x00, RTTR "Parts"
    std::vector<S_DocumentContentImage> m_images;      // +0x18, RTTR "Images"
};
static_assert(sizeof(S_DocumentContent) == 0x30,
              "S_DocumentContent must be 0x30");
static_assert(offsetof(S_DocumentContent, m_images) == 0x18,
              "document images must be at 0x18");

}  // namespace wh::entitymodule
