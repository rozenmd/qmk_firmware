/* Copyright 2020 Ibnu D. Aji
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_7,   KC_8,   KC_9,   KC_ENT,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   \
        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_4,   KC_5,   KC_6,   KC_ENT,       KC_H,   KC_J,   KC_K,   KC_L,   KC_QUOT,\
        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_1,   KC_2,   KC_3,   KC_ENT,       KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,\
        KC_ESC, KC_TAB, KC_LGUI,KC_LSFT,KC_BSPC,    KC_0,   KC_0,   KC_DOT, KC_ENT,       KC_SPC, KC_LALT,KC_MINS,KC_QUOT,KC_ENT
    )
};

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
