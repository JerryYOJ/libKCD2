#pragma once

#include <cstddef>
#include <cstdint>
#include <deque>
#include <mutex>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "conceptmodule/C_ActiveTriggerPort.h"
#include "conceptmodule/I_Port.h"
#include "crysystem/ScriptAnyValue.h"
#include "rttr/RttrRuntime.h"
#include "skald/SkaldNodeHost.h"

namespace Offsets {
struct IScriptSystem;
struct IScriptTable;
}

namespace luautils::skald {

class SkaldRuntime
{
public:
    using Handle = std::uint64_t;

    struct OutputUpdate
    {
        Handle binding = 0;
        rttr::type declaredType;
        rttr::variant value;
    };

    struct TriggerCapture
    {
        std::uint64_t generation = 0;
        std::uint64_t sequence = 0;
        Handle node = 0;
        std::vector<Handle> connections;
        std::vector<OutputUpdate> updates;

        explicit operator bool() const noexcept
        {
            return node != 0 && !connections.empty();
        }
    };

    explicit SkaldRuntime(RttrRuntime& rttrRuntime) noexcept;
    ~SkaldRuntime();

    SkaldRuntime(const SkaldRuntime&) = delete;
    SkaldRuntime& operator=(const SkaldRuntime&) = delete;

    void SetScriptSystem(Offsets::IScriptSystem* scriptSystem) noexcept;
    bool SetUpdateDispatcher(HSCRIPTFUNCTION dispatcher, std::string& error);

    bool CreateNode(std::string_view cppType,
                    Offsets::IScriptTable* arguments,
                    Handle& nodeHandle,
                    RttrHandleRegistry::Handle& rttrHandle,
                    std::string& error);
    bool DestroyNode(Handle nodeHandle, std::string& error);
    // Introspection: reports a node class's live port definitions without
    // attaching or activating anything.
    bool DescribeNode(std::string_view cppType, std::string_view typeParameter,
                      std::vector<SkaldPortInfo>& ports, std::string& error);
    bool BindTriggerOutput(Handle nodeHandle, std::string_view outputName,
                           HSCRIPTFUNCTION callback, Handle& connectionHandle,
                           std::string& error);
    bool BindDataOutput(Handle nodeHandle, std::string_view outputName,
                        Handle& bindingHandle, OutputUpdate& initialValue,
                        std::string& error);
    bool UnbindDataOutput(Handle bindingHandle, std::string& error);
    bool Disconnect(Handle connectionHandle, std::string& error);
    bool TriggerInput(Handle nodeHandle, std::string_view triggerName,
                      std::vector<OutputUpdate>& updates, std::string& error);
    // GC path: enqueue a node for destruction at the next safe drain point
    // (DeliverQueuedEvents). Never destroys inline -- safe to call from Lua
    // __gc finalizers, which fire at arbitrary VM allocation points.
    void QueueDestroy(Handle nodeHandle) noexcept;
    bool SetActivation(Handle nodeHandle, bool active,
                       std::vector<OutputUpdate>& updates, std::string& error);

    Offsets::IScriptTable* CreateUpdateTable(
        std::vector<OutputUpdate>& updates, std::string& error);

    TriggerCapture CaptureOutputTrigger(
        wh::conceptmodule::C_ActiveTriggerPort* port) noexcept;
    void EnqueueOutputTrigger(TriggerCapture&& capture) noexcept;
    void DeliverQueuedEvents() noexcept;
    void InvalidateLuaOutputs() noexcept;

    void Clear() noexcept;

    wh::conceptmodule::C_Node* GetNode(Handle nodeHandle) const noexcept;

private:
    struct NodeRecord
    {
        RttrHandleRegistry::Handle rttrHandle = 0;
        _smart_ptr<wh::conceptmodule::C_Node> node;
        std::vector<Handle> dataBindings;
        std::vector<Handle> triggerConnections;
    };

    struct DataBindingRecord
    {
        Handle node = 0;
        _smart_ptr<wh::conceptmodule::I_Port> port;
        rttr::type declaredType;
    };

    struct TriggerConnectionRecord
    {
        Handle node = 0;
        _smart_ptr<wh::conceptmodule::I_Port> port;
        HSCRIPTFUNCTION callback = nullptr;
    };

    struct BindingSource
    {
        Handle binding = 0;
        _smart_ptr<wh::conceptmodule::I_Port> port;
        rttr::type declaredType;
    };

    bool AllocateHandle(Handle& handle, std::string& error) noexcept;
    bool SerializeConstant(const rttr::type& valueType,
                           const rttr::variant& value,
                           std::string& literal,
                           std::string& error);
    bool FindOutputPort(Handle nodeHandle, std::string_view outputName,
                        bool expectTrigger,
                        _smart_ptr<wh::conceptmodule::I_Port>& port,
                        rttr::type& declaredType,
                        std::string& error) const;
    std::vector<BindingSource> CollectBindingSources(
        Handle nodeHandle) const;
    static std::vector<OutputUpdate> SnapshotBindings(
        const std::vector<BindingSource>& sources);
    bool BuildUpdateTable(std::vector<OutputUpdate>& updates,
                          Offsets::IScriptTable*& table,
                          std::vector<RttrHandleRegistry::Handle>& createdHandles,
                          std::string& error);
    void ReleaseHandles(
        const std::vector<RttrHandleRegistry::Handle>& handles) noexcept;
    void RemoveNodeRecordsLocked(
        Handle nodeHandle, std::vector<HSCRIPTFUNCTION>& callbacks);
    void Log(const char* format, ...) const noexcept;
    void Shutdown() noexcept;

    static constexpr std::size_t kMaxDataBindingsPerNode = 64;
    static constexpr std::size_t kMaxTriggerConnectionsPerNode = 64;
    static constexpr std::size_t kMaxQueuedEvents = 1024;

    RttrRuntime& m_rttrRuntime;
    SkaldNodeHost m_host;
    mutable std::mutex m_mutex;
    std::unordered_map<Handle, NodeRecord> m_nodes;
    std::unordered_map<Handle, DataBindingRecord> m_dataBindings;
    std::unordered_map<Handle, TriggerConnectionRecord> m_triggerConnections;
    std::unordered_map<wh::conceptmodule::C_ActiveTriggerPort*,
                       std::vector<Handle>> m_triggerRoutes;
    std::deque<TriggerCapture> m_eventQueue;
    std::vector<Handle> m_destroyQueue;
    Offsets::IScriptSystem* m_scriptSystem = nullptr;
    HSCRIPTFUNCTION m_updateDispatcher = nullptr;
    Handle m_nextHandle = 1;
    std::uint64_t m_generation = 1;
    std::uint64_t m_nextEventSequence = 1;
    std::size_t m_droppedEvents = 0;
};

inline SkaldRuntime g_skaldRuntime{ g_rttrRuntime };

}  // namespace luautils::skald
