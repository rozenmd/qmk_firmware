#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

#define AD_DEL  LT(_ADJUST, KC_DELT)
#define AD_SPC  LT(_ADJUST, KC_SPC)
#define AL_ENT  ALT_T(KC_ENT)
#define CT_SLSH CTL_T(KC_SLSH)
#define CT_TAB  CTL_T(KC_TAB)
#define LW_BSPC LT(_LOWER, KC_BSPC)
#define RS_SPC  LT(_RAISE, KC_SPC)
#define SH_ESC  SFT_T(KC_ESC)

#define ADJUST  MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,         KC_F,    KC_G,    KC_C,    KC_R,  KC_L, \
  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,         KC_D,    KC_H,    KC_T,    KC_N,  KC_S, \
  KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,         KC_B,    KC_M,    KC_W,    KC_V,  KC_Z, \
                    LW_BSPC, SH_ESC,  CT_TAB,       CT_SLSH, AL_ENT,  RS_SPC                \
),

[_RAISE] = LAYOUT( \
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_BSLS, KC_7,    KC_8,   KC_9,   KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_EQL,  KC_4,    KC_5,   KC_6,   KC_ENT ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3,   KC_PLUS ,
                      ADJUST,  _______, KC_0,                      _______, _______, KC_DOT                    \
),

[_LOWER] = LAYOUT( \
    KC_ESC,  KC_PSCR, KC_PAUS, KC_F1, KC_F2,                    KC_F3,  KC_F4,   KC_MINS, KC_SLSH, KC_BSPC ,
    KC_LSFT, KC_TAB,  KC_PGUP, KC_F5, KC_F6,                    KC_F7,  KC_F8,   KC_HOME, KC_LALT, KC_ENT  ,
    KC_CLCK, KC_LSFT, KC_PGDN, KC_F9, KC_F10,                   KC_F11, KC_F12,  KC_END,  KC_INS, KC_SLSH ,
                      _______, _______, _______,                KC_ENT, KC_DEL,  ADJUST                    \
),

[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, _______, _______,      _______, _______, _______, TSKMGR, CALTDEL, \
  RESET,   _______, _______, _______, RESET,        _______, _______, _______, _______,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case QWERTY:
	  if (record->event.pressed) {
		#ifdef AUDIO_ENABLE
		  PLAY_SONG(tone_qwerty);
		#endif
		persistant_default_layer_set(1UL<<_QWERTY);
	  }
	  return false;
	  break;
	case LOWER:
	  if (record->event.pressed) {
		layer_on(_LOWER);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  } else {
		layer_off(_LOWER);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  }
	  return false;
	  break;
	case RAISE:
	  if (record->event.pressed) {
		layer_on(_RAISE);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  } else {
		layer_off(_RAISE);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
	  }
	  return false;
	  break;
	case ADJUST:
	  if (record->event.pressed) {
		layer_on(_ADJUST);
	  } else {
		layer_off(_ADJUST);
	  }
	  return false;
	  break;
  }
  return true;
}
