#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include <stdio.h>
#include <stdlib.h>
struct stack_double {
  struct val_double *top;
};
struct val_double {
  double value;
  struct val_double *next;
};
struct stack {
  struct val *top;
};
struct val {
  char value;
  struct val *next;
};
struct stack_double *init_double();
int empty_double(struct stack_double *stack);
void push_double(double value, struct stack_double *stack);
double pop_double(struct stack_double *stack);
void destroy_double(struct stack_double *stack);
struct stack *init();
int empty(struct stack *stack);
void push(char value, struct stack *stack);
char pop(struct stack *stack);
void destroy(struct stack *stack);
#endif  //  SRC_STACK_H_
