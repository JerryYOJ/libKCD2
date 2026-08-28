#pragma once
#include <cstddef>
#include <vector>
#include "I_MusicManager.h"

namespace wh::musicmodule {

class C_MusicMatrix;
class C_MusicProbe;

class C_MusicManager : public I_MusicManager {
public:
    void Initialize() override;                                // [0] 0x180D7671C
    void Update(float frameTime) override;                     // [1] 0x180533E94
    void unk_02() override;                                    // [2] 0x1803B6E80
    void unk_03() override;                                    // [3] 0x180D743A4
    void unk_04() override;                                    // [4] 0x180D74340
    void unk_05() override;                                    // [5] 0x180D741E0
    void unk_06() override;                                    // [6] 0x180D74B74
    void unk_07() override;                                    // [7] 0x182F2368C; shuts down and deletes probes
    void unk_08() override;                                    // [8] 0x182F23658
    ~C_MusicManager() override;                                // [9] 0x182F2308C
    RTTR_ENABLE(I_MusicManager)                                // [10..12]

    C_MusicMatrix* m_musicMatrix;                              // +0x08 RTTR "MusicMatrix" (read-only)
    std::vector<C_MusicProbe*> m_probes;                       // +0x10 owned probe pointers
    double m_elapsedTime;                                      // +0x28 deferred-toggle clock
};

static_assert(offsetof(C_MusicManager, m_musicMatrix) == 0x08,
              "C_MusicManager::m_musicMatrix offset mismatch");
static_assert(offsetof(C_MusicManager, m_probes) == 0x10,
              "C_MusicManager::m_probes offset mismatch");
static_assert(offsetof(C_MusicManager, m_elapsedTime) == 0x28,
              "C_MusicManager::m_elapsedTime offset mismatch");
static_assert(sizeof(C_MusicManager) == 0x30,
              "C_MusicManager size mismatch");

}  // namespace wh::musicmodule
