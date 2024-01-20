// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "../keymap.h"

#include "encoder.h"

bool enc0_mode = false;

bool handle_encoder_keys(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case KC_ENC0:
            enc0_mode = !enc0_mode;
            break;

        case ENC0_CW:
            if (!enc0_mode) {
                tap_code(KC_PGUP);
            } else {
                tap_code16(U_RDO);
            }
            break;

        case ENC0_CC:
            if (!enc0_mode) {
                tap_code(KC_PGDN);
            } else {
                tap_code16(U_UND);
            }
            break;

        default:
            return true;
    }

    return false;
}