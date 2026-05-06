#ifndef _LINUX_NET_H
#define _LINUX_NET_H

/*
 * Dummy net.h - minimal stub implementation
 * No includes allowed
 */

/* Basic type stubs */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

/* Socket types */
#define SOCK_STREAM    1
#define SOCK_DGRAM     2
#define SOCK_RAW       3
#define SOCK_PACKET    10

/* Protocol families */
#define PF_UNSPEC      0
#define PF_INET        2
#define PF_INET6      10
#define PF_NETLINK    16

/* Address families (mirror PF) */
#define AF_UNSPEC      PF_UNSPEC
#define AF_INET        PF_INET
#define AF_INET6       PF_INET6
#define AF_NETLINK     PF_NETLINK

/* Socket states (minimal) */
#define SS_FREE        0
#define SS_UNCONNECTED 1
#define SS_CONNECTING  2
#define SS_CONNECTED   3
#define SS_DISCONNECTING 4

/* Shutdown modes */
#define SHUT_RD        0
#define SHUT_WR        1
#define SHUT_RDWR      2

/* Socket structure forward declaration */
struct socket;

/* Basic socket ops stub */
struct proto_ops {
    int (*release)(struct socket *sock);
    int (*bind)(struct socket *sock, void *addr, int addr_len);
    int (*connect)(struct socket *sock, void *addr, int addr_len, int flags);
    int (*sendmsg)(struct socket *sock, void *msg, int len);
    int (*recvmsg)(struct socket *sock, void *msg, int len, int flags);
};

/* Minimal socket structure */
struct socket {
    int state;
    int type;
    int flags;

    struct proto_ops *ops;
    void *sk;
};

/* Stub socket helpers */
static inline int sock_create(int family, int type, int protocol, struct socket **res)
{
    (void)family;
    (void)type;
    (void)protocol;
    *res = (struct socket *)0;
    return -1;
}

static inline void sock_release(struct socket *sock)
{
    (void)sock;
}

#endif /* _LINUX_NET_H */
