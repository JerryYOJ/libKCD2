#pragma once
#include <cstddef>

// -----------------------------------------------
// CCryName -- interned-string handle (one pointer).
// -----------------------------------------------
// Stock CryName.h cannot be included from kcd.h: it pulls ISystem.h, which
// redefines RE console/env/xml types. Member spacing in RowSimulationParams
// (DirTransJoint +0x00, ClampMode +0x08) proves the handle is 8 bytes. The
// stored pointer spelling matches stock CryName.h (m_str).

class CCryName {
    const char* m_str;
};

static_assert(sizeof(CCryName) == 0x08, "CCryName size mismatch");
