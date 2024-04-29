#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "dlmalloc.h"

int main() {
    // char* ptr = (char*)mmap(NULL, 4 * 1024 * 1024, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS  | MAP_POPULATE, -1, 0);
    char* ptr = (char*)dlmalloc(4 * 1024 * 1024);
    for (int i = 0; i < 13; ++i) {
        ptr[i] = "hello world!\n"[i];
    }
    ptr[13] = '\0';
    printf("ptr:%p content:%s", ptr, ptr);

    char* other = (char*)dlrealloc(ptr, 8 * 1024 * 1024);
    other[12] = '\t';
    other[13] = 'I';
    other[14] = '\n';
    other[14] = '\0';
    printf("ptr:%p content:%s", other, other);

    dlfree(other);

    return 0;
}
