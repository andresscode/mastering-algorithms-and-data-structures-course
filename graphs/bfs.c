#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
  int s; // size
  int f; // front
  int r; // rear
  int *a; // array
};

void bfs(int *a, int n, int root);

void init(struct Queue *q, int n);

void enqueue(struct Queue *q, int value);

int is_full(struct Queue q);

int dequeue(struct Queue *q);

int is_empty(struct Queue q);

int main()
{
  int n = 4;
  int a[] = {5, 8, 10, 13, 15, 2, 3, 4, 1, 3, 1, 2, 4, 1, 3};
  bfs(a, n, 0);
  return 0;
}

void bfs(int *a, int n, int root)
{
  if (n > 0)
  {
    struct Queue q;
    init(&q, n);
    int b[n];
    int i, j;
    for (i = 0; i < n; ++i)
      b[i] = 0;
    printf("%d ", root + 1);
    enqueue(&q, root);
    b[root]++;
    while (!is_empty(q))
    {
      i = dequeue(&q);
      for (j = a[i]; j < a[i + 1]; ++j)
      {
        if (b[a[j] - 1] == 0)
        {
          printf("%d ", a[j]);
          enqueue(&q, a[j] - 1);
          b[a[j] - 1]++;
        }
      }
    }
  }
}

void init(struct Queue *q, int n)
{
  q->s = n;
  q->a = (int *) malloc(sizeof(int) * q->s);
  q->f = 0;
  q->r = -1;
}

void enqueue(struct Queue *q, int value)
{
  if (!is_full(*q))
  {
    q->r = ++q->r % q->s;
    q->a[q->r] = value;
  }
}

int is_full(struct Queue q)
{
  return (q.r != -1 && (q.r + 1) % q.s == q.f) ? 1 : 0;
}

int dequeue(struct Queue *q)
{
  if (is_empty(*q))
    return INT_MIN;
  int tmp = q->a[q->f];
  if (q->f == q->r)
  {
    q->f = 0;
    q->r = -1;
  }
  else
    q->f = ++q->f % q->s;
  return tmp;
}

int is_empty(struct Queue q)
{
  return (q.r == -1) ? 1 : 0;
}