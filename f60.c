#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _karjalasta 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  karjalasta,
  LOWER,
  RAISE,
  ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define MT_RSFT_ENT MT(MOD_RSFT, KC_ENT)
#define CTL_ESC MT(MOD_LCTL,KC_ESC)
#define CTL_QUOT MT(MOD_RCTL,KC_QUOT)
#define RCMD_LEFT RCMD_T(KC_LEFT)
#define RALT_DOWN RALT_T(KC_DOWN)
#define RCTL_UP RCTL_T(KC_UP)
#define LCMD_RIGHT LGUI_T(KC_RIGHT)
#define SPC_NUM LT(_karjalasta,KC_SPC)
#define ALT_W LALT_T(KC_W)
#define ALT_O RALT_T(KC_O)
#define CMD_E LCMD_T(KC_E)
#define CMD_I LCMD_T(KC_I)
#define SFT_F LSFT_T(KC_F)
#define SFT_J RSFT_T(KC_J)
#define CNTRL_D LCTL_T(KC_D)
#define CNTRL_K RCTL_T(KC_K)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    ALT_W,    CMD_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    CMD_I,    ALT_O,    KC_P,    KC_BSPC, \
  CTL_ESC,  KC_A,    KC_S,    CNTRL_D,    SFT_F,    KC_G,                   KC_H,    SFT_J,    CNTRL_K,    KC_L,    KC_SCLN, CTL_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_RSFT_ENT , \
                 KC_LALT, LCMD_RIGHT,   LOWER,  SPC_NUM, SPC_NUM,  KC_SPC, SPC_NUM, RAISE,    RCMD_LEFT, RALT_DOWN\
),


[_karjalasta] = LAYOUT( \
  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BSPC, \
  KC_NO,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_BSLS, \
  KC_NO,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO, \
  KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,  , KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, _______,    _______ , \
                 KC_NO, KC_NO,   KC_NO,  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO\
),


[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                   _______,    KC_PGDN,    KC_PGUP,    KC_INSERT, KC_PSCR, KC_DEL,  \
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, KC_PIPE, \
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,  RESET, _______, _______, _______, KC_END,  KC_HOME, _______, _______,\
                    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),


[_RAISE] = LAYOUT( \
  _______,  _______,    _______,    _______,    _______,    _______,                       _______,    _______,    _______,    _______,    _______,    KC_DEL,  \
  _______,  _______,    _______,   _______,    _______,    _______,                       _______,    _______,    _______,    _______,    _______,    KC_BSPC, \
  _______, _______, KC_MPRV, KC_MPLY, KC_MUTE, KC_VOLD,                      KC_F6,KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,    KC_BSLS, \
  _______, _______,   _______,   _______,   _______,  _______,  _______, RESET,  _______,  _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),

[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_BSPC, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, _______, BL_TOGG, BL_STEP, _______, _______, \
  QWERTY,  COLEMAK, karjalasta,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case karjalasta:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_karjalasta);
      }
      return false;
      break;
  }
  return true;
}
