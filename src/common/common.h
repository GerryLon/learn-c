#ifndef _COMMON_H
#define _COMMON_H 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// free memory safely
void _safeFree(void** p);

#define safeFree(p) _safeFree((void**)(&p))

// input

/**
 * get a line from std input
 * you should free returned pointer
 */
char* getLine(void);
// end input

// char buf[32];
// getTimeLocal(buf);
int getTimeLocal(char* timeBuf);

#endif // COMMON_H_INCLUDED
