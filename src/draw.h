#ifndef SRC_DRAW_H_
#define SRC_DRAW_H_
#define NMAX 100
#define X_MAX 80
#define Y_MAX 25
#include "calculate.h"
#include "polish_notation.h"
void input(char* str);
void make_points(char* str, double* data);
void normalize(double* data, int* a);
void output(const int* arr);
#endif  //  SRC_DRAW_H_
