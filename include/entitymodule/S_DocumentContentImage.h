#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::S_DocumentContentImage -- reflected document image entry
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x10.
// -----------------------------------------------
// Native RTTR registration proves the authored properties Page (unsigned int)
// and Image (CryStringT<char>).

namespace wh::entitymodule {

struct S_DocumentContentImage {
    std::uint32_t m_page;       // +0x00, RTTR "Page"
    std::uint32_t _pad04;       // +0x04
    CryStringT<char> m_image;   // +0x08, RTTR "Image"
};
static_assert(sizeof(S_DocumentContentImage) == 0x10,
              "S_DocumentContentImage must be 0x10");
static_assert(offsetof(S_DocumentContentImage, m_image) == 0x08,
              "document image path must be at 0x08");

}  // namespace wh::entitymodule
