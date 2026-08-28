#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::playermodule {

class C_Blacksmithing;

struct S_BlacksmithingProcessState {
    C_Blacksmithing* m_owner;          // +0x00
    std::uint8_t m_unknown08[0xD8];    // +0x08, dense scalar/timer state
    std::uint32_t m_unknownE0;         // +0xE0
    bool m_unknownE4;                  // +0xE4
    std::uint8_t m_paddingE5[3];
};

static_assert(sizeof(S_BlacksmithingProcessState) == 0xE8,
              "S_BlacksmithingProcessState size mismatch");
static_assert(offsetof(S_BlacksmithingProcessState, m_unknownE0) == 0xE0,
              "S_BlacksmithingProcessState tail offset mismatch");

} // namespace wh::playermodule
