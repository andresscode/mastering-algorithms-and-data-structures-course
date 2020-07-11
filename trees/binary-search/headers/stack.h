#include <stdlib.h>
#include "tree_node.h"

#ifndef ALGORITHMS_DATA_STRUCTURES_STACK_H
#define ALGORITHMS_DATA_STRUCTURES_STACK_H

struct StackNode
{
  struct TreeNode *data;
  struct StackNode *next;
};

struct Stack
{
  struct StackNode *top;
};

void init_stack(struct Stack *s);

int is_empty(struct Stack s);

void push(struct Stack *s, struct TreeNode *p);

struct TreeNode *pop(struct Stack *s);

void init_stack(struct Stack *s)
{
  s->top = NULL;
}

int is_empty(struct Stack s)
{
  if (s.top)
    return 0;
  return 1;
}

void push(struct Stack *s, struct TreeNode *p)
{
  struct StackNode *tmp = (struct StackNode *) malloc(sizeof(struct StackNode));
  tmp->data = p;
  tmp->next = s->top;
  s->top = tmp;
}

struct TreeNode *pop(struct Stack *s)
{
  if (is_empty(*s))
    return NULL;
  struct StackNode *p = s->top;
  s->top = s->top->next;
  struct TreeNode *data = p->data;
  free(p);
  return data;
}

#endif //ALGORITHMS_DATA_STRUCTURES_STACK_H
