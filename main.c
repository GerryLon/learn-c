#include "src/common/common.h"
#include "src/string/my_string_test.h"
#include "src/common/common_test.h"
#include "src/fptr/fprt_test.h"
#include "src/callback/str/str_test.h"
#include "src/ds/ds_test.h"
#include "src/secure/secure_test.h"

void test() {
    char *pc = (char*)malloc(6);
    int i = 0;
    for (i = 0; i < 8; i++) {
        pc[i] = 0;
    }
}

int main() {
    test_common();
    test_my_string();
    test_fptr();
    test_callback__str();
    test_ds();
    test_secure();

    return 0;
}
