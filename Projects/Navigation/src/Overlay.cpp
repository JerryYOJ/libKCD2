#include "Overlay.h"

#include "CryEngine/CryCommon/CFlashPlayer.h"
#include "CryEngine/CryCommon/CFlashUIElement.h"
#include "CryEngine/CryCommon/SFlashVarValue.h"
#include "guimodule/C_UIMap.h"
#include "Offsets/vtables/IFlashPlayer.h"
#include "Offsets/vtables/IFlashVariableObject.h"

using Offsets::FlashVarPtr;

static Offsets::IFlashPlayer* ApsePlayer()
{
    auto* map = wh::guimodule::C_UIMap::GetInstance();
    if (!map || !map->m_content.m_pElement)
        return nullptr;
    auto* el = static_cast<CFlashUIElement*>(map->m_content.m_pElement);
    return el->m_pFlashPlayer.get();
}

void Overlay::PushPath(const std::vector<Vec3>& nodes)
{
    auto* fp = ApsePlayer();
    if (!fp || !fp->IsAvailable("_root.map.navOverlay"))
        return;

    std::vector<float> xy;
    xy.reserve(nodes.size() * 2);
    for (const auto& p : nodes)
    {
        xy.push_back(p.x);
        xy.push_back(p.y);
    }
    if (xy.size() < 4)
        return;

    fp->SetVariableArray(Offsets::IFlashPlayer::FVAT_Float, "_root.map.navOverlay.pathA",
                         0, xy.data(), static_cast<unsigned>(xy.size()));
}

void Overlay::ClearPath()
{
    auto* fp = ApsePlayer();
    if (!fp || !fp->IsAvailable("_root.map.navOverlay"))
        return;
    FlashVarPtr ov;
    if (!fp->GetVariable("_root.map.navOverlay", ov.put()) || !ov)
        return;
    ov->Invoke("ClearPath", static_cast<const SFlashVarValue*>(nullptr), 0);
}

bool Overlay::CheckpointHovered()
{
    auto* fp = ApsePlayer();
    if (!fp || !fp->IsAvailable("_root.map.navOverlay._hover"))
        return false;
    SFlashVarValue v;
    if (!fp->GetVariable("_root.map.navOverlay._hover", v))
        return false;
    if (v.IsBool())
        return v.GetBool();
    if (v.IsDouble())
        return v.GetDouble() != 0;
    if (v.IsInt())
        return v.GetInt() != 0;
    if (v.IsFloat())
        return v.GetFloat() != 0;
    return false;
}
