#include "fptr.h"

double calc(operation op, double a, double b) {
    return op(a, b);
}

// a+b
double add(double a, double b) {
    return a + b;
}

// a-b
double minus(double a, double b) {
    return a - b;
}

// a*b
double multiply(double a, double b) {
    return a * b;
}

// a/b
double divide(double a, double b) {
    if (b == 0) {
        perror("divisor can not be zero");
        exit(1);
    }
    return a / b;
}
