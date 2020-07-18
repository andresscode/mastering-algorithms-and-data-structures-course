#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Heap
{
  int n;
  int i;
  int *a;
};

void init(struct Heap *h, int n);

void init_array(struct Heap *h, int *a, int n);

void max_heap(struct Heap *h);

void insert(struct Heap *h, int x);

int delete(struct Heap *h, int x);

void pre_order(struct Heap h, int root);

int main()
{
  struct Heap h;
  init_array(&h, (int[]) {1, 2, 3, 4, 5, 6, 7}, 7);
  max_heap(&h);
  pre_order(h, 0);
  printf("\ndeleted=%d", delete(&h, 7));
  printf("\n");
  pre_order(h, 0);
  return 0;
}

void init(struct Heap *h, int n)
{
  h->n = n;
  h->i = 0;
  h->a = (int *) malloc(sizeof(int) * h->n);
}

void init_array(struct Heap *h, int *a, int n)
{
  h->n = n;
  h->i = 0;
  h->a = a;
}

void max_heap(struct Heap *h)
{
  for (int i = 0; i < h->n; ++i)
    insert(h, h->a[i]);
}

void insert(struct Heap *h, int x)
{
  if (h->i < h->n)
  {
    int i = h->i++;
    while (i > 0 && x > h->a[(i - 1) / 2])
    {
      h->a[i] = h->a[(i - 1) / 2];
      i = (i - 1) / 2;
    }
    h->a[i] = x;
  }
}

int delete(struct Heap *h, int x)
{
  if (x <= h->a[0])
  {
    int i = 0;
    while (h->a[i] != x && i++ < h->i);
    if (i < h->i)
    {
      for (int j = i; j < h->i - 1; ++j)
        h->a[j] = h->a[j + 1];
      h->i--;
      return i;
    }
  }
  return -1;
}

void pre_order(struct Heap h, int root)
{
  if (root < h.i)
  {
    printf("%d ", h.a[root]);
    int tmp = root * 2 + 1;
    pre_order(h, tmp);
    pre_order(h, tmp + 1);
  }
}