#ifndef _MYSTRING_H
#define _MYSTRING_H 1

#include "../common/common.h"

int my_strlen(const char* s);
int my_strcmp(const char* s1, const char* s2);
int my_strcpy(char* to, const char* from);
int my_strcat(char* s1, const char* s2);

// is space tab etc.
int my_isspace(char c);

// need free memory in outside
char* my_strtrim(char* s);
#endif // _MYSTRING_H
