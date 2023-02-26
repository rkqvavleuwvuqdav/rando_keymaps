// Copyright 2022 kreme
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _karjalasta,
    _RAISE,
    _MACRO,
    _ADJUST
};

#define MT_RSFT_ENT MT(MOD_RSFT, KC_ENT)
#define CTL_ESC MT(MOD_LCTL,KC_ESC)
#define ALT_W LALT_T(KC_W)
#define ALT_O RALT_T(KC_O)
#define CMD_E LCMD_T(KC_E)
#define CMD_I LCMD_T(KC_I)
#define SFT_F LSFT_T(KC_F)
#define SFT_J RSFT_T(KC_J)
#define CNTRL_D LCTL_T(KC_D)
#define CNTRL_K RCTL_T(KC_K)
#define SPC_L LT(1,KC_SPC)
#define SPC_R LT(2,KC_SPC)
#define EXPOSE LCTL(KC_UP)

enum custom_keycodes {
 MOUSEJIGGLERMACRO
};

bool mouse_jiggle_mode = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOUSEJIGGLERMACRO:
      if (record->event.pressed) {
        mouse_jiggle_mode = true;
      } else {
        mouse_jiggle_mode = false;
      }
      break;
  }
  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    CMD_E,    KC_R,    KC_T,    KC_Y,    KC_U,    CMD_I,    KC_O,    KC_P,    KC_BSPC, KC_RBRC, KC_BSPC,
        CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_RSFT_ENT,   MO(4),
        KC_LCTL, KC_LALT, SPC_L,  MO(5),   SPC_R,  KC_LGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LOWER] = LAYOUT(
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,    _______, KC_PGDN, KC_PGUP, KC_INSERT, KC_PSCR, KC_DEL, KC_EQL,  KC_BSLS,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  KC_SLSH, KC_PIPE,  _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, KC_END, KC_HOME, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_VOLD, _______
    ),


    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,  _______,  KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,  _______,
        _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11, KC_F12,  KC_F13,
        _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______,   _______,   _______,   _______,   _______,  _______,  _______,
        _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    [_MACRO] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, MOUSEJIGGLERMACRO, KC_LOCK, _______, _______, _______, _______,
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______
    ),    


    [_karjalasta] = LAYOUT(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, QK_BOOT,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______
    )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_scan_user(void) {
  if (mouse_jiggle_mode) {
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
    tap_code(KC_MS_WH_DOWN);
  } else {
 }
}
