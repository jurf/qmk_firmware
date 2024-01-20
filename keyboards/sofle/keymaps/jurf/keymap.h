// Copyright 2023-2024 Juraj Fiala (@jurf)
//
// Based on Miryoku by Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <stdbool.h>

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_HGHL = SAFE_RANGE, // No-op, just highlight in RGB
#ifdef ENCODER_ENABLE
    KC_ENC0,
    ENC0_CW,
    ENC0_CC,
#endif
    // These require a dead key, so they are implemented as macros
    EU_OCIR, // ô
    EU_NCAR, // ň
    EU_DCAR, // ď
    EU_LCAR, // ľ
    EU_SCAR, // š
    EU_CCAR, // č
    EU_TCAR, // ť
    EU_ZCAR, // ž
};

#define UC_SLQM UC(0x201A) // Single Low-9 Quotation Mark (‚)
#define UC_LSQM UC(0x2018) // Left Single Quotation Mark (‘)
#define UC_RSQM UC(0x2019) // Right Single Quotation Mark (’)

#define UC_DLQM UC(0x201E) // Double Low-9 Quotation Mark („)
#define UC_LDQM UC(0x201C) // Left Double Quotation Mark (“)
#define UC_RDQM UC(0x201D) // Right Double Quotation Mark (”)

#define UC_ENDS UC(0x2013) // En Dash (–)
#define UC_EMDS UC(0x2014) // Em Dash (—)

#define UC_MDOT UC(0x00B7) // Middle Dot (·)
#define UC_BULL UC(0x2022) // Bullet (•)
#define UC_ELLS UC(0x2026) // Horizontal Ellipsis (…)

#if !defined(MIRYOKU_LAYER_LIST)
#    define MIRYOKU_LAYER_LIST  \
        MIRYOKU_X(GAME, 0x90)   \
        MIRYOKU_X(BASE, 0x94)   \
        MIRYOKU_X(EXTRA, 0x98)  \
        MIRYOKU_X(TAP, 0x94)    \
        MIRYOKU_X(1HAND, 0x9c)  \
        MIRYOKU_X(BUTTON, 0xa0) \
        MIRYOKU_X(NAV, 0xa4)    \
        MIRYOKU_X(MOUSE, 0x30)  \
        MIRYOKU_X(MEDIA, 0x34)  \
        MIRYOKU_X(NUM, 0x38)    \
        MIRYOKU_X(SYM, 0x3c)    \
        MIRYOKU_X(FUN, 0x40)
#endif

enum miryoku_layers {
#define MIRYOKU_X(LAYER, STRING) U_##LAYER,
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#define U_RDO C(S(KC_Z))
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

bool is_base_layer(const uint8_t layer);
