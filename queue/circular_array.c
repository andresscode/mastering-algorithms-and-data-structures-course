#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
    int s; // size
    int f; // front
    int r; // rear
    int *a; // array
};

void init(struct Queue *q, int n);

void display(struct Queue q);

int is_empty(struct Queue q);

int is_full(struct Queue q);

void enqueue(struct Queue *q, int value);

int dequeue(struct Queue *q);

int front(struct Queue q);

int rear(struct Queue q);

int main() {
  struct Queue q;
  init(&q, 3);
  enqueue(&q, 1);
  display(q);
  printf("front=%d rear=%d\n", front(q), rear(q));
  enqueue(&q, 2);
  display(q);
  printf("front=%d rear=%d\n", front(q), rear(q));
  dequeue(&q);
  display(q);
  printf("front=%d rear=%d\n", front(q), rear(q));
  enqueue(&q, 3);
  display(q);
  printf("front=%d rear=%d\n", front(q), rear(q));
  enqueue(&q, 4);
  display(q);
  printf("front=%d rear=%d\n", front(q), rear(q));
  dequeue(&q);
  display(q);
  printf("front=%d rear=%d\n", front(q), rear(q));
  dequeue(&q);
  display(q);
  printf("front=%d rear=%d\n", front(q), rear(q));
  enqueue(&q, 5);
  display(q);
  printf("front=%d rear=%d\n", front(q), rear(q));
  enqueue(&q, 6);
  display(q);
  printf("front=%d rear=%d\n", front(q), rear(q));
//  enqueue(&q, 1);
//  enqueue(&q, 2);
//  enqueue(&q, 3);
//  display(q);
//  printf("dequeue=%d\n", dequeue(&q));
//  display(q);
//  printf("dequeue=%d\n", dequeue(&q));
//  display(q);
//  printf("dequeue=%d\n", dequeue(&q));
//  display(q);
//  printf("is_empty=%d\n", is_empty(q));
//  printf("is_full=%d\n", is_full(q));
  return 0;
}

int rear(struct Queue q) {
  if (!is_empty(q))
    return q.a[q.r];
}

int front(struct Queue q) {
  if (!is_empty(q))
    return q.a[q.f];
}

int dequeue(struct Queue *q) {
  if (is_empty(*q))
    return INT_MIN;
  int tmp = q->a[q->f];
  if (q->f == q->r) {
    q->f = 0;
    q->r = -1;
  } else
    q->f = ++q->f % q->s;
  return tmp;
}

void enqueue(struct Queue *q, int value) {
  if (!is_full(*q)) {
    q->r = ++q->r % q->s;
    q->a[q->r] = value;
  }
}

int is_full(struct Queue q) {
  return (q.r != -1 && (q.r + 1) % q.s == q.f) ? 1 : 0;
}

int is_empty(struct Queue q) {
  return (q.r == -1) ? 1 : 0;
}

void display(struct Queue q) {
  if (is_empty(q))
    return;
  if (q.f == q.r)
    printf("%d ", q.a[q.f]);
  else {
    int i = q.f;
    do {
      printf("%d ", q.a[i]);
      i = (i + 1) % q.s;
    } while (i != q.r);
    printf("%d ", q.a[i]);
  }
  printf("\n");
}

void init(struct Queue *q, int n) {
  q->s = n;
  q->a = (int *) malloc(sizeof(int) * q->s);
  q->f = 0;
  q->r = -1;
}