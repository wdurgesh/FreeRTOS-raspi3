#ifndef _LINUX_ETHERDEVICE_H
#define _LINUX_ETHERDEVICE_H

static inline bool is_multicast_ether_addr(const u8 *addr)
{
#if defined(CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS)
        u32 a = *(const u32 *)addr;
#else
        u16 a = *(const u16 *)addr;
#endif
#ifdef __BIG_ENDIAN
        return 0x01 & (a >> ((sizeof(a) * 8) - 8));
#else
        return 0x01 & a;
#endif
}

#endif /* _LINUX_ETHERDEVICE_H */
