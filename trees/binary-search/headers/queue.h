#include <stdlib.h>
#include "tree_node.h"

#ifndef ALGORITHMS_DATA_STRUCTURES_QUEUE_H
#define ALGORITHMS_DATA_STRUCTURES_QUEUE_H

struct QueueNode
{
  struct TreeNode *data;
  struct QueueNode *next;
};

struct Queue
{
  struct QueueNode *front;
  struct QueueNode *rear;
};

void init_queue(struct Queue *q);

void enqueue(struct Queue *q, struct TreeNode *x);

struct TreeNode *dequeue(struct Queue *q);

void init_queue(struct Queue *q)
{
  q->front = NULL;
  q->rear = NULL;
}

void enqueue(struct Queue *q, struct TreeNode *x)
{
  struct QueueNode *new = (struct QueueNode *) malloc(sizeof(struct QueueNode));
  if (!new)
    return;
  new->data = x;
  new->next = NULL;
  if (!q->front)
    q->front = q->rear = new;
  else
  {
    q->rear->next = new;
    q->rear = q->rear->next;
  }
}

struct TreeNode *dequeue(struct Queue *q)
{
  if (!q->front)
    return NULL;
  struct QueueNode *p = q->front;
  struct TreeNode *tmp = q->front->data;
  q->front = q->front->next;
  free(p);
  p = NULL;
  return tmp;
}

#endif //ALGORITHMS_DATA_STRUCTURES_QUEUE_H
