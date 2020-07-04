#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int *p;
};

void init(struct Stack *s, int size, const int *a, int n);

void display(struct Stack s);

void push(struct Stack *s, int value);

int is_empty(struct Stack s);

int is_full(struct Stack s);

int pop(struct Stack *s);

int peek(struct Stack s, int index);

int top(struct Stack s);

int main() {
  struct Stack stack;
  init(&stack, 5, (int[]) {1, 2, 3, 4, 5}, 0);
  display(stack);
  printf("top=%d\n", top(stack));
  return 0;
}

int top(struct Stack s) {
  if (!is_empty(s))
    return s.p[s.top];
  return -1;
}

int peek(struct Stack s, int index) {
  if (index >= 0 && s.top - index >= 0)
      return s.p[s.top - index];
  return -1;
}

int pop(struct Stack *s) {
  if (!is_empty(*s)) {
    return s->p[s->top--];
  }
  return -1;
}

int is_full(struct Stack s) {
  if (s.top == s.size - 1)
    return 1;
  return 0;
}

int is_empty(struct Stack s) {
  if (s.top < 0)
    return 1;
  return 0;
}

void push(struct Stack *s, int value) {
  if (s->top < s->size - 1)
    s->p[++s->top] = value;
}

void display(struct Stack s) {
  if (s.top >= 0) {
    for (int i = s.top; i >= 0; i--)
      printf("%d ", s.p[i]);
    printf("\n");
  }
}

void init(struct Stack *s, int size, const int *a, int n) {
  s->top = -1;
  s->size = size;
  s->p = (int *) malloc(sizeof(int) * size);
  for (int i = 0; i < n; ++i) {
    s->p[i] = a[i];
    s->top++;
  }
}