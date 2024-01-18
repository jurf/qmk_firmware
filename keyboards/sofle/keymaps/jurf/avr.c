// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Save space
// https://docs.qmk.fm/#/squeezing_avr?id=magic-functions

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}