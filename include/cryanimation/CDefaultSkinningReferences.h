#pragma once
#include <cstddef>
#include <vector>

class CAttachmentSKIN;
class CAttachmentVCLOTH;

struct CDefaultSkinningReferences {
    std::vector<CAttachmentSKIN*> m_refByInstances;          // +0x00 RTTR "RefByInstances"
    std::vector<CAttachmentVCLOTH*> m_refByInstancesVCloth;  // +0x18 RTTR "RefByInstancesVCloth"
};

static_assert(offsetof(CDefaultSkinningReferences, m_refByInstancesVCloth) == 0x18,
              "CDefaultSkinningReferences::m_refByInstancesVCloth offset mismatch");
static_assert(sizeof(CDefaultSkinningReferences) == 0x30,
              "CDefaultSkinningReferences size mismatch");
