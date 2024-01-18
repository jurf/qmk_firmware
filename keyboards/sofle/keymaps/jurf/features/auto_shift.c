// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap.h"
#include "keymap_extras/keymap_eurkey.h"

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EU_ACUT:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case EU_ACUT:
            register_code16((!shifted) ? EU_ACUT : EU_CARN);
            break;
        case KC_DOT:
            if (IS_LAYER_ON(U_NUM)) {
                register_code16((!shifted) ? KC_DOT : KC_LEFT_PAREN);
                break;
            }
            [[fallthrough]];
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case EU_ACUT:
            unregister_code16((!shifted) ? EU_ACUT : EU_CARN);
            break;
        case KC_DOT:
            if (IS_LAYER_ON(U_NUM)) {
                unregister_code16((!shifted) ? KC_DOT : KC_LEFT_PAREN);
                break;
            }
            [[fallthrough]];
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
