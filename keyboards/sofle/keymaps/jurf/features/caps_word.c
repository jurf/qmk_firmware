// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "../keymap.h"
#include "../keymap_extras/keymap_eurkey.h"

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case EU_YACU: // ý
        case EU_AACU: // á
        case EU_IACU: // í
        case EU_EACU: // é
        case EU_UACU: // ú
        case EU_OACU: // ó
        case EU_ADIA: // ä
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        // Keys input with deadkeys need to have caps word applied manually
        case EU_OCIR ... EU_ZCAR:
        // So do 16-bit mod-taps
        case GUI_T(EU_OCIR):
        case SFT_T(EU_NCAR):
        case SFT_T(EU_OACU):
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}