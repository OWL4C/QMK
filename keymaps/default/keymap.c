// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _BASE 0
#define _STENO 1
#define _STENO_OVER 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11,  KC_F12, // FIVE X SIX MATRIX
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,   KC_0,  KC_BSPC,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT,                                       // DOUBLE THUMBFAN
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,    KC_BSPC,  KC_ENT, KC_SPC,
                                      //`--------------------------'  `--------------------------'
                                          KC_LGUI,                                        KC_RALT  // THUMB EXTRA
                                      //`--------------------------'  `--------------------------'

  ),

};


const uint16_t PROGMEM switch_combo1[] = {KC_A, KC_Q, COMBO_END};
const uint16_t PROGMEM switch_combo2[] = {KC_SPC, KC_BSPC, COMBO_END};
const uint16_t PROGMEM switch_combo3[] = {KC_TAB, KC_ENT, COMBO_END};
const uint16_t PROGMEM bootloader[] = {STN_ST1, STN_ST2, STN_ST3, STN_ST4, COMBO_END};
combo_t key_combos[] = {
    COMBO(switch_combo1, TG(_STENO)),
    COMBO(switch_combo2, TG(_STENO_OVER)),
    COMBO(switch_combo3, TG(_STENO_OVER)),
    COMBO(bootloader, QK_BOOT),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
