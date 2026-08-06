#pragma once
#include <cstddef>
#include "IXmlNode.h"

// -----------------------------------------------
// XmlNodeRef -- CryCommon's intrusive XML node ref (KCD2 WHGame.dll Steam
// 1.5.6, e4cp).  sizeof 8.
// -----------------------------------------------
// One pointer to the engine's IXmlNode.  The RE'd IXmlNode vtable must be used:
// the stock CryCommon IXml.h order is interfuscated differently from the shipped
// binary.  Copy helper 0x18041EBF4 AddRefs through slot 3; destructor helper
// 0x1804FB980 Releases through slot 4.  Restoring those non-trivial semantics is
// also required for MSVC's indirect, callee-destroy ABI for XmlNodeRef-by-value.
// Declared at global scope to match the engine spelling used by conceptmodule.

class XmlNodeRef {
public:
    XmlNodeRef() noexcept = default;
    explicit XmlNodeRef(std::nullptr_t) noexcept {}

    XmlNodeRef(Offsets::IXmlNode* node) noexcept
        : m_ptr(node)
    {
        if (m_ptr)
            m_ptr->AddRef();
    }

    XmlNodeRef(const XmlNodeRef& other) noexcept
        : m_ptr(other.m_ptr)
    {
        if (m_ptr)
            m_ptr->AddRef();
    }

    ~XmlNodeRef()
    {
        if (m_ptr)
            m_ptr->Release();
    }

    XmlNodeRef& operator=(Offsets::IXmlNode* node) noexcept
    {
        if (node)
            node->AddRef();
        if (m_ptr)
            m_ptr->Release();
        m_ptr = node;
        return *this;
    }

    XmlNodeRef& operator=(const XmlNodeRef& other) noexcept
    {
        return operator=(other.m_ptr);
    }

    operator Offsets::IXmlNode*() const noexcept { return m_ptr; }
    operator const Offsets::IXmlNode*() const noexcept { return m_ptr; }
    Offsets::IXmlNode& operator*() const noexcept { return *m_ptr; }
    Offsets::IXmlNode* operator->() const noexcept { return m_ptr; }
    explicit operator bool() const noexcept { return m_ptr != nullptr; }
    bool operator!() const noexcept { return m_ptr == nullptr; }

    Offsets::IXmlNode* m_ptr = nullptr;  // +0x00
};
static_assert(sizeof(XmlNodeRef) == 8, "XmlNodeRef is one IXmlNode*");
