/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "W95FA:size=12:antialias=true" };
static const char dmenufont[]       = "W95FA:size=12:antialias=true";
static const char col_gray1[]       = "#c0c0c0";
static const char col_gray2[]       = "#c0c0c0";
static const char col_gray3[]       = "#000000";
static const char col_gray4[]       = "#ffffff";
static const char col_blue[]        = "#000080";    
static const char col_green[]       = "#00ff00";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_blue,  col_green }
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",       NULL,       NULL,       0,          1,           -1 },
	{ "Firefox",    NULL,       NULL,       0,          0,           -1 },
    { "mpv",        NULL,       NULL,       0,          1,           -1 }
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask 
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]           = { "dmenu_run", NULL };
static const char *termcmd[]            = { "st", NULL };
static const char *web_browser[]        = { "firefox", NULL };
static const char *vifm[]               = { "st", "-e", "vifm" };
static const char *htop[]               = { "st", "-e", "htop" };
static const char *screen_shooter[]     = { "xfce4-screenshooter", NULL };
static const char *vol_down[]           = { "pamixer", "-d", "2", NULL};
static const char *vol_up[]             = { "pamixer", "-i", "2", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_r,               spawn,              {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,          spawn,              {.v = termcmd } },
	{ MODKEY,           			XK_i,	            spawn,	            {.v = web_browser } },
    { MODKEY,                       XK_f,               spawn,              {.v = vifm } },
    { MODKEY,                       XK_p,               spawn,              {.v = htop} },
	{ MODKEY,			            XK_s,               spawn,	            {.v = screen_shooter } },
	{ MODKEY,			            XK_period,          spawn,	            {.v = vol_up} },
	{ MODKEY,			            XK_comma,           spawn,	            {.v = vol_down } },
	{ MODKEY,                       XK_b,               togglebar,          {0} },
	{ MODKEY,                       XK_Right,           focusstack,         {.i = +1 } },
	{ MODKEY,                       XK_Left,            focusstack,         {.i = -1 } },
	{ MODKEY,                       XK_j,               incnmaster,         {.i = +1 } },
	{ MODKEY,                       XK_k,               incnmaster,         {.i = -1 } },

    /// Window resizing shortcuts
    { MODKEY|ControlMask,           XK_h,               moveresize,         {.v = "0x 0y -40w 0h"} },
    { MODKEY|ControlMask,           XK_j,               moveresize,         {.v = "0x 0y 0w 40h"} },
    { MODKEY|ControlMask,           XK_k,               moveresize,         {.v = "0x 0y 0w -40h"} },
    { MODKEY|ControlMask,           XK_l,               moveresize,         {.v = "0x 0y 40w 0h"} },

    /// Window moving shortcuts
    { MODKEY|ShiftMask,             XK_h,               moveresize,         {.v = "-40x 0y 0w 0h"} },
    { MODKEY|ShiftMask,             XK_j,               moveresize,         {.v = "0x 40y 0w 0h"} },
    { MODKEY|ShiftMask,             XK_k,               moveresize,         {.v = "0x -40y 0w 0h"} },
    { MODKEY|ShiftMask,             XK_l,               moveresize,         {.v = "40x 0y 0w 0h"} },

	{ MODKEY,                       XK_h,               setmfact,           {.f = -0.05} },
	{ MODKEY,                       XK_l,               setmfact,           {.f = +0.05} },
	{ MODKEY,                       XK_Return,          zoom,               {0} },
	{ MODKEY,                       XK_Tab,             view,               {0} },
	{ MODKEY|ShiftMask,             XK_c,               killclient,         {0} },
	{ MODKEY,                       XK_t,               setlayout,          {.v = &layouts[0]} },
	{ MODKEY,                       XK_y,               setlayout,          {.v = &layouts[1]} },
	{ MODKEY,                       XK_u,               setlayout,          {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,               togglefloating,     {0} },
	{ MODKEY,                       XK_0,               view,               {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,               tag,                {.ui = ~0 } },
	{ MODKEY,                       XK_bracketright,    focusmon,           {.i = -1 } },
	{ MODKEY,                       XK_bracketleft,     focusmon,           {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,           tagmon,             {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,          tagmon,             {.i = +1 } },
	TAGKEYS(                        XK_1,                                   0)
	TAGKEYS(                        XK_2,                                   1)
	TAGKEYS(                        XK_3,                                   2)
	TAGKEYS(                        XK_4,                                   3)
	TAGKEYS(                        XK_5,                                   4)
	TAGKEYS(                        XK_6,                                   5)
	TAGKEYS(                        XK_7,                                   6)
	TAGKEYS(                        XK_8,                                   7)
	TAGKEYS(                        XK_9,                                   8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
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
