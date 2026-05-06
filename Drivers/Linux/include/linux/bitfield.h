#ifndef _LINUX_BITFIELD_H
#define _LINUX_BITFIELD_H

/* Basic BIT macro */
#ifndef BIT
#define BIT(n) (1U << (n))
#endif

/* Extract bits from value using mask */
#define FIELD_GET(mask, val) \
    (((val) & (mask)) >> __builtin_ctz(mask))

/* For your ieee80211 usage */
#define le16_get_bits(val, mask) \
    FIELD_GET(mask, (val))

#endif
