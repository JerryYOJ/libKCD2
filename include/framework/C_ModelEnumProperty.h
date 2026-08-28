#pragma once

#include "C_ModelProperty.h"

namespace wh::shared {

template <class Enum, class Save = traits::C_NoSaveLoad>
class C_ModelEnumProperty
    : public C_ModelProperty<
          typename Enum::Type,
          traits::C_StandardDefaultValueTrait<typename Enum::Type>,
          traits::C_SignalWithNewValueTrait<typename Enum::Type>,
          traits::C_DebugNoTrace,
          Save,
          traits::C_OwnershipEmpty> {};

} // namespace wh::shared
