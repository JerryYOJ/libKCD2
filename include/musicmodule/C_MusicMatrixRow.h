#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "../rttr/rttr_enable.h"
#include "C_Address.h"
#include "C_MusicMatrixCell.h"

namespace wh::musicmodule {

class C_MusicMatrixRow {
public:
    virtual ~C_MusicMatrixRow();                            // [0]
    RTTR_ENABLE()                                           // [1..3]

    std::shared_ptr<void> m_unknown08;                      // +0x08 pointee type unresolved
    std::uint32_t m_addressId;                              // +0x18 accessor backing "Address"
    std::uint8_t _pad1C[4];                                 // +0x1C
    C_Address m_address;                                    // +0x20 constructor/destructor proven
    std::vector<std::shared_ptr<C_MusicMatrixCell>> m_cells; // +0x38 RTTR "Cells"
    bool m_addressValid;                                    // +0x50 setter result
    std::uint8_t _pad51[7];                                 // +0x51
};

static_assert(offsetof(C_MusicMatrixRow, m_unknown08) == 0x08,
              "C_MusicMatrixRow::m_unknown08 offset mismatch");
static_assert(offsetof(C_MusicMatrixRow, m_addressId) == 0x18,
              "C_MusicMatrixRow::m_addressId offset mismatch");
static_assert(offsetof(C_MusicMatrixRow, m_address) == 0x20,
              "C_MusicMatrixRow::m_address offset mismatch");
static_assert(offsetof(C_MusicMatrixRow, m_cells) == 0x38,
              "C_MusicMatrixRow::m_cells offset mismatch");
static_assert(sizeof(C_MusicMatrixRow) == 0x58,
              "C_MusicMatrixRow size mismatch");

}  // namespace wh::musicmodule
