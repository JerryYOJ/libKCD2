#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../Offsets/vtables/IRenderer.h"
#include "../rttr/rttr_enable.h"
#include "CRendererCVars.h"
#include "CRendererResources.h"

// renderer-internal types not yet RE'd (referenced by RT_* slots only)
class CRenderView;
class CTexture;
class CParticleBufferSet;
struct SDisplayContextKey;
struct SGraphicsPipelineKey;
struct SSkinningData;
struct SRenderingPassInfo;
struct IFlashPlayer;               // global namespace (RTTI .?AUIFlashPlayer@@)
struct IFlashPlayer_RenderProxy;
enum EReadTextureFormat : int;
namespace compute_skinning { struct IComputeSkinningStorage; }

class __declspec(empty_bases) CRenderer
    : public Offsets::IRenderer,
      public CRendererResources,
      public CRendererCVars {
public:
    CRenderer();
    ~CRenderer() override;                                     // [0] 0x1824DA884
    RTTR_ENABLE(Offsets::IRenderer)                            // [334..336]
    virtual void InitRenderer();                               // [337] 0x18074A3E0
    virtual void RT_BlitLoadingSplash() = 0; // [338] pure
    virtual void RT_ClearActiveTarget() = 0; // [339] pure
    virtual void RT_PresentFast() = 0; // [340] pure
    virtual void RT_BeginFrame(const SDisplayContextKey& displayContextKey, const SGraphicsPipelineKey& graphicsPipelineKey) = 0; // [341] pure
    virtual void RT_EndFrame() = 0; // [342] pure
    virtual void RT_Init() = 0; // [343] pure
    virtual void RT_ShutDown(std::uint32_t flags) = 0; // [344] pure
    virtual bool RT_CreateDevice() = 0; // [345] pure
    virtual void unk_346() = 0;                                // [346] pure
    virtual void RT_RenderScene(CRenderView* renderView) = 0; // [347] pure
    virtual void RT_ReleaseRenderResources(std::uint32_t flags) = 0; // [348] pure
    virtual void RT_CreateRenderResources() = 0; // [349] pure
    virtual void RT_CreateBaseGraphicsPipeline() = 0; // [350] pure
    virtual void RT_PrecacheDefaultShaders() = 0; // [351] pure
    virtual bool RT_ReadTexture(void* destination, int destinationWidth, int destinationHeight, EReadTextureFormat format, CTexture* source, bool centerCrop) = 0; // [352] pure
    virtual bool RT_StoreTextureToFile(const char* filePath, CTexture* source, bool copyToClipboard) = 0; // [353] pure
    virtual bool RT_StoreHDRTextureToFile(const char* filePath, CTexture* source) = 0; // [354] pure
    virtual void RT_RenderDebug() = 0; // [355] pure
    virtual void unk_356() = 0;                                // [356] pure
    virtual void RT_FlashRenderProxyInternal(std::shared_ptr<IFlashPlayer_RenderProxy>&& player, bool doRealRender) = 0; // [357] pure
    virtual void RT_FlashRenderPlayerInternal(std::shared_ptr<IFlashPlayer>&& player) = 0; // [358] pure
    virtual void RT_FlashRenderPlaybackLocklessInternal(std::shared_ptr<IFlashPlayer_RenderProxy>&& player, int commandBufferIndex, bool finalPlayback, bool doRealRender) = 0; // [359] pure
    virtual bool ForceFlushRTCommands(); // [360] 0x1819DE1E0
    virtual void WaitForParticleBuffer(int frameId) = 0; // [361] pure
    virtual void unk_362() = 0;                                // [362] pure
    virtual void unk_363() = 0;                                // [363] pure
    virtual int GetWireframeMode(); // [364] 0x181A74DC0
    virtual void GetLogVBuffers() = 0; // [365] pure
    virtual void FlushPendingShaderTasks() = 0; // [366] pure
    virtual void* FX_AllocateCharInstCB(SSkinningData* skinningData, std::uint32_t frameId); // [367] 0x18066CD10
    virtual void FX_ClearCharInstCB(std::uint32_t frameId); // [368] 0x1803B6E80
    virtual void ClearPerFrameData(const SRenderingPassInfo& passInfo); // [369] 0x1803B6E80
    virtual void unk_370();                                    // [370] 0x18066CD10
    virtual void unk_371();                                    // [371] 0x18066CD10
    virtual void SetCurDownscaleFactor(Vec2 factor) = 0; // [372] pure
    virtual void unk_373();                                    // [373] 0x1803B6E80
    virtual compute_skinning::IComputeSkinningStorage* GetComputeSkinningStorage() = 0; // [374] pure
    virtual CParticleBufferSet& GetParticleBufferSet() = 0; // [375] pure

    std::uint8_t m_runtimeState[0x2F80 - 0x08];                 // +0x08
};

static_assert(sizeof(Offsets::IRenderer) == 0x08,
              "IRenderer size mismatch");
static_assert(offsetof(CRenderer, m_runtimeState) == 0x08,
              "CRenderer runtime-state offset mismatch");
static_assert(sizeof(CRenderer) == 0x2F80,
              "CRenderer size mismatch");
