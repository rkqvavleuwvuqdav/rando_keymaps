/* Copyright 2021 Moritz Plattner
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define LOWER MO(1)
#define RAISE MO(2)
#define ADJ MO(3)

#define MT_RSFT_ENT MT(MOD_RSFT, KC_ENT)
#define CTL_ESC MT(MOD_LCTL,KC_ESC)
#define RCMD_LEFT RCMD_T(KC_LEFT)
#define SPC_L LT(1,KC_SPC)
#define SPC_R LT(2,KC_SPC)
#define ALT_W LALT_T(KC_W)
#define ALT_O RALT_T(KC_O)
#define CMD_E LCMD_T(KC_E)
#define CMD_I LCMD_T(KC_I)
#define SFT_F LSFT_T(KC_F)
#define SFT_J RSFT_T(KC_J)
#define CNTRL_D LCTL_T(KC_D)
#define CNTRL_K RCTL_T(KC_K)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_alice_split_bs(
        KC_PSCR, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_PGUP, KC_TAB,  KC_Q,    ALT_W,    CMD_E,    KC_R,    KC_T,    KC_Y,    KC_U,    CMD_I,    ALT_O,    KC_P,    KC_BSPC, KC_RBRC, KC_BSLS,
        KC_PGDN, CTL_ESC, KC_A,    KC_S,    CNTRL_D,    SFT_F,    KC_G,    KC_H,    SFT_J,    CNTRL_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_RSFT_ENT, MO(4),
                 KC_LCTL,                   KC_LALT, SPC_L,  MO(5),          SPC_R,           KC_RALT,                            KC_RCTL
    ),
    [1] = LAYOUT_alice_split_bs(
        KC_MUTE, KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_MUTE,
        KC_VOLU, KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_PGDN, KC_PGUP, KC_INSERT, KC_PSCR, KC_DEL, KC_TRNS, KC_TRNS,
        KC_VOLD, KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  KC_SLSH, KC_PIPE,          KC_TRNS,
                 KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS, KC_END,  KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,                            KC_TRNS
    ),

    [2] = LAYOUT_alice_split_bs(
        KC_TRNS, KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_VOLD,
        KC_HOME, KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_END, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,          KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS, KC_TRNS,
                 KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,                            KC_TRNS
    ),
    [3] = LAYOUT_alice_split_bs(
        KC_TRNS, KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_VOLU,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 RESET,                   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,                            KC_TRNS
    ),
    [4] = LAYOUT_alice_split_bs(
        KC_TRNS, KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_PGDN,
        KC_SLCK, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,                            KC_TRNS
    ),

    [5] = LAYOUT_alice_split_bs(
        KC_TRNS, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_END,
        KC_TRNS, KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS, KC_TRNS,
                 KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,                            KC_TRNS
    )
};
