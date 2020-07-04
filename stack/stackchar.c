#include <stdio.h>
#include <stdlib.h>
#include "stackchar.h"

char top(struct Stack s) {
  if (is_empty(s))
    return -1;
  return s.top->value;
}

char pop(struct Stack *s) {
  if (is_empty(*s))
    return -1;
  struct Node *p = s->top;
  s->top = s->top->next;
  char value = p->value;
  free(p);
  return value;
}

void push(struct Stack *s, char value) {
  struct Node *p = (struct Node *) malloc(sizeof(struct Node));
  p->value = value;
  p->next = s->top;
  s->top = p;
}

int is_empty(struct Stack s) {
  if (s.top)
    return 0;
  return 1;
}

void display(struct Stack s) {
  if (s.top) {
    struct Node *p = s.top;
    while (p) {
      printf("%c ", p->value);
      p = p->next;
    }
    printf("\n");
  }
}

void init(struct Stack *s, const char *a, int n) {
  if (n > 0) {
    s->top = (struct Node *) malloc(sizeof(struct Node));
    s->top->value = a[0];
    s->top->next = NULL;
    struct Node *p;
    for (int i = 1; i < n; ++i) {
      p = (struct Node *) malloc(sizeof(struct Node));
      p->value = a[i];
      p->next = s->top;
      s->top = p;
    }
  } else {
    s->top = NULL;
  }
}