#ifndef _MYSTRING_H
#define _MYSTRING_H 1

#include "../common/common.h"

int my_strlen(const char* s);
int my_strcmp(const char* s1, const char* s2);
int my_strcpy(char* to, const char* from);
int my_strcat(char* s1, const char* s2);

 // tolower
char* my_tolower(const char* s);

// toupper
char* my_toupper(const char* s);

// is space tab etc.
int my_isspace(char c);

// need free memory in outside
char* my_strtrim(char* s);
int compareIgnoreCase(const char* s1, const char* s2);
#endif // _MYSTRING_H
