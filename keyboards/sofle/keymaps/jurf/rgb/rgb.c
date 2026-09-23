// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "../keymap.h"
#include "rgb.h"

bool disable_layer_rgb = false;

static const HSV HSV_LAYERS_PRIMARY[] PROGMEM = {
    [U_GAME]   = {HSV_SOLARIZED_BASE03}, //
    [U_BUTTON] = {HSV_SOLARIZED_BASE03}, //
};

static const HSV HSV_LAYERS_SECONDARY[] PROGMEM = {
    [U_GAME]   = {HSV_SOLARIZED_RED},     //
    [U_BUTTON] = {HSV_SOLARIZED_VIOLET},  //
    [U_NAV]    = {HSV_SOLARIZED_CYAN},    //
    [U_MOUSE]  = {HSV_SOLARIZED_YELLOW},  //
    [U_MEDIA]  = {HSV_SOLARIZED_MAGENTA}, //
    [U_NUM]    = {HSV_SOLARIZED_BLUE},    //
    [U_SYM]    = {HSV_SOLARIZED_GREEN},   //
    [U_FUN]    = {HSV_SOLARIZED_RED},     //
    [U_UNIC_R] = {HSV_SOLARIZED_ORANGE},  //
    [U_UNIC_L] = {HSV_SOLARIZED_ORANGE},  //
};

static HSV pgm_read_hsv(const HSV *hsv) {
    HSV result;
    memcpy_P(&result, hsv, sizeof(HSV));
    return result;
}

static bool filter_base(const uint16_t keycode) {
    switch (keycode) {
        case KC_NO ... KC_TRANSPARENT:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return false;
        default:
            return true;
    }
}

static bool filter_wasd(const uint16_t keycode) {
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

// bool filter_gaming(const uint16_t keycode) {
//     switch (keycode) {
//         case KC_LCTL:
//         case KC_LSFT:
//         case KC_SPACE:
//             // case KC_1 ... KC_5:
//             return true;
//         default:
//             return false;
//     }
// }

static void set_accents(const uint8_t led_min, const uint8_t led_max, const uint8_t layer, const RGB rgb, bool (*is_accented)(const uint16_t keycode)) {
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

static uint8_t index_to_hue_analogous(const uint8_t index, const uint8_t length, const int8_t offset) {
    // Wrap around base hue
    // int8_t offset = (index < max ? index : index - size) * 0x24;
    // return offset >= 0 ? offset : 0x100 + offset;
    // return (offset % 0x100 + 0x100) % 0x100;
    return ((index % length) + offset) * 0x20;
}

static HSV get_base_layer_accent(const uint8_t index, HSV base_color, uint8_t base_layer) {
    // Create analogous colors
    uint8_t offset = index_to_hue_analogous(index, 5, -base_layer);
    base_color.h   = (base_color.h + offset) % 0xFF;
    // Use speed as saturation
    base_color.s = rgb_matrix_config.speed;
    return base_color;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const uint8_t layer            = get_highest_layer(default_layer_state | (disable_layer_rgb ? 0x0 : layer_state));
    const bool    is_default_layer = layer == get_highest_layer(default_layer_state);

    RGB primary;
    RGB secondary;
    RGB underglow;
    if (is_base_layer(layer)) {
        HSV primary_hsv   = rgb_matrix_config.hsv;
        HSV secondary_hsv = get_base_layer_accent(layer, primary_hsv, U_BASE);
        primary           = hsv_to_rgb(primary_hsv);
        // secondary_hsv.v *= 2;
        primary_hsv.v /= 2;
        underglow = hsv_to_rgb(primary_hsv);
        // Make modifiers shine as bright as possible
        secondary_hsv.v = 0xFF;
        secondary       = hsv_to_rgb(secondary_hsv);
    } else {
        HSV primary_hsv   = pgm_read_hsv(&(HSV_LAYERS_PRIMARY[layer < U_BUTTON ? layer : U_BUTTON]));
        HSV secondary_hsv = pgm_read_hsv(&(HSV_LAYERS_SECONDARY[layer]));
        primary           = hsv_to_rgb(primary_hsv);
        secondary         = hsv_to_rgb(secondary_hsv);
        // Make underglow a little brighter to be able to see it
        secondary_hsv.v *= 2;
        underglow = hsv_to_rgb(secondary_hsv);
    }

    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
            if (layer != U_BASE) {
                rgb_matrix_set_color(i, primary.r, primary.g, primary.b);
            }
            // else if (layer == U_GAME) {
            //     rgb_matrix_set_color(i, RGB_OFF);
            // }

        } else if (g_led_config.flags[i] & LED_FLAG_INDICATOR) {
            if (is_caps_word_on()) {
                rgb_matrix_set_color(i, RGB_SOLARIZED_YELLOW);
            } else if (is_swap_hands_on()) {
                rgb_matrix_set_color(i, RGB_SOLARIZED_BLUE);
            } else if (get_mods()) {
                rgb_matrix_set_color(i, primary.r, primary.g, primary.b);
            } else if (is_default_layer && layer != U_BASE) {
                rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
            } else {
                rgb_matrix_set_color(i, RGB_OFF);
            }

        } else if (g_led_config.flags[i] & LED_FLAG_MODIFIER) {
            if (layer == U_GAME) {
                rgb_matrix_set_color(i, primary.r, primary.g, primary.b);
            } else {
                rgb_matrix_set_color(i, secondary.r, secondary.g, secondary.b);
            }

        } else if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
            if (layer != U_BASE) {
                rgb_matrix_set_color(i, underglow.r, underglow.g, underglow.b);
            }
        }
    }

    switch (layer) {
        case U_GAME:
            // set_accents(led_min, led_max, layer, primary, filter_gaming);
            set_accents(led_min, led_max, layer, secondary, filter_wasd);
            break;
        case U_BUTTON ... U_UNIC_L:
            set_accents(led_min, led_max, layer, secondary, filter_base);
            break;
    }

    return false;
}

void override_led_flags(void) {
    g_led_config.flags[14] = g_led_config.flags[19] = g_led_config.flags[24] = g_led_config.flags[29] = g_led_config.flags[50] = g_led_config.flags[55] = g_led_config.flags[60] = g_led_config.flags[65] = LED_FLAG_MODIFIER;
}
