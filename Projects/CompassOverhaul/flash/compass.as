// CompassOverhaul :: compass.gfx  (ActionScript 2 / Scaleform GFx)
// ---------------------------------------------------------------------------
// Self-driven HUD overlay, loaded by the plugin into
// _root.tc.compass.compassOverlay of the game's "hud" movie. Lives under
// tc.compass so HudMask photo-mode hide takes it with the strip. Stage is
// 1x1 px so the leftover displayRect does not inflate compass bounds.
// Labels sit in parent space via globalToLocal. Reads the native compass data directly:
//   _root.g_MarkersO  dict (Enum.MARKER+id) -> CompassMarker (m_Mc, m_Distance, ...)
//
// TUNING: edit the C_* constants below and rebuild (build_gfx.sh). Text size
// is authored in base.xml (DefineEditTextTag fontHeight, twips = px * 20).
//
// TEXT (authentic game pattern): both labels are AUTHORED DefineEditTexts bound
// to the ImportAssets2-imported "DefaultFont" from gfxfontlib.gfx -- the exact
// mechanism hud.gfx uses (sprite prototype + instance "tField"; see base.xml).
// AS only attachMovie()s them and sets .text here. CORRECTED (2026-07-13): an
// earlier version of this comment claimed runtime TextFormat.font/size/color
// changes are ignored by GFx -- that's wrong, disproven by
// analysis/CompassOverhaul/texttest.gfx: TextFormat correctly restyles both
// fresh createTextField() fields and already tag-bound fields like these,
// PROVIDED .embedFonts = true is set first (the real missing ingredient
// behind the old belief -- unset, a field silently falls back to
// non-embedded/device rendering, indistinguishable from "the restyle did
// nothing"). Left baked here anyway: this template predates the finding and
// already works, so there's no functional reason to change it.
//
// DISTANCE UNIT: @ui_compass_meters (mod loc pak). CryGFxTranslator
// LocalizeCryString-s @keys at display time on this HUD player. RU/UK paks
// ship "м", every other language "m". Marker NAMES stay C++-localized
// (not @keys — objective text + ui_maplegend_* suffix remaps).
//
// TARGETING: a marker is "aimed" when its global x is near the screen centre
// (the native code scrolls markers so the faced bearing lands at centre).
// Markers at the SAME bearing but different distances STACK at the same x, so
// the grow is applied to EVERY marker inside the aim window (fixes the desync
// where the enlarged marker was a hidden one behind the visible icon). The
// label follows the TOP-MOST in-window marker; alpha-0 (far-culled) and locked
// markers are skipped -- g_MarkersO holds ALL registered markers, not just
// visible ones.
//
// SCALING: native CompassMarker.updateMC() owns m_Mc._xscale (distance-based);
// we scale m_Mc.inside (icon+char+arrow), which native never touches, so the
// aimed marker renders at native_scale * 1.325 with no tug-of-war.
// ---------------------------------------------------------------------------

stop();

var C_AIM_FRAC  = 0.006;   // aim window half-width, fraction of screen width
var C_AIM_SCALE = 132.5;   // aimed inner-group scale (Skyrim's x1.325); 100 = native
var C_LABEL_DY  = -46;     // distance label offset above the marker, px
var C_NAME_DY   = 25;      // name label offset BELOW the marker, px

var self = this;
self.attachMovie("DistLabel", "lbl", self.getNextHighestDepth());
self.lbl._visible = false;
self.attachMovie("NameLabel", "nameLbl", self.getNextHighestDepth());
self.nameLbl._visible = false;

// Soft gray halo so white glyphs read on the strip. GlowFilter on the
// TEXT FIELD only (not the overlay / compass sprite). Tight blur — last
// time this was blur 8 / strength 3 on the whole label clip and it ate
// the compass; this is a 渐变 outline, not a drop shadow.
var halo = new flash.filters.GlowFilter(0x000000, 0.55, 4, 4, 2, 2, false, false);
self.lbl.tField.filters = [halo];
self.nameLbl.tField.filters = [halo];

// Measure each field's authored centre inside its sprite, then let autoSize
// "center" keep that centre anchored while the field hugs the text -- the
// label sprite can then be placed by centre, independent of text length or
// the field's own alignment.
var lblCx  = self.lbl.tField._x + self.lbl.tField._width / 2;
var nameCx = self.nameLbl.tField._x + self.nameLbl.tField._width / 2;
self.lbl.tField.autoSize = "center";
self.nameLbl.tField.autoSize = "center";

var namesTable     = {};
var lastNamesLen   = -1;
var typeNamesTable = {};
var lastTypesLen   = -1;

function parsePairs(arr)
{
   var o = {};
   for (var i = 0; i + 1 < arr.length; i += 2)
   {
      o[arr[i]] = arr[i + 1];
   }
   return o;
}

function isShown(mc)
{
   var o = mc;
   while (o != undefined && o != _root)
   {
      if (o._visible == false || o._alpha <= 0) return false;
      o = o._parent;
   }
   return true;
}

self.onEnterFrame = function()
{
   // Parent (tc.compass) is hidden in photo mode. GFx can still fire
   // onEnterFrame on an invisible clip.
   if (self._parent._visible == false)
   {
      self.lbl._visible = false;
      self.nameLbl._visible = false;
      return;
   }

   var na = self.co_names;
   if (na != undefined && na.length != lastNamesLen)
   {
      lastNamesLen = na.length;
      namesTable = parsePairs(na);
   }
   var ta = self.co_typeNames;
   if (ta != undefined && ta.length != lastTypesLen)
   {
      lastTypesLen = ta.length;
      typeNamesTable = parsePairs(ta);
   }

   var mo = _root.g_MarkersO;
   if (mo == undefined) { self.lbl._visible = false; self.nameLbl._visible = false; return; }

   var cx  = Stage.width / 2;
   var thr = Stage.width * C_AIM_FRAC;

   var tgtKey    = undefined;
   var bestDepth = undefined;
   var tgtPt     = undefined;

   for (var key in mo)
   {
      var m  = mo[key];
      var mc = m.m_Mc;
      if (mc == undefined || mc.inside == undefined) continue;
      // skip anything not actually on screen (own fade OR hidden ancestor)
      if (!isShown(mc)) continue;
      if (m.m_IsLocked) continue;   // locked markers: m_Distance forced to 0, spread at fixed offsets
      // CreateMC tweens inside._alpha 0->100 on the same clip; writing scale
      // every frame fights that tween and can leave the icon at alpha 0.
      if (mc.inside._alpha < 100) continue;

      var p = {x: 0, y: 0};
      mc.localToGlobal(p);
      var dx = Math.abs(p.x - cx);

      // grow EVERY marker inside the aim window (stacked markers share one x)
      var sc = (dx < thr) ? C_AIM_SCALE : 100;
      mc.inside._xscale = sc;
      mc.inside._yscale = sc;

      // label the TOP-MOST in-window marker (nearer markers get higher depths
      // via getMCDepth) -- that is the icon the player actually sees grown
      if (dx < thr)
      {
         var d = mc.getDepth();
         if (bestDepth == undefined || d > bestDepth) { bestDepth = d; tgtKey = key; tgtPt = p; }
      }
   }

   if (tgtKey == undefined) { self.lbl._visible = false; self.nameLbl._visible = false; return; }

   self.globalToLocal(tgtPt);
   self.lbl._x = tgtPt.x - lblCx;         // field centre -> icon centre
   self.lbl._y = tgtPt.y + C_LABEL_DY;
   self.lbl.tField.text = Math.round(mo[tgtKey].m_Distance) + " @ui_compass_meters";
   self.lbl._visible = true;

   var nm = namesTable[tgtKey];           // localized objective name from the plugin
   if (nm == undefined) nm = typeNamesTable[mo[tgtKey].m_Type];
   if (nm == undefined)
   {
      self.nameLbl._visible = false;
   }
   else
   {
      self.nameLbl._x = tgtPt.x - nameCx; // field centre -> icon centre
      self.nameLbl._y = tgtPt.y + C_NAME_DY;   // below the icon
      self.nameLbl.tField.text = nm;      // pre-localized by the plugin
      self.nameLbl._visible = true;
   }
};
