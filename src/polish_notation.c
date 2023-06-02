#include "polish_notation.h"
int priority(char c) {
  int flag = 0;
  switch (c) {
  case ')':
  case '(':
    flag = 0;
    break;
  case '^':
    flag = 3;
    break;
  case '*':
  case '/':
    flag = 2;
    break;

  case '+':
  case '-':
    flag = 1;
    break;

  case 's':
  case 'q':
  case 'r':
  case 't':
  case 'c':
  case 'o':
  case 'i':
  case 'g':
  case 'n':
  case 'l':
    flag = 0;
    break;
  }
  return flag;
}
void read_function(struct stack *stack, char *str) {
  if (strncmp(str, "cos", 3) == 0) {
    push('s', stack);
    push('o', stack);
    push('c', stack);
  }
  if (strncmp(str, "sin", 3) == 0) {
    push('n', stack);
    push('i', stack);
    push('s', stack);
  }
  if (strncmp(str, "tg", 2) == 0) {
    push('g', stack);
    push('t', stack);
  }
  if (strncmp(str, "ctg", 3) == 0) {
    push('g', stack);
    push('t', stack);
    push('c', stack);
  }
  if (strncmp(str, "ln", 2) == 0) {
    push('n', stack);
    push('l', stack);
  }
  if (strncmp(str, "sqrt", 4) == 0) {
    push('t', stack);
    push('r', stack);
    push('q', stack);
    push('s', stack);
  }
}
int read_number(char *str, char *str_out) {
  int i = 0;
  if (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') ||
      (str[i] == '-' &&
       ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '.'))) {
    while (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') ||
           (str[i] == '-' &&
            ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '.'))) {
      i++;
    }
    strncat(str_out, str, i);
    strncat(str_out, " ", i);
  }
  return i;
}
void read_operators(char *str, char *str_out, struct stack *stack) {
  if (*str == '-' || *str == '+' || *str == '^' || *str == '/' || *str == '*') {
    while (empty(stack) && priority(stack->top->value) >= priority(*str)) {
      char symb[2];
      symb[0] = pop(stack);
      symb[1] = '\0';
      strncat(str_out, symb, 1);
      if (priority(symb[0]) != 0)
        strncat(str_out, " ", 1);
    }
    push(*str, stack);
  }
}
void polish_notation(char *str, char *str_out) {
  int i = 0;
  struct stack *stack = init();
  while (str[i] != '\n' && str[i] != '\0') {
    i += read_number(str + i, str_out);
    read_function(stack, str + i);
    if (str[i] == 'x') {
      char symb[2];
      symb[0] = 'x';
      symb[1] = ' ';
      strncat(str_out, symb, 2);
    }
    read_operators(str + i, str_out, stack);
    if (str[i] == '(')
      push(str[i], stack);
    if (str[i] == ')') {
      while (stack->top->value != '(') {
        char symb[1];
        symb[0] = pop(stack);
        strncat(str_out, symb, 1);
      }
      pop(stack);
    }
    i++;
  }
  while (empty(stack)) {
    char symb[2];
    symb[0] = pop(stack);
    symb[1] = '\0';
    strncat(str_out, symb, 1);
  }
  destroy(stack);
}
