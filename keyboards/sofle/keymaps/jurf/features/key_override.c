#include QMK_KEYBOARD_H

#include "quantum/keymap_extras/keymap_slovak.h"

const key_override_t comma_override   = ko_make_basic(MOD_MASK_SHIFT, SK_COMM, ALGR(SK_COMM));
const key_override_t five_override    = ko_make_basic(0b0, SK_TCAR, SK_5);
const key_override_t percent_override = ko_make_basic(MOD_MASK_SHIFT, SK_5, SK_PERC);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_override, &five_override, &percent_override,
    NULL // Null terminate the array of overrides!
};