#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryArray.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"
#include "CModelMesh.h"
#include "ISkin.h"

struct SAttachmentVClothPreProcessData;

class CSkin : public ISkin {
public:
    struct SJointInfo {
        std::int32_t m_idxParent;                              // +0x00
        std::uint32_t m_jointCRC32Lower;                       // +0x04
        QuatT m_defaultAbsolute;                               // +0x08
        QuatT m_defaultRelative;                               // +0x24
        CryStringT<char> m_nameModelSkin;                      // +0x40
    };

    explicit CSkin(CryStringT<char> const& fileName,
                   std::uint32_t loadingFlags);
    ~CSkin() override;                                         // [0] 0x1803C2A60
    void Release() override;                                   // [1] 0x1809780E8
    void PrecacheMesh(bool fullUpdate, int roundId, int lod) override; // [2] 0x180ECDCDC
    IRenderMesh* GetIRenderMesh(std::uint32_t lod) const override;      // [3] 0x1804A2F60
    const char* GetModelFilePath() const override;             // [4] 0x18113CE50
    IMaterial* GetIMaterial(std::uint32_t lod) const override; // [5] 0x180F56528
    std::uint32_t GetMeshLodInfo(Array<SMeshLodInfo> lods) const override; // [6] 0x180977724
    bool AreRenderMeshesReady(int* pKey) const override; // [7] 0x1820F57C0
    Vec3 GetRenderMeshOffset(std::uint32_t lod) const override; // [8] 0x1837A5398
    std::uint32_t GetNumJoints() const override;               // [9] 0x181AAF020
    std::uint32_t GetJointIDByCRC32(std::uint32_t crc32) const override; // [10] 0x1837A51F8
    std::uint32_t GetJointIDByName(const char* name) const override;     // [11] 0x1837A523C
    std::int32_t GetJointParentID(std::uint32_t jointId) const override; // [12] 0x1837A5288
    const QuatT& GetJointDefaultAbs(std::uint32_t jointId) const override; // [13] 0x1837A51B0
    const QuatT& GetJointDefaultRel(std::uint32_t jointId) const override; // [14] 0x1837A51D4
    const IVertexFrames* GetVertexFrames() const override;      // [15] 0x180AB9600
    RTTR_ENABLE(ISkin)                                         // [16..18]
    virtual void SetKeepInMemory(bool keep);                   // [19] 0x181AAFC70
    virtual std::uint32_t GetNumLODs() const;                  // [20] 0x181A74C00
    virtual std::uint32_t GetTextureMemoryUsage2(
        ICrySizer* sizer = nullptr) const;                     // [21] 0x1837A53F8
    virtual std::uint32_t GetMeshMemoryUsage(
        ICrySizer* sizer = nullptr) const;                     // [22] 0x1837A532C

    void AddRef();
    void DeleteIfNotReferenced();
    std::int32_t GetRefCounter() const;

    DynArray<SJointInfo> m_arrModelJoints;                     // +0x08
    DynArray<CModelMesh> m_arrModelMeshes;                     // +0x10
    std::uint32_t m_loadingFlags;                              // +0x18
    std::int32_t m_keepInMemory;                               // +0x1C
    std::int32_t m_refCounter;                                 // +0x20
    std::int32_t m_instanceCounter;                            // +0x24
    CryStringT<char> m_filePath;                               // +0x28
    bool m_needsComputeSkinningBuffers;                        // +0x30
    std::uint8_t m_padding31[7];                              // +0x31
    SAttachmentVClothPreProcessData* m_vClothData;             // +0x38, owned heap object
};

static_assert(sizeof(CSkin::SJointInfo) == 0x48,
              "CSkin::SJointInfo size mismatch");
static_assert(offsetof(CSkin::SJointInfo, m_defaultAbsolute) == 0x08,
              "CSkin::SJointInfo absolute transform offset mismatch");
static_assert(offsetof(CSkin::SJointInfo, m_defaultRelative) == 0x24,
              "CSkin::SJointInfo relative transform offset mismatch");
static_assert(offsetof(CSkin::SJointInfo, m_nameModelSkin) == 0x40,
              "CSkin::SJointInfo name offset mismatch");
static_assert(offsetof(CSkin, m_arrModelJoints) == 0x08,
              "CSkin joint array offset mismatch");
static_assert(offsetof(CSkin, m_arrModelMeshes) == 0x10,
              "CSkin mesh array offset mismatch");
static_assert(offsetof(CSkin, m_filePath) == 0x28,
              "CSkin file-path offset mismatch");
static_assert(offsetof(CSkin, m_vClothData) == 0x38,
              "CSkin VCloth data offset mismatch");
static_assert(sizeof(CSkin) == 0x40,
              "CSkin size mismatch");
