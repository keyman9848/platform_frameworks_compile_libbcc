/* ===-- fixunsdfsi.c - Implement __fixunsdfsi -----------------------------===
 *
 *                     The LLVM Compiler Infrastructure
 *
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 *
 * ===----------------------------------------------------------------------===
 *
 * This file implements __fixunsdfsi for the compiler_rt library.
 *
 * ===----------------------------------------------------------------------===
 */

#if !defined(__GNUC__) || __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 7) || defined(ARCH_X86)
// ARM gcc >= 4.7 implements this in libgcc
#include "int_lib.h"

/* Returns: convert a to a unsigned int, rounding toward zero.
 *          Negative values all become zero.
 */

/* Assumption: double is a IEEE 64 bit floating point type 
 *             su_int is a 32 bit integral type
 *             value in double is representable in su_int or is negative 
 *                 (no range checking performed)
 */

/* seee eeee eeee mmmm mmmm mmmm mmmm mmmm | mmmm mmmm mmmm mmmm mmmm mmmm mmmm mmmm */

su_int
__fixunsdfsi(double a)
{
    double_bits fb;
    fb.f = a;
    int e = ((fb.u.s.high & 0x7FF00000) >> 20) - 1023;
    if (e < 0 || (fb.u.s.high & 0x80000000))
        return 0;
    return (
                0x80000000u                      |
                ((fb.u.s.high & 0x000FFFFF) << 11) |
                (fb.u.s.low >> 21)
           ) >> (31 - e);
}
#endif
