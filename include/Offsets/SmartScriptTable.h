#pragma once
#include <cstddef>
#include "vtables/IScriptTable.h"

namespace Offsets {

class SmartScriptTable {
public:
    SmartScriptTable() noexcept = default;

    explicit SmartScriptTable(IScriptTable* table)
        : m_pTable(table) {
        if (m_pTable)
            m_pTable->AddRef();
    }

    SmartScriptTable(const SmartScriptTable& other)
        : SmartScriptTable(other.m_pTable) {}

    SmartScriptTable(SmartScriptTable&& other) noexcept
        : m_pTable(other.m_pTable) {
        other.m_pTable = nullptr;
    }

    ~SmartScriptTable() {
        if (m_pTable)
            m_pTable->Release();
    }

    SmartScriptTable& operator=(const SmartScriptTable& other) {
        return operator=(other.m_pTable);
    }

    SmartScriptTable& operator=(SmartScriptTable&& other) noexcept {
        if (this != &other) {
            if (m_pTable)
                m_pTable->Release();
            m_pTable = other.m_pTable;
            other.m_pTable = nullptr;
        }
        return *this;
    }

    SmartScriptTable& operator=(IScriptTable* table) {
        if (table)
            table->AddRef();
        if (m_pTable)
            m_pTable->Release();
        m_pTable = table;
        return *this;
    }

    IScriptTable* operator->() const noexcept { return m_pTable; }
    IScriptTable* GetPtr() const noexcept { return m_pTable; }
    explicit operator bool() const noexcept { return m_pTable != nullptr; }

private:
    IScriptTable* m_pTable{};
};
static_assert(sizeof(SmartScriptTable) == 0x08,
              "SmartScriptTable must be one retained table pointer");

}  // namespace Offsets
