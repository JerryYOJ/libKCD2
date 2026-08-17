#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/SerializeFwd.h"

class TRMIInventory_Dummy {
public:
    virtual ~TRMIInventory_Dummy();
    virtual void SerializeWith(TSerialize serializer);
};
static_assert(sizeof(TRMIInventory_Dummy) == 0x08,
              "TRMIInventory_Dummy must be vptr-only");
