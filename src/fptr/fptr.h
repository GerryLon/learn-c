#ifndef _FPTR_H
#define _FPRT_H 1

#include "../common/common.h"

#define OP_LEN 128
typedef double (*operation)(double, double);

// ��ʾ����ָ������, ��߷ŵĺ���ָ��, ָ��ָ��һ������(����double���, ����double)
typedef double (*operations[OP_LEN])(double, double);

double calc(operation op, double a, double b);

double add(double a, double b);
double minus(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
#endif // _FPTR_H
