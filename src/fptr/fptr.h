#ifndef _FPTR_H
#define _FPRT_H 1

#include "../common/common.h"

#define OPS_LEN 128 // 128:ASCII码有效字符
typedef double (*operation)(double, double);

// 表示函数指针数组, 里边放的函数指针, 指针指向一个函数(两个double入参, 返回double)
typedef double (*operations[OPS_LEN])(double, double);

double calc(operation op, double a, double b);
double calcBySymbol(char code, double a, double b);

double add(double a, double b);
double minus(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
#endif // _FPTR_H
