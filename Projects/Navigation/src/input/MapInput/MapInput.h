#pragma once

#include "Offsets/vtables/IInputEventListener.h"

class MapInput : public Offsets::IInputEventListener {
public:
    static bool Install();
    static void Uninstall();
    static bool BindConfirm();

    bool OnInputEvent(const Offsets::SInputEvent& e) override;
    bool OnInputEventUI(const void*) override { return false; }
    int  GetPriority() const override { return 0; }
    bool _vf3(const void*) override { return false; }

private:
    static MapInput s_listener;
    static bool s_registered;
};
