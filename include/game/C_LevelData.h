#pragma once
#include <cstddef>
#include <string>
#include <vector>
#include "../framework/C_LocalizedString.h"
#include "../rttr/rttr_enable.h"
#include "I_LevelData.h"

namespace wh::game {

class C_LevelData : public I_LevelData {
public:
    int GetLevelId() const override;                          // [0] 0x181A72970
    const CryStringT<char>& GetLevelName() const override;    // [1] 0x181A72EC0
    const CryStringT<char>& unk_02() const override;          // [2] 0x181A73320
    float GetCompassOffset() const override;                  // [3] 0x181A9A920
    CryStringT<char> GetMapName() const override;             // [4] 0x180821600
    float GetMapDefaultZoom() const override;                 // [5] 0x181A72730
    float GetMapMinZoom() const override;                     // [6] 0x181AACC40
    float GetMapMaxZoom() const override;                     // [7] 0x182137F30
    Vec2 GetMapLevelSize() const override;                    // [8] 0x182137EF0
    Vec2 GetMapWorldOrigin() const override;                  // [9] 0x182137FD0
    Vec2 GetMapWorldSize() const override;                    // [10] 0x182137FE0
    Vec2 GetMapDefaultPosition() const override;              // [11] 0x182137EA0
    Vec2 GetMapTilesSize() const override;                    // [12] 0x182137FC0
    Vec2 GetMapTilesCropOrigin() const override;              // [13] 0x182137F70
    Vec2 GetMapTilesCropSize() const override;                // [14] 0x182137F80
    std::vector<int> GetMapTiles() const override;            // [15] 0x182137F40
    RTTR_ENABLE(I_LevelData)                                  // [16..18]

    std::string GetMapTilesString() const;                    // 0x182137FF0
    void SetMapTilesString(std::string value);                // 0x182138020

    int m_levelId;                                            // +0x08 RTTR "LevelId"
    CryStringT<char> m_levelName;                             // +0x10 RTTR "LevelName"
    float m_compassOffset;                                    // +0x18 RTTR "CompassOffset"
    wh::framework::C_LocalizedString m_unknown20;             // +0x20, slot [2] returns m_text
    CryStringT<char> m_mapName;                               // +0x30 RTTR "MapName"
    float m_mapDefaultZoom;                                   // +0x38 RTTR "MapDefaultZoom"
    float m_mapMinZoom;                                       // +0x3C RTTR "MapMinZoom"
    float m_mapMaxZoom;                                       // +0x40 RTTR "MapMaxZoom"
    Vec2 m_mapLevelSize;                                      // +0x44 RTTR "MapLevelSize"
    Vec2 m_mapWorldOrigin;                                    // +0x4C RTTR "MapWorldOrig"
    Vec2 m_mapWorldSize;                                      // +0x54 RTTR "MapWorldSize"
    Vec2 m_mapDefaultPosition;                                // +0x5C RTTR "MapDefaultPos"
    Vec2 m_mapTilesSize;                                      // +0x64 RTTR "MapTilesSize"
    Vec2 m_mapTilesCropOrigin;                                // +0x6C RTTR "MapTilesCropOrig"
    Vec2 m_mapTilesCropSize;                                  // +0x74 RTTR "MapTilesCropSize"
    std::vector<int> m_mapTiles;                              // +0x80, RTTR accessor-backed "MapTiles"
};

static_assert(offsetof(C_LevelData, m_levelId) == 0x08,
              "C_LevelData::m_levelId offset mismatch");
static_assert(offsetof(C_LevelData, m_unknown20) == 0x20,
              "C_LevelData::m_unknown20 offset mismatch");
static_assert(offsetof(C_LevelData, m_mapName) == 0x30,
              "C_LevelData::m_mapName offset mismatch");
static_assert(offsetof(C_LevelData, m_mapLevelSize) == 0x44,
              "C_LevelData::m_mapLevelSize offset mismatch");
static_assert(offsetof(C_LevelData, m_mapTilesCropSize) == 0x74,
              "C_LevelData::m_mapTilesCropSize offset mismatch");
static_assert(offsetof(C_LevelData, m_mapTiles) == 0x80,
              "C_LevelData::m_mapTiles offset mismatch");
static_assert(sizeof(C_LevelData) == 0x98,
              "C_LevelData size mismatch");

}  // namespace wh::game
