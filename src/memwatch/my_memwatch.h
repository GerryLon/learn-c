#ifndef _MEMWATCH_MY_MEMWATCH_H
#define _MEMWATCH_MY_MEMWATCH_H

#ifdef MY_MEMWATCH // set -DMY_MEMWATCH when compile

void* my_malloc(unsigned int size, const char* file, int line);
#define malloc(n) my_malloc(n, __FILE__, __LINE__) // hijack malloc()

#endif // MY_MEMWATCH

#endif // _MEMWATCH_MY_MEMWATCH_h
