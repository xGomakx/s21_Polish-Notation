#ifndef SRC_POLISH_NOTATION_H_
#define SRC_POLISH_NOTATION_H_
#include "stack.h"
#include <string.h>
void read_function(struct stack *stack, char *str);
int read_number(char *str, char *str_out);
void read_operators(char *str, char *str_out, struct stack *stack);
void polish_notation(char *str, char *str_out);
#endif  //  SRC_POLISH_NOTATION_H_
