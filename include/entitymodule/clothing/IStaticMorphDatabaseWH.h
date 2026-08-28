#pragma once
#include <cstddef>

class IStaticMorphDatabaseWH {
public:
    virtual bool HasMorph(const CryStringT<char>& name) const = 0; // [0] 0x18114934C
};

static_assert(sizeof(IStaticMorphDatabaseWH) == 0x08,
              "IStaticMorphDatabaseWH size mismatch");
