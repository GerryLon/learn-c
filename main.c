#include "src/common/common.h"
#include "src/string/my_string_test.h"
#include "src/common/common_test.h"
#include "src/fptr/fprt_test.h"
#include "src/callback/str/str_test.h"
#include "src/ds/ds_test.h"
#include "src/secure/secure_test.h"
#include "src/memwatch/my_memwatch_test.h"

int main() {
    test_common();
    test_my_string();
    test_fptr();
    test_callback__str();
    test_ds();
    test_secure();
    test_my_memwatch();

    return 0;
}
