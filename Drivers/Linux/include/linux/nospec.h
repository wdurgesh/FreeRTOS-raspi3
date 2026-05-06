/* Minimal dependency-free dummy linux/nospec.h
 *
 * Purpose: provide a small, portable set of nospec helpers so code that
 * includes <linux/nospec.h> will compile outside the kernel. This file
 * contains no libc or kernel dependencies and is intended for
 * compilation/testing only. It does not provide real hardware/speculation
 * mitigation guarantees.
 */

#ifndef _LINUX_NOSPEC_H
#define _LINUX_NOSPEC_H


#endif /* _LINUX_NOSPEC_H */

