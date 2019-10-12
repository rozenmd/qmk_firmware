/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "../../config.h"

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#define FORCE_NKRO
#define ONESHOT_TIMEOUT 1000
=======
#undef TAPPING_TERM
>>>>>>> keymap iteration.
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

=======
>>>>>>> added sunat
=======
>>>>>>> added sunat
=======
#define TAPPING_TERM 500
=======
#define FORCE_NKRO
>>>>>>> nkro enabled.

>>>>>>> idk anymore what should be done.
=======
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

>>>>>>> a67ea0b6b9a3864c3bf4f51b3cd897677ee1695a
/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS
