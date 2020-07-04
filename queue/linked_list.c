#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void init(struct Queue *q);

void enqueue(struct Queue *q, int x);

void display(struct Queue q);

int dequeue(struct Queue *q);

int main() {
  struct Queue q;
  init(&q);
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  display(q);
  printf("dequeue=%d\n", dequeue(&q));
  display(q);
  printf("dequeue=%d\n", dequeue(&q));
  display(q);
  printf("dequeue=%d\n", dequeue(&q));
  display(q);
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  display(q);
  return 0;
}

int dequeue(struct Queue *q) {
  if (!q->front)
    return INT_MIN;
  struct Node *p = q->front;
  int tmp = q->front->data;
  q->front = q->front->next;
  free(p);
  p = NULL;
  return tmp;
}

void display(struct Queue q) {
  if (q.front) {
    struct Node *p = q.front;
    while (p) {
      printf("%d ", p->data);
      p = p->next;
    }
    printf("\n");
  }
}

void enqueue(struct Queue *q, int x) {
  struct Node *new = (struct Node *) malloc(sizeof(struct Node));
  if (!new)
    return;
  new->data = x;
  new->next = NULL;
  if (!q->front)
    q->front = q->rear = new;
  else {
    q->rear->next = new;
    q->rear = q->rear->next;
  }
}

void init(struct Queue *q) {
  q->front = NULL;
  q->rear = NULL;
}