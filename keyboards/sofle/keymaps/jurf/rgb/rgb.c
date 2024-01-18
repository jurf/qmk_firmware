// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "../keymap.h"
#include "rgb.h"

const RGB RGB_LAYERS_PRIMARY[] PROGMEM = {
    [U_GAME]   = INIT_RGB(RGB_SOLARIZED_BASE03), //
    [U_BUTTON] = INIT_RGB(RGB_SOLARIZED_BASE03), //
};

const RGB RGB_LAYERS_SECONDARY[] PROGMEM = {
    [U_GAME]   = INIT_RGB(RGB_SOLARIZED_RED),     //
    [U_BUTTON] = INIT_RGB(RGB_SOLARIZED_VIOLET),  //
    [U_NAV]    = INIT_RGB(RGB_SOLARIZED_CYAN),    //
    [U_MOUSE]  = INIT_RGB(RGB_SOLARIZED_YELLOW),  //
    [U_MEDIA]  = INIT_RGB(RGB_SOLARIZED_MAGENTA), //
    [U_NUM]    = INIT_RGB(RGB_SOLARIZED_BLUE),    //
    [U_SYM]    = INIT_RGB(RGB_SOLARIZED_GREEN),   //
    [U_FUN]    = INIT_RGB(RGB_SOLARIZED_RED),     //
};

RGB pgm_read_rgb(const RGB *rgb) {
    RGB result;
    memcpy_P(&result, rgb, sizeof(RGB));
    return result;
}

bool filter_base(const uint16_t keycode) {
    switch (keycode) {
        case KC_NO ... KC_TRANSPARENT:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return false;
        default:
            return true;
    }
}

bool filter_wasd(const uint16_t keycode) {
    switch (keycode) {
        case KC_W:
        case KC_A:
        case KC_S:
        case KC_D:
        case LT(U_FUN, KC_ESC):
            return true;
        default:
            return false;
    }
}

bool filter_gaming(const uint16_t keycode) {
    switch (keycode) {
        case KC_LCTL:
        case KC_LSFT:
        case KC_SPACE:
            // case KC_1 ... KC_5:
            return true;
        default:
            return false;
    }
}

void set_accents(const uint8_t led_min, const uint8_t led_max, const uint8_t layer, const RGB rgb, bool (*is_accented)(const uint16_t keycode)) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            const uint8_t index = g_led_config.matrix_co[row][col];
            if (index < led_min || index > led_max || index == NO_LED) {
                continue;
            }
            const uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});
            if (!(*is_accented)(keycode)) {
                continue;
            }
            rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const uint8_t layer            = get_highest_layer(default_layer_state | layer_state);
    const bool    is_default_layer = layer == get_highest_layer(default_layer_state);

    RGB primary;
    RGB secondary;
    if (is_base_layer(layer)) {
        HSV hsv   = rgb_matrix_config.hsv;
        primary   = hsv_to_rgb(hsv);
        hsv.s     = rgb_matrix_config.speed;
        hsv.h     = (hsv.h + (0x100 / 4) * (layer - U_BASE)) % 0x100;
        hsv.v     = 0xFF;
        secondary = hsv_to_rgb(hsv);
    } else {
        primary   = pgm_read_rgb(&(RGB_LAYERS_PRIMARY[layer < U_BUTTON ? layer : U_BUTTON]));
        secondary = pgm_read_rgb(&(RGB_LAYERS_SECONDARY[layer]));
    }

    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
            if (layer > U_BASE) {
                rgb_matrix_set_color(i, primary.r, primary.g, primary.b);
            } else if (layer == U_GAME) {
                rgb_matrix_set_color(i, RGB_OFF);
            }

        } else if (g_led_config.flags[i] & LED_FLAG_INDICATOR) {
            if (is_default_layer && layer != U_BASE) {
                rgb_matrix_set_color(i, secondary.r, secondary.g, secondary.b);
            } else if (is_caps_word_on()) {
                rgb_matrix_set_color(i, RGB_SOLARIZED_YELLOW);
            } else if (get_mods()) {
                rgb_matrix_set_color(i, primary.r, primary.g, primary.b);
            } else {
                rgb_matrix_set_color(i, RGB_OFF);
            }

        } else if (g_led_config.flags[i] & LED_FLAG_MODIFIER) {
            rgb_matrix_set_color(i, secondary.r, secondary.g, secondary.b);

        } else if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
            rgb_matrix_set_color(i, RGB_OFF);
        }
    }

    switch (layer) {
        case U_GAME:
            set_accents(led_min, led_max, layer, primary, filter_gaming);
            set_accents(led_min, led_max, layer, secondary, filter_wasd);
            break;
        case U_BUTTON ... U_FUN:
            set_accents(led_min, led_max, layer, secondary, filter_base);
            break;
    }

    return false;
}

void override_led_flags(void) {
    g_led_config.flags[14] = g_led_config.flags[19] = g_led_config.flags[24] = g_led_config.flags[29] = g_led_config.flags[50] = g_led_config.flags[55] = g_led_config.flags[60] = g_led_config.flags[65] = LED_FLAG_MODIFIER;
}