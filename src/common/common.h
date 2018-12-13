#ifndef _COMMON_H
#define _COMMON_H 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// free memory safely
void _safeFree(void** p);

#define safeFree(p) _safeFree((void**)(&p))

#endif // COMMON_H_INCLUDED
