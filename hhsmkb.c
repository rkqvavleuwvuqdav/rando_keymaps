/*
Copyright 2020 Croktopus

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H


#define LOWER MO(1)
#define RAISE MO(2)

#define MT_RSFT_ENT MT(MOD_RSFT, KC_ENT)
#define CTL_ESC MT(MOD_LCTL,KC_ESC)
#define CTL_QUOT MT(MOD_RCTL,KC_QUOT)
#define RCMD_LEFT RCMD_T(KC_LEFT)
#define RALT_DOWN RALT_T(KC_DOWN)
#define RCTL_UP RCTL_T(KC_UP)
#define LCMD_RIGHT LGUI_T(KC_RIGHT)
#define SPC_NUM LT(3,KC_SPC)
#define ALT_W LALT_T(KC_W)
#define ALT_O RALT_T(KC_O)
#define CMD_E LCMD_T(KC_E)
#define CMD_I LCMD_T(KC_I)
#define SFT_F LSFT_T(KC_F)
#define SFT_J RSFT_T(KC_J)
#define CNTRL_D LCTL_T(KC_D)
#define CNTRL_K RCTL_T(KC_K)
#define SPC_RSE LT(2,KC_SPC)


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_all(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
		KC_TAB,  KC_Q,    ALT_W,    CMD_E,    KC_R,    KC_T,    KC_Y,    KC_U,    CMD_I,    ALT_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		CTL_ESC,  KC_A,    KC_S,    CNTRL_D,    SFT_F,    KC_G,    KC_H,    SFT_J,    CNTRL_K,    KC_L,    KC_SCLN, CTL_QUOT, KC_NUHS, MO(5),
		KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_RSFT_ENT, MO(4),
		                           KC_LALT, LCMD_RIGHT, LOWER,  SPC_NUM,  SPC_RSE,  RAISE,  RCMD_LEFT, RALT_DOWN
    ),

    [1] = LAYOUT_all(
		RESET,   _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______,
		_______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______, KC_PGDN, KC_PGUP, KC_INSERT, KC_PSCR, KC_PIPE, _______, KC_PIPE,
		_______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______,
		_______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, KC_END, KC_HOME, _______, _______, _______, _______, _______,
		                           _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [2] = LAYOUT_all(
		RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
		_______, _______, _______, _______, _______, _______, _______,  KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		                           _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT_all(
		RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,
		_______, KC_1, KC_2,    KC_3,    KC_4,    KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		                           _______, _______, _______, _______, _______, _______, _______, _______
    ),


		[4] = LAYOUT_all(
		_______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_WBAK, KC_WSTP, KC_WREF, KC_WFWD, _______, _______, _______, _______,
		_______, RGB_MOD, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______,
				                           _______, _______, _______, _______, _______, _______, _______, _______
		  ),


		[5] = LAYOUT_all(
	  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F11,  KC_F12, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
					                           _______, _______, _______, _______, _______, _______, _______, _______
			 )



};


void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case 0:
            rgblight_setrgb(100,160, 100);
            break;
        case 1:
            rgblight_setrgb(0,100, 0);
            break;
        case 2:
            rgblight_setrgb(0,16, 64);
            break;
        case 3:
            rgblight_setrgb(100,0, 100);
            break;
        case 4:
            rgblight_setrgb(0,120, 120);
            break;
        default:
            rgblight_setrgb(50,50, 0);
            break;
    }

};
