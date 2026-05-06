/* Minimal dependency-free dummy linux/netlink.h
 *
 * Purpose: compilation-only stub for userland/test builds that include
 * <linux/netlink.h> without pulling in kernel headers or libc.
 *
 * This header intentionally avoids dynamic allocation and libc calls.
 * It provides a small set of types, constants, and inline helpers commonly
 * referenced by code that interacts with netlink. It is NOT suitable for
 * building real kernel modules or for production networking code.
 */

#ifndef _LINUX_NETLINK_H
#define _LINUX_NETLINK_H


#endif /* _LINUX_NETLINK_H */

