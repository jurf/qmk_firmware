// Copyright 2023-2024 Juraj Fiala (@jurf)
//
// Based on Miryoku by Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include QMK_KEYBOARD_H

#define SS_EU_CARN SS_RSFT(SS_RALT(SS_TAP(X_6)))
#define SS_EU_CIRC SS_RSFT() SS_ALGR(SS_TAP(X_6))

#define SS_EU_OCIR SS_EU_CIRC "o"
#define SS_EU_NCAR SS_EU_CARN "n"
#define SS_EU_DCAR SS_EU_CARN "d"
#define SS_EU_LCAR SS_EU_CARN "l"
#define SS_EU_SCAR SS_EU_CARN "s"
#define SS_EU_CCAR SS_EU_CARN "c"
#define SS_EU_TCAR SS_EU_CARN "t"
#define SS_EU_ZCAR SS_EU_CARN "z"
