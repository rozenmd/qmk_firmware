// dustypomerleau, Minidox config
#pragma once

#define EE_HANDS
#define USE_SERIAL

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 150
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 400

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#undef UNUSED_PINS

// Pin configuration for github.com/ibnuda/atreus/tree/promicro
#define MATRIX_ROW_PINS { B1, B3, B2, B6 }
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5 }
#define UNUSED_PINS
