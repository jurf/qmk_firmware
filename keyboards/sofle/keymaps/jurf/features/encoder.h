// Copyright 2023-2024 Juraj Fiala (@jurf)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <stdbool.h>

#include QMK_KEYBOARD_H

// Left encoder mode
extern bool enc0_mode;

bool handle_encoder_keys(uint16_t keycode, keyrecord_t *record);
