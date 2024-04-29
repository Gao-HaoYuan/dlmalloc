#pragma once
#include <sys/types.h>

extern void* (*m_sys_malloc)(size_t);
extern void (*m_sys_free)(void*);
extern void* (*m_sys_calloc)(size_t, size_t);
extern void* (*m_sys_realloc)(void*, size_t);
extern int (*m_sys_posix_memalign)(void**, size_t, size_t);
extern void* (*m_sys_mmap)(void*, size_t, int, int, int, off_t); // 采用 mmap64 代替
extern int (*m_sys_munmap)(void*, size_t);