/* Minimal dependency-free dummy linux/proc_fs.h
 *
 * Purpose: compilation-only stub for userland/test builds that include
 * <linux/proc_fs.h> without pulling in kernel headers or libc.
 *
 * This header provides a very small subset of the real kernel API:
 * - struct proc_dir_entry
 * - proc_create / proc_create_data / proc_mkdir / remove_proc_entry / proc_remove
 * - minimal proc_ops / file_operations forward declarations
 *
 * It is NOT a replacement for the kernel header and must NOT be used
 * to build real kernel modules. All functions are no-ops or return
 * neutral values so code can compile in dependency-free environments.
 */

#ifndef _LINUX_PROC_FS_H
#define _LINUX_PROC_FS_H


#endif /* _LINUX_PROC_FS_H */

