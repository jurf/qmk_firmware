// Copyright 2023-2024 Juraj Fiala (@jurf)
//
// Based on Miryoku by Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#undef TAPPING_TERM
#define TAPPING_TERM 160

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
// Do not wait for tapping term if chord is well-formed
#define PERMISSIVE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA // Cannot be used due to homerow mods
#define NO_AUTO_SHIFT_TAB   // Fixes tabbing in games
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP
// #define RETRO_SHIFT 500

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

#define TAPPING_TERM_PER_KEY
#define TAPPING_TOGGLE 2

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE

#ifdef OLED_ENABLE
#    define OLED_FONT_H "keyboards/sofle/keymaps/jurf/oled/glcndfont.c"
#    define OLED_FONT_END 239
#    define OLED_SPRITE_WIDTH 24
#    define OLED_TIMEOUT 60000 // 60 seconds
#    define OLED_FADE_OUT
#    define OLED_FADE_OUT_INTERVAL 0x0F // max
#    define SPLIT_OLED_ENABLE
#endif

#ifdef RGB_MATRIX_ENABLE
#    define WS2812_DI_PIN D3
#    define RGB_MATRIX_LED_COUNT 72
#    define RGB_MATRIX_SPLIT \
        { 36, 36 }
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 144 // Higher brightness causes the controller to crash (brownout?)
#    define RGB_MATRIX_DEFAULT_SPD 172

#    define ENABLE_RGB_MATRIX_ALPHAS_MODS            // Static dual hue, speed is hue for secondary hue
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN       // Static gradient top to bottom, speed controls how much gradient changes
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right, speed controls how much gradient changes
#    define RGB_MATRIX_BAND_SAT                      // Single hue band fading saturation scrolling left to right
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Full gradient Chevron shapped scrolling left to right
#endif

// Save space
// https://docs.qmk.fm/#/squeezing_avr?id=squeezing-the-most-out-of-avr
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define LAYER_STATE_16BIT
