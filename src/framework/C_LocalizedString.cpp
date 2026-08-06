#include "framework/C_LocalizedString.h"
#include "Offsets/Offsets.h"
#include "Offsets/vtables/ILocalizationManager.h"
#include "Offsets/vtables/ISystem.h"
#include "crysystem/SSystemGlobalEnvironment.h"

// C_LocalizedString helpers -- KCD2 WHGame.dll 1.5.6 RVAs (verified in kd7u).

namespace wh::framework {

CryStringT<char> C_LocalizedString::Standardize(const CryStringT<char>& text)
{
    // sub_1803C235C: collapses repeated spaces, removes spaces around '|',
    // and prefixes eligible tokens with '@'. No localization lookup occurs.
    using Fn = CryStringT<char>(__fastcall*)(const CryStringT<char>&);
    static REL::Relocation<Fn> fn{ REL::ID(1) };
    return fn(text);
}

bool C_LocalizedString::Localize(const CryStringT<char>& text,
                                 CryStringT<char>& output, bool english)
{
    output = text;
    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (!env || !env->pSystem)
        return false;

    auto* manager = env->pSystem->GetLocalizationManager();
    if (!manager)
        return false;

    CryStringT<char> localized;
    if (!manager->LocalizeString(text.c_str(), localized, english))
        return false;

    output = localized;
    return true;
}

}  // namespace wh::framework
