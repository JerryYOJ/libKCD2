#pragma once

// -----------------------------------------------
// IMergeMeshStreamListener -- Cry3DEngine merged-mesh streaming callback
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x08, two slots, no destructor.
// -----------------------------------------------
// CMergedMeshesManager broadcasts slot [0] after a node reaches StreamedIn and
// slot [1] before stream-out resources are released. C_RespawnManager is the
// confirmed implementation at secondary-base offset +0x08.

class CMergedMeshRenderNode;

namespace Offsets {

class IMergeMeshStreamListener {
public:
    virtual void OnMergedMeshStreamedIn(CMergedMeshRenderNode* pNode) = 0;  // [0]
    virtual void OnMergedMeshStreamedOut(CMergedMeshRenderNode* pNode) = 0; // [1]
};
static_assert(sizeof(IMergeMeshStreamListener) == 0x08,
              "IMergeMeshStreamListener is a vptr-only two-slot interface");

}  // namespace Offsets
