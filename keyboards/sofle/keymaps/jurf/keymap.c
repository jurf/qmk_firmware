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
#ifdef TAP_DANCE_ENABLE
#    include "features/tap_dance.inc"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [U_GAME] = LAYOUT(
        TD(TD_GRV),        KC_1,              KC_2,              KC_3,              KC_4,              KC_5,                                                    KC_6,              KC_7,              KC_8,              KC_9,              KC_0,                 DF(U_BASE),
        KC_T,              KC_TAB,            KC_Q,              KC_W,              KC_E,              KC_R,                                                    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 KC_LBRC,
        KC_G,              KC_LCTL,           KC_A,              KC_S,              KC_D,              KC_F,                                                    KC_H,              KC_J,              KC_K,              KC_L,              KC_SCLN,              KC_QUOT,
        KC_B,              KC_LSFT,           KC_Z,              KC_X,              KC_C,              KC_V,              KC_MPLY,           KC_MPLY,           KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,              KC_RBRC,
                                              KC_LGUI,           KC_LALT,           LT(U_FUN,KC_ESC),  KC_SPC,            SH_T(KC_ENT),      KC_ENT,            LT(U_BASE,KC_BSPC),KC_DEL,            KC_EQL,            KC_BSLS
    ),
    // [U_BASE] = LAYOUT(
    //     DF(U_MACRO),       EU_OACU,           EU_LCAR,           EU_SCAR,           EU_CCAR,           EU_TCAR,                                                 EU_ZCAR,           EU_YACU,           EU_AACU,           EU_IACU,           EU_EACU,              XXXXXXX,
    //     SH_T(EU_NCAR),     KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                                    KC_J,              KC_L,              KC_U,              KC_Y,              EU_UACU,              SH_T(EU_OCIR),
    //     LM_LCTL,           GUI_T(KC_A),       ALT_T(KC_R),       CTL_T(KC_S),       SFT_T(KC_T),       LT(U_UNIC_R,KC_G),                                       LT(U_UNIC_L,KC_M), SFT_T(KC_N),       CTL_T(KC_E),       ALT_T(KC_I),       GUI_T(KC_O),          CTL_T(KC_QUOT),
    //     LM_LSFT,           LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      LT(0,KC_C),        LT(0,KC_D),        LT(0,KC_V),        KC_ENC0,           KC_MPLY,           KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH), SFT_T(EU_ADIA),
    //                                           LM_LGUI,           LM_LALT,           LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  KC_LEFT,           KC_RIGHT
    // ),
    [U_BASE] = LAYOUT(
        DF(U_MACRO),       EU_OACU,           EU_LCAR,           EU_SCAR,           EU_CCAR,           EU_TCAR,                                                 EU_ZCAR,           EU_YACU,           EU_AACU,           EU_IACU,           EU_EACU,              XXXXXXX,
        SH_T(EU_NCAR),     KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                                    KC_J,              KC_L,              KC_U,              KC_Y,              EU_UACU,              SH_T(EU_OCIR),
        LM_LCTL,           GUI_T(KC_A),       ALT_T(KC_R),       CTL_T(KC_S),       SFT_T(KC_T),       LT(U_UNIC_R,KC_G),                                       LT(U_UNIC_L,KC_M), SFT_T(KC_N),       CTL_T(KC_E),       ALT_T(KC_I),       GUI_T(KC_O),          CTL_T(KC_QUOT),
        LM_LSFT,           LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      LT(0,KC_C),        LT(0,KC_D),        LT(0,KC_V),        KC_ENC0,           KC_MPLY,           KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH), SFT_T(EU_ADIA),
                                              LM_LGUI,           LM_LALT,           LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  KC_LEFT,           KC_RIGHT
    ),
    [U_EXTRA] = LAYOUT(
        DF(U_MACRO),       EU_DCAR,           EU_LCAR,           EU_SCAR,           EU_CCAR,           EU_TCAR,                                                 EU_ZCAR,           EU_YACU,           EU_AACU,           EU_IACU,           EU_EACU,              XXXXXXX,
        EU_ADIA,           KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                                                    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 EU_UACU,
        CTL_T(KC_MINS),    GUI_T(KC_A),       ALT_T(KC_S),       CTL_T(KC_D),       SFT_T(KC_F),       KC_G,                                                    KC_H,              SFT_T(KC_J),       CTL_T(KC_K),       ALT_T(KC_L),       GUI_T(EU_OCIR),       CTL_T(KC_QUOT),
        SFT_T(EU_NCAR),    LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_ENC0,           KC_MPLY,           KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH), SFT_T(EU_OACU),
                                              GUI_T(KC_RIGHT),   ALT_T(KC_RIGHT),   LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  KC_LEFT,           KC_RIGHT
    ),
    [U_TAP_BS] = LAYOUT(
        DF(U_MACRO),       EU_DCAR,           EU_LCAR,           EU_SCAR,           EU_CCAR,           EU_TCAR,                                                 EU_ZCAR,           EU_YACU,           EU_AACU,           EU_IACU,           EU_EACU,              DF(U_BASE),
        KC_TAB,            KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                                    KC_J,              KC_L,              KC_U,              KC_Y,              EU_UACU,              EU_OCIR,
        CTL_T(KC_MINS),    KC_A,              KC_R,              KC_S,              KC_T,              KC_G,                                                    KC_M,              KC_N,              KC_E,              KC_I,              KC_O,                 CTL_T(KC_QUOT),
        SFT_T(EU_DCAR),    KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_ENC0,           KC_MPLY,           KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,              SFT_T(EU_ADIA),
                                              MO(U_MEDIA),       GUI_T(EU_ADIA),    ALT_T(KC_ESC),     LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  ALGR_T(KC_LEFT),   LWIN_T(KC_RIGHT)
    ),
    [U_TAP_XT] = LAYOUT(
        DF(U_MACRO),       EU_OACU,           EU_LCAR,           EU_SCAR,           EU_CCAR,           EU_TCAR,                                                 EU_ZCAR,           EU_YACU,           EU_AACU,           EU_IACU,           EU_EACU,              DF(U_BASE),
        KC_TAB,            KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                                                    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 EU_UACU,
        CTL_T(KC_MINS),    KC_A,              KC_S,              KC_D,              KC_F,              KC_G,                                                    KC_H,              KC_J,              KC_K,              KC_L,              EU_OCIR,              CTL_T(KC_QUOT),
        SFT_T(EU_DCAR),    KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_ENC0,           KC_MPLY,           KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,              SFT_T(EU_OACU),
                                              MO(U_MEDIA),       GUI_T(EU_ADIA),    ALT_T(KC_ESC),     LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  ALGR_T(KC_LEFT),   LWIN_T(KC_RIGHT)
    ),
    [U_VANILL] = LAYOUT(
        KC_GRV,            KC_1,              KC_2,              KC_3,              KC_4,              KC_5,                                                    KC_6,              KC_7,              KC_8,              KC_9,              KC_0,                 KC_MINS,
        KC_TAB,            KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                                                    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 KC_LBRC,
        KC_LCTL,           KC_A,              KC_S,              KC_D,              KC_F,              KC_G,                                                    KC_H,              KC_J,              KC_K,              KC_L,              EU_OCIR,              KC_RCTL,
        KC_LSFT,           KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_ENC0,           KC_MPLY,           KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,              KC_RSFT,
                                              KC_LGUI,           KC_LALT,           KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            KC_RALT,           KC_LGUI
    ),
    [U_MACRO] = LAYOUT(
        TD(U_TD_U_BASE),   KC_LEFT,           KC_UP,             KC_DOWN,           KC_RIGHT,          XXXXXXX,                                                 KC_6,              KC_7,              KC_8,              KC_9,              KC_0,                 DF(U_BASE),
        KC_BSPC,           KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                                                    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 KC_LBRC,
        CTL_T(KC_DEL),     GUI_T(KC_A),       ALT_T(KC_S),       CTL_T(KC_D),       SFT_T(KC_F),       LT(0,KC_G),                                              KC_H,              SFT_T(KC_J),       CTL_T(KC_K),       ALT_T(KC_L),       GUI_T(KC_SCLN),       KC_QUOT,
        SFT_T(KC_ENT),     LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      LT(0,KC_C),        LT(0,KC_V),        LT(0,KC_B),        KC_ENC0,           KC_MPLY,           KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH), KC_RBRC,
                                              LM_LGUI,           LM_LALT,           LT(U_FUN,KC_ESC),  LT(U_NUM,KC_SPC),  SH_T(KC_TAB),      LT(U_MOUSE,KC_ENT),LT(U_NAV,KC_BSPC), LT(U_MEDIA,KC_DEL),KC_LEFT,           KC_RIGHT
    ),
    [U_BUTTON] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,                                                   U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                _______,
        _______,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,                                                    U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              _______,
        _______,           U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             _______,           _______,           U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                _______,
                                              U_NP,              U_NP,              MS_BTN3,           MS_BTN1,           MS_BTN2,           MS_BTN2,           MS_BTN1,           MS_BTN3,           U_NP,              U_NP
    ),
    [U_NAV] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 KC_CAPS,           _______,           _______,           _______,           _______,              _______,
        _______,           TD(U_TD_BOOT),     TD(U_TD_U_TAP_BS), TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   TD(U_TD_U_GAME),                                         U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                KC_TAB,
        _______,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                    CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,              LCTL_T(KC_SPC),
        _______,           U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              _______,           _______,           KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,               LSFT_T(KC_ESC),
                                              U_NP,              U_NP,              U_NA,              KC_HGHL,           U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            KC_LALT,           KC_LGUI
    ),
    [U_MOUSE] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           TD(U_TD_BOOT),     TD(U_TD_U_TAP_BS), TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   TD(U_TD_U_GAME),                                         U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                KC_TAB,
        _______,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                    KC_WWW_FORWARD,    MS_LEFT,           MS_DOWN,           MS_UP,             MS_RGHT,              LCTL_T(KC_SPC),
        _______,           U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              _______,           _______,           KC_WWW_BACK,       MS_WHLL,           MS_WHLD,           MS_WHLU,           MS_WHLR,              LSFT_T(KC_ESC),
                           U_NP,              U_NP,              U_NA,              U_NA,              KC_HGHL,           MS_BTN2,           MS_BTN1,           MS_BTN3,           KC_LALT,           KC_LGUI
    ),
    [U_MEDIA] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           UC_LINX,           UC_WINC,           UC_WIN,            _______,              _______,
        _______,           TD(U_TD_BOOT),     TD(U_TD_U_TAP_BS), TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   TD(U_TD_U_GAME),                                         RM_TOGG,           RM_NEXT,           RM_HUEU,           RM_SATU,           RM_VALU,              RM_SPDU,
        _______,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                    U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,              _______,
        _______,           U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              _______,           _______,           DM_RSTP,           DM_PLY1,           DM_PLY2,           DM_REC1,           DM_REC2,                 _______,
                                              U_NP,              U_NP,              KC_HGHL,           U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP
    ),
    [U_NUM] = LAYOUT(
        _______,           _______,           KC_DOT,            KC_0,              KC_MINS,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        KC_COMMA,          KC_LBRC,           KC_4,              KC_5,              KC_6,              KC_RBRC,                                                 TD(U_TD_U_GAME),   TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP_BS), TD(U_TD_BOOT),        _______,
        LCTL_T(KC_DOT),    KC_SCLN,           KC_1,              KC_2,              KC_3,              KC_EQL,                                                  U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              _______,
        LSFT_T(KC_SLSH),   KC_GRV,            KC_7,              KC_8,              KC_9,              KC_BSLS,           _______,           _______,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,                 _______,
                                              KC_LGUI,           KC_LALT,           KC_DOT,            KC_0,              KC_MINS,           U_NA,              KC_HGHL,           U_NA,              U_NP,              U_NP
    ),
    [U_SYM] = LAYOUT(
        _______,           _______,           KC_LPRN,           KC_RPRN,           KC_UNDS,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        KC_BSPC,           KC_LCBR,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_RCBR,                                                 TD(U_TD_U_GAME),   TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP_BS), TD(U_TD_BOOT),        _______,
        LCTL_T(KC_DEL),    KC_COLN,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PLUS,                                                 U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              _______,
        LSFT_T(KC_ENT),    KC_TILD,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_PIPE,           _______,           _______,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  KC_ALGR,           U_NA,                 _______,
                                              KC_LGUI,           KC_LALT,           KC_LPRN,           KC_RPRN,           KC_UNDS,           KC_HGHL,           U_NA,              U_NA,              U_NP,              U_NP
    ),
    [U_FUN] = LAYOUT(
        _______,           KC_ESC,            KC_APP,            KC_SPC,            KC_TAB,            _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        KC_BSPC,           KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,                                                 TD(U_TD_U_GAME),   TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP_BS), TD(U_TD_BOOT),        _______,
        LCTL_T(KC_DEL),    KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,                                                 U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              _______,
        LSFT_T(KC_ENT),    KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           _______,           _______,           U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,                 _______,
                                              KC_LGUI,           KC_LALT,           KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              KC_HGHL,           U_NP,              U_NP
    ),
    [U_UNIC_R] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           EU_SLQM,           EU_LSQM,           EU_RSQM,           _______,              _______,
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           EU_DLQM,           EU_LDQM,           EU_RDQM,           UC_BULL,              _______,
        _______,           _______,           _______,           _______,           _______,           _______,           _______,           _______,           _______,           UC_ENDS,           UC_EMDS,           EU_ELLS,           UC_MDOT,              _______,
                                              _______,           _______,           _______,           _______,           _______,           _______,           _______,           _______,           _______,           _______
    ),
    [U_UNIC_L] = LAYOUT(
        _______,           _______,           _______,           _______,           _______,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           EU_DIVN,           EU_MULT,           UC_MINS,           KC_PLUS,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           EU_RING,           EU_UMLA,           EU_CARN,           EU_ACUT,           _______,                                                 _______,           _______,           _______,           _______,           _______,              _______,
        _______,           UC_LEFT,           UC_UP,             UC_DOWN,           UC_RGHT,           _______,           _______,           _______,           _______,           _______,           _______,           _______,           _______,              _______,
                                              _______,           _______,           _______,           _______,           _______,           _______,           _______,           _______,           _______,           _______
    ),
    // clang-format on
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Set a long-ish tapping term for tap-dance keys
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        // Pinky keys
        case GUI_T(QK_BASIC)... GUI_T(QK_BASIC_MAX):
        case LT(U_BUTTON, QK_BASIC)... LT(U_BUTTON, QK_BASIC_MAX):
            return 200;
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

bool get_speculative_hold(uint16_t keycode, keyrecord_t * /* record */) {
    const uint8_t mods = mod_config(QK_MOD_TAP_GET_MODS(keycode));
    // Do not eagerly apply mods that have an effect on tap
    return (mods & (MOD_LGUI | MOD_RGUI)) == 0;
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    int layer = get_highest_layer(default_layer_state);
    if (layer != U_BASE && layer != U_EXTRA) {
        // Not a home-row mod layer
        return true;
    }
    if (IS_QK_SWAP_HANDS(tap_hold_keycode)) {
        // Allow same-hand holds for swap hands
        return true;
    }

    if (IS_QK_MOD_TAP(other_keycode) || IS_QK_LAYER_TAP(other_keycode)) {
        if (QK_MOD_TAP_GET_TAP_KEYCODE(other_keycode) > KC_Z) {
            // Allow same-hand holds with non-alpha keys.
            return true;
        }
    }

    switch (tap_hold_keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            switch (QK_MOD_TAP_GET_TAP_KEYCODE(tap_hold_keycode)) {
                // If the tap-hold is on a alpha key, do not allow chord
                case KC_A ... KC_Z:
                case KC_COMMA ... KC_SLASH:
                    // Unless it is the button layer
                    if (IS_QK_LAYER_TAP(tap_hold_keycode) && QK_LAYER_TAP_GET_LAYER(tap_hold_keycode) == U_BUTTON) {
                        return true;
                    }
                    return get_chordal_hold_default(tap_hold_record, other_record);
            }
    }

    return true;
}

// bool process_qwerty_mods(uint16_t keycode, keyrecord_t *record) {
//     if (!IS_QK_MOD_TAP(keycode) || record->tap.count) {
//         return true;
//     }

//     switch (QK_MOD_TAP_GET_TAP_KEYCODE(keycode)) {
//         case KC_A ... KC_Z:
//         case KC_COMMA ... KC_SLASH:
//             return true;
//     }

//     uint8_t mods = QK_MOD_TAP_GET_MODS(keycode);
//     if (record->event.pressed) {
//         layer_on(U_TAP_EX);
//         add_mods(mods);
//     } else {
//         layer_off(U_TAP_EX);
//         del_mods(mods);
//     }
//     return false;
// }
bool process_qwerty_mods(uint16_t keycode, keyrecord_t *record) {
    if (!record->tap.count || !record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case LM_LSFT:
            tap_code16(EU_DCAR);
            break;
        case LM_LCTL:
            tap_code16(KC_MINS);
            break;
        case LM_LALT:
            tap_code16(KC_UP);
            break;
        case LM_LGUI:
            tap_code16(KC_DOWN);
            break;

        case LM_RSFT:
            tap_code16(EU_ADIA);
            break;
        case LM_RCTL:
            tap_code16(KC_QUOT);
            break;

        default:
            return true;
    }
    return false;
}

void process_rgb_keys(uint16_t keycode, keyrecord_t *record) {
    static uint16_t key_timer = 0;
    if (IS_RGB_KEYCODE(keycode)) {
        key_timer = timer_read();
    }

    disable_layer_rgb = timer_elapsed(key_timer) < 5000;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_qwerty_mods(keycode, record)) {
        return false;
    }

    process_rgb_keys(keycode, record);

    // I have yet to decide which of these keys I want to have space on
    if ((keycode == LT(0, KC_C) || keycode == LT(0, KC_G) || keycode == LT(0, KC_V) || keycode == LT(0, KC_D) || keycode == LT(0, KC_B)) && !record->tap.count) {
        if (record->event.pressed) {
            register_code(KC_SPACE);
        } else {
            unregister_code(KC_SPACE);
        }
        return false;
    }

    if (!process_eurkeys(keycode, record)) {
        return false;
    }

#ifdef ENCODER_ENABLE
    if (!handle_encoder_keys(keycode, record)) {
        return false;
    }
#endif

    return true;
}

// Moving this to features/encoder.c causes a compiler error (I guess it wants to be defined after the keymap?)
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // clang-format off
    [U_GAME]   = {ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_BASE]   = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_EXTRA]  = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_TAP_BS] = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_TAP_XT] = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_VANILL] = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_MACRO]  = {ENCODER_CCW_CW(ENC0_CC, ENC0_CW), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [U_BUTTON] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_NAV]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_MOUSE]  = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_MEDIA]  = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_NUM]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_SYM]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_FUN]    = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_UNIC_R] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    [U_UNIC_L] = {ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)},
    // clang-format on
};
#endif

bool is_base_layer(const uint8_t layer) {
    return layer >= U_BASE && layer < U_BUTTON;
}
