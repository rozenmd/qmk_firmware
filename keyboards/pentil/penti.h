#include QMK_KEYBOARD_H
#include "mousekey.h"
#include "keymap.h"
#include "keymap_steno.h"

// Bitfield representing the current chord
uint32_t cChord = 0;

// See if a given chord is pressed.
// P will return
// PJ will continue processing, removing the found chord
#define P(chord, act)  if (cChord == (chord)) { act; return true; }
#define PJ(chord, act) if ((cChord & (chord)) == (chord)) { cChord ^= chord; act; }

// All Steno Codes
// Shift to internal representation
#define PENT(n) (1L << n)

enum ORDER = {
              PTHM = 0, PIDX, PMDL, PRNG, PPNK
};

#define THUMB  PENT(PTHM)
#define INDEX  PENT(PIDX)
#define MIDDLE PENT(PMDL)
#define RING   PENT(PRNG)
#define PINKY  PENT(PPNK)

bool processQwerty(void);
