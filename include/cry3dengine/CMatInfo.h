#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include <vector>
#include "../CryEngine/CryCommon/CryArray.h"
#include "../CryEngine/CryCommon/smartptr.h"
#include "../Offsets/vtables/IMaterial.h"
#include "../framework/CryDeferrable.h"
#include "../rttr/rttr_enable.h"
#include "Cry3DEngineBase.h"
#include "EMaterialCopyFlags.h"
#include "SMaterialResourceEntry.h"
#include "SShaderItem.h"
#include "SStreamingPredictionZone.h"
#include "intrusive_linked_list_node.h"

class CMaterialLayer;

class CMatInfo : public IMaterial,
                 public stl::intrusive_linked_list_node<CMatInfo>,
                 public Cry3DEngineBase,
                 public UnsafeOp::CryDeferrable<0> {
public:
    CMatInfo();
    ~CMatInfo() override;                                      // [0] 0x1803A76A4
    bool IsValid() const override;                              // [1] 0x180454F48
    void AddRef() override;                                    // [2] 0x1806BCF90
    void Release() override;                                   // [3] 0x18069636C
    int GetNumRefs() override;                                 // [4] 0x181A72810
    IMaterialHelpers& GetMaterialHelpers() override;           // [5] 0x181AACCA0
    IMaterialManager* GetMaterialManager() override;           // [6] 0x181AACC80
    void SetName(const char* name) override;                    // [7] 0x18076D64C
    const char* GetName() const override;                       // [8] 0x18113CE50
    void SetFlags(int flags) override;                          // [9] 0x181A72930
    int GetFlags() const override;                              // [10] 0x181A72820
    bool IsDefault() const override;                            // [11] 0x1806BA918
    int GetSurfaceTypeId() const override;                      // [12] 0x181A73A40
    void SetSurfaceType(const char* name) override;             // [13] 0x18076C9F8
    ISurfaceType* GetSurfaceType() override;                    // [14] 0x18054B91C
    void SetMatTemplate(const char* name) override;             // [15] 0x18076CB38
    IMaterial* GetMatTemplate() override;                       // [16] 0x1834C1E38
    void SetShaderItem(const SShaderItem& shaderItem) override; // [17] 0x1834C5F4C
    void IncrementModificationId() override;                    // [18] 0x181AAD530
    void AssignShaderItem(const SShaderItem& shaderItem) override; // [19] 0x1807EA460
    const SShaderItem& GetShaderItemForSlotConst(
        int slot) const override;                               // [20] 0x1834C292C
    SShaderItem& GetShaderItemForSlot(int slot) override;       // [21] 0x1804A5060
    const SShaderItem& GetShaderItemConst() const override;     // [22] 0x181A73940
    SShaderItem& GetShaderItem() override;                      // [23] 0x181A73940
    bool IsStreamedInRounds(const int* roundIds) const override; // [24] 0x1834C3754
    bool IsStreamedInMesh(const int* roundIds,
                          IRenderMesh* renderMesh) const override; // [25] 0x1834C37C4
    bool unk_26() const override;                               // [26] 0x1834C3654
    void SetSubMtlCount(int count) override;                    // [27] 0x1812E1B68
    int GetSubMtlCount() override;                              // [28] 0x1804846B0
    IMaterial* FindSubMtlByName(const char* name) override;     // [29] 0x1834C2AE8
    IMaterial* GetSubMtl(int slot) override;                    // [30] 0x1804846B8
    void SetSubMtl(int slot, IMaterial* material) override;     // [31] 0x18076C71C
    void VisitSelfAndSubMtls(
        std::uint32_t flags,
        std::function<bool(IMaterial*)> visitor) override;      // [32] 0x180708FDC
    void VisitSubMtls(
        std::uint32_t flags,
        std::function<bool(IMaterial*)> visitor) override;      // [33] 0x180709098
    void SetLayerCount(std::uint32_t count) override;           // [34] 0x181977BB4
    std::uint32_t GetLayerCount() const override;               // [35] 0x1834C1D24
    void SetLayer(std::uint32_t slot,
                  IMaterialLayer* layer) override;              // [36] 0x180C16B74
    const IMaterialLayer* GetLayerBySlot(
        std::uint32_t slot) const override;                     // [37] 0x180C16AB8
    const IMaterialLayer* GetLayerByMask(
        std::uint8_t layersMask,
        std::uint8_t usageMask) const override;                 // [38] 0x1834C1CC0
    IMaterialLayer* CreateLayer() override;                     // [39] 0x180C16AE0
    IMaterial* GetSafeSubMtl(int slot) override;                // [40] 0x180520500
    int FillSurfaceTypeIds(int* surfaceIds) override;           // [41] 0x18054B8C4
    void SetUserData(void* userData) override;                  // [42] 0x181A72DC0
    void* GetUserData() const override;                         // [43] 0x181AAD520
    bool SetGetMaterialParamFloat(
        const char* name, float& value, bool get) override;     // [44] 0x180AB6DBC
    bool SetGetMaterialParamVec3(
        const char* name, Vec3& value, bool get) override;      // [45] 0x180AB6CAC
    bool unk_46(const char* name,
                float& value) const override;                   // [46] 0x180AB7E20
    bool unk_47(const char* name,
                Vec3& value) const override;                    // [47] 0x180AB5C20
    void SetTextureId(int textureId, int textureSlot) override; // [48] 0x1834C6478
    void SetTextureObject(ITexture* texture,
                          int textureSlot) override;            // [49] 0x1820D6D60
    void SetSubTexture(int textureId,
                       int subMaterialSlot,
                       int textureSlot) override;               // [50] 0x1834C63E0
    void SetTexturePath(const char* path,
                        int textureSlot) override;              // [51] 0x18073EFB0
    void SetCamera(CCamera& camera) override;                   // [52] 0x1834C5938
    void GetMemoryUsage(ICrySizer* sizer) const override;       // [53] 0x1834C2084
    std::size_t GetResourceMemoryUsage(
        ICrySizer* sizer) override;                             // [54] 0x1834C2748
    const char* GetLoadingCallstack() override;                 // [55] 0x181A72B70
    void RequestTexturesLoading(float mipFactor) override;      // [56] 0x18080C20C
    void ForceTexturesLoadingMip(float mipFactor) override;     // [57] 0x1834C1658
    void ForceTexturesLoadingScreenTexels(
        int screenTexels) override;                             // [58] 0x1834C1660
    void PrecacheMaterial(float entityDistance,
                          IRenderMesh* renderMesh,
                          bool fullUpdate,
                          bool drawNear) override;              // [59] 0x18078E46C
    int GetTextureMemoryUsage(ICrySizer* sizer,
                              int subMaterialSlot) override;    // [60] 0x1834C2B6C
    void SetMaterialLinkName(const char* name) override;        // [61] 0x1834C5CEC
    const char* GetMaterialLinkName() const override;           // [62] 0x181A73360
    void SetKeepLowResSysCopyForDiffTex() override;             // [63] 0x1806B9518
    CryCriticalSection& GetSubMaterialResizeLock() override;    // [64] 0x1807C7730
    void ActivateDynamicTextureSources(bool activate) override; // [65] 0x1834C0474
    void LoadConsoleMaterial() override;                        // [66] 0x1803B6E80
    bool unk_67(const char* name,
                Vec4& value) const override;                    // [67] 0x1819512D4
    bool unk_68(const char* name,
                std::uint32_t& value) const override;           // [68] 0x1834C2974
    bool unk_69(const CryStringT<char>& name,
                const Vec4& value) override;                    // [69] 0x1819CAA00
    bool unk_70(const CryStringT<char>& name,
                float value) override;                          // [70] 0x1834C6034
    bool unk_71(std::uint32_t value) const override;            // [71] 0x180C169C0
    bool unk_72(int value, bool enabled) override;              // [72] 0x1834C5EF0
    void RebuildResourceEntries() override;                     // [73] 0x18076CF78
    DynArray<SMaterialResourceEntry>& GetResourceEntries() override; // [74] 0x181A947E0
    std::uint32_t unk_75() const override;                      // [75] 0x1834C2E04
    bool unk_76(std::uint32_t flags) const override;            // [76] 0x1834C2E70
    bool unk_77(std::uint16_t flags) const override;            // [77] 0x18121F474
    void SetUniqueMaterialName(const char* name) override;      // [78] 0x180563CA4
    bool unk_79() override;                                    // [79] 0x180708F9C
    void unk_80(void* output) const override;                   // [80] 0x180AB96D8
    RTTR_ENABLE(IMaterial)                                     // [81..83]
    virtual CMatInfo* Clone(CMatInfo* parentOfClone);           // [84] 0x18073E508
    virtual void Copy(IMaterial* destination,
                      EMaterialCopyFlags flags);                // [85] 0x1834C0D5C

    void ShutDown();

    CryStringT<char> m_materialName;                            // +0x28
    CryStringT<char> m_uniqueMaterialName;                      // +0x30
    std::int32_t m_surfaceTypeId;                               // +0x38
    volatile std::int32_t m_refCount;                           // +0x3C
    std::int32_t m_flags;                                       // +0x40
    bool m_deleted;                                             // +0x44
    bool m_deletePending;                                       // +0x45
    bool m_unknown46;                                           // +0x46
    std::uint8_t m_padding47;                                  // +0x47
    SShaderItem m_shaderItem;                                   // +0x48
    std::uint8_t m_shaderItemState[8];                          // +0x60
    std::uint32_t m_modificationId;                             // +0x68
    std::uint32_t m_padding6C;                                 // +0x6C
    DynArray<_smart_ptr<CMatInfo>> m_subMaterials;              // +0x70
    void* m_userData;                                          // +0x78
    CryStringT<char> m_materialLinkName;                        // +0x80
    CryStringT<char> m_materialTemplate;                        // +0x88
    std::vector<_smart_ptr<CMaterialLayer>>* m_materialLayers;  // +0x90
    mutable CMaterialLayer* m_activeLayer;                      // +0x98
    SStreamingPredictionZone m_streamingPredictionZones[2];     // +0xA0
    Vec4 m_textureSlotParameters[14];                           // +0xB0
    std::uint32_t m_shaderResourceState;                        // +0x190
    std::uint32_t m_padding194;                                // +0x194
    DynArray<SMaterialResourceEntry> m_resourceEntries;         // +0x198
};

static_assert(sizeof(SShaderItem) == 0x18,
              "SShaderItem size mismatch");
static_assert(offsetof(CMatInfo, m_materialName) == 0x28,
              "CMatInfo material-name offset mismatch");
static_assert(offsetof(CMatInfo, m_refCount) == 0x3C,
              "CMatInfo ref-count offset mismatch");
static_assert(offsetof(CMatInfo, m_shaderItem) == 0x48,
              "CMatInfo shader-item offset mismatch");
static_assert(offsetof(CMatInfo, m_subMaterials) == 0x70,
              "CMatInfo submaterial offset mismatch");
static_assert(offsetof(CMatInfo, m_streamingPredictionZones) == 0xA0,
              "CMatInfo streaming-zone offset mismatch");
static_assert(offsetof(CMatInfo, m_textureSlotParameters) == 0xB0,
              "CMatInfo texture-slot cache offset mismatch");
static_assert(offsetof(CMatInfo, m_shaderResourceState) == 0x190,
              "CMatInfo shader-resource state offset mismatch");
static_assert(offsetof(CMatInfo, m_resourceEntries) == 0x198,
              "CMatInfo resource-entry offset mismatch");
static_assert(sizeof(CMatInfo) == 0x1A0,
              "CMatInfo size mismatch");
