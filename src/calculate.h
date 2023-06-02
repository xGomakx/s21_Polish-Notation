#ifndef SRC_CALCULATE_H_
#define SRC_CALCULATE_H_
#include "stack.h"
#include <string.h>
#include <math.h>
void calculate_functions(char *str, struct stack_double *stack);
void calculate_operations(const char *str, struct stack_double *stack);
double stack_machine(char *str, double x);
#endif  // SRC_CALCULATE_H_
