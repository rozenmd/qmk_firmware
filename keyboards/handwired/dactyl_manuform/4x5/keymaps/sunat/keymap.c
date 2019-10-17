#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE    0
#define _LOWER   1
#define _RAISE   2
#define _ADJUST  3

#define ____ KC_TRNS

#define ALT_ENT   ALT_T(KC_ENT)
#define SFT_ESC   SFT_T(KC_ESC)

#define CT_O RCTL_T(KC_O)
#define CT_N RCTL_T(KC_N)
#define SH_A RSFT_T(KC_A)
#define SH_S RSFT_T(KC_S)
#define AL_E RALT_T(KC_E)
#define AL_T RALT_T(KC_T)
#define GU_U RGUI_T(KC_U)
#define GU_H RGUI_T(KC_H)

#define LW_DEL   LT(_LOWER, KC_DELT)
#define LW_BSPC  LT(_LOWER, KC_BSPC)
#define RS_BSPC  LT(_RAISE, KC_BSPC)
#define RS_SPC   LT(_RAISE, KC_SPC)

#define RAISE    MO(_RAISE)
#define LOWER    MO(_LOWER)
#define ADDDD    MO(_ADJUST)

#define NEXTTAB  LCTL(KC_PGDN)
#define PREVTAB  LCTL(KC_PGUP)
#define NEXTWIN  LALT(KC_TAB)
#define PREVWIN  LALT(LSFT(KC_TAB))
#define CALTDEL  LCTL(LALT(KC_DELT))
#define TASKMGR  LCTL(LSFT(KC_ESC))
#define EXPLORER LGUI(KC_E)
#define LOCKGUI  LGUI(KC_L)

#define CLOSEGUI LALT(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_SCLN, KC_COMM, KC_DOT,  KC_P, KC_Y,                                     KC_F, KC_G, KC_C,    KC_R,   KC_L,
  SH_A,    CT_O,    AL_E,    GU_U, KC_I,                                     KC_D, GU_H, AL_T,    CT_N,   SH_S,
  KC_QUOT, KC_Q,    KC_J,    KC_K, KC_X,                                     KC_B, KC_M, KC_W,    KC_V,   KC_Z,
           KC_TAB,  KC_LGUI,                                                             KC_MINS, KC_SLSH,
                                         LW_BSPC, SFT_ESC,  ALT_ENT, RS_SPC,
                                         KC_LCTL, LW_DEL,   KC_LEAD, KC_LCTL,
                                         ____,    ____,     ____,    ____
),

[_RAISE] = LAYOUT(
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                             KC_BSLS, KC_7, KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                              KC_EQL,  KC_4, KC_5,   KC_6, KC_ENT  ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                             KC_GRV,  KC_1, KC_2,   KC_3, KC_PLUS ,
             KC_INS,  KC_LGUI,                                                        KC_0, KC_DOT,
                                               ADDDD,   ____,    ____, ____,
                                               ____,    ____,    ____, ____,
                                               ____,    ____,    ____, ____
),
[_LOWER] = LAYOUT(
    KC_ESC,  KC_LCTL, KC_DELT, KC_F1, KC_F2,                           KC_F3,  KC_F4,  KC_MINS, KC_SLSH, KC_BSPC ,
    KC_LSFT, KC_TAB,  KC_PGUP, KC_F5, KC_F6,                           KC_F7,  KC_F8,  KC_HOME, KC_LALT, KC_ENT  ,
    KC_CLCK, KC_SLCK, KC_PGDN, KC_F9, KC_F10,                          KC_F11, KC_F12, KC_END,  KC_INS,  KC_SLSH ,
             KC_INS,  KC_LGUI,                                                         KC_APP,  ____,
                                             ____, ____,  ____, ADDDD,
                                             ____, ____,  ____, ____,
                                             ____, ____,  ____, ____
),
[_ADJUST] = LAYOUT(
    ____,    EXPLORER, KC_UP,   PREVTAB, PREVWIN,                         NEXTWIN, NEXTTAB, ____,    ____, LOCKGUI,
    TASKMGR, KC_LEFT,  KC_DOWN, KC_RGHT, ____,                            ____,    ____,    KC_LGUI, ____, CALTDEL,
    ____,    CLOSEGUI, ____,    ____,    RESET,                           ____,    ____,    ____,    ____, ____,
             ____,     ____,                                                                ____,    ____,
                                                ____, ____,  ____, ____,
                                                ____, ____,  ____, ____,
                                                ____, ____,  ____, ____
),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
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
