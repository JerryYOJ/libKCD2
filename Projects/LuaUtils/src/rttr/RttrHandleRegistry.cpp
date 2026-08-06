#include "rttr/RttrHandleRegistry.h"

#include <limits>
#include <stdexcept>
#include <utility>

namespace luautils {

namespace {

bool IsUsableDedupKey(const RttrHandleRegistry::DedupKey* key)
{
    return key && key->pointer && key->type.is_valid();
}

}  // namespace

RttrHandleRegistry::Handle RttrHandleRegistry::Store(
    rttr::variant&& value, const DedupKey* dedupKey)
{
    if (!value.is_valid())
        throw std::invalid_argument("cannot store an invalid RTTR variant");

    if (IsUsableDedupKey(dedupKey)) {
        const auto key = std::make_pair(dedupKey->type, dedupKey->pointer);
        const auto found = m_byPointer.find(key);
        if (found != m_byPointer.end()) {
            const auto entry = m_entries.find(found->second);
            if (entry != m_entries.end()) {
                ++entry->second.refCount;
                return found->second;
            }
            // Stale reverse-index leftover (should not happen if Release()
            // stays consistent with m_byPointer) -- drop it and fall through
            // to a fresh insert below.
            m_byPointer.erase(found);
        }
    }

    if (m_nextHandle == 0)
        throw std::overflow_error("RTTR handle space exhausted");

    const Handle handle = m_nextHandle;
    Entry entry{std::move(value), 1, {}, nullptr};
    if (IsUsableDedupKey(dedupKey)) {
        entry.dedupType = dedupKey->type;
        entry.dedupPointer = dedupKey->pointer;
    }

    auto [inserted, ok] = m_entries.emplace(handle, std::move(entry));
    if (!ok)
        throw std::logic_error("RTTR handle collision");

    if (IsUsableDedupKey(dedupKey)) {
        m_byPointer.emplace(
            std::make_pair(dedupKey->type, dedupKey->pointer), handle);
    }

    m_nextHandle = handle == std::numeric_limits<Handle>::max()
        ? 0
        : handle + 1;
    return handle;
}

const rttr::variant* RttrHandleRegistry::Lookup(Handle handle) const noexcept
{
    if (handle == 0)
        return nullptr;
    const auto entry = m_entries.find(handle);
    return entry != m_entries.end() ? &entry->second.value : nullptr;
}

bool RttrHandleRegistry::Release(Handle handle) noexcept
{
    if (handle == 0)
        return false;
    const auto entry = m_entries.find(handle);
    if (entry == m_entries.end())
        return false;
    if (--entry->second.refCount > 0)
        return true;
    if (entry->second.dedupPointer) {
        m_byPointer.erase(
            std::make_pair(entry->second.dedupType, entry->second.dedupPointer));
    }
    m_entries.erase(entry);
    return true;
}

void RttrHandleRegistry::Clear() noexcept
{
    m_entries.clear();
    m_byPointer.clear();
}

}  // namespace luautils
