#pragma once

#include "crysystem/SUserFunctionDesc.h"
#include "skald/SkaldRuntime.h"

namespace Offsets {
struct IFunctionHandler;
struct IScriptSystem;
struct IScriptTable;
}

namespace luautils {

class CScriptBind_SKALD
{
public:
    explicit CScriptBind_SKALD(skald::SkaldRuntime& runtime) noexcept;

    void Init(Offsets::IScriptSystem* scriptSystem);
    bool IsInitialized() const noexcept { return m_pMethodsTable != nullptr; }
    void ClearRuntime() noexcept
    {
        m_runtime.InvalidateLuaOutputs();
        m_runtime.Clear();
    }

    int CreateNode(Offsets::IFunctionHandler* handler);
    int DestroyNode(Offsets::IFunctionHandler* handler);
    int GetPortDefinitions(Offsets::IFunctionHandler* handler);
    int BindTriggerOutput(Offsets::IFunctionHandler* handler);
    int BindDataOutput(Offsets::IFunctionHandler* handler);
    int UnbindDataOutput(Offsets::IFunctionHandler* handler);
    int Disconnect(Offsets::IFunctionHandler* handler);
    int TriggerInput(Offsets::IFunctionHandler* handler);
    int QueueDestroy(Offsets::IFunctionHandler* handler);
    int SetActivation(Offsets::IFunctionHandler* handler);
    int SetUpdateDispatcher(Offsets::IFunctionHandler* handler);

private:
    void RegisterFunction(const char* name, const char* params,
                          const FunctionFunctor& function);

    skald::SkaldRuntime& m_runtime;
    Offsets::IScriptSystem* m_pSS = nullptr;
    Offsets::IScriptTable* m_pMethodsTable = nullptr;
};

inline CScriptBind_SKALD g_skaldBind(skald::g_skaldRuntime);

}  // namespace luautils
