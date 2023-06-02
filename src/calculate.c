#include "calculate.h"
void calculate_functions(char *str, struct stack_double *stack) {
  if (strncmp(str, "cos", 3) == 0) {
    double x = pop_double(stack);
    x = cos(x);
    push_double(x, stack);
  }
  if (strncmp(str, "sin", 3) == 0) {
    double x = pop_double(stack);
    x = sin(x);
    push_double(x, stack);
  }
  if (strncmp(str, "tg", 2) == 0) {
    double x = pop_double(stack);
    x = tan(x);
    push_double(x, stack);
  }
  if (strncmp(str, "ctg", 3) == 0) {
    double x = pop_double(stack);
    x = 1.0 / tan(x);
    push_double(x, stack);
  }
  if (strncmp(str, "ln", 2) == 0) {
    double x = pop_double(stack);
    x = log(x);
    push_double(x, stack);
  }
  if (strncmp(str, "sqrt", 4) == 0) {
    double x = pop_double(stack);
    x = sqrt(x);
    push_double(x, stack);
  }
}
void calculate_operations(const char *str, struct stack_double *stack) {
  if (*str == '-') {
    double a = pop_double(stack);
    double b = pop_double(stack);
    push_double(b - a, stack);
  }
  if (*str == '*') {
    double a = pop_double(stack);
    double b = pop_double(stack);
    push_double(b * a, stack);
  }
  if (*str == '/') {
    double a = pop_double(stack);
    double b = pop_double(stack);
    push_double(b / a, stack);
  }
  if (*str == '+') {
    double a = pop_double(stack);
    double b = pop_double(stack);
    push_double(b + a, stack);
  }
  if (*str == '^') {
    double a = pop_double(stack);
    double b = pop_double(stack);
    push_double(pow(b, a), stack);
  }
}
double stack_machine(char *str, double x) {
  int i = 0;
  struct stack_double *stack = init_double();
  while (str[i] != '\n' && str[i] != '\0') {
    if (str[i] == 'x')
      push_double(x, stack);
    if (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') ||
        (str[i] == '-' &&
         ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '.'))) {
      push_double(atof(str + i), stack);
      while (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') ||
             (str[i] == '-' && ((str[i + 1] >= '0' && str[i + 1] <= '9') ||
                                str[i + 1] == '.'))) {
        i++;
      }
    }
    calculate_functions(str + i, stack);
    calculate_operations(str + i, stack);
    i++;
  }
  double res = 0;
  if (empty_double(stack))
    res = pop_double(stack);
  destroy_double(stack);
  return res;
}
