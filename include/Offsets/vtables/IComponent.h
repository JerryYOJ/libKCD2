#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>

struct IComponentEventDistributer;
struct SEntityEvent;

namespace Offsets {

struct IEntity;

// KCD2 binary-facing CryEngine component base. Interfuscator controls slot order.
class IComponent : public std::enable_shared_from_this<IComponent> {
public:
    virtual ~IComponent() = default;                         // [0] base dtor 0x1827D1F44
    virtual void ProcessEvent(SEntityEvent& event) = 0;      // [1]
    virtual bool _vf2() = 0;                                // [2] default false
    virtual int GetEventPriority(int eventId) = 0;           // [3]
    virtual void _vf4() = 0;                                // [4] default no-op
    virtual IEntity* GetEntity() = 0;                        // [5]

    IComponentEventDistributer* m_pComponentEventDistributer; // +0x18, borrowed
    std::uint32_t m_componentEntityId;                        // +0x20
    std::uint32_t m_componentFlags;                           // +0x24
};
static_assert(sizeof(IComponent) == 0x28, "IComponent must be 0x28");
static_assert(offsetof(IComponent, m_pComponentEventDistributer) == 0x18,
              "component event distributer must be at 0x18");

}  // namespace Offsets
