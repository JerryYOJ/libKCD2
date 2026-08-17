// Navigation overlay — loaded into ApseMap at _root.map.navOverlay.
stop();

var self = this;
self.pathA = [];
self._hover = false;
self._dots = [];
self._anim = [];
self._show = true;

function clearDots()
{
   var i = 0;
   while (i < self._dots.length)
   {
      if (self._dots[i])
         self._dots[i].removeMovieClip();
      i = i + 1;
   }
   self._dots = [];
   self._anim = [];
}

// Full reset (invoked from C++): also drops pathA so onEnterFrame won't redraw.
function ClearPath()
{
   clearDots();
   self.pathA = [];
}

function makeDot(big, name, depth)
{
   var d = self.createEmptyMovieClip(name, depth);
   d.isBig = big;
   var inside = d.createEmptyMovieClip("inside", 1);
   inside._alpha = 0;
   inside._xscale = big ? 58.53729248046875 : 62.5;
   inside._yscale = big ? 58.50067138671875 : 62.5;
   var w = big ? 41 : 16;
   var h = big ? 40 : 16;
   var img = inside.createEmptyMovieClip("img", 1);
   img._x = -w * 0.5;
   img._y = big ? -20.5 : -h * 0.5;
   var loader = new MovieClipLoader();
   var listener = {};
   listener.onLoadInit = function(mc)
   {
      mc._width = w;
      mc._height = h;
      var color = new Color(mc);
      color.setRGB(0xFFE731);
   };
   loader.addListener(listener);
   loader.loadClip(big ? "img://Libs/UI/Textures/Maps/fast_travel_dot_big.dds" : "img://Libs/UI/Textures/Maps/fast_travel_dot_small.dds", img);
   return d;
}

function updateDots()
{
   if (self._anim.length < 1)
      return;
   var n = self._dots.length != self._anim.length ? Math.round(Math.sqrt(self._anim.length)) : 1;
   var i = 0;
   while (i < n)
   {
      var d = self._anim.pop();
      if (d && d.inside != undefined)
      {
         if (self._show)
            d.inside.tweenTo(0.6, {_alpha:100, _xscale:100, _yscale:100}, Easing.linear);
         else
            d.inside.tweenTo(0.6, {_alpha:0, _xscale:!d.isBig ? 62.5 : 58.5, _yscale:!d.isBig ? 62.5 : 58.5}, Easing.linear);
      }
      i = i + 1;
   }
}

function mapReady()
{
   if (_root.g_GlobalMap == undefined || _root.g_GlobalMap.Data == undefined)
      return false;
   var d = _root.g_GlobalMap.Data;
   if (d.WorldCrop == undefined || d.WorldCrop.width == undefined || d.WorldCrop.width == 0)
      return false;
   if (_root.g_Scale == undefined || _root.g_Scale <= 0)
      return false;
   return true;
}

// Redraw from pathA (kept for zoom-change redraws) — only removes the dots.
function SetPath()
{
   clearDots();
   var data = self.pathA;
   if (data == undefined || data.length < 4)
      return;
   if (!mapReady())
      return;

   var pts = [];
   var i = 0;
   while (i + 1 < data.length)
   {
      pts.push(MEnum.GetMapFromWorldCoord(new flash.geom.Point(data[i], data[i + 1]), _root.g_GlobalMap.Data));
      i += 2;
   }
   pts.reverse();

   var scale = _root.g_Scale;
   var spacing = 64 * (1 / scale);
   var along = 0;
   var n = 0;
   var seg = 0;
   while (seg < pts.length - 1)
   {
      var dx = pts[seg + 1].x - pts[seg].x;
      var dy = pts[seg + 1].y - pts[seg].y;
      var len = Math.sqrt(dx * dx + dy * dy);
      if (len > 0)
      {
         dx /= len;
         dy /= len;
         while (len >= along)
         {
            var d = makeDot(n % 4 == 0, "dot" + n, n + 1);
            d._x = pts[seg].x + dx * along;
            d._y = pts[seg].y + dy * along;
            d._xscale = 100 * (1 / scale);
            d._yscale = 100 * (1 / scale);
            self._dots.push(d);
            self._anim.push(d);
            n = n + 1;
            along += spacing;
         }
         along -= len;
      }
      seg = seg + 1;
   }
   self._show = true;
   self._anim.reverse();
   self._drawnScale = scale;
}

function checkpointClip()
{
   if (_root.map == undefined || _root.map.playerAndCheckpoint == undefined)
      return undefined;
   return _root.map.playerAndCheckpoint.checkpoint;
}

function applyHover(cp, on)
{
   var target = cp.icon != undefined ? cp.icon : cp;
   var c = new Color(target);
   if (on)
      c.setTransform({ra:"100", rb:"25", ga:"100", gb:"25", ba:"100", bb:"25"});
   else
      c.setTransform({ra:"100", rb:"0", ga:"100", gb:"0", ba:"100", bb:"0"});
}

function setHover(on)
{
   var cp = checkpointClip();
   if (on == self._hover)
      return;
   self._hover = on;
   if (cp)
      applyHover(cp, on);
   flash.external.ExternalInterface.call("onNavCheckpointHighlight", on ? 1 : 0);
}

var FLAG_HIT_WIDTH = 56;

function ensureHit(cp)
{
   if (cp.navHit != undefined)
      cp.navHit.removeMovieClip();
   if (cp.active != undefined)
      cp.active.removeMovieClip();
   var side = cp.icon != undefined && cp.icon._height > 0 ? cp.icon._height : 64;
   var h = side;
   var hw = FLAG_HIT_WIDTH * 0.5;
   var a = cp.createEmptyMovieClip("navHit", 50);
   a._x = 0;
   a._y = 0;
   a.beginFill(0xFFFFFF, 0);
   a.moveTo(-hw, 0);
   a.lineTo(hw, 0);
   a.lineTo(hw, -h);
   a.lineTo(-hw, -h);
   a.lineTo(-hw, 0);
   a.endFill();
   return a;
}

function bindCheckpoint(cp)
{
   if (self._boundCp == cp)
      return;
   self._boundCp = cp;
   var a = ensureHit(cp);
   a.parent = {OnRollOver:function()
   {
      setHover(true);
   }, OnRollOut:function()
   {
      setHover(false);
   }};
   a.onRollOver = function()
   {
      if (_root.g_InputId == ControlsEnum.E_INPUT_KEYBOARD)
         this.parent.OnRollOver();
   };
   a.onRollOut = function()
   {
      if (_root.g_InputId == ControlsEnum.E_INPUT_KEYBOARD)
         this.parent.OnRollOut();
   };
   a.onReleaseOutsideAux = a.onRollOut;
   a.onDragOut = a.onRollOut;
   a.onDragOver = a.onRollOver;
}

function padCursorOver(cp)
{
   if (cp.navHit == undefined || !cp._visible)
      return false;
   var sx = _root.GetCursorX();
   var sy = _root.GetCursorY();
   var mapPt = MEnum.GetMapFromScreenCoord(new flash.geom.Point(sx, sy), _root.g_Position, _root.g_Scale);
   var w = cp.navHit._width * cp._xscale * 0.01;
   var h = cp.navHit._height * cp._yscale * 0.01;
   var rect = new flash.geom.Rectangle(cp._x - w * 0.5, cp._y - h, w, h);
   return rect.containsPoint(mapPt);
}

self.onEnterFrame = function()
{
   if (self.pathA != undefined && self.pathA.length >= 4 && mapReady())
   {
      if (self._dots.length == 0 || self._drawnScale != _root.g_Scale)
         SetPath();
   }
   updateDots();
   var cp = checkpointClip();
   if (cp == undefined)
   {
      self._boundCp = undefined;
      setHover(false);
      return;
   }
   bindCheckpoint(cp);
   if (_root.g_Cursor != undefined && _root.g_Cursor.IsActive && !(_root.g_Loading != undefined && _root.g_Loading.FaderVisible))
      setHover(padCursorOver(cp));
};
