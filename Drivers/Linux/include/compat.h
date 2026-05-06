#include <linux/skbuff.h>

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint8_t  __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;

typedef int8_t   __s8;
typedef int16_t  __s16;
typedef int32_t  __s32;
typedef int64_t  __s64;

/* ================= errno ================= */

#ifndef _LINUX_ERRNO_H
#define _LINUX_ERRNO_H

#define EPERM           1
#define ENOENT          2
#define ESRCH           3
#define EINTR           4
#define EIO             5
#define ENXIO           6
#define E2BIG           7
#define ENOEXEC         8
#define EBADF           9
#define ECHILD         10
#define EAGAIN         11
#define ENOMEM         12
#define EACCES         13
#define EFAULT         14
#define ENOTBLK        15
#define EBUSY          16
#define EEXIST         17
#define EXDEV          18
#define ENODEV         19
#define ENOTDIR        20
#define EISDIR         21
#define EINVAL         22
#define ENFILE         23
#define EMFILE         24
#define ENOTTY         25
#define ETXTBSY        26
#define EFBIG          27
#define ENOSPC         28
#define ESPIPE         29
#define EROFS          30
#define EMLINK         31
#define EPIPE          32
#define EDOM           33
#define ERANGE         34

#define EOPNOTSUPP     95

#endif

/* ================= misc macros ================= */

#define __acquires(x)
#define __releases(x)

#define DEFINE_GUARD(name, type, lock, unlock)

#ifndef struct_group
#define struct_group(NAME, MEMBERS...) MEMBERS
#endif

#ifndef offsetofend
#define offsetofend(TYPE, MEMBER) \
    (offsetof(TYPE, MEMBER) + sizeof(((TYPE *)0)->MEMBER))
#endif

#ifndef DIV_ROUND_UP
#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#endif

#ifndef typeof
#define typeof __typeof__
#endif

#ifndef likely
#define likely(x)   __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif

/* ================= byte order ================= */

#ifndef _LINUX_BYTEORDER_H
#define _LINUX_BYTEORDER_H

#define cpu_to_le16(x) (x)
#define le16_to_cpu(x) (x)

#define cpu_to_le32(x) (x)
#define le32_to_cpu(x) (x)

#define cpu_to_le64(x) (x)
#define le64_to_cpu(x) (x)

#endif

#ifndef DECLARE_FLEX_ARRAY
#define DECLARE_FLEX_ARRAY(type, name) type name[0]
#endif

/* ================= bits ================= */

#ifndef _LINUX_BITS_H
#define _LINUX_BITS_H

#define GENMASK(h, l) \
    (((~0ULL) << (l)) & (~0ULL >> (63 - (h))))

#endif

/* ================= annotations ================= */

#define __force
#define __iftd
#define __user
#define __iomem
#define __rcu
#define __counted_by(x)

/* ================= config ================= */

#define IS_ENABLED(x) (0)

/* ================= debug ================= */

#undef WARN_ON
#define WARN_ON(x) ((void)(x), (x))

/* ================= helpers ================= */

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

/* ================= constants ================= */

#define ETHTOOL_FWVERS_LEN 32

/* ================= bit helpers ================= */

#ifndef hweight8
static inline unsigned int hweight8(unsigned int w)
{
    w = w - ((w >> 1) & 0x55);
    w = (w & 0x33) + ((w >> 2) & 0x33);
    return (w + (w >> 4)) & 0x0F;
}
#endif

static inline unsigned char u8_get_bits(unsigned char v, unsigned char mask)
{
    return v & mask;
}

#ifndef hweight16
static inline unsigned int hweight16(unsigned int w)
{
    w = w - ((w >> 1) & 0x5555);
    w = (w & 0x3333) + ((w >> 2) & 0x3333);
    w = (w + (w >> 4)) & 0x0F0F;
    return (w + (w >> 8)) & 0x00FF;
}
#endif

#ifndef u16_get_bits
static inline unsigned short u16_get_bits(unsigned short v, unsigned short mask)
{
    return v & mask;
}
#endif

#ifndef get_unaligned_le16
static inline unsigned short get_unaligned_le16(const void *p)
{
    const unsigned char *b = (const unsigned char *)p;
    return (unsigned short)(b[0] | (b[1] << 8));
}
#endif

/* ================= time / timer constants ================= */

#define CLOCK_BOOTTIME 0
#define HRTIMER_MODE_REL 0

typedef long long ktime_t;

/* ================= workqueue ================= */

struct work_struct {
    int dummy;
};

/* ================= locking ================= */

typedef int spinlock_t;

/* ================= networking ================= */

struct net_device {
    unsigned char dev_addr[6];
};

/* ================= kernel struct stubs ================= */

/* RCU */
struct rcu_head {
    void (*func)(struct rcu_head *head);
};

/* Linked list */
struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

/* Mutex */
struct mutex {
    int dummy;
};

/* Device */
struct device {
    int dummy;
    struct device *parent;
};

/* Timer stub */
struct timer_list {
    int dummy;
};

/* High resolution timer stub */
struct hrtimer {
    int dummy;
};

/* Network namespace */
typedef int possible_net_t;

/* Forward declaration to silence warning */
struct regulatory_request;

/* Alignment */
#ifndef __aligned
#define __aligned(x) __attribute__((aligned(x)))
#endif

#ifndef NETDEV_ALIGN
#define NETDEV_ALIGN 32
#endif
