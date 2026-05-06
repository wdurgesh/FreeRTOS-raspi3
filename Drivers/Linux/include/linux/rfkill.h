/* Minimal dependency-free dummy linux/rfkill.h
 *
 * Purpose: compilation-only stub for userland/test builds that include
 * <linux/rfkill.h>. No libc or kernel headers are required.
 *
 * This file provides a small, safe subset of the real rfkill API so
 * code can compile. It does NOT implement kernel semantics, locking,
 * device registration, or real hardware control.
 */

#ifndef _LINUX_RFKILL_H
#define _LINUX_RFKILL_H


#endif /* _LINUX_RFKILL_H */

