// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "../keymap.h"

#include "keymap_eurkey.h"

#define SS_CARN SS_LSFT(SS_ALGR(SS_TAP(X_6)))
#define SS_CIRC SS_ALGR(SS_TAP(X_6))

// Index from 0
#define LOOKUP(keycode) (keycode - EU_OCIR)

const uint8_t EU_KEYS[] PROGMEM = {
    [LOOKUP(EU_OCIR)] = KC_O, // ô
    [LOOKUP(EU_NCAR)] = KC_N, // ň
    [LOOKUP(EU_DCAR)] = KC_D, // ď
    [LOOKUP(EU_LCAR)] = KC_L, // ľ
    [LOOKUP(EU_SCAR)] = KC_S, // š
    [LOOKUP(EU_CCAR)] = KC_C, // č
    [LOOKUP(EU_TCAR)] = KC_T, // ť
    [LOOKUP(EU_ZCAR)] = KC_Z, // ž
};

bool process_deadkey(uint16_t keycode, keyrecord_t *record) {
    uint8_t next_keycode = pgm_read_byte(&EU_KEYS[LOOKUP(keycode)]);

    if (!record->event.pressed) {
        unregister_code(next_keycode);
        return true;
    }

    swap_hands_off();

    // Prevent mods from being applied to the deadkey
    uint8_t mod_state = get_mods();
    del_mods(MOD_MASK_CSAG);
    switch (keycode) {
        case EU_NCAR ... EU_ZCAR:
            SEND_STRING(SS_CARN);
            break;
        case EU_OCIR:
            SEND_STRING(SS_CIRC);
            break;
    }
    set_mods(mod_state);

#ifdef CAPS_WORD_ENABLE
    // Not sure why, but caps word will not work on these keys automatically,
    // so we need to apply it manually
    if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
#endif

    register_code(next_keycode);

    return true;
}

bool override_tap(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count == 0) {
        // Do not override hold function
        return true;
    }

    if (!record->event.pressed) {
        unregister_code16(keycode);
        return false;
    }

#ifdef CAPS_WORD_ENABLE
    if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
#endif

    register_code16(keycode);

    return false;
}

bool override_tap_deadkey(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count == 0) {
        // Do not override hold function
        return true;
    }
    process_deadkey(keycode, record);
    return false;
}

bool process_eurkeys(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EU_OCIR ... EU_ZCAR:
            return process_deadkey(keycode, record);

        // Mod-taps do not support 16-bit keys; manually set the keycode
        case SFT_T(EU_ADIA):
            return override_tap(EU_ADIA, record);
        case SFT_T(EU_DCAR):
            return override_tap_deadkey(EU_DCAR, record);
        case GUI_T(EU_OCIR):
            return override_tap_deadkey(EU_OCIR, record);
        case SH_T(EU_NCAR):
            return override_tap_deadkey(EU_NCAR, record);
        case SH_T(EU_OCIR):
            return override_tap_deadkey(EU_OCIR, record);

        default:
            return true;
    }
}
