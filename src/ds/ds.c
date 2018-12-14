#include "../ds/ds.h"

// compare data, default using id
int compareData(const Data* d1, const Data* d2) {
    if (d1 == NULL || d2 == NULL) {
        printf("%s() arguments err\n", __func__);
        return 0;
    }

    if (d1->id == d2->id) {
        return 0;
    } else if (d1->id > d2->id) {
        return 1;
    } else {
        return -1;
    }
}

void printData(const Data* d) {
    printf("name: %s, id: %d\n", d->name, d->id);
}
