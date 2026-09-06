#pragma once

// -----------------------------------------------
// EAudioObjectObstructionCalcType (KCD2 WHGame.dll 1.5.6)
// -----------------------------------------------
// Enum-name string 0x184096C98; members eAOOCT_Ignore 0x1840B8138 /
// eAOOCT_SingleRay 0x1840B8148 / eAOOCT_MultiRay 0x1840B8128.
// Parser sub_182AADDA8 maps Ignore=1, SingleRay=2, MultiRay=3, else 0.
enum EAudioObjectObstructionCalcType {
    eAOOCT_None      = 0,   // parser fallback
    eAOOCT_Ignore    = 1,
    eAOOCT_SingleRay = 2,
    eAOOCT_MultiRay  = 3,
};
