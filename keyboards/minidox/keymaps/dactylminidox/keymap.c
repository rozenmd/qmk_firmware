#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MAUS  3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_UNDR LSFT(KC_MINS)
#define KC_QUES LSFT(KC_SLSH)

#define AD_DEL  LT(_ADJUST, KC_DELT)
#define AD_SPC  LT(_ADJUST, KC_SPC)
#define AL_ENT  ALT_T(KC_ENT)
#define CT_SLSH CTL_T(KC_SLSH)
#define CT_TAB  CTL_T(KC_TAB)
#define LW_BSPC LT(_LOWER, KC_BSPC)
#define RS_SPC  LT(_RAISE, KC_SPC)
#define SH_ESC  SFT_T(KC_ESC)

#define AL_E    ALT_T(KC_E)
#define AL_T    ALT_T(KC_T)
#define CT_N    CTL_T(KC_N)
#define CT_O    CTL_T(KC_O)
#define GU_H    LGUI_T(KC_H)
#define GU_U    LGUI_T(KC_U)
#define SH_A    SFT_T(KC_A)
#define SH_S    SFT_T(KC_S)

#define CALTDEL  LCTL(LALT(KC_DEL))
#define CLOSEGUI LALT(KC_F4)
#define EXPLORER LGUI(KC_E)
#define LOCKGUI  LGUI(KC_L)
#define NEXTTAB  LCTL(KC_PGDN)
#define NEXTWIN  LALT(KC_TAB)
#define PREVTAB  LCTL(KC_PGUP)
#define PREVWIN  LALT(LSFT(KC_TAB))
#define TASKMGR  LCTL(LSFT(KC_ESC))

#define ADJUST  MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,         KC_F,    KC_G,    KC_C,    KC_R,  KC_L, \
  SH_A,    CT_O,    AL_E,    GU_U,    KC_I,         KC_D,    GU_H,    AL_T,    CT_N,  SH_S, \
  KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,         KC_B,    KC_M,    KC_W,    KC_V,  KC_Z, \
                    LW_BSPC, SH_ESC,  CT_TAB,       CT_SLSH, AL_ENT,  RS_SPC                \
),

[_RAISE] = LAYOUT( \
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,    KC_BSLS, KC_7,    KC_8,   KC_9,   KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,     KC_EQL,  KC_4,    KC_5,   KC_6,   KC_0 ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_PLUS ,
                      ADJUST,  _______, KC_ENT,     _______, _______, KC_DOT                    \
),

[_LOWER] = LAYOUT( \
    KC_ESC,  KC_QUES, KC_UNDR, KC_F1, KC_F2,        KC_F3,  KC_F4,   KC_MINS, KC_SLSH, KC_BSPC ,
    KC_LSFT, KC_TAB,  KC_PGUP, KC_F5, KC_F6,        KC_F7,  KC_F8,   KC_HOME, KC_LALT, KC_ENT  ,
    KC_CLCK, KC_LSFT, KC_PGDN, KC_F9, KC_F10,       KC_F11, KC_F12,  KC_END,  KC_INS, KC_SLSH ,
                      _______, _______, _______,    KC_ENT, KC_DEL,  ADJUST                    \
),

[_ADJUST] =  LAYOUT( \
  _______, EXPLORER, KC_UP,   PREVTAB, PREVWIN,      NEXTWIN, NEXTTAB, _______, _______, LOCKGUI, \
  TASKMGR, KC_LEFT,  KC_DOWN, KC_RGHT, _______,      _______, KC_LEAD, KC_LGUI, _______, CALTDEL, \
  _______, CLOSEGUI, _______, _______, RESET,        _______, _______, _______, _______, _______, \
                     _______, _______, _______,      _______,  _______, _______                    \
),
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
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


LEADER_EXTERNS();

void matrix_scan_user() {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // emojis for input tech's discord server.
    SEQ_ONE_KEY(KC_A) {
      SEND_STRING(":ayyy:");
    }
    SEQ_ONE_KEY(KC_O) {
      SEND_STRING(":owo:");
    }
    SEQ_ONE_KEY(KC_U) {
      SEND_STRING(":uwu:");
    }
    SEQ_ONE_KEY(KC_W) {
      SEND_STRING(":we_already_had_sex_this_week:");
    }
    SEQ_ONE_KEY(KC_M) {
      SEND_STRING(":megu:");
    }
    SEQ_ONE_KEY(KC_Y) {
      SEND_STRING(":yeetcry:");
    }
    SEQ_ONE_KEY(KC_D) {
      SEND_STRING(":dogg:");
    }
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING(":crocodile:");
    }
    SEQ_ONE_KEY(KC_K) {
      SEND_STRING(":kek:");
    }
    SEQ_ONE_KEY(KC_G) {
      SEND_STRING(":germ:");
    }
    SEQ_TWO_KEYS(KC_A, KC_I) {
      SEND_STRING(":ai03:");
    }
    SEQ_TWO_KEYS(KC_A, KC_X) {
      SEND_STRING(":axolotl:");
    }
    SEQ_TWO_KEYS(KC_C, KC_R) {
      SEND_STRING(":crocodilereverse:");
    }
    SEQ_TWO_KEYS(KC_L, KC_F) {
      SEND_STRING(":lightfire:");
    }
  }
}
