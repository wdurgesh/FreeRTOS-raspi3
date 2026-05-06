/* Dummy linux/notifier.h - minimal, dependency-free stub for kernel 7.0.1
 *
 * Purpose: allow compilation of code that includes <linux/notifier.h>
 * in userland/test builds without pulling in kernel headers.
 *
 * This is a compilation-only shim. It provides simple notifier chain
 * types and helpers. It does NOT implement kernel locking, blocking
 * semantics, or real concurrency guarantees and must NOT be used in
 * real kernel/module builds.
 */

#ifndef _LINUX_NOTIFIER_H
#define _LINUX_NOTIFIER_H


#endif /* _LINUX_NOTIFIER_H */

