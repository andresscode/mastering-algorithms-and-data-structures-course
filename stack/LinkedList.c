#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

void init(struct Stack *s, const int *a, int n);

void display(struct Stack s);

int is_empty(struct Stack s);

void push(struct Stack *s, int value);

int pop(struct Stack *s);

int peek(struct Stack s, int i);

int top(struct Stack s);

int main() {
  struct Stack s;
  init(&s, (int[]) {1, 2, 3, 4, 5}, 5);
  display(s);
  printf("top=%d\n", top(s));
  return 0;
}

int peek(struct Stack s, int i) {
  if (!is_empty(s)) {
    struct Node *p = s.top;
    int j;
    for (j = 0; j < i && p->next; ++j)
      p = p->next;
    if (i == j)
      return p->value;
  }
  return -1;
}

int top(struct Stack s) {
  if (is_empty(s))
    return -1;
  return s.top->value;
}

int pop(struct Stack *s) {
  if (is_empty(*s))
    return -1;
  struct Node *p = s->top;
  s->top = s->top->next;
  int value = p->value;
  free(p);
  return value;
}

void push(struct Stack *s, int value) {
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
      printf("%d ", p->value);
      p = p->next;
    }
    printf("\n");
  }
}

void init(struct Stack *s, const int *a, int n) {
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