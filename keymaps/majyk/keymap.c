/*

                                        █         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
                                        █        █     █          ▄▀            ▀▄      █          █
                                        █       █      █        ▄▀                ▀▄    █          █
                                        █      █       █        █                  █    █          █
                                        █     █        █       █                    █   █          █
                                        █    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
                                        █   █ █        █       █                    █   █      █
                                        █  █   █       █        █                  █    █       █
                                        █ █     █      █        ▀▄                ▄▀    █        █
                                        ██       █     █          ▀▄            ▄▀      █         █
                                        █         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █

                                        ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
                                        M A J Y K

*/
#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "sendstring_french.h"
#include <stdio.h>
#include <string.h>
#include "klor.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                 │
// └───────────────────────────────────────────────────────────┘ 

enum klor_layers {
	Default = 0,
	NumArr,
	Unic,
	Fun,
	Media,
	Mouse,
	Gaming
};


// ┌───────────────────────────────────────────────────────────┐
// │ u n i c o d e                                             │
// └───────────────────────────────────────────────────────────┘

enum unicode_names {
	AGrL,
	AGrU,
	AE_L,
	AE_U,
	OE_L,
	OE_U,
	CCedL,
	CCedU,
	E_AigL,
	E_AigU,
	E_GrL,
	U_Gr,
	Micro,
	Inf,
	Sup,
	Slash,
	BkSla,
	Pipe,
	Excl,
	At,
	BakQut,
	InvQuest,
	InvExcl,
	Dollar,
	Percent,
	Copyright,
	Registrd,
	ArrowR
};

const uint32_t unicode_map[] PROGMEM = {
	[AGrL]		= 0x00E0, // à
	[AGrU]		= 0x00C0, // À
	[AE_L]		= 0x00E6, // æ
	[AE_U]		= 0x00C6, // Æ
	[OE_L]		= 0x0153, // œ
	[OE_U]		= 0x0152, // Œ
	[CCedL]		= 0x00E7, // ç
	[CCedU]		= 0x00C7, // Ç
	[E_AigL]	= 0x00E9, // é
	[E_AigU]	= 0x00C9, // É
	[E_GrL]		= 0x00E8, // è
	[U_Gr]		= 0x00F9, // ù
	[Micro]		= 0x00B5, // µ
	[Inf]		= 0x003C, // <
	[Sup]		= 0x003E, // >
	[Slash]		= 0x002F, // /
	[BkSla]		= 0x005C, // 
	[Pipe]		= 0x007C, // |
	[Excl]		= 0x0021, // !
	[At]		= 0x0040, // @
	[InvQuest]	= 0x00BF, // ¡
	[InvExcl]	= 0x00A1, // ¿
	[Dollar]	= 0x0024, // $
	[Percent]	= 0x0025, // %
	[Registrd]	= 0x00AE, // ®
	[ArrowR]	= 0x2192, // →
	[BakQut]	= 0x0060, // `
};


// ┌───────────────────────────────────────────────────────────┐
// │ c o m b o s                                               │
// └───────────────────────────────────────────────────────────┘ 

const uint16_t PROGMEM combo1[] = {FR_Q, FR_W, COMBO_END};
const uint16_t PROGMEM combo2[] = {FR_M, XP(Excl,BkSla), COMBO_END};
const uint16_t PROGMEM combo3[] = {FR_A, FR_E, COMBO_END};
const uint16_t PROGMEM combo4[] = {FR_O, FR_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	COMBO(combo1, FR_A),
	COMBO(combo2, FR_P),
	COMBO(combo3, XP(AE_L,AE_U)),
	COMBO(combo4, XP(OE_L,OE_U)),
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ Default                                                   │
   └───────────────────────────────────────────────────────────┘
               ╭───────────┬───────────┬───────────┬───────────┬───────────╮                    ╭───────────┬───────────┬───────────┬───────────┬───────────╮
               │     A     │     Z     │     E     │     R     │     T     │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │     Y     │     U     │     I     │     O     │     P     │
   ╭───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────╮
   │    ESC    │     Q     │     S     │     D     │     F     │     G     ├─╯                ╰─┤     H     │     J     │     K     │     L     │     M     │     ^     │
   ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤╭────────╮╭────────╮├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   │   CTRL    │     W     │     X     │     C     │     V     │     B     ││  MUTE  ││PLY/PSE ││     N     │     ,     │     ;     │     :     │     !     │    DEL    │
   ╰───────────┴───────────┴───────────┼───────────┼───────────┼───────────┼╰────────╯╰────────╯┼───────────┼───────────┼───────────┼───────────┴───────────┴───────────╯
                                       │    GUI    │    TAB    │   ENTER   │   ALT   ││   CTRL  │   SPACE   │   SHIFT   │   MENU    │
                                       ╰───────────┴───────────┴───────────┴─────────╯╰─────────┴───────────┴───────────┴───────────╯ */

   [Default] = LAYOUT_polydactyl(
							FR_A,				FR_Z,				FR_E,				FR_R,				FR_T,											FR_Y,				FR_U,				FR_I,				FR_O,				FR_P,
		LT(Mouse,KC_ESC),	FR_Q,				FR_S,				FR_D,				FR_F,				FR_G,											FR_H,				FR_J,				FR_K,				FR_L,				FR_M,				LT(Media,FR_CIRC),
		KC_LCTL,			FR_W,				FR_X,				FR_C,				FR_V,				FR_B,			KC_MUTE,		KC_MPLY,		FR_N,				FR_COMM,			FR_SCLN,			FR_COLN,			XP(Excl,BkSla),		KC_DEL,
														KC_LGUI,			LT(Unic,KC_TAB),	LT(Fun,KC_ENT),		KC_LALT,						LCTL_T(KC_ESC),		LT(NumArr,KC_SPC),	LSFT_T(KC_BSPC),	KC_APP),

/*
   ┌───────────────────────────────────────────────────────────┐
   │ NumArr                                                    │
   └───────────────────────────────────────────────────────────┘
               ╭───────────┬───────────┬───────────┬───────────┬───────────╮                    ╭───────────┬───────────┬───────────┬───────────┬───────────╮
               │     6     │     7     │     8     │     9     │     0     │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │   PGUP    │     '     │    UP     │     "     │   HOME    │
   ╭───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────╮
   │     =     │     1     │     2     │     3     │     4     │     5     ├─╯                ╰─┤   PGDN    │   LEFT    │   DOWN    │   RIGHT   │    END    │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤╭────────╮╭────────╮├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   │           │     %     │     /     │     *     │     -     │     +     ││        ││        ││     (     │     )     │     [     │     ]     │     <     │     >     │
   ╰───────────┴───────────┴───────────┼───────────┼───────────┼───────────┼╰────────╯╰────────╯┼───────────┼───────────┼───────────┼───────────┴───────────┴───────────╯
                                       │           │           │           │         ││         │           │           │           │
                                       ╰───────────┴───────────┴───────────┴─────────╯╰─────────┴───────────┴───────────┴───────────╯ */

	[NumArr] = LAYOUT_polydactyl(
							FR_6,				FR_7,				FR_8,				FR_9,				FR_0,											KC_PGUP,			FR_QUOT,			KC_UP,				FR_DQUO,			KC_HOME,
		FR_EQL,				FR_1,				FR_2,				FR_3,				FR_4,				FR_5,											KC_PGDN,			KC_LEFT,			KC_DOWN,			KC_RGHT,			KC_END,				KC_NO,
		KC_TRNS,			X(Percent),			KC_PSLS,			KC_PAST,			KC_PMNS,			KC_PPLS,		KC_TRNS,		KC_TRNS,		FR_LPRN,			FR_RPRN,			FR_LBRC,			FR_RBRC,			X(Inf),				X(Sup),
														KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS,						KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ Unic                                                      │
   └───────────────────────────────────────────────────────────┘
               ╭───────────┬───────────┬───────────┬───────────┬───────────╮                    ╭───────────┬───────────┬───────────┬───────────┬───────────╮
               │     À     │     è     │     É     │     ®     │     &     │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │           │     ù     │           │     Œ     │           │
   ╭───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────╮
   │           │           │     $     │     #     │           │           ├─╯                ╰─┤     `     │     |     │           │     →     │     µ     │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤╭────────╮╭────────╮├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   │           │           │           │     Ç     │     _     │     -     ││        ││        ││     @     │     ¿     │     {     │     }     │     ¡     │           │
   ╰───────────┴───────────┴───────────┼───────────┼───────────┼───────────┼╰────────╯╰────────╯┼───────────┼───────────┼───────────┼───────────┴───────────┴───────────╯
                                       │           │           │           │         ││         │           │           │           │
                                       ╰───────────┴───────────┴───────────┴─────────╯╰─────────┴───────────┴───────────┴───────────╯ */

	[Unic] = LAYOUT_polydactyl(
							XP(AGrL,AGrU),		X(E_GrL),			XP(E_AigL,E_AigU),	X(Registrd),		FR_AMPR,										X(Pipe),			X(U_Gr),			KC_NO,				XP(OE_L,OE_U),		KC_NO,
		KC_NO,				KC_NO,				X(Dollar),			FR_HASH,			FR_UNDS,			FR_MINS,										X(BakQut),			KC_NO,				KC_NO,				X(ArrowR),			X(Micro),			KC_NO,
		KC_TRNS,			KC_NO,				KC_NO,				XP(CCedL,CCedU),	KC_NO,				KC_NO,			KC_TRNS,		KC_TRNS,		X(At),				X(InvQuest),		FR_LCBR,			FR_RCBR,			X(InvExcl),			KC_NO,
														KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS,						KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ Fun                                                       │
   └───────────────────────────────────────────────────────────┘
               ╭───────────┬───────────┬───────────┬───────────┬───────────╮                    ╭───────────┬───────────┬───────────┬───────────┬───────────╮
               │           │           │           │           │           │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │           │           │           │           │           │
   ╭───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────╮
   │    F1     │    F2     │    F3     │    F4     │    F5     │    F6     ├─╯                ╰─┤    F7     │    F8     │    F9     │    F10    │    F11    │    F12    │
   ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤╭────────╮╭────────╮├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   │           │           │           │CTL ALT DEL│  ALT F4   │CTL SFT ESC││        ││        ││  QK_BOOT  │  QK_RBT   │           │           │           │           │
   ╰───────────┴───────────┴───────────┼───────────┼───────────┼───────────┼╰────────╯╰────────╯┼───────────┼───────────┼───────────┼───────────┴───────────┴───────────╯
                                       │           │           │           │         ││         │           │           │           │
                                       ╰───────────┴───────────┴───────────┴─────────╯╰─────────┴───────────┴───────────┴───────────╯ */

	[Fun] = LAYOUT_polydactyl(
							KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_F1,				KC_F2,				KC_F3,				KC_F4,				KC_F5,				KC_F6,											KC_F7,				KC_F8,				KC_F9,				KC_F10,				KC_F11,				KC_F12,
		KC_TRNS,			KC_NO,				KC_NO,				C(A(KC_DEL)),		A(KC_F4),			C(S(KC_ESC)),	KC_TRNS,		KC_TRNS,		QK_BOOT,			QK_RBT,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
														KC_TRNS,			KC_TRNS,			KC_TRNS, 			KC_TRNS,						KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌───────────────────────────────────────────────────────────┐
   │ Media                                                     │
   └───────────────────────────────────────────────────────────┘
               ╭───────────┬───────────┬───────────┬───────────┬───────────╮                    ╭───────────┬───────────┬───────────┬───────────┬───────────╮
               │           │           │           │           │           │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │           │    ⏹︎	    │    ⏶︎	    │    ⏯︎	    │           │
   ╭───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────╮
   │           │           │           │           │           │           ├─╯                ╰─┤    ⏪︎	    │    ⏮︎	    │    ⏷︎	    │    ⏭︎	    │    ⏩︎	    │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤╭────────╮╭────────╮├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   │           │           │           │           │           │           ││        ││        ││           │           │           │           │           │           │
   ╰───────────┴───────────┴───────────┼───────────┼───────────┼───────────┼╰────────╯╰────────╯┼───────────┼───────────┼───────────┼───────────┴───────────┴───────────╯
                                       │           │           │           │         ││         │           │           │           │
                                       ╰───────────┴───────────┴───────────┴─────────╯╰─────────┴───────────┴───────────┴───────────╯ */

	[Media] = LAYOUT_polydactyl(
							KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_MSTP,			KC_VOLU,			KC_MPLY,			KC_NO,
		TO(Gaming),			KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_MRWD,			KC_MPRV,			KC_VOLD,			KC_MNXT,			KC_MFFD,			KC_NO,
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,			KC_TRNS,		KC_TRNS,		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
														KC_NO,				KC_NO,				KC_NO,				KC_NO,							KC_NO,				KC_NO,				KC_NO,				KC_NO),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ Mouse                                                     │
   └───────────────────────────────────────────────────────────┘
               ╭───────────┬───────────┬───────────┬───────────┬───────────╮                    ╭───────────┬───────────┬───────────┬───────────┬───────────╮
               │           │           │           │           │           │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │           │ LEFT CLICK│    ⏶︎	    │RIGHT CLICK│   WH UP   │
   ╭───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────╮
   │           │           │   ACL0    │   ACL1    │   ACL2    │           ├─╯                ╰─┤           │    ⏴︎	    │    ⏷︎	    │    ⏵︎	    │  WH DOWN  │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤╭────────╮╭────────╮├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   │           │           │           │           │           │           ││        ││        ││           │  WH LEFT  │ MID CLICK │ WH RIGHT  │           │           │
   ╰───────────┴───────────┴───────────┼───────────┼───────────┼───────────┼╰────────╯╰────────╯┼───────────┼───────────┼───────────┼───────────┴───────────┴───────────╯
                                       │           │           │           │         ││         │           │           │           │
                                       ╰───────────┴───────────┴───────────┴─────────╯╰─────────┴───────────┴───────────┴───────────╯ */

	[Mouse] = LAYOUT_polydactyl(
							KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,											KC_NO,				KC_BTN1,			KC_MS_U,			KC_BTN2,			KC_WH_U,
		KC_NO,				KC_NO,				KC_ACL0,			KC_ACL1,			KC_ACL2,			KC_NO,											KC_NO,				KC_MS_L,			KC_MS_D,			KC_MS_R,			KC_WH_D,			KC_NO,
		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,			KC_TRNS,		KC_TRNS,		KC_NO,				KC_WH_L,			KC_BTN3,			KC_WH_R,			KC_NO,				KC_NO,
														KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS,						KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ Gaming                                                    │
   └───────────────────────────────────────────────────────────┘
               ╭───────────┬───────────┬───────────┬───────────┬───────────╮                    ╭───────────┬───────────┬───────────┬───────────┬───────────╮
               │    TAB    │     A     │     Z     │     E     │     R     │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │           │           │           │           │           │
   ╭───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────╮
   │   SHIFT   │     3     │     Q     │     S     │     D     │     F     ├─╯                ╰─┤           │           │           │           │           │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤╭────────╮╭────────╮├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   │   CTRL    │     4     │     W     │     X     │     C     │     B     ││   5    ││        ││           │           │           │           │           │           │
   ╰───────────┴───────────┴───────────┼───────────┼───────────┼───────────┼╰────────╯╰────────╯┼───────────┼───────────┼───────────┼───────────┴───────────┴───────────╯
                                       │    ESC    │     2     │   SPACE   │    1    ││  ENTER  │   SHIFT   │           │           │
                                       └───────────┴───────────┴───────────┴─────────┘└─────────┴───────────┴───────────┴───────────┘ */

	[Gaming] = LAYOUT_polydactyl(
							KC_TAB,				FR_A,				FR_Z,				FR_E,				FR_R,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_LSFT,			FR_3,				FR_Q,				FR_S,				FR_D,				FR_F,											KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
		KC_LCTL,			FR_4,				FR_W,				FR_X,				FR_C,				FR_V,			FR_5,			KC_TRNS,		KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,				KC_NO,
														KC_ESC,				FR_2,				KC_SPC,				FR_1,							KC_ENT,				TO(Default),		KC_TRNS,			KC_NO),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │                                                           │
   └───────────────────────────────────────────────────────────┘
               ╭───────────┬───────────┬───────────┬───────────┬───────────╮                    ╭───────────┬───────────┬───────────┬───────────┬───────────╮
               │           │           │           │           │           │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │           │           │           │           │           │
   ╭───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────╮
   │           │           │           │           │           │           ├─╯                ╰─┤           │           │           │           │           │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤╭────────╮╭────────╮├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
   │           │           │           │           │           │           ││        ││        ││           │           │           │           │           │           │
   ╰───────────┴───────────┴───────────┼───────────┼───────────┼───────────┼╰────────╯╰────────╯┼───────────┼───────────┼───────────┼───────────┴───────────┴───────────╯
                                       │           │           │           │         ││         │           │           │           │
                                       ╰───────────┴───────────┴───────────┴─────────╯╰─────────┴───────────┴───────────┴───────────╯ */

};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ H A P T I C   F E E D B A C K                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

void keyboard_post_init_user(void) {
  // Call the post init code.
  #if HAPTIC_ENABLE
    haptic_disable(); // disables per key haptic feedback by default
  #endif //HAPTIC ENABLE
}

/*
// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O L E D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef OLED_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ d y n a m i c   m a c r o                                 │
// └───────────────────────────────────────────────────────────┘

char layer_state_str[24];
char o_text[24] = "";
int dmacro_num = 0; 

#ifdef DYNAMIC_MACRO_ENABLE
    char dmacro_text[4][24] = { "", "RECORDING", "STOP RECORDING",  "PLAY RECORDING"};
    static uint16_t dmacro_timer;
    const char PROGMEM rec_ico[] = {0xD1, 0xE1, 0};
    const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
    const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};


    // DYNMACRO RECORD ├─────────────────────────────────────────────────────────────┐
    void dynamic_macro_record_start_user(void) {
          dmacro_num = 1;
        return;
    }

    // DYNMACRO STOP RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_record_end_user(int8_t direction) {
          dmacro_num = 2;
          dmacro_timer = timer_read();
        return; 
    }

    // DYNMACRO PLAY RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_play_user(int8_t direction) {
          dmacro_num = 3;
          dmacro_timer = timer_read();
        return; 
    }
#endif //DYNAMIC_MACRO_ENABLE


void matrix_scan_user(void) {
  #ifdef DYNAMIC_MACRO_ENABLE
    // DynMacroTimer
    if(dmacro_num > 0){
        if (timer_elapsed(dmacro_timer) < 3000) {
            strcpy ( o_text, dmacro_text[dmacro_num] );
          }    
        else {
            if (dmacro_num == 1) {
                strcpy ( o_text, dmacro_text[1] );
              }
            else {
                strcpy ( o_text, layer_state_str );
                dmacro_num = 0;
              }
          }
      }
   #endif //DYNAMIC_MACRO_ENABLE
}


// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘

void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};  
    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0}; 
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
    #ifdef AUDIO_ENABLE  
      static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
      static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
    #endif
    #ifdef HAPTIC_ENABLE
      static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
    #endif

// os mode status ────────────────────────────────────────┐

    oled_write_ln_P(sep_v, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_1, false); // ──── MAC
    } else {
        oled_write_P(os_w_1, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_1, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_2, false); // ──── MAC
    } else {
        oled_write_P(os_w_2, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_2, false);
    oled_write_ln_P(sep_v, false);

    
// lock key layer status ─────────────────────────────────┐

    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.num_lock) {
        oled_write_P(n_lock, false); // ──── NUMLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.caps_lock) {
        oled_write_P(c_lock, false); // ─── CAPSLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
        oled_write_P(s_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }

// hardware feature status ──────────────────────────────┐

    oled_write_P(sep_h2, false);

    #ifndef AUDIO_ENABLE 
        oled_write_P(b_lock, false);
    #endif
    #ifndef HAPTIC_ENABLE 
        oled_write_P(b_lock, false);
    #endif

    #ifdef AUDIO_ENABLE // ────────────────── AUDIO
        if (is_audio_on()) { 
          oled_write_P(aud_en, false); 
        } else {
          oled_write_P(aud_di, false);
        }
    #endif // AUDIO ENABLE

     #ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
        oled_write_P(hap_en, false); 
     #endif // HAPTIC ENABLE
}


// layer status ──────────────────────────────────────────┐

int layerstate = 0;

layer_state_t layer_state_set_kb(layer_state_t state) {
      switch (get_highest_layer(layer_state | default_layer_state)) {
            case 0:
                strcpy ( layer_state_str, "Default");
                break;
            case 1:
                strcpy ( layer_state_str, "NumArr");
                break;
            case 2:
                strcpy ( layer_state_str, "Unic");
                break;
            case 3:
                strcpy ( layer_state_str, "Fun");
                break;
            case 4:
                strcpy ( layer_state_str, "Media");
                break;
            case 5:
                strcpy ( layer_state_str, "Mouse");
                break;
            case 6:
                strcpy ( layer_state_str, "Gaming");
                break;
            default:
                strcpy ( layer_state_str, "Default");
        }
      if (dmacro_num < 1) {
          strcpy ( o_text, layer_state_str );
    }
  //return state;
    return update_tri_layer_state(state, NumArr, Unic, Media);
}


// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {  // ────────────────────────── PRIMARY SIDE

        // layer status ──────────────────────────────────────────────────┐
        #ifdef DYNAMIC_MACRO_ENABLE
            if(dmacro_num == 1){ oled_write_P(rec_ico, false); }
            if(dmacro_num == 2){ oled_write_P(stop_ico, false); }
            if(dmacro_num == 3){ oled_write_P(play_ico, false); }
        #endif //DYNAMIC_MACRO_ENABLE

        oled_write_ln(o_text, false);
        render_os_lock_status();

    } else {  // ─────────────────────────────────────────── SECONDARY SIDE

        // KLOR face ─────────────────────────────────────────────────────┐

        static const char PROGMEM klor_face[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
            0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 
            0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(klor_face, sizeof(klor_face));
    }
    return false;
}
#endif // OLED_ENABLE
*/

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ E N C O D E R                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef ENCODER_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  L                                          │
// └───────────────────────────────────────────────────────────┘ 

bool encoder_update_kb(uint8_t index, bool clockwise) {
	if (!encoder_update_user(index, clockwise)) {
		return false;
	}
	if (index == 0) {
		uint8_t mods = get_mods();
		bool shift = mods & MOD_MASK_SHIFT;
		// bool control = mods & MOD_MASK_CTRL;
		bool alt = mods & MOD_MASK_ALT;

		// Shift Horizontal scroll
		if (shift) {
			if (clockwise) {
				tap_code(KC_WH_D);
			} else {
				tap_code(KC_WH_U);
			}
		}

		// Alt Vertical scroll
		else if (alt) {
			if (clockwise) {
				tap_code(KC_WH_D);
			} else {
				tap_code(KC_WH_U);
			}
		} 

		// Volume control
		else {
			if (clockwise) {
				tap_code(KC_VOLU);
			} else {
				tap_code(KC_VOLD);
			}
		}


// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  R                                          │
// └───────────────────────────────────────────────────────────┘

	} else if (index == 1) {
		uint8_t mods = get_mods();
		bool shift = mods & MOD_MASK_SHIFT;
		bool control = mods & MOD_MASK_CTRL;
		bool alt = mods & MOD_MASK_ALT;

		// Ctrl+Shift - RGB mode
		if (control && shift) {
				if (clockwise) {
					rgb_matrix_step_noeeprom();
				} else {
					rgb_matrix_step_reverse_noeeprom();
				}
		}

		// Ctrl+Alt - Speed
		else if (control && alt) {
			if (clockwise) {
				rgb_matrix_increase_speed_noeeprom();
			} else {
				rgb_matrix_decrease_speed_noeeprom();
			}
		}

		// Shift - Brightness
		else if (shift) {
			if (clockwise) {
				rgb_matrix_increase_val_noeeprom();
			} else {
				rgb_matrix_decrease_val_noeeprom();
			}
		}

		// Control - Hue
		else if (control) {
			if (clockwise) {
				rgb_matrix_increase_hue_noeeprom();
			} else {
				rgb_matrix_decrease_hue_noeeprom();
			}
		}

		// Alt - Saturation
		else if (alt) {
			if (clockwise) {
				rgb_matrix_increase_sat_noeeprom();
			} else {
				rgb_matrix_decrease_sat_noeeprom();
			}
		}

		// No modifier
		else {
		tap_code(clockwise ? KC_MNXT : KC_MPRV);
		}
	}
return true;
}

#endif

// Turn off Liatris LED
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

/*

                                                       ▐█    ▟▛ ▐█     ▄▆▀▀▀▀▀▀▆▄  ▐█▀▀▀▀▀█▌
                                                       ▐█   ▟▛  ▐█    ▟▛        ▜▙ ▐█     █▌
                                                       ▐█  ▟▛   ▐█   ▐█          █▋▐█     █▌
                                                       ▐█ ▟█▙   ▐█   ▐█          █▋▐█▀▀▜█▀▀▘
                                                       ▐█▟▛ ▜▙  ▐█    ▜▙        ▟▛ ▐█   ▜▙
                                                       ▐█▛   ▜▙ ▐█▄▄▄▄ ▀▜▆▄▄▄▄▆▛▀  ▐█    ▜▙

                                                                 ▄██████████████▄
                                                                 ████████████████
                                                            ▄██████▀  ▀████▀  ▀██████▄
                                                            ███████▄  ▄████▄  ▄███████
                                                            ███████████▀▀▀▀███████████
                                                            ▀█████████▀ ▄▄ ▀█████████▀
                                                                 ████▀ ▄██▄ ▀████
                                                                 ████▄▄████▄▄████

*/