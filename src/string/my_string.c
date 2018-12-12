#include "my_string.h"

/**
 * get c style string's length
 */
int my_strlen(const char* s) {
    int len = 0;

    if (!s) {
        return -1;
    }

    char *p = (char *)s;
    while ((*p++) != '\0') {
        len++;
    }
    return len;
}

int my_strcpy(char* to, const char* from) {
    if (to == NULL || from == NULL) {
        return -1;
    }

    char *_from = (char *)from;
    while ((*to++ = *_from++) != '\0');

    return 0;
}

int my_strcat(char* dest, const char* src) {
    char *tmp1 = dest;
    char *tmp2 = (char*)src;

    if (!dest || !src) {
        return -1;
    }

    // while(*dest++); // 这个会把\0也放到中间
    while (*tmp1) tmp1++;
    while ((*tmp1++ = *tmp2++) != '\0');

    return 0;
}

// s1 > s2: 1
// s1 == s2: 0
// s1 < s2: -1
// invalid argument: -2
int my_strcmp(const char* s1, const char* s2) {
    int ret = 0;

    while (
        // 如果相等, ret为0, !ret为真, 继续比较
        // 如果不相等, !ret为假, 退出, 此时ret保存的就是差值(和返回的意义对比)
        !(ret = *((unsigned char*)s1) - *((unsigned char*)s2))
        && *s1 != '\0'
    ) {
        s1++;
        s2++;
    }

    if (ret < 0) {
        return -1;
    } else if (ret > 0) {
        return 1;
    } else {
        return 0;
    }
}
