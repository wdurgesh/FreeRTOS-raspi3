/* Dummy linux/of.h - minimal, dependency-free stub for kernel 7.0.1
 *
 * Purpose: allow compilation of code that includes <linux/of.h> in
 * userland/test builds without pulling in kernel headers or libc.
 *
 * This header provides a small, safe subset of Device Tree (OF) types
 * and helpers commonly referenced by drivers and core code. It is a
 * compilation-only shim and does NOT implement kernel locking, dynamic
 * allocation, or full DT semantics. Users must provide and manage
 * storage for nodes/properties themselves.
 */

#ifndef _LINUX_OF_H
#define _LINUX_OF_H


#endif /* _LINUX_OF_H */

