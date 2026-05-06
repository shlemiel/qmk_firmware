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

enum custom_keycodes {
    UK_M0 = SAFE_RANGE,
    UK_M1,
    KC_BT1
};

const uint16_t PROGMEM kc_mt[] = {UK_M0, UK_M1, COMBO_END};
combo_t key_combos[] = {
    COMBO(kc_mt, MO(4)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// base
[0] = LAYOUT_planck_grid(
     KC_ESC  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
     KC_TAB  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
     KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
     TG(3)   , UK_M0   , UK_M1   , KC_LCTL , MO(1)   , KC_SPC  , KC_SPC  , MO(2)   , KC_LALT , KC_LGUI , KC_RALT , KC_RCTL
),

// lower (sym)
[1] = LAYOUT_planck_grid(
     KC_ESC  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_BSPC ,
     KC_TAB  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS ,
     KC_TRNS , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_GRV  , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_TRNS ,
     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
),

// higher (special)
[2] = LAYOUT_planck_grid(
     KC_ESC  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_INS  , KC_NO   , KC_APP  , KC_PSCR , KC_NO   , KC_PAUS , KC_BSPC ,
     KC_TAB  , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_DEL  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_NO   , KC_NO   ,
     KC_TRNS , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_NO   , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , KC_NO   , KC_TRNS ,
     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
),

// mouse
[3] = LAYOUT_planck_grid(
     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
     KC_NO   , KC_BTN1 , KC_BTN2 , KC_BTN3 , KC_BTN4 , KC_BTN5 , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , KC_NO   , KC_NO   ,
     KC_TRNS , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_NO   , KC_NO   , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
),

// maintenance
[4] = LAYOUT_planck_grid(
     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_BT1  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , RGB_VAD ,
     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO  
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t bootloader_key_timer = 0;
    static bool bootloader_other_key_recorded = false;
    if(keycode != KC_BT1) { bootloader_other_key_recorded = true; }

    switch (keycode) {
    case KC_BT1:
        if (record->event.pressed) {
            bootloader_key_timer = timer_read();
            bootloader_other_key_recorded = false;
        } else {
            if(!bootloader_other_key_recorded) {
                if(timer_elapsed(bootloader_key_timer) >= 10000) {
                    bootloader_jump();
                }
            }
            bootloader_key_timer = 0;
        }
        break;
    }
    return true;
};
