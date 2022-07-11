/* See LICENSE file for copyright and license details. */

#define DEBUG_VAL 0
#define EMOJI_SUPPORT 0
#define SESSION_FILE "/tmp/dwm-session"

/* alt-tab configuration */
static const unsigned int tabModKey 		= 0x40;	/* if this key is hold the alt-tab functionality stays acitve. This key must be the same as key that is used to active functin altTabStart `*/
static const unsigned int tabCycleKey 		= 0x17;	/* if this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active functin altTabStart */
static const unsigned int tabPosY 			= 1;	/* tab position on Y axis, 0 = bottom, 1 = center, 2 = top */
static const unsigned int tabPosX 			= 1;	/* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab 			= 600;	/* tab menu width */
static const unsigned int maxHTab 			= 200;	/* tab menu height */

/* appearance */
static const unsigned int borderpx 			= 2;	/* border pixel of windows */
static const unsigned int gappx 			= 4;	/* gaps between windows */
static const unsigned int snap 				= 32;	/* snap pixel */
static const unsigned int systraypinning 	= 0;	/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft 	= 1;	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing 	= 2;	/* systray spacing */
static const int systraypinningfailfirst 	= 1;	/* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray 				= 1;	/* 0 means no systray */
static const int showbar 					= 1;	/* 0 means no bar */
static const int topbar 					= 1;	/* 0 means bottom bar */

// static const char *fonts[]          = { "monospace:size=10", "JoyPixels:pixelsize=10:antialias=true:autohint=true"
static const char *fonts[] 		= {"sans:size=10", "JoyPixels:pixelsize=10:antialias=true:autohint=true", "hack", "IcoMoon-Free:pixelsize=10:antialias=true:autohint=true"};
static const char dmenufont[] 	= "monospace:size=10";

/* 
 * default color scheme
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
*/

static const char col_gray1[]       = "#000000"; // black
static const char col_gray2[]       = "#434758"; // bright black
static const char col_gray3[]       = "#D0D0D0"; // white
static const char col_gray4[]       = "#FFFFFF"; // bright white
static const char col_cyan[]        = "#FF8C00"; // orange
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeHid]  = { col_cyan,  col_gray1, col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "7", "8", "9"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       2,            1,           -1 },
	{ "code",     NULL,       NULL,       3,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include <X11/XF86keysym.h> /* inlcude fn keys */
#include "patches/layouts.c"
#include "patches/bstack.c"
#include "patches/maximize.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
 	/* first entry is default */
	{ "><",       NULL },    /* no layout function means floating behavior */
	{ "[]",       tile },
	{ "MM",       monocle },
	{ "HH",       grid },
	{ "TT",       bstack },
	{ NULL,       NULL },	/* End of layouts */
};

/* key definitions */
#define MODKEY Mod4Mask
#define MODKEY1 Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]         = { "dmenu_run", NULL };
static const char *termcmd[]          = { "st", NULL };

static Key keys[] = {
	// START_KEYS
	/* modifier                     key        function        argument */

	// GROUP spawn
	{ MODKEY,                       XK_r,      spawn,			{.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,			{.v = termcmd } },
	{ 0,                            XK_Print,  spawn,			SHCMD("mate-screenshot") },
	{ ShiftMask,                    XK_Print,  spawn,			SHCMD("flameshot gui") },
	{ Mod1Mask|ControlMask,         XK_l,      spawn,			SHCMD("slock") },
	// GROUP wm_basic
	{ MODKEY,                       XK_b,      togglebar,		{0} },
	{ MODKEY,                       XK_j,      focusstackvis,	{.i = +1 } },
	{ MODKEY,                       XK_k,      focusstackvis,	{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,	{.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,		{.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,		{.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,		{.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,		{.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,			{0} },
	{ Mod1Mask,                     XK_q,      view,			{0} },
	{ MODKEY,                       XK_q,      view,			{0} },
	{ Mod1Mask,             		XK_Tab,    altTabStart,	   	{0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,		{0} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,		{.v = &layouts[0]} },
	{ MODKEY,                       XK_t,      setlayout,		{.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,		{.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,		{.v = &layouts[3]} },
	{ MODKEY,		                XK_space,  cyclelayout,		{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  cyclelayout,		{.i = -1 } },
	{ MODKEY|ControlMask,           XK_f,      togglefloating,	{0} },
	{ MODKEY,                       XK_f,      togglefullscr,	{0} },
	{ MODKEY,                       XK_0,      view,			{.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,				{.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,		{.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,		{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,			{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,			{.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,			{.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,			{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,			{.i = 0  } },
	{ MODKEY|ControlMask,           XK_n,      unhide,			{0} },
	{ MODKEY,             			XK_n,      hide,			{0} },
	{ MODKEY,                       XK_m,      togglemaximize,	{0} },
	// GROUP call_scripts
	{ ControlMask|ShiftMask,        XK_m,      spawn,			SHCMD("$HOME/.local/src/dwm/scripts/toggle-mic.sh; pkill -RTMIN+13 dwmblocks") },
	{ MODKEY|ShiftMask|ControlMask, XK_k,      spawn,			SHCMD("$HOME/.local/src/dwm/scripts/change-keyboard.sh; pkill -RTMIN+10 dwmblocks") },
	{ Mod1Mask|ControlMask,         XK_k,      spawn,			SHCMD("$HOME/.local/src/dwm/scripts/change-keyboard.sh; pkill -RTMIN+10 dwmblocks") },
	{ 0,							XF86XK_AudioMicMute,		spawn, SHCMD("$HOME/.local/src/dwm/scripts/toggle-mic.sh; pkill -RTMIN+13 dwmblocks") },
	{ 0,                            XF86XK_AudioMute,			spawn, SHCMD("pactl set-sink-mute 0 toggle; pkill -RTMIN+11 dwmblocks") },
	{ 0,                            XF86XK_AudioLowerVolume,	spawn, SHCMD("pactl set-sink-volume 0 -3%; pkill -RTMIN+11 dwmblocks") },
	{ 0,                            XF86XK_AudioRaiseVolume,	spawn, SHCMD("pactl set-sink-volume 0 +3%; pkill -RTMIN+11 dwmblocks") },
  // { 0,                            XF86XK_MonBrightnessDown,  spawn, SHCMD("xbacklight -dec 2; pkill -RTMIN+12 dwmblocks") },
  // { 0,                            XF86XK_MonBrightnessUp,    spawn, SHCMD("xbacklight -inc 2; pkill -RTMIN+12 dwmblocks") },
	{ 0,                            XF86XK_MonBrightnessDown,	spawn, SHCMD("$HOME/.local/src/dwm/scripts/brightnessDown.sh; pkill -RTMIN+12 dwmblocks") },
	{ 0,                            XF86XK_MonBrightnessUp,		spawn, SHCMD("$HOME/.local/src/dwm/scripts/brightnessUp.sh; pkill -RTMIN+12 dwmblocks") },
	// GROUP move
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {0} },
	{ MODKEY|ControlMask,           XK_r,      quit,           {1} }, 
	// END_KEYS
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
