#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;


#define _BASE    0
#define _QWERTY  1
#define _LOWER   2
#define _RAISE   3
#define _ADJUST  4
#define _TETIKUS 5

#define ____     KC_TRNS

#define ALT_ENT  ALT_T(KC_ENT)
#define CTL_BSPC CTL_T(KC_BSPC)
#define CTL_TAB  CTL_T(KC_TAB)
#define CTL_SLSH CTL_T(KC_SLSH)
#define GUI_TAB  LGUI_T(KC_TAB)
#define SFT_ESC  SFT_T(KC_ESC)

#define AL_E    ALT_T(KC_E)
#define AL_DOT  ALT_T(KC_DOT)
#define AL_T    ALT_T(KC_T)
#define AL_C    ALT_T(KC_C)
#define CT_N    CTL_T(KC_N)
#define CT_R    CTL_T(KC_R)
#define CT_O    CTL_T(KC_O)
#define CT_COMM CTL_T(KC_COMM)
#define GU_H    LGUI_T(KC_H)
#define GU_U    LGUI_T(KC_U)
#define GU_P    LGUI_T(KC_P)
#define GU_G    LGUI_T(KC_G)
#define SH_A    SFT_T(KC_A)
#define SH_S    SFT_T(KC_S)

#define LW_DEL   LT(_LOWER, KC_DELT)
#define LW_BSPC  LT(_LOWER, KC_BSPC)
#define RS_BSPC  LT(_RAISE, KC_BSPC)
#define RS_SPC   LT(_RAISE, KC_SPC)

#define RAISE    MO(_RAISE)
#define LOWER    MO(_LOWER)
#define ADDDD    MO(_ADJUST)

#define ADJUST   TG(_ADJUST)
#define REBASE   TO(_BASE)
#define QWERTY   TO(_QWERTY)

#define NEXTTAB  LCTL(KC_PGDN)
#define PREVTAB  LCTL(KC_PGUP)
#define NEXTWIN  LALT(KC_TAB)
#define PREVWIN  LALT(LSFT(KC_TAB))
#define CALTDEL  LCTL(LALT(KC_DELT))
#define TASKMGR  LCTL(LSFT(KC_ESC))
#define EXPLORER LGUI(KC_E)
#define LOCKGUI  LGUI(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_SCLN, KC_COMM, KC_DOT,  KC_P, KC_Y,                                     KC_F, KC_G, KC_C,    KC_R,   KC_L,
  SH_A,    CT_O,    AL_E,    GU_U, KC_I,                                     KC_D, GU_H, AL_T,    CT_N,   SH_S,
  KC_QUOT, KC_Q,    KC_J,    KC_K, KC_X,                                     KC_B, KC_M, KC_W,    KC_V,   KC_Z,
           KC_TAB,  KC_LGUI,                                                             KC_MINS, KC_SLSH,
                                         LW_BSPC, SFT_ESC,  ALT_ENT, RS_SPC,
                                         CTL_TAB, LW_DEL,   ALT_ENT, CTL_SLSH,
                                         ____,    ____,     ____,    ____
),

[_RAISE] = LAYOUT(
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                             KC_BSLS, KC_7, KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                              KC_EQL,  KC_4, KC_5,   KC_6, KC_ENT ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                             KC_GRV,  KC_1, KC_2,   KC_3, KC_PLUS ,
             KC_INS,  ADJUST,                                                         KC_0, KC_DOT,
                                               ADDDD,   ____,    ____, ____,
                                               ____,    ____,    ____, ____,
                                               ____,    ____,    ____, ____
),
[_LOWER] = LAYOUT(
    KC_ESC,  KC_PSCR, KC_PAUS, KC_F1, KC_F2,                           KC_F3,  KC_F4,  KC_MINS, KC_SLSH, KC_BSPC ,
    KC_LSFT, KC_TAB,  KC_PGUP, KC_F5, KC_F6,                           KC_F7,  KC_F8,  KC_HOME, KC_LALT, KC_ENT  ,
    KC_CLCK, KC_SLCK, KC_PGDN, KC_F9, KC_F10,                          KC_F11, KC_F12, KC_END,  KC_INS,  KC_SLSH ,
             KC_INS,  KC_LGUI,                                                         KC_APP,  ____,
                                             ____, ____,  ____, ADDDD,
                                             ____, ____,  ____, ____,
                                             ____, ____,  ____, ____
),
[_ADJUST] = LAYOUT(
    ____,    EXPLORER, KC_UP,   PREVTAB, PREVWIN,                         NEXTWIN, NEXTTAB, ____,    ____, LOCKGUI,
    TASKMGR, KC_LEFT,  KC_DOWN, KC_RGHT, ____,                            ____,    REBASE,  KC_LGUI, ____, CALTDEL,
    ____,    ____,     ____,    ____,    RESET,                           QWERTY,  KC_MUTE, ____,    ____, ____,
             ____,     ____,                                                                ____,    ____,
                                                ____, ____,  ____, ____,
                                                ____, ____,  ____,   ____,
                                                ____, ____,  ____,   ____
),
[_QWERTY] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I,    KC_O,   KC_P    ,
    KC_A, KC_S, KC_D, KC_F, KC_G,                                      KC_H, KC_J, KC_K,    KC_L,   KC_SCLN ,
    KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH ,
          ____, ADJUST,                                                            KC_MINS, KC_QUOT,
                                 LW_BSPC, SFT_ESC,  ALT_ENT, RS_SPC,
                                 CTL_TAB, LW_DEL,   ALT_ENT, CTL_SLSH,
                                 ____,    ____,     ____,    ____
),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

