#include "common.h"

// free memory safely
void _safeFree(void** p) {
    if (p != NULL && *p != NULL) {
        free(*p);
        *p = NULL;
    }
}
