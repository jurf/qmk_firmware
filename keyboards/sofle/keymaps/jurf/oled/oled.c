// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>

#include "oled.h"

// uint8_t render_logo(const uint8_t col) {
//     uint16_t logo_row_size = sizeof(IMG_LOGO) / oled_max_lines();
//     for (uint8_t line = 0; line < oled_max_lines(); line++) {
//         oled_set_cursor(col, line);
//         oled_write_raw_P(IMG_LOGO + line * logo_row_size, logo_row_size);
//     }
//     return col + (logo_row_size / OLED_FONT_WIDTH);
// }

uint8_t render_space(const uint8_t col, const uint8_t width, const bool invert) {
    for (uint8_t x = 0; x < width; x++) {
        for (uint8_t line = 0; line < oled_max_lines(); line++) {
            oled_set_cursor(col + x, line);
            oled_write_char(IMG_BLANK, invert);
        }
    }
    return col + width;
}
uint8_t render_image(const uint8_t col, const uint8_t line, const uint8_t width, const uint8_t height, const char index, const bool invert) {
    for (uint8_t y = 0; y < height; y++) {
        oled_set_cursor(col, line + y);
        for (uint8_t x = 0; x < width; x++) {
            oled_write_char(index + y * OLED_SPRITE_WIDTH + x, invert);
        }
    }
    return col + width;
}

uint8_t render_image_P(const uint8_t col, const uint8_t line, const uint8_t width, const uint8_t height, const char* index, const bool invert) {
    return render_image(col, line, width, height, pgm_read_byte(index), invert);
}

uint8_t render_mod_status(const uint8_t col, const uint8_t modifiers) {
    const bool gui   = modifiers & MOD_MASK_GUI;
    const bool alt   = modifiers & MOD_MASK_ALT;
    const bool shift = modifiers & MOD_MASK_SHIFT || is_caps_word_on();
    const bool ctrl  = modifiers & MOD_MASK_CTRL;

    uint8_t x = col;
    uint8_t y = 0;

    x = render_image_P(x, y, 2, 2, &IMG_MOD_ALT[alt], false);
    x = render_image_P(x, y, 1, 2, &IMG_MOD_GAPS[alt][shift], false);
    x = render_image_P(x, y, 2, 2, &IMG_MOD_SHIFT[shift], false);

    x = col;
    y = 2;

    x = render_image_P(x, y, 2, 2, &IMG_MOD_GUI[gui], false);
    x = render_image_P(x, y, 1, 2, &IMG_MOD_GAPS[gui][ctrl], false);
    x = render_image_P(x, y, 2, 2, &IMG_MOD_CTRL[ctrl], false);
    return x;
}

uint8_t render_status(uint8_t col) {
    const uint8_t current_layer = get_highest_layer(default_layer_state | layer_state);
    const uint8_t default_layer = get_highest_layer(default_layer_state);

    const bool is_on_this_half = (current_layer == U_BUTTON                                                      // Both sides
                                  || (!is_keyboard_left() && current_layer >= U_NAV && current_layer <= U_MEDIA) // Right side
                                  || (is_keyboard_left() && current_layer >= U_NUM)                              // Left side
    );

    const uint8_t layer            = is_on_this_half ? current_layer : default_layer;
    const bool    is_default_layer = layer == default_layer;

    // uint8_t col = oled_max_chars() - (IMG_BUBBLE_WIDTH * 2) - (enc0_mode * 3);

    // Padlock
    const bool is_locked = is_default_layer && layer > U_BUTTON;
    if (is_locked) {
        col = render_image(col, 1, 2, 2, IMG_PADLOCK, false);
    } else {
        col = render_space(col, 2, false);
    }

    // Layer
    if (is_on_this_half) {
        col = render_image(col, 0, 1, oled_max_lines(), IMG_BUBBLE_TOP, false);
    } else {
        col = render_space(col, 1, false);
    }
    col = render_image_P(col, 0, IMG_LAYER_WIDTH, oled_max_lines(), &IMG_LAYERS[layer], is_on_this_half);

    // Encoder
    if (enc0_mode) {
        if (is_default_layer) {
            col = render_image(col, 0, 1, oled_max_lines(), IMG_BUBBLE_TOP, false);
        } else {
            col = render_space(col, 1, !is_on_this_half);
        }
        col = render_image(col, 0, 2, oled_max_lines(), IMG_ENC_MODE, false);
    } else {
        col = render_space(col, 3, false);
    }

    return col;
}

bool oled_task_user(void) {
    uint8_t col = 0;
    // col = render_logo(col);
    // col = render_space(col, 2, false);
    col = render_mod_status(col, get_mods());
    col = render_space(col, 2, false);
    col = render_status(col);
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}
