#include "../../callback/str/str.h"
#include "../../string/my_string.h"

int compare(const char* s1, const char* s2) {
    return my_strcmp(s1, s2);
}


void sortStrings(char* strings[], int len, fptrCompareStr compareFn) {

    if (strings == NULL || len <= 0) {
        return;
    }

    int sorted = 0;
    int i = 0;
    char* tmp;

    while (!sorted) {
        sorted = 1;
        for (i = 0; i < len - 1; i++) {
            if (compareFn(strings[i], strings[i+1]) > 0) {
                sorted = 0;

                tmp = strings[i];
                strings[i] = strings[i+1];
                strings[i+1] = tmp;
            }
        }
    }
}
