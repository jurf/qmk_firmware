// Copyright 2023-2024 Juraj Fiala (@jurf)
//
// Based on Miryoku by Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// SPDX-License-Identifier: GPL-2.0-or-later

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

void td_fn_backtick_U_BASE(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code(KC_GRAVE);
            break;
        case 2:
            default_layer_set((layer_state_t)1 << U_BASE);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_GRV]    = ACTION_TAP_DANCE_FN(td_fn_backtick_U_BASE),
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};