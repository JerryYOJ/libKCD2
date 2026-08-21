#pragma once
#include <cstddef>
#include <map>
#include <vector>

#include "C_ModuleBase.h"
#include "S_ProjectEdgeRecord.h"

// wh::conceptmodule::C_Project -- root module for a concept graph
// (KCD2 WHGame.dll Steam 1.5.6).  sizeof 0xB8.

namespace wh::conceptmodule {

class C_Project : public C_ModuleBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Project;
    CryStringT<char> m_databaseName;  // +0xA0, descriptive name
    std::map<CryStringT<char>, std::vector<S_ProjectEdgeRecord>,
             std::less<CryStringT<char>>> m_edgeGroups;  // +0xA8, descriptive name
};
static_assert(sizeof(C_Project) == 0xB8);
static_assert(offsetof(C_Project, m_databaseName) == 0xA0);
static_assert(offsetof(C_Project, m_edgeGroups) == 0xA8);

// 0x180BC2498, REL::ID(63017). The returned smart pointer owns one reference.
_smart_ptr<C_Project> CreateProject(const char* name);

}  // namespace wh::conceptmodule
