#pragma once

#include "crysystem/SUserFunctionDesc.h"
#include "rttr/RttrRuntime.h"

namespace Offsets {
struct IFunctionHandler;
struct IScriptSystem;
struct IScriptTable;
}

namespace luautils {

class CScriptBind_RTTR
{
public:
    explicit CScriptBind_RTTR(RttrRuntime& runtime) noexcept;

    void Init(Offsets::IScriptSystem* pSS);
    bool IsInitialized() const noexcept { return m_pMethodsTable != nullptr; }
    void ClearHandles() noexcept { m_runtime.ClearHandles(); }

    int CallGlobal(Offsets::IFunctionHandler* pH);
    int CallMethod(Offsets::IFunctionHandler* pH);
    int GetProperty(Offsets::IFunctionHandler* pH);
    int GetEnum(Offsets::IFunctionHandler* pH);
    int GetTypeName(Offsets::IFunctionHandler* pH);
    int Release(Offsets::IFunctionHandler* pH);
    int Clear(Offsets::IFunctionHandler* pH);
    // soulWuid (a Warhorse WUID, e.g. player.soul -- a DIFFERENT id space
    // from a CryEngine EntityId) -> an object_handle for wh.rpgmodule.I_Soul,
    // via C_SoulList::LookupByWUID. Accepts either an ANY_THANDLE or a plain
    // integer ANY_TNUMBER, since the caller's own representation for a raw
    // WUID (as opposed to one of our own registry tokens) is not certified.
    int GetSoulByWuid(Offsets::IFunctionHandler* pH);

private:
    void RegisterFunction(const char* name, const char* params,
                          const FunctionFunctor& function);

    RttrRuntime& m_runtime;
    Offsets::IScriptSystem* m_pSS = nullptr;
    Offsets::IScriptTable* m_pMethodsTable = nullptr;
};

inline CScriptBind_RTTR g_rttrBind(g_rttrRuntime);

}  // namespace luautils
