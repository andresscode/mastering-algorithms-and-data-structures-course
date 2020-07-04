#include <stdio.h>
#include "stackchar.h"

void convert(char *exp);

short is_operator(char c);

short exp_precedence(char c);

short stack_precedence(char c);

int main() {
  char exp[] = "(a+b)*(c-d)^e^f";
  convert(exp);
  printf("%s\n", exp);
  return 0;
}

short is_operator(char c) {
  if (c == '(' || c == ')' || c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
    return 1;
  return 0;
}

short exp_precedence(char c) {
  if (c == '+' || c == '-')
    return 1;
  if (c == '*' || c == '/')
    return 3;
  if (c == '^')
    return 6;
  if (c == '(')
    return 7;
  if (c == ')')
    return 0;
  else
    return -1;
}

short stack_precedence(char c) {
  if (c == '+' || c == '-')
    return 2;
  if (c == '*' || c == '/')
    return 4;
  if (c == '^')
    return 5;
  if (c == '(')
    return 0;
  else
    return -1;
}

void convert(char *exp) {
  struct Stack s;
  s.top = NULL;
  int j = 0;
  for (int i = 0; exp[i] != '\0'; ++i) {
    if (is_operator(exp[i])) {
      if (is_empty(s) || exp_precedence(exp[i]) > stack_precedence(top(s)))
        push(&s, exp[i]);
      else if (exp_precedence(exp[i]) == stack_precedence(top(s)))
        pop(&s);
      else {
        while (exp_precedence(exp[i]) < stack_precedence(top(s)))
          exp[j++] = pop(&s);
        if (exp_precedence(exp[i]) == stack_precedence(top(s)))
          pop(&s);
        else
          push(&s, exp[i]);
      }
    } else
      exp[j++] = exp[i];
  }
  while (!is_empty(s))
    exp[j++] = pop(&s);
  for (; exp[j] != '\0'; ++j)
    exp[j] = '\0';
}