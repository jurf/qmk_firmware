// Copyright 2023-2024 Juraj Fiala (@jurf)
//
// Based on Miryoku by Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "../keymap.h"

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