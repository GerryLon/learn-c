#include "../../string/my_string.h"
#include "../../callback/str/str.h"
#include "../../callback/str/str_test.h"

int test_callback__str() {
    printf("------- %s() start -------\n", __func__);

    char* strings[] = {"abc", "DEF", "ghi", "ABC"};
    int size = sizeof(strings) / sizeof(char*);
    int i = 0;

    // compare case sensitive
    char* strings_compare[] = {"ABC", "DEF", "abc", "ghi"};
    sortStrings(strings, size, compare);

    for (i = 0; i < size; i++) {
//        if (strcmp(strings[i], strings_compare[i]) != 0) {
//            printf("%s() sortStrings() compare() err, i=%d\n", __func__, i);
//            return -1;
//        }
        assert(strcmp(strings[i], strings_compare[i]) == 0);
    }
    // printf("%s() sortStrings() compare() ok\n", __func__);

    // compare ignore case
    char* strings_compareIgnoreCase[] = {"ABC", "abc", "DEF", "ghi"};
    sortStrings(strings, size, compareIgnoreCase);

    for (i = 0; i < size; i++) {
//        if (strcmp(strings[i], strings_compareIgnoreCase[i]) != 0) {
//            printf("%s() sortStrings() strings_compareIgnoreCase() err, i=%d\n", __func__, i);
//            return -1;
//        }
        assert(strcmp(strings[i], strings_compareIgnoreCase[i]) == 0);
    }
    // printf("%s() sortStrings() strings_compareIgnoreCase() ok\n", __func__);

    printf("------- %s() end -------\n\n", __func__);
    return 0;
}
