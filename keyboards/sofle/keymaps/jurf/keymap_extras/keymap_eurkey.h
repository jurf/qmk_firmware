// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

#define EU_YACU RALT(KC_R)    // ý
#define EU_AACU RALT(KC_X)    // á
#define EU_IACU RALT(KC_B)    // í
#define EU_EACU RALT(KC_G)    // é
#define EU_UACU RALT(KC_J)    // ú
#define EU_OACU RALT(KC_DOT)  // ó
#define EU_ADIA RALT(KC_A)    // ä
#define EU_ACUT RALT(KC_QUOT) // Acute (dead)
#define EU_CARN S(RALT(KC_6)) // Caron (dead)

#define EU_MULT RALT(KC_EQL) //
#define EU_DIVN S(RALT(KC_EQL))

#define EU_SLQM S(RALT(KC_8)) // Single Low-9 Quotation Mark (‚)
#define EU_LSQM S(RALT(KC_9)) // Left Single Quotation Mark (‘)
#define EU_RSQM S(RALT(KC_0)) // Right Single Quotation Mark (’)

#define EU_APPO EU_RSQM // Curly appostrophe (’)

#define EU_DLQM RALT(KC_8) // Double Low-9 Quotation Mark („)
#define EU_LDQM RALT(KC_9) // Left Double Quotation Mark (“)
#define EU_RDQM RALT(KC_0) // Right Double Quotation Mark (”)

#define EU_ENDS RALT(KC_MINS)    // En Dash (–)
#define EU_EMDS S(RALT(KC_MINS)) // Em Dash (—)

#define EU_MDOT S(RALT(KC_SCLN)) // Middle Dot (·)
#define EU_ELLS S(RALT(KC_SLSH)) // Horizontal Ellipsis (…)

bool handle_eurkeys(uint16_t keycode, keyrecord_t *record);