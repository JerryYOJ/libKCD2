#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include "CryArray.h"
#include "CryThread.h"
#include "Cry_Math.h"
#include "../../cry3dengine/SMaterialResourceEntry.h"

class CCamera;
class ICrySizer;
class ITexture;
struct IMaterialHelpers;
struct IMaterialLayer;
struct IMaterialManager;
struct IRenderMesh;
struct ISurfaceType;
struct SShaderItem;

// KCD2 Interfuscator-shuffled binary order. CMatInfo overrides all 81 slots.
struct IMaterial {
    virtual ~IMaterial() = default;                              // [0]
    virtual bool IsValid() const = 0;                            // [1]
    virtual void AddRef() = 0;                                  // [2]
    virtual void Release() = 0;                                 // [3]
    virtual int GetNumRefs() = 0;                               // [4]
    virtual IMaterialHelpers& GetMaterialHelpers() = 0;         // [5]
    virtual IMaterialManager* GetMaterialManager() = 0;         // [6]
    virtual void SetName(const char* name) = 0;                  // [7]
    virtual const char* GetName() const = 0;                     // [8]
    virtual void SetFlags(int flags) = 0;                        // [9]
    virtual int GetFlags() const = 0;                            // [10]
    virtual bool IsDefault() const = 0;                          // [11]
    virtual int GetSurfaceTypeId() const = 0;                    // [12]
    virtual void SetSurfaceType(const char* name) = 0;           // [13]
    virtual ISurfaceType* GetSurfaceType() = 0;                  // [14]
    virtual void SetMatTemplate(const char* name) = 0;           // [15]
    virtual IMaterial* GetMatTemplate() = 0;                     // [16]
    virtual void SetShaderItem(const SShaderItem& shaderItem) = 0; // [17]
    virtual void IncrementModificationId() = 0;                  // [18]
    virtual void AssignShaderItem(const SShaderItem& shaderItem) = 0; // [19]
    virtual const SShaderItem& GetShaderItemForSlotConst(int slot) const = 0; // [20]
    virtual SShaderItem& GetShaderItemForSlot(int slot) = 0;     // [21]
    virtual const SShaderItem& GetShaderItemConst() const = 0;   // [22]
    virtual SShaderItem& GetShaderItem() = 0;                    // [23]
    virtual bool IsStreamedInRounds(const int* roundIds) const = 0; // [24]
    virtual bool IsStreamedInMesh(const int* roundIds,
                                  IRenderMesh* renderMesh) const = 0; // [25]
    virtual bool unk_26() const = 0;                             // [26]
    virtual void SetSubMtlCount(int count) = 0;                  // [27]
    virtual int GetSubMtlCount() = 0;                            // [28]
    virtual IMaterial* FindSubMtlByName(const char* name) = 0;   // [29]
    virtual IMaterial* GetSubMtl(int slot) = 0;                  // [30]
    virtual void SetSubMtl(int slot, IMaterial* material) = 0;   // [31]
    virtual void VisitSelfAndSubMtls(
        std::uint32_t flags,
        std::function<bool(IMaterial*)> visitor) = 0;            // [32]
    virtual void VisitSubMtls(
        std::uint32_t flags,
        std::function<bool(IMaterial*)> visitor) = 0;            // [33]
    virtual void SetLayerCount(std::uint32_t count) = 0;         // [34]
    virtual std::uint32_t GetLayerCount() const = 0;             // [35]
    virtual void SetLayer(std::uint32_t slot,
                          IMaterialLayer* layer) = 0;             // [36]
    virtual const IMaterialLayer* GetLayerBySlot(
        std::uint32_t slot) const = 0;                           // [37]
    virtual const IMaterialLayer* GetLayerByMask(
        std::uint8_t layersMask,
        std::uint8_t usageMask) const = 0;                       // [38]
    virtual IMaterialLayer* CreateLayer() = 0;                   // [39]
    virtual IMaterial* GetSafeSubMtl(int slot) = 0;              // [40]
    virtual int FillSurfaceTypeIds(int* surfaceIds) = 0;         // [41]
    virtual void SetUserData(void* userData) = 0;                // [42]
    virtual void* GetUserData() const = 0;                       // [43]
    virtual bool SetGetMaterialParamFloat(
        const char* name, float& value, bool get) = 0;           // [44]
    virtual bool SetGetMaterialParamVec3(
        const char* name, Vec3& value, bool get) = 0;            // [45]
    virtual bool unk_46(const char* name, float& value) const = 0; // [46]
    virtual bool unk_47(const char* name, Vec3& value) const = 0; // [47]
    virtual void SetTextureId(int textureId, int textureSlot) = 0; // [48]
    virtual void SetTextureObject(ITexture* texture,
                                  int textureSlot) = 0;          // [49]
    virtual void SetSubTexture(int textureId,
                               int subMaterialSlot,
                               int textureSlot) = 0;             // [50]
    virtual void SetTexturePath(const char* path,
                                int textureSlot) = 0;            // [51]
    virtual void SetCamera(CCamera& camera) = 0;                 // [52]
    virtual void GetMemoryUsage(ICrySizer* sizer) const = 0;     // [53]
    virtual std::size_t GetResourceMemoryUsage(ICrySizer* sizer) = 0; // [54]
    virtual const char* GetLoadingCallstack() = 0;               // [55]
    virtual void RequestTexturesLoading(float mipFactor) = 0;    // [56]
    virtual void ForceTexturesLoadingMip(float mipFactor) = 0;   // [57]
    virtual void ForceTexturesLoadingScreenTexels(
        int screenTexels) = 0;                                  // [58]
    virtual void PrecacheMaterial(float entityDistance,
                                  IRenderMesh* renderMesh,
                                  bool fullUpdate,
                                  bool drawNear) = 0;             // [59]
    virtual int GetTextureMemoryUsage(ICrySizer* sizer,
                                      int subMaterialSlot) = 0;  // [60]
    virtual void SetMaterialLinkName(const char* name) = 0;      // [61]
    virtual const char* GetMaterialLinkName() const = 0;         // [62]
    virtual void SetKeepLowResSysCopyForDiffTex() = 0;           // [63]
    virtual CryCriticalSection& GetSubMaterialResizeLock() = 0;  // [64]
    virtual void ActivateDynamicTextureSources(bool activate) = 0; // [65]
    virtual void LoadConsoleMaterial() = 0;                      // [66]
    virtual bool unk_67(const char* name, Vec4& value) const = 0; // [67]
    virtual bool unk_68(const char* name,
                        std::uint32_t& value) const = 0;         // [68]
    virtual bool unk_69(const CryStringT<char>& name,
                        const Vec4& value) = 0;                  // [69]
    virtual bool unk_70(const CryStringT<char>& name,
                        float value) = 0;                        // [70]
    virtual bool unk_71(std::uint32_t value) const = 0;          // [71]
    virtual bool unk_72(int value, bool enabled) = 0;            // [72]
    virtual void RebuildResourceEntries() = 0;                   // [73]
    virtual DynArray<SMaterialResourceEntry>& GetResourceEntries() = 0; // [74]
    virtual std::uint32_t unk_75() const = 0;                    // [75]
    virtual bool unk_76(std::uint32_t flags) const = 0;          // [76]
    virtual bool unk_77(std::uint16_t flags) const = 0;          // [77]
    virtual void SetUniqueMaterialName(const char* name) = 0;    // [78]
    virtual bool unk_79() = 0;                                  // [79]
    virtual void unk_80(void* output) const = 0;                 // [80]

    std::uint8_t m_defaultMappingAxis;                           // +0x08
    std::uint8_t m_padding09[3];                                // +0x09
    float m_defaultMappingScale;                                // +0x0C
};

static_assert(offsetof(IMaterial, m_defaultMappingAxis) == 0x08,
              "IMaterial mapping-axis offset mismatch");
static_assert(offsetof(IMaterial, m_defaultMappingScale) == 0x0C,
              "IMaterial mapping-scale offset mismatch");
static_assert(sizeof(IMaterial) == 0x10,
              "IMaterial size mismatch");
