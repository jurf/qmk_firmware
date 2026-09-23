// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

#define EU_ACUT ALGR(KC_QUOT)    // Acute (dead)
#define EU_CARN S(ALGR(KC_6))    // Caron (dead)
#define EU_UMLA S(ALGR(KC_QUOT)) // Umlaut (dead)
#define EU_RING ALGR(KC_7)       // Ring (dead)

#define EU_YACU ALGR(KC_R)   // ý
#define EU_AACU ALGR(KC_X)   // á
#define EU_IACU ALGR(KC_B)   // í
#define EU_EACU ALGR(KC_G)   // é
#define EU_UACU ALGR(KC_J)   // ú
#define EU_OACU ALGR(KC_DOT) // ó
#define EU_ADIA ALGR(KC_A)   // ä

#define EU_MULT ALGR(KC_EQL)    // Multiplication Sign (×)
#define EU_DIVN S(ALGR(KC_EQL)) // Division Sign (÷)

#define EU_SLQM S(ALGR(KC_8)) // Single Low-9 Quotation Mark (‚)
#define EU_LSQM S(ALGR(KC_9)) // Left Single Quotation Mark (‘)
#define EU_RSQM S(ALGR(KC_0)) // Right Single Quotation Mark (’)

#define EU_APPO EU_RSQM // Curly appostrophe (’)

#define EU_DLQM ALGR(KC_8) // Double Low-9 Quotation Mark („)
#define EU_LDQM ALGR(KC_9) // Left Double Quotation Mark (“)
#define EU_RDQM ALGR(KC_0) // Right Double Quotation Mark (”)

#define EU_ENDS ALGR(KC_MINS)    // En Dash (–)
#define EU_EMDS S(ALGR(KC_MINS)) // Em Dash (—)

#define EU_MDOT S(ALGR(KC_SCLN)) // Middle Dot (·)
#define EU_ELLS S(ALGR(KC_SLSH)) // Horizontal Ellipsis (…)

/**
 * Process keys implemented with EurKEY dead keys.
 */
bool process_eurkeys(uint16_t keycode, keyrecord_t *record);