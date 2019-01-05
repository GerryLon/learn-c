#include "my_string.h"
#include "my_string_test.h"

static int test_my_strlen() {
    const char *s = "abcd";

    int expected = strlen(s);
    int actual = my_strlen(s);
    assert(actual == expected);
//    if (actual != expected) {
//        fprintf(stderr, "test_my_strlen() err\n");
//        return -1;
//    } else {
//        fprintf(stdout, "test_my_strlen() ok\n");
//    }

    return 0;
}

static int test_my_strcmp() {
    const char* s1 = "abc";
    const char* s2 = "abd";

    int actual = my_strcmp(s1, s2);
    assert(actual < 0);
//    if (actual >= 0) {
//        fprintf(stderr, "test_my_strcmp() err\n");
//        return -1;
//    } else {
//        fprintf(stdout, "test_my_strcmp() ok\n");
//    }

    return 0;
}

static int test_my_strcpy() {
    const char *from = "abcd";
    char to[10];

    my_strcpy(to, from);
    assert(strcmp(from, to) == 0);
//    if (strcmp(from, to) != 0) {
//        fprintf(stderr, "test_my_strcpy() err\n");
//        return -1;
//    } else {
//        fprintf(stdout, "test_my_strcpy() ok\n");
//    }
    return 0;
}

static int test_my_strcat() {
    char s1[20] = "abc";
    const char* s2 = "hello";

    my_strcat(s1, s2);
    assert(strcmp(s1, "abchello") == 0);

//    if (strcmp(s1, "abchello") != 0) {
//        fprintf(stderr, "test_my_strcat() err\n");
//        return -1;
//    } else {
//        fprintf(stderr, "test_my_strcat() ok\n");
//    }
    return 0;
}

static int test_my_strchr() {
    char* s = "hello";
    char c = 'e';
    char* index = my_strchr(s, c);

//    if (index == NULL) {
//        printf("%s() err\n", __func__);
//        return -1;
//    }
    assert(index != NULL);
    assert(strncmp("ello", index, strlen(index)) == 0);

//    if (strncmp("ello", index, strlen(index)) != 0) {
//        printf("%s() err\n", __func__);
//        return -1;
//    } else {
//        printf("%s() ok\n", __func__);
//    }

    return 0;
}

static int test_my_strstr() {
    const char* s1 = "hello=world";
    const char* s2 = "hello";
    char* index = my_strstr(s1, s2);

//    if (strcmp(index, "hello=world") != 0) {
//        printf("%s() err\n", __func__);
//        return -1;
//    } else {
//        printf("%s() ok\n", __func__);
//    }
    assert(strcmp(index, "hello=world") == 0);

    return 0;
}

static int test_my_strtrim() {
    char* s = "  a b ";
    char* s2 = my_strtrim(s);

//    if (strcmp("a b", s2) != 0) {
//        printf("%s() err\n", __func__);
//        safeFree(s2);
//        return -1;
//    } else {
//        printf("test_my_strtrim() ok\n");
//        safeFree(s2);
//    }
    assert(strcmp("a b", s2) == 0);

    return 0;
}

static int test_my_tolower() {
    const char* s = "Hello World!";
    char* s2 = my_tolower(s);

//    if (strcmp(s2, "hello world!") != 0) {
//        printf("%s() err\n", __func__);
//        safeFree(s2);
//        return -1;
//    } else {
//        printf("%s() ok\n", __func__);
//        safeFree(s2);
//    }
    assert(strcmp(s2, "hello world!") == 0);

    return 0;
}

static int test_my_toupper() {
    const char* s = "Hello World!";
    char* s2 = my_toupper(s);

//    if (strcmp(s2, "HELLO WORLD!") != 0) {
//        printf("%s() err\n", __func__);
//        safeFree(s2);
//        return -1;
//    }
//
//    printf("%s() ok\n", __func__);
    assert(strcmp(s2, "HELLO WORLD!") == 0);
    safeFree(s2);
    return 0;
}

static int test_compareIgnoreCase() {
    const char* s1 = "abc";
    const char* s2 = "ABc";
//    if (compareIgnoreCase(s1, s2) != 0) {
//        printf("%s() err\n", __func__);
//        return -1;
//    }
//
//    printf("%s() ok\n", __func__);
    assert(compareIgnoreCase(s1, s2) == 0);
    return 0;
}

static int test_bf() {
    assert(bf("abcde", "abc", 1) == 0);
    assert(bf("hello", "lo", 4) == 3);
    assert(bf("fjlsd", "jflsfjlds", 1) == -2);
    assert(bf("hello world", "world", 1) == 6);
    assert(bf("abcdefghi", "abcdx", 1) == -1);
    return 0;
}

int test_my_string() {
    printf("------- %s() start -------\n", __func__);
    test_my_strlen();
    test_my_strcmp();
    test_my_strcpy();
    test_my_strcat();
    test_my_strchr();
    test_my_strstr();
    test_my_strtrim();
    test_my_tolower();
    test_my_toupper();
    test_compareIgnoreCase();
    test_bf();
    printf("------- %s() end -------\n\n", __func__);

    return 0;
}
