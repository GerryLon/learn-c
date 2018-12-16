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

char* my_strchr(const char* s, const char c) {
    if (s == NULL) {
        return NULL;
    }

    char* old = (char*)s;

    while (*old != '\0') {
        if (*old == c) {
            return old;
        }
        old++;
    }

    return NULL;
}

char* my_strstr(const char* s1, const char* s2) {
    const int len2 = strlen(s2);
    if (!len2) {
        return NULL;
    }

    char* old = (char*)s1;
    while (*old) {
        if (*old == *s2 && strncmp(s1, s2, len2) == 0) {
            return old;
        }
        old++;
    }

    return NULL;
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

// simulate tolower()
// remember to free
char* my_tolower(const char* s) {
    int len = my_strlen(s);
    // int i = 0;
    const char* _s = s;

    char* ret = (char*)malloc(len + 1);
    char* _ret = ret;

    if (ret == NULL) {
        printf("%s() malloc() err\n", __func__);
        return NULL;
    }

    while (*_s != '\0') {
        if (*_s >= 'A' && *_s <= 'Z') {
            *_ret = *_s + 32;
        } else {
            *_ret = *_s;
        }

        _ret++;
        _s++;
    }
    *_ret = '\0';

    return ret;
}

// toupper
// remember to free
char* my_toupper(const char* s) {
    int len = my_strlen(s);
    // int i = 0;
    const char* _s = s;

    char* ret = (char*)malloc(len + 1);
    char* _ret = ret;

    if (ret == NULL) {
        printf("%s() malloc() err\n", __func__);
        return NULL;
    }

    while (*_s != '\0') {
        if (*_s >= 'a' && *_s <= 'z') {
            *_ret = *_s - 32;
        } else {
            *_ret = *_s;
        }

        _ret++;
        _s++;
    }
    *_ret = '\0';

    return ret;
}


int my_isspace(char c) {
    if (c == ' ' || c == '\t' || c == '\f' || c == '\r' || c == '\n' || c == '\v') {
        return 1;
    }
    return 0;
}

/**
 * 记得在外边释放返回的指针
 */
char* my_strtrim(char* s) {
    if (s == NULL) {
        return NULL;
    }
    int i = 0;
    int finalLen = 0;

    char* _s1 = s;
    int len = my_strlen(s);
    char* _s2 = s;
    _s2 += len - 1;

    while (my_isspace(*_s1) && _s1 < _s2) {
        _s1++;
    }

    while (my_isspace(*_s2) && _s1 < _s2) {
        _s2--;
    }

    // trimmed string's length
    finalLen = _s2 - _s1 + 1;

    char* ret = (char*)malloc(finalLen + 1);

    if (ret == NULL) {
        printf("my_strtrim() malloc() err\n");
        return NULL;
    }

    for (i = 0; i < finalLen; i++) {
        *(ret + i) = *(_s1 + i);
    }
    *(ret + finalLen) = '\0';

    return ret;
}

int compareIgnoreCase(const char* s1, const char* s2) {
    char* _s1 = my_tolower(s1);
    char* _s2 = my_tolower(s2);
    int result = my_strcmp(_s1, _s2);
    safeFree(_s1);
    safeFree(_s2);
    return result;
}
