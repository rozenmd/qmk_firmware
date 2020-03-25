#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _MALTRON 0
#define _LOWER   1
#define _RAISE   2
#define _ADJUST  3

enum custom_keycodes {
  MALTRON = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

enum combos {
  Q_P,
  P_Y,
  Y_C,
  DOT_COMMA,
  COMMA_J,
  J_G,

  L_Z,
  Z_U,
  U_M,
  EX_UNDS,
  UNDS_K,
  K_W,
};

const uint16_t PROGMEM q_p_combo[]       = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM p_y_combo[]        = {KC_P, KC_Y, COMBO_END};
const uint16_t PROGMEM y_c_combo[]        = {KC_Y, KC_C, COMBO_END};
const uint16_t PROGMEM dot_comma_combo[]  = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM comma_j_combo[]    = {KC_COMM, KC_J, COMBO_END};
const uint16_t PROGMEM j_g_combo[]        = {KC_J, KC_G, COMBO_END};

const uint16_t PROGMEM l_z_combo[]        = {KC_L, KC_Z, COMBO_END};
const uint16_t PROGMEM z_u_combo[]        = {KC_Z, KC_U, COMBO_END};
const uint16_t PROGMEM u_m_combo[]        = {KC_U, KC_M, COMBO_END};
const uint16_t PROGMEM ex_unds_combo[]    = {KC_X, KC_UNDS, COMBO_END};
const uint16_t PROGMEM unds_k_combo[]     = {KC_UNDS, KC_K, COMBO_END};
const uint16_t PROGMEM k_w_combo[]        = {KC_K, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [Q_P]       = COMBO(q_p_combo,        KC_TAB),
  [P_Y]       = COMBO(p_y_combo,        KC_QUES),
  [Y_C]       = COMBO(y_c_combo,        KC_UNDS),
  [DOT_COMMA] = COMBO(dot_comma_combo,  KC_ENT),
  [COMMA_J]   = COMBO(comma_j_combo,    LCTL(KC_W)),
  [J_G]       = COMBO(j_g_combo,        KC_DELT),

  [L_Z]       = COMBO(l_z_combo,        KC_BSPC),
  [Z_U]       = COMBO(z_u_combo,        KC_SLSH),
  [U_M]       = COMBO(u_m_combo,        KC_MINS),
  [EX_UNDS]   = COMBO(ex_unds_combo,    KC_ESC),
  [UNDS_K]    = COMBO(unds_k_combo,     KC_APP),
  [K_W]       = COMBO(k_w_combo,        KC_DELT),
};

#define AL_ENT    ALT_T(KC_ENT)
#define SH_BSPC   SFT_T(KC_BSPC)

#define SH_A      RSFT_T(KC_A)
#define SH_R      RSFT_T(KC_R)
#define CT_N      RCTL_T(KC_N)
#define CT_O      RCTL_T(KC_O)
#define AL_I      RALT_T(KC_I)
#define AL_H      RALT_T(KC_H)
#define GU_F      RGUI_T(KC_F)
#define GU_D      RGUI_T(KC_D)

#define LW_E      LT(_LOWER, KC_E)
#define RS_SPC    LT(_RAISE, KC_SPC)

#define ADJUST MO(_ADJUST)

// common shortcuts for windows and linux that i use.
#define NXTTAB LCTL(KC_PGDN)
#define PRVTAB LCTL(KC_PGUP)
#define UPTAB  LCTL(LSFT(KC_PGUP))
#define DNTAB  LCTL(LSFT(KC_PGDN))
#define NXTWIN LALT(KC_TAB)
#define PRVWIN LALT(LSFT(KC_TAB))
#define CALDL  LCTL(LALT(KC_DELT))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define EXPLR  LGUI(KC_E)
#define LCKGUI LGUI(KC_L)
#define CONPST LSFT(KC_INS)
#define CLSGUI LALT(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MALTRON] = LAYOUT( \
        KC_TAB, KC_Q,   KC_P,   KC_Y,   KC_C,   KC_B,                      KC_V,   KC_M,   KC_U,   KC_Z,  KC_L,   KC_BSPC,\
        KC_LCTL,KC_A,   KC_N,   KC_I,   KC_S,   KC_F,                      KC_D,   KC_T,   KC_H,   KC_O,  KC_R,   KC_QUOT,\
        KC_LSFT,KC_COMM,KC_DOT, KC_J,   KC_G,   KC_SCLN,                   KC_SLSH,KC_W,   KC_K,   KC_DOT,KC_MINS,KC_RSFT,\
                                        LW_E,   SH_BSPC,LOWER,     RAISE,  AL_ENT, RS_SPC \
    ),
    [_LOWER] = LAYOUT( \
        KC_ESC, KC_ESC, KC_QUES,KC_UNDS,KC_F1,  KC_F2,                     KC_F3,  KC_F4,  KC_MINS,KC_SLSH,KC_BSPC,KC_BSPC,\
        KC_LCTL,KC_LSFT,KC_TAB, KC_PGUP,KC_F5,  KC_F6,                     KC_F7,  KC_F8,  KC_HOME,KC_LALT,KC_ENT, XXXXXXX,\
        KC_LSFT,KC_CLCK,KC_SLCK,KC_PGDN,KC_F9,  KC_F10,                    KC_F11, KC_F12, KC_END, KC_INS, KC_SLSH,XXXXXXX,\
                                        LW_E,   SH_BSPC,LOWER,     RAISE,  AL_ENT, RS_SPC \
    ),
    [_RAISE] = LAYOUT( \
        KC_ESC, KC_EXLM,KC_AT,  KC_UP,  KC_LCBR,KC_RCBR,                   KC_BSLS,KC_7,   KC_8,   KC_9,   KC_ASTR,KC_BSPC,\
        KC_LCTL,KC_HASH,KC_LEFT,KC_DOWN,KC_RGHT,KC_DLR,                    KC_EQL, KC_4,   KC_5,   KC_6,   KC_0,   XXXXXXX,\
        KC_LSFT,KC_LBRC,KC_RBRC,KC_LPRN,KC_RPRN,KC_AMPR,                   KC_GRV, KC_1,   KC_2,   KC_3,   KC_PLUS,XXXXXXX,\
                                        LW_E,   SH_BSPC,LOWER,     RAISE,  AL_ENT, RS_SPC \
    ),
    [_ADJUST] = LAYOUT( \
        KC_ESC, _______,EXPLR,  KC_UP,  PRVTAB, PRVWIN,                    NXTWIN, NXTTAB, _______,_______,LCKGUI, KC_BSPC,\
        KC_LCTL,TSKMGR, KC_LEFT,KC_DOWN,KC_RGHT,UPTAB,                     DNTAB,  KC_ENT, KC_LGUI,_______,CALDL,  XXXXXXX,\
        KC_LSFT,_______,CLSGUI, _______,CONPST, RESET,                     _______,_______,_______,_______,_______,XXXXXXX,\
                                        LW_E,   SH_BSPC,LOWER,     RAISE,  AL_ENT, RS_SPC \
    ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MALTRON:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_MALTRON);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
  }
  return true;
}
