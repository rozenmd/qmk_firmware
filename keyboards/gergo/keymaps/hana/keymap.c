/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define IGNORE_MOD_TAP_INTERRUPT
#define _BASE  0 // default layer
#define _RAISE 1 // symbols
#define _LOWER 2 // numbers/motion

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define ALT_ENT ALT_T(KC_ENT)
#define SH_ESC  SFT_T(KC_ESC)

#define LW_DEL  LT(_LOWER, KC_DELT)

#define ST_GUI  OSM(MOD_LGUI)
#define ST_CTL  OSM(MOD_LALT)
#define ST_ALT  OSM(MOD_LALT)

enum custom_keycodes {
  M1_STRING = SAFE_RANGE,
  M2_URL,
};

// Blank template at the bottom

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 *       ,-------------------------------------------.                         ,-------------------------------------------.
 *       |  TAB   |   Q  |   W  |   F  |   P  |   G  |                         |   J  |   L  |   U  |   Y  | ; :  |  | \   |
 *       |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 *       |  Ctrl  |   A  |   R  |  S   |   T  |   D  |O(CMD)|           |O(CTL)|   H  |   N  |   E  |   I  |  O   |  ' "   |
 *       |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 *       | LShift |   Z  |   X  |   C  |   V  |   B  |O(ALT)|           |      |   K  |   M  | ,  < | . >  | /  ? | RShift |
 *       `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                          .----------.   .-------.                                 .------.   .--------.
 *                          | alt/del  |   | BKSP  |                                 | Space|   |cmd/del |
 *                          '----------'   '-------'                                 `------.   '--------'
 *                                              ,-------.                      ,-------.
 *                                              | MMB   |                      |  :    |
 *                                       ,------|-------|                      |-------|------.
 *                                       | NUMB | SYMB  |                      | SYMB  | NUMB |
 *                                       |  Esc |  F13  |                      | F14   | Enter|
 *                                       |      |       |                      |       |      |
 *                                       `--------------'                      `--------------'
 */
[_BASE] = LAYOUT_gergo(
      KC_TAB,   KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y,                        KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
      KC_LCTL,  KC_A,    KC_O,    KC_E,   KC_U, KC_I, ST_GUI,       ST_CTL,  KC_D, KC_H, KC_T, KC_N, KC_S, KC_ENT,
      KC_LSFT,  KC_QUOT, KC_Q,    KC_J,   KC_K, KC_X, ST_ALT,       KC_TRNS, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT,

                               KC_LGUI, SH_ESC,                                  ALT_ENT, KC_MINS,

                                                      KC_BTN2,      KC_BTN3,
                                             KC_BSPC, LW_DEL,       RAISE,    KC_SPC),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                         |   ^  |  &   |  *   |  (   |  )   |  VolUp |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  [   |  ]   |  {   |  }   |  `   |  M1  |           |      |      |  -   |  _   |  +   |  =   |  VolDn |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  `   |  ~   |      |      |  ~   |  M2  |           |      |      |      | Prev |Pl/Pau| Next |  Mute  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[_RAISE] = LAYOUT_gergo(
      KC_TAB,   KC_EXLM, KC_AT,   KC_UP,   KC_LBRC, KC_RBRC,                  KC_BSLS, KC_7, KC_8, KC_9, KC_ASTR, KC_SLSH,
      KC_LCTL,  KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,  ST_GUI, ST_CTL,  KC_EQL,  KC_4, KC_5, KC_6, KC_ENT,  KC_ENT,
      KC_LSFT,  KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, ST_ALT, KC_TRNS, KC_GRV,  KC_1, KC_2, KC_3, KC_PLUS, KC_RSFT,

                               KC_LGUI, SH_ESC,                                        ALT_ENT, KC_0,

                                                      KC_BTN2,                 KC_BTN3,
                                             KC_BSPC, LOWER,                   RAISE,    KC_SPC),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   | PgUp   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  F1    |  F2  | F3   | F4   | F5   | F6   | BTN1 |           | Home | LEFT | DOWN |  UP  | RIGHT| End  | PgDn   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  F7    |  F8  | F9   | F10  | F11  | F12  | BTN2 |           |      | MLFT | MDWN | MUP  | MRGHT|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |  ALT |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[_LOWER] = LAYOUT_gergo(
      KC_TAB,   KC_ESC,  KC_PSCR, KC_PAUS, KC_F1, KC_F2,                   KC_F3,  KC_F4,  KC_INS,  KC_DELT, KC_BSPC, KC_SLSH,
      KC_LCTL,  KC_CLCK, KC_TAB,  KC_PGUP, KC_F5, KC_F6,  ST_GUI, ST_CTL,  KC_F7,  KC_F8,  KC_HOME, KC_LALT, KC_ENT,  KC_ENT,
      KC_LSFT,  KC_LSFT, KC_SLCK, KC_PGDN, KC_F9, KC_F10, ST_ALT, KC_TRNS, KC_F11, KC_F12, KC_END,  KC_MINS, KC_SLSH, KC_RSFT,

                               KC_LGUI, SH_ESC,                                        ALT_ENT, KC_APP,

                                                      KC_BTN2,          KC_BTN3,
                                             KC_BSPC, LOWER,            RAISE,    KC_SPC)
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,

                                                  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                                           KC_TRNS,       KC_TRNS,
                                             	  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS),
 */

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    //uint8_t layer = biton32(layer_state);
    biton32(layer_state);
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M1_STRING:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("Hi!" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case M2_URL:
      if (record->event.pressed) {
          SEND_STRING("https://ddg.gg" SS_TAP(X_ENTER));
      }
      break;

  }
  return true;
};

