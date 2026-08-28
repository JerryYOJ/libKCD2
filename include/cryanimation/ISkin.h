#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"

struct ICrySizer;
struct IMaterial;
struct IRenderMesh;
struct IVertexFrames;

// KCD2 Interfuscator-shuffled binary order. CSkin overrides these 16 slots,
// inserts its RTTR trio, then appends concrete-only virtuals.
struct ISkin {
    virtual ~ISkin() = default;                                  // [0]
    virtual void Release() = 0;                                  // [1]
    virtual void PrecacheMesh(bool fullUpdate, int roundId, int lod) = 0; // [2]
    virtual IRenderMesh* GetIRenderMesh(std::uint32_t lod) const = 0;      // [3]
    virtual const char* GetModelFilePath() const = 0;             // [4]
    virtual IMaterial* GetIMaterial(std::uint32_t lod) const = 0; // [5]
    virtual void unk_06(void* output) const = 0;                  // [6]
    virtual bool unk_07(void* context) const = 0;                 // [7]
    virtual Vec3 GetRenderMeshOffset(std::uint32_t lod) const = 0; // [8]
    virtual std::uint32_t GetNumJoints() const = 0;               // [9]
    virtual std::uint32_t GetJointIDByCRC32(std::uint32_t crc32) const = 0; // [10]
    virtual std::uint32_t GetJointIDByName(const char* name) const = 0;     // [11]
    virtual std::int32_t GetJointParentID(std::uint32_t jointId) const = 0; // [12]
    virtual const QuatT& GetJointDefaultAbs(std::uint32_t jointId) const = 0; // [13]
    virtual const QuatT& GetJointDefaultRel(std::uint32_t jointId) const = 0; // [14]
    virtual const IVertexFrames* GetVertexFrames() const = 0;      // [15]
};

static_assert(sizeof(ISkin) == 0x08, "ISkin size mismatch");
