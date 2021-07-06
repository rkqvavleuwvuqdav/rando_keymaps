// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _karjalasta
};


#define LOWER MO(1)
#define RAISE MO(2)
#define ADJ MO(_ADJUST)
#define CTL_ESC MT(MOD_LCTL,KC_ESC)
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
  [_QWERTY] = LAYOUT( /* QWERTY */
    KC_Q,    ALT_W,    CMD_E,    KC_R,    KC_T,            KC_Y,    KC_U,  CMD_I,    ALT_O,   KC_P,
    KC_A, KC_S,    CNTRL_D,    SFT_F,    KC_G,            KC_H,    SFT_J,  CNTRL_K,    KC_L,   KC_SCLN,
    KC_L, KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                                    LOWER, SPC_NUM, SPC_NUM, RAISE
  ),

  [_LOWER] = LAYOUT( /* [> LOWER <] */
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,            _______, KC_PGDN, KC_PGUP, KC_INSERT, KC_PSCR,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  KC_SLSH,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,         _______, KC_END,  KC_HOME, _______,  _______,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, RESET,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_ADJUST] = LAYOUT(
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
_______, _______, _______, _______, _______,     _______, _______, _______, KC_F11,  KC_F12,
_______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
                           _______, _______,     _______, _______
),

[_karjalasta] = LAYOUT(
KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
_______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
                         _______, _______,     _______, _______
)


};



enum combos {
COMBO_TAB,
COMBO_ESC,
COMBO_BACKSPACE,
COMBO_QUOT,
COMBO_BACKSLASH,
COMBO_ENT,
};

const uint16_t PROGMEM combo_tab[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_quot[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_backslash[] = {KC_H, KC_K, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_BACKSPACE] = COMBO(combo_backslash, KC_BSPC),
    [COMBO_QUOT] = COMBO(combo_backspace, KC_QUOT),
    [COMBO_BACKSLASH] = COMBO(combo_quot, KC_BSLS),
    [COMBO_ENT] = COMBO(combo_ent, KC_ENT),
};
