#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "../Offsets/vtables/IStreamCallback.h"
#include "../cry3dengine/Cry3DEngineBase.h"
#include "../wh/I_HLod.h"

enum EFileStreamingStatus : std::uint8_t;

namespace wh::engine3d {

class C_HLodStreaming : public Cry3DEngineBase,
                        public std::enable_shared_from_this<C_HLodStreaming>,
                        public wh::I_HLod,
                        public Offsets::IStreamCallback {
public:
    IRenderNode* GetProxyMesh() const override;              // [9] 0x181A735C0
    void SetProxyMesh(IRenderNode* proxyMesh) override;       // [10] 0x1834C5E64
    void* unk_11() override;                                 // [11] 0x1834C5ED4
    std::size_t AddObject(IRenderNode* object) override;      // [12] 0x1803FC01C
    void RemoveObject(IRenderNode* object) override;          // [13] 0x1834C50F8
    IRenderNode* GetObject(int index) override;               // [14] 0x18043D78C
    void unk_17() override;                                  // [17] 0x1834C5408
    RTTR_ENABLE(wh::I_HLod)                                  // [21..23]
    std::uintptr_t unk_24(
        std::uint32_t** cursor,
        int* remaining,
        int* offset,
        std::uintptr_t a5,
        std::uintptr_t a6,
        std::uintptr_t a7,
        bool flag) override;                                 // [24] 0x1834C1B48
    void unk_25(void* a2, void* a3, void* a4) override;      // [25] 0x1834C1728
    void unk_26(void* output) override;                       // [26] 0x1834C4EC8
    float GetNearestObserverDistance() const override;        // [27] 0x181A72EE0

    void* _vf1(std::shared_ptr<IReadStream> pStream) override; // IStreamCallback [1]
    void StreamAsyncOnComplete(std::shared_ptr<IReadStream> pStream) override; // IStreamCallback [2]
    void StreamOnComplete(std::shared_ptr<IReadStream> pStream) override; // IStreamCallback [3]

    std::uint8_t m_unknown20[4];                             // +0x20 unreflected
    int m_dataOffset;                                        // +0x24 RTTR "DataOffset"
    int m_dataSize;                                          // +0x28 RTTR "DataSize"
    int m_updateStreamingPrioriryFrame;                       // +0x2C shipped spelling
    int m_proxyIndex;                                        // +0x30 RTTR "ProxyIndex"
    std::uint8_t m_unknown34[4];                             // +0x34 unreflected
    std::vector<IRenderNode*> m_objects;                     // +0x38 RTTR "Objects"
    std::uint8_t m_unknown50[0x18];                          // +0x50 unreflected
    IRenderNode* m_proxyMesh;                                // +0x68 RTTR "ProxyMesh"
    std::uint8_t m_unknown70[0x10];                          // +0x70 unreflected
    EFileStreamingStatus m_streamingStatus;                  // +0x80 RTTR "StreamingStatus"
    std::uint8_t m_unknown81[7];                             // +0x81 unreflected
};

static_assert(offsetof(C_HLodStreaming, m_dataOffset) == 0x24,
              "C_HLodStreaming::m_dataOffset offset mismatch");
static_assert(offsetof(C_HLodStreaming, m_objects) == 0x38,
              "C_HLodStreaming::m_objects offset mismatch");
static_assert(offsetof(C_HLodStreaming, m_proxyMesh) == 0x68,
              "C_HLodStreaming::m_proxyMesh offset mismatch");
static_assert(offsetof(C_HLodStreaming, m_streamingStatus) == 0x80,
              "C_HLodStreaming::m_streamingStatus offset mismatch");
static_assert(sizeof(C_HLodStreaming) == 0x88,
              "C_HLodStreaming size mismatch");

}  // namespace wh::engine3d
