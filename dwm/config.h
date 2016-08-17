/* See LICENSE file for copyright and license details. */

/* appearance */
// static const char font[]            = "Droid Sans Mono 9";
// static const char font[]            = "Sans 9";
static const char font[]            = "Monospace 9";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#005577";
static const char selbgcolor[]      = "#005577";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool statusmarkup      = True;      /* FOR PANGO by ME */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */

/* tagging */
static const char *tags[] = { "web", "work1", "work2", "work3", "misc", "mail" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	{ "Netbeans", NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Thunderbird",NULL,     NULL,       1 << 5,       False,       -1 },
	{ "Geary",    NULL,       NULL,       1 << 5,       False,       -1 },
	{ "Deluge",   NULL,       NULL,       1 << 3,       False,       -1 },
	{ "Frd",      NULL,       NULL,       1 << 3,       False,       -1 },
	{ "Gtg",      NULL,       NULL,       1 << 3,       False,       -1 },
	{ "Pidgin",   NULL,       NULL,       1 << 3,       True,        -1 },
	{ "Guake",    NULL,       NULL,      ~0,            True,        -1 },
	{ "Firefox",  NULL,       NULL,       1,            False,       -1 },
	{ "Chromium", NULL,       NULL,       1,            False,       -1 },
	{ "Opera",    NULL,       NULL,       1,            False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTMODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *chromiumcmd[]  = { "chromium", NULL };
static const char *thunderbirdcmd[]  = { "thunderbird", NULL };
static const char *gnomecommandercmd[]  = { "gnome-commander", NULL };
static const char *mccmd[]  = { "urxvt", "-e", "mc", NULL };
static const char *slimlockcmd[]  = { "slimlock", NULL };
/* alsa */
static const char *alsamutecmd[]  = { "amixer", "set", " Master", "toggle", NULL };
static const char *alsavolupcmd[]  = { "amixer", "set", " Master", "5%+", NULL };
static const char *alsavoldowncmd[]  = { "amixer", "set", "Master", "5%-", NULL };
/* cmus */
static const char *cmusnextcmd[] = { "cmus-remote", "--next", NULL};
static const char *cmusprevcmd[] = { "cmus-remote", "--prev", NULL};
static const char *cmusplaytogglecmd[] = { "cmus-remote", "--pause", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ 0,                            0x1008ff18,spawn,          {.v = chromiumcmd } },
	{ 0,                            0x1008ff19,spawn,          {.v = thunderbirdcmd } },
	{ 0,                            0x1008ff12,spawn,          {.v = alsamutecmd } },
	{ 0,                            0x1008ff11,spawn,          {.v = alsavoldowncmd } },
	{ 0,                            0x1008ff13,spawn,          {.v = alsavolupcmd } },
	{ 0,                            0x1008ff16,spawn,          {.v = cmusprevcmd } },
	{ 0,                            0x1008ff17,spawn,          {.v = cmusnextcmd } },
	{ 0,                            0x1008ff14,spawn,          {.v = cmusplaytogglecmd } },
	{ ALTMODKEY,                    XK_F1,     spawn,          {.v = termcmd } },
	{ ALTMODKEY,                    XK_F2,     spawn,          {.v = dmenucmd } },
	{ ALTMODKEY,                    XK_F3,     spawn,          {.v =
   mccmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          {.v = slimlockcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ ALTMODKEY,                    XK_Tab,    focusstack,     {.i = +1 } },
	{ ALTMODKEY|ShiftMask,          XK_Tab,    focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ ALTMODKEY|ControlMask,        XK_Left,   view_adjacent,  {.i = -1 } },
	{ ALTMODKEY|ControlMask,        XK_Right,  view_adjacent,  {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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
