#ifndef _CALLBACK__STR_H
#define _CALLBACK__STR_H 1
#include "../../common/common.h"

typedef int (*fptrCompareStr)(const char* s1, const char* s2);
int compare(const char* s1, const char* s2);
void sortStrings(char* strings[], int len, fptrCompareStr compareFn);

#endif // _CALLBACK__STR_H
