#include <stdio.h>
#include "stackchar.h"

int main() {
  struct Stack stack;
  stack.top = NULL;
  short flag = 0;
  char str[] = "((a + b)(a - b)))";
  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] == '(')
      push(&stack, str[i]);
    else if (str[i] == ')') {
      if (is_empty(stack)) {
        flag = 1;
        break;
      }
      else
        pop(&stack);
    }
  }
  if (is_empty(stack) && flag == 0)
    printf("OK.\n");
  else
    printf("FAILED.\n");
  return 0;
}