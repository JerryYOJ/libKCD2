#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryArray.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/smartptr.h"
#include "RChunk.h"

struct IMaterial;
struct IRenderMesh;

class CModelMesh {
public:
    CModelMesh();
    ~CModelMesh();

    _smart_ptr<IRenderMesh> m_renderMesh;                      // +0x00
    _smart_ptr<IMaterial> m_defaultMaterial;                   // +0x08
    Vec3 m_renderMeshOffset;                                   // +0x10
    volatile std::int32_t m_threadMeshAccessCounter;           // +0x1C
    DynArray<RChunk> m_renderChunks;                            // +0x20
    std::uint8_t m_runtime28[0x88];                            // +0x28, streaming/software-mesh/cache region
};

static_assert(offsetof(CModelMesh, m_renderMesh) == 0x00,
              "CModelMesh render-mesh offset mismatch");
static_assert(offsetof(CModelMesh, m_defaultMaterial) == 0x08,
              "CModelMesh material offset mismatch");
static_assert(offsetof(CModelMesh, m_renderMeshOffset) == 0x10,
              "CModelMesh render offset mismatch");
static_assert(offsetof(CModelMesh, m_renderChunks) == 0x20,
              "CModelMesh render-chunk array offset mismatch");
static_assert(sizeof(CModelMesh) == 0xB0,
              "CModelMesh size mismatch");
