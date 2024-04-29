#include "memory_hook.h"

void* (*m_sys_malloc)(size_t) = NULL;
void (*m_sys_free)(void*) = NULL;
void* (*m_sys_calloc)(size_t, size_t) = NULL;
void* (*m_sys_realloc)(void*, size_t) = NULL;
int (*m_sys_posix_memalign)(void**, size_t, size_t) = NULL;
void* (*m_sys_mmap)(void*, size_t, int, int, int, off_t) = NULL;
int (*m_sys_munmap)(void*, size_t) = NULL;