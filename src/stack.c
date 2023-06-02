#include "stack.h"
struct stack_double *init_double() {
  struct stack_double *stack = malloc(sizeof(struct stack_double));
  stack->top = NULL;
  return stack;
}
int empty_double(struct stack_double *stack) {
  int res = 1;
  if (stack->top == NULL)
    res = 0;
  return res;
}
void push_double(double value, struct stack_double *stack) {
  struct val_double *n = malloc(sizeof(struct val_double));
  n->value = value;
  n->next = stack->top;
  stack->top = n;
}
double pop_double(struct stack_double *stack) {
  double res;
  if (stack->top->next != NULL) {
    res = stack->top->value;
    struct val_double *del = stack->top;
    stack->top = stack->top->next;
    free(del);
  } else {
    res = stack->top->value;
    struct val_double *del = stack->top;
    free(del);
    stack->top = NULL;
  }
  return res;
}
void destroy_double(struct stack_double *stack) {
  if (stack->top != NULL) {
    while (stack->top->next != NULL) {
      struct val_double *del = stack->top;
      stack->top = stack->top->next;
      free(del);
    }
    free(stack->top);
  }
  free(stack);
}
struct stack *init() {
  struct stack *stack = malloc(sizeof(struct stack));
  stack->top = NULL;
  return stack;
}
int empty(struct stack *stack) {
  int res = 1;
  if (stack->top == NULL)
    res = 0;
  return res;
}
void push(char value, struct stack *stack) {
  struct val *n = malloc(sizeof(struct val));
  n->value = value;
  n->next = stack->top;
  stack->top = n;
}
char pop(struct stack *stack) {
  char res;
  if (stack->top->next != NULL) {
    res = stack->top->value;
    struct val *del = stack->top;
    stack->top = stack->top->next;
    free(del);
  } else {
    res = stack->top->value;
    struct val *del = stack->top;
    free(del);
    stack->top = NULL;
  }
  return res;
}
void destroy(struct stack *stack) {
  if (stack->top != NULL) {
    while (stack->top->next != NULL) {
      struct val *del = stack->top;
      stack->top = stack->top->next;
      free(del);
    }
    free(stack->top);
  }
  free(stack);
}
