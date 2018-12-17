#include "../memwatch/my_memwatch.h"

void* my_malloc(unsigned int size, const char* file, int line) {
    printf("malloc() in file: %s, line: %d\n", file, line);
    return malloc(size);
}
