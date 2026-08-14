#pragma once
#include <cstdint>

using NetworkAspectType = std::uint32_t;

#ifndef KCD_EENTITYASPECTS_DEFINED
#define KCD_EENTITYASPECTS_DEFINED

enum EEntityAspects : NetworkAspectType {
    eEA_All = 0xFFFFFFFFu,
    eEA_Script = 0x00000002u,
    eEA_Physics = 0x00000008u,
    eEA_GameClientStatic = 0x00000010u,
    eEA_GameServerStatic = 0x00000020u,
    eEA_GameClientDynamic = 0x00000040u,
    eEA_GameServerDynamic = 0x00000080u,
    eEA_GameClientA = 0x00000100u,
    eEA_GameServerA = 0x00000200u,
    eEA_GameClientB = 0x00000400u,
    eEA_GameServerB = 0x00000800u,
    eEA_GameClientC = 0x00001000u,
    eEA_GameServerC = 0x00002000u,
    eEA_GameClientD = 0x00004000u,
    eEA_GameClientE = 0x00008000u,
    eEA_GameClientF = 0x00010000u,
    eEA_GameClientG = 0x00020000u,
    eEA_GameClientH = 0x00040000u,
    eEA_GameClientI = 0x00080000u,
    eEA_GameClientJ = 0x00100000u,
    eEA_GameServerD = 0x00200000u,
    eEA_GameClientK = 0x00400000u,
    eEA_GameClientL = 0x00800000u,
    eEA_GameClientM = 0x01000000u,
    eEA_GameClientN = 0x02000000u,
    eEA_GameClientO = 0x04000000u,
    eEA_GameClientP = 0x08000000u,
    eEA_GameServerE = 0x10000000u,
    eEA_Aspect29 = 0x20000000u,
    eEA_Aspect30 = 0x40000000u,
    eEA_Aspect31 = 0x80000000u,
};

#endif
