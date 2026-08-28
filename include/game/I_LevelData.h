#pragma once
#include <vector>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::game {

class I_LevelData {
public:
    virtual int GetLevelId() const = 0;                       // [0]
    virtual const CryStringT<char>& GetLevelName() const = 0; // [1]
    virtual const CryStringT<char>& unk_02() const = 0;       // [2]
    virtual float GetCompassOffset() const = 0;               // [3]
    virtual CryStringT<char> GetMapName() const = 0;          // [4]
    virtual float GetMapDefaultZoom() const = 0;              // [5]
    virtual float GetMapMinZoom() const = 0;                  // [6]
    virtual float GetMapMaxZoom() const = 0;                  // [7]
    virtual Vec2 GetMapLevelSize() const = 0;                 // [8]
    virtual Vec2 GetMapWorldOrigin() const = 0;               // [9]
    virtual Vec2 GetMapWorldSize() const = 0;                 // [10]
    virtual Vec2 GetMapDefaultPosition() const = 0;           // [11]
    virtual Vec2 GetMapTilesSize() const = 0;                 // [12]
    virtual Vec2 GetMapTilesCropOrigin() const = 0;           // [13]
    virtual Vec2 GetMapTilesCropSize() const = 0;             // [14]
    virtual std::vector<int> GetMapTiles() const = 0;         // [15]
};

static_assert(sizeof(I_LevelData) == 0x08,
              "I_LevelData size mismatch");

}  // namespace wh::game
