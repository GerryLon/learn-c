#ifndef _FPTR_H
#define _FPRT_H 1

#include "../common/common.h"

#define OPS_LEN 128 // 128:ASCII����Ч�ַ�
typedef double (*operation)(double, double);

// ��ʾ����ָ������, ��߷ŵĺ���ָ��, ָ��ָ��һ������(����double���, ����double)
typedef double (*operations[OPS_LEN])(double, double);

double calc(operation op, double a, double b);
double calcBySymbol(char code, double a, double b);

double add(double a, double b);
double minus(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
#endif // _FPTR_H
