// Copyright 2023-2024 Juraj Fiala (@jurf)
//
// Based on Miryoku by Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap.h"
#include "keymap_extras/keymap_eurkey.h"
#ifdef ENCODER_ENABLE
#    include "features/encoder.h"
#endif
#ifdef RGB_MATRIX_ENABLE
#    include "rgb/rgb.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [U_GAME] = LAYOUT(
        KC_GRV,            KC_1,              KC_2,              KC_3,              KC_4,              KC_5,                                                    KC_6,              KC_7,              KC_8,              KC_9,              KC_0,                 DF(U_BASE),
        KC_T,              KC_TAB,            KC_Q,              KC_W,              KC_E,              KC_R,                                                    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 KC_LBRC,
        KC_G,              KC_LCTL,           KC_A,              KC_S,              KC_D,              KC_F,                                                    KC_H,              KC_J,              KC_K,              KC_L,              KC_SCLN,              KC_QUOT,
        KC_B,              KC_LSFT,           KC_Z,              KC_X,              KC_C,              KC_V,              KC_MPLY,           KC_ENC0,           KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,              KC_EQL,
                                              TD(U_TD_U_BASE),   KC_LALT,           LT(U_FUN,KC_ESC),  KC_SPC,            KC_LGUI,           KC_ENT,            LT(U_BASE,KC_BSPC),KC_DEL,            KC_LEFT,           KC_RIGHT
    ),
    [U_BASE] = LAYOUT(
        DF(U_1HAND),       EU_DCAR,           EU_LCAR,           EU_SCAR,           EU_CCAR,           EU_TCAR,                                                 EU_ZCAR,           EU_YACU,           EU_AACU,           EU_IACU,           EU_EACU,              XXXXXXX,
        EU_ADIA,           KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                                    KC_J,              KC_L,              KC_U,              KC_Y,              EU_OCIR,              EU_UACU,
        CTL_T(KC_MINS),    GUI_T(KC_A),       ALT_T(KC_R),       CTL_T(KC_S),       SFT_T(KC_T),       LT(0,KC_G),                                              KC_M,              SFT_T(KC_N),       CTL_T(KC_E),       ALT_T(KC_I),       GUI_T(KC_O),          CTL_T(KC_QUOT),
        SFT_T(EU_NCAR),    LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      LT(0,KC_C),        LT(0,KC_D),        LT(0,KC_V),        KC_ENC0,           KC_MPLY,           KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH), SFT_T(EU_OACU),
                                              GUI_T(KC_RIGHT),   ALT_T(KC_RIGHT),   LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  KC_LEFT,           KC_RIGHT
    ),
    [U_EXTRA] = LAYOUT(
        DF(U_1HAND),       EU_DCAR,           EU_LCAR,           EU_SCAR,           EU_CCAR,           EU_TCAR,                                                 EU_ZCAR,           EU_YACU,           EU_AACU,           EU_IACU,           EU_EACU,              XXXXXXX,
        EU_ADIA,           KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                                                    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 EU_UACU,
        CTL_T(KC_MINS),    GUI_T(KC_A),       ALT_T(KC_S),       CTL_T(KC_D),       SFT_T(KC_F),       KC_G,                                                    KC_H,              SFT_T(KC_J),       CTL_T(KC_K),       ALT_T(KC_L),       GUI_T(EU_OCIR),       CTL_T(KC_QUOT),
        SFT_T(EU_NCAR),    LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_ENC0,           KC_MPLY,           KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH), SFT_T(EU_OACU),
                                              GUI_T(KC_RIGHT),   ALT_T(KC_RIGHT),   LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  KC_LEFT,           KC_RIGHT
    ),
    [U_TAP] = LAYOUT(
        DF(U_1HAND),       EU_DCAR,           EU_LCAR,           EU_SCAR,           EU_CCAR,           EU_TCAR,                                                 EU_ZCAR,           EU_YACU,           EU_AACU,           EU_IACU,           EU_EACU,              DF(U_BASE),
        EU_ADIA,           KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                                    KC_J,              KC_L,              KC_U,              KC_Y,              EU_OCIR,              EU_UACU,
        CTL_T(KC_MINS),    KC_A,              KC_R,              KC_S,              KC_T,              KC_G,                                                    KC_M,              KC_N,              KC_E,              KC_I,              KC_O,                 CTL_T(KC_QUOT),
        SFT_T(EU_NCAR),    KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_ENC0,           KC_MPLY,           KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,              SFT_T(EU_OACU),
                                              GUI_T(KC_RIGHT),   ALT_T(KC_RIGHT),   LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  KC_LEFT,           KC_RIGHT
    ),
    [U_1HAND] = LAYOUT(
        XXXXXXX,           KC_LEFT,           KC_UP,             KC_DOWN,           KC_RIGHT,          XXXXXXX,                                                 KC_6,              KC_7,              KC_8,              KC_9,              KC_0,                 DF(U_BASE),
        KC_DEL,            KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                                                    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 KC_LBRC,
        CTL_T(KC_BSPC),    GUI_T(KC_A),       ALT_T(KC_S),       CTL_T(KC_D),       SFT_T(KC_F),       LT(0,KC_G),                                              KC_H,              SFT_T(KC_J),       CTL_T(KC_K),       ALT_T(KC_L),       GUI_T(KC_SCLN),       KC_QUOT,
        SFT_T(KC_ENT),     LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      LT(0,KC_C),        LT(0,KC_V),        LT(0,KC_B),        KC_ENC0,           KC_MPLY,           KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH), KC_RBRC,
                                              GUI_T(KC_RIGHT),   ALT_T(KC_RIGHT),   LT(U_FUN,KC_ESC),  LT(U_NUM,KC_SPC),  LT(U_SYM,KC_TAB),  LT(U_MOUSE,KC_ENT),LT(U_NAV,KC_BSPC), LT(U_MEDIA,KC_DEL),KC_LEFT,           KC_RIGHT
    ),
    [U_BUTTON] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,                                                   U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                _______,
        _______,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,                                                    U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              _______,
        _______,           U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             _______,           _______,           U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                _______,
                                              U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
    ),
    [U_NAV] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 KC_CAPS,           _______,           _______,           _______,           _______,              _______,
        _______,           TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   TD(U_TD_U_GAME),                                         U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                _______,
        _______,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                    CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,              _______,
        _______,           U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              _______,           _______,           KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,               _______,
                                              U_NP,              U_NP,              U_NA,              KC_HGHL,           U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP
    ),
    [U_MOUSE] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   TD(U_TD_U_GAME),                                         U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                _______,
        _______,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                    KC_WWW_FORWARD,    KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,              _______,
        _______,           U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              _______,           _______,           KC_WWW_BACK,       KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,              _______,
                                              U_NP,              U_NP,              U_NA,              U_NA,              KC_HGHL,           KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
    ),
    [U_MEDIA] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   TD(U_TD_U_GAME),                                         RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,              RGB_SPI,
        _______,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                    U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,              _______,
        _______,           U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              _______,           _______,           OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,                 _______,
                                              U_NP,              U_NP,              KC_HGHL,           U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP
    ),
    [U_NUM] = LAYOUT(
        _______,           EU_MDOT,           EU_DLQM,           EU_LDQM,           EU_RDQM,           EU_MULT,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        EU_ENDS,           KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,                                                 TD(U_TD_U_GAME),   TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),        _______,
        KC_MINS,           KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,                                                  U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              _______,
        EU_ELLS,           KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           _______,           _______,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,                 _______,
                                              _______,           KC_0,              KC_DOT,            KC_0,              EU_ACUT,           U_NA,              KC_HGHL,           U_NA,              U_NP,              U_NP
    ),
    [U_SYM] = LAYOUT(
        _______,           UC_BULL,           EU_SLQM,           EU_LSQM,           EU_RSQM,           EU_DIVN,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        EU_EMDS,           KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,                                                 TD(U_TD_U_GAME),   TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),        _______,
        KC_UNDS,           KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,                                                 U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              _______,
        _______,           KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           _______,           _______,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  KC_ALGR,           U_NA,                 _______,
                                              _______,           KC_RPRN,           KC_LPRN,           KC_RPRN,           EU_CARN,           KC_HGHL,           U_NA,              U_NA,              U_NP,              U_NP
    ),
    [U_FUN] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,                                                 TD(U_TD_U_GAME),   TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),        _______,
        _______,           KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,                                                 U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              _______,
        _______,           KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           _______,           _______,           U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,                 _______,
                                              KC_ESC,            KC_APP,            KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              KC_HGHL,           U_NP,              U_NP
    ),
    // clang-format on
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Set a long-ish tapping term for tap-dance keys
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        // Colemak-DH
        case GUI_T(KC_A):
        case GUI_T(KC_O):
        case LT(U_BUTTON, KC_Z):
        case LT(U_BUTTON, KC_SLSH):
        // Qwerty
        case GUI_T(KC_SCLN):
        case GUI_T(EU_OCIR):
            return 240;
        default:
            return TAPPING_TERM;
    }
}

void keyboard_post_init_user(void) {
    // The gaming layer is the first one, so that it is possible to use the
    // base layer from it for typing
    default_layer_set((layer_state_t)1 << U_BASE);

#ifdef RGB_MATRIX_ENABLE
    override_led_flags();
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // I have yet to decide which of these keys I want to have space on
    if ((keycode == LT(0, KC_C) || keycode == LT(0, KC_G) || keycode == LT(0, KC_V) || keycode == LT(0, KC_D) || keycode == LT(0, KC_B)) && !record->tap.count) {
        if (record->event.pressed) {
            register_code(KC_SPACE);
        } else {
            unregister_code(KC_SPACE);
        }
        return false;
    }

    if (!handle_eurkeys(keycode, record)) {
        return false;
    }

#ifdef ENCODER_ENABLE
    if (!handle_encoder_keys(keycode, record)) {
        return false;
    }
#endif

    return true;
}

// Tap dances
void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

#define MIRYOKU_X(LAYER, STRING)                                        \
    void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
        if (state->count == 2) {                                        \
            default_layer_set((layer_state_t)1 << U_##LAYER);           \
        }                                                               \
    }
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {[U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
                                          MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

// Moving this to features/encoder.c causes a compiler error (I guess it wants to be defined after the keymap?)
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // clang-format off
    [U_GAME]   = {ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_BASE]   = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_EXTRA]  = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_TAP]    = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_1HAND]  = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_BUTTON] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_NAV]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_MOUSE]  = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_MEDIA]  = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_NUM]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_SYM]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_FUN]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    // clang-format on
};
#endif

bool is_base_layer(const uint8_t layer) {
    return layer >= U_BASE && layer < U_BUTTON;
}