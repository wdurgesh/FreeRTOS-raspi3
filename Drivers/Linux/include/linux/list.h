#ifndef _DUMMY_LINUX_LIST_H
#define _DUMMY_LINUX_LIST_H

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#endif /* _DUMMY_LINUX_LIST_H */
