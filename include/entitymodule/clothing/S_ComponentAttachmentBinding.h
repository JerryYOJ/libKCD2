#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

namespace wh::entitymodule::clothing {

// Synthetic name; element stride and shared-pointer ownership are binary-proven.
struct S_ComponentAttachmentBinding {
    std::shared_ptr<void> m_object;                                     // +0x00
    std::uint64_t m_unknown10;                                          // +0x10
};

static_assert(offsetof(S_ComponentAttachmentBinding, m_unknown10) == 0x10,
              "S_ComponentAttachmentBinding::m_unknown10 offset mismatch");
static_assert(sizeof(S_ComponentAttachmentBinding) == 0x18,
              "S_ComponentAttachmentBinding size mismatch");

} // namespace wh::entitymodule::clothing
