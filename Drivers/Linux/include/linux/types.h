#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <stdint.h>
#include <stdbool.h>

/* Basic integer types */
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

/* Endianness types (used in networking) */
typedef u16 __le16;
typedef u32 __le32;
typedef u64 __le64;

typedef u16 __be16;
typedef u32 __be32;
typedef u64 __be64;

/* Common kernel helpers */
#define __packed __attribute__((packed))
#define __aligned(x) __attribute__((aligned(x)))

#endif /* _LINUX_TYPES_H */
