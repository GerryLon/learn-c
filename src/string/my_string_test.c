#include "my_string.h"
#include "my_string_test.h"

int test_my_strlen() {
    const char *s = "abcd";

    int expected = strlen(s);
    int actual = my_strlen(s);

    if (actual != expected) {
        fprintf(stderr, "test_my_strlen() err\n");
        return -1;
    } else {
        fprintf(stdout, "test_my_strlen() ok\n");
    }

    return 0;
}

int test_my_strcmp() {
    const char* s1 = "abc";
    const char* s2 = "abd";

    int actual = my_strcmp(s1, s2);

    if (actual >= 0) {
        fprintf(stderr, "test_my_strcmp() err\n");
        return -1;
    } else {
        fprintf(stdout, "test_my_strcmp() ok\n");
    }

    return 0;
}

int test_my_strcpy() {
    const char *from = "abcd";
    char to[10];

    my_strcpy(to, from);

    if (strcmp(from, to) != 0) {
        fprintf(stderr, "test_my_strcpy() err\n");
        return -1;
    } else {
        fprintf(stdout, "test_my_strcpy() ok\n");
    }
    return 0;
}

int test_my_strcat() {
    char s1[20] = "abc";
    const char* s2 = "hello";

    my_strcat(s1, s2);

    if (strcmp(s1, "abchello") != 0) {
        fprintf(stderr, "test_my_strcat() err\n");
        return -1;
    } else {
        fprintf(stderr, "test_my_strcat() ok\n");
    }
    return 0;
}

int test_my_string() {
    test_my_strlen();
    test_my_strcmp();
    test_my_strcpy();
    test_my_strcat();

    return 0;
}
