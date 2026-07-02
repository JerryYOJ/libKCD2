#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::E_DerivedStat -- KCD2 WHGame.dll 1.5.6 (kd7u).  4-byte enum, 103 registered values.
// -----------------------------------------------
// THE enum Soul:GetDerivedStat("code") resolves. Recovered from the C_RPGUtils converters:
// name->id vtable+0x70 = sub_180BE2B8C (table builder sub_1801C2E30 @0x185331B70), id->name
// sub_182CCC474. VERIFIED both directions for ids 0..102. The Lua handler (sub_180BE3834 via
// thunk sub_180BE3D54) rejects id >= 0xDA (218): 218 is the DECLARED range / miss sentinel,
// but ids 103..217 are unregistered ("<unknown enum value>").
//
// The enumerators are the raw 3-letter derived_stat.xml row codes; their human meanings were NOT
// decoded from the binary (needs rpg/derived_stat.xml). hlh(10)/slh(11)/sls(12) are the
// health/stamina-family candidates (UNVERIFIED). Derived stats are NOT stored on the soul --
// computed on demand by sub_180648B18 from base stats + config.
//
// NOTE: a genuinely DIFFERENT 218-slot enum (codes "charisma", "rch", "cse", ..., ids 0..109 +
// 213..217; name->id builder sub_1801C39F0 @0x185330DD0, id->name sub_181121EE8) is wired to
// C_RPGUtils vtable+0x78 (sub_182CF4574, same 0xDA reject). It is NOT what GetDerivedStat's
// string argument maps to; its binary enum name is unresolved, so it is documented here but
// deliberately not fabricated as a typed enum.
//
// The readable Health/Stamina METERS are a separate 6-value condition enum -- see E_SoulCondition.h.

namespace wh::rpgmodule {

enum class E_DerivedStat : uint32_t {
    ade = 0,    uat = 1,    wat = 2,    wac = 3,    ahm = 4,
    rtm = 5,    act = 6,    asp = 7,    pbs = 8,    cli = 9,
    hlh = 10,   slh = 11,   sls = 12,   dig = 13,   exh = 14,
    hod = 15,   psp = 16,   lcs = 17,   srg = 18,   sco = 19,
    srb = 20,   sra = 21,   ard = 22,   skp = 23,   rst = 24,
    pdp = 25,   eep = 26,   lpd = 27,   lpn = 28,   ain = 29,
    hin = 30,   fae = 31,   dee = 32,   dew = 33,   osb = 34,
    dsl = 35,   cos = 36,   pac = 37,   lpb = 38,   res = 39,
    ors = 40,   ptp = 41,   shr = 42,   ser = 43,   pim = 44,
    ald = 45,   aam = 46,   uab = 47,   fhm = 48,   fne = 49,
    dth = 50,   dtd = 51,   tdh = 52,   adc = 53,   sla = 54,
    sta = 55,   ssa = 56,   wsr = 57,   war = 58,   wrs = 59,
    wra = 60,   efc = 61,   dsc = 62,   wde = 63,   ewd = 64,
    scv = 65,   scx = 66,   skv = 67,   cat = 68,   acm = 69,
    rat = 70,   rls = 71,   ptw = 72,   ala = 73,   apq = 74,
    bid = 75,   fob = 76,   ode = 77,   dmd = 78,   dmh = 79,
    drn = 80,   bqc = 81,   bqy = 82,   ifc = 83,   pwc = 84,
    paa = 85,   itd = 86,   rkm = 87,   rhm = 88,   phv = 89,
    bnv = 90,   pnv = 91,   fnv = 92,   aps = 93,   fbm = 94,
    tdm = 95,   cps = 96,   spv = 97,   pct = 98,   nhp = 99,
    nrb = 100,  btd = 101,  opd = 102,

    RegisteredCount = 103,   // last registered id + 1 (SYNTHETIC enumerator)
    DeclaredRange   = 218,   // handler reject threshold / name->id miss sentinel (0xDA)
};

}  // namespace wh::rpgmodule
