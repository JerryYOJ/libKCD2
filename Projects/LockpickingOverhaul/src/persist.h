#pragma once

namespace LockpickOverhaul {

void LoadPersistedEdits();
void PersistSetting(const char* cvarName, double value, bool isFloat);

}  // namespace LockpickOverhaul
