/* Copyright 2015-2021 Jack Humbert
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

enum planck_layers {
  L0,
  L1,
  L2,
  L3,
  L4,
  L5,
  L6
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// base
[L0] = LAYOUT_planck_grid(
    KC_ESC  , KC_Q    , KC_W    , KC_E    , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I    , KC_O    , KC_P    , KC_BSPC ,
    KC_TAB  , KC_A    , KC_S    , KC_D    , KC_F   , KC_G   , KC_H   , KC_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
    MO(L1)  , KC_LCTL , KC_LGUI , KC_LALT , MO(L2) , KC_SPC , KC_SPC , MO(L3) , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),

// mouse
[L1] = LAYOUT_planck_grid(
    KC_NO   , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
    KC_NO   , KC_BTN1 , KC_BTN2 , KC_BTN3 , KC_NO   , KC_NO   , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , KC_NO   , KC_NO ,
    KC_LSFT , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
    KC_TRNS , KC_RCTL , KC_LGUI , KC_RALT , KC_ACL2 , KC_NO   , KC_NO   , KC_TRNS , KC_LALT , KC_LGUI , KC_LCTL , KC_NO
),

// lower (num)
[L2] = LAYOUT_planck_grid(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC ,
    KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS ,
    KC_TRNS , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_APP  , KC_INS  , KC_PSCR , KC_PAUS , KC_TRNS ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),

// higher (sym)
[L3] = LAYOUT_planck_grid(
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC ,
    KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE ,
    KC_TRNS , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_APP  , KC_INS  , KC_PSCR , KC_PAUS , KC_TRNS ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_HOME , KC_PGDN , KC_PGUP , KC_END
),

// unused
[L4] = LAYOUT_planck_grid(
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
    KC_TRNS , KC_NO   , KC_NO   , KC_NO   , KC_TRNS , KC_NO , KC_NO , KC_TRNS , KC_NO   , KC_NO   , KC_NO   , KC_NO
),

// unused
[L5] = LAYOUT_planck_grid(
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
    KC_TRNS , KC_NO   , KC_NO   , KC_NO   , KC_TRNS , KC_NO , KC_NO , KC_TRNS , KC_NO   , KC_NO   , KC_NO   , KC_NO
),

// adjust
[L6] = LAYOUT_planck_grid(
    KC_TRNS , QK_BOOT , DB_TOGG , RGB_TOG , RGB_MOD , RGB_HUI , RGB_HUD , RGB_SAI , RGB_SAD , RGB_VAI , RGB_VAD , KC_DEL  ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, L1, L2, L4);
  state = update_tri_layer_state(state, L1, L3, L5);
  state = update_tri_layer_state(state, L2, L3, L6);
  return state;
}

