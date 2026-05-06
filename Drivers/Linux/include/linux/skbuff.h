#ifndef _LINUX_SKBUFF_H
#define _LINUX_SKBUFF_H

#include <stdint.h>
#include <stddef.h>

struct sk_buff {
    void *data;
    unsigned int len;
};

static inline int skb_is_nonlinear(const struct sk_buff *skb)
{
    (void)skb;
    return 0;
}

#ifndef skb_network_offset
static inline unsigned int skb_network_offset(const struct sk_buff *skb)
{
    (void)skb;
    return 0;
}
#endif

static inline unsigned char *skb_network_header(const struct sk_buff *skb)
{
    return (unsigned char *)skb->data;
}

static inline unsigned short get_unaligned_be16(const void *p)
{
    const unsigned char *b = (const unsigned char *)p;
    return ((unsigned short)b[0] << 8) | b[1];
}

#endif
