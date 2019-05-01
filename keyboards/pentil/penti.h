#include QMK_KEYBOARD_H
#include "keymap.h"

// See if a given chord is pressed.
// P will return
// PJ will continue processing, removing the found chord
#define P(chord, act)  if (cChord == (chord)) { act; return true; }
#define PJ(chord, act) if ((cChord & (chord)) == (chord)) { cChord ^= chord; act; }

// All Steno Codes
// Shift to internal representation
#define PENT(n) (1L << n)

enum ORDER {
            PTHM = 0, PIDX, PMDL, PRNG, PPNK
};

#define THUMB  PENT(PTHM)
#define INDEX  PENT(PIDX)
#define MIDDLE PENT(PMDL)
#define RING   PENT(PRNG)
#define PINKY  PENT(PPNK)

/* `current_chord` is a bitfield that represents the current chord.
 * by itself, it won't tell you anything except that it is just an 32bit int.
 * but when you're using it with `PENT` and bitwise operator `|`, you will
 * get something meaningful.
 * for example, by pressing `INDEX`, `MIDDLE`, and `RING` at the same time,
 * we are going to process it using the following step:
 * 1. for each thing, we are process them using `PENT`.
 *    - `INDEX`  -> 1 bitshifted to the left by `PIDX` (1) -> 0010 -> 2.
 *    - `MIDDLE` -> 1 bitshifted to the left by `PMDL` (2) -> 0100 -> 4.
 *    - `RING`   -> 1 bitshifted to the left by `PRNG` (3) -> 1000 -> 8.
 * 2. apply `OR` bitwise operator to them.
 * 3. the result is 1110 or 14.
 */
uint32_t current_chord = 0;

bool process_qwerty(void);
void send(uint8_t kc);

/*
 * there are four modes:
 * - ALPHA: latin alphabet.
 * - SHIFT: shift-ed alphabet.
 * - PUNCT: punctuations.
 * - DIGIT: numerics.
 * in pentichord, there should be at least 6 or so modes.
 * but considering i'm not strong enough, i will limit myself to four.
 */
enum MODE { ALPHA = 0, SHIFT, PUNCT, DIGIT };
enum MODE currentMode = ALPHA;

void send(uint8_t kc) {
}
