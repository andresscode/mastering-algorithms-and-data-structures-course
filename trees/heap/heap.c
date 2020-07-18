#include <stdio.h>
#include <stdlib.h>

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

void sort(struct Heap *h);

void pre_order(struct Heap h, int root);

int main()
{
  struct Heap h;
  init_array(&h, (int[]) {1, 2, 3, 4, 5, 6, 7}, 7);
  max_heap(&h);
  pre_order(h, 0);
  printf("\n");
  sort(&h);
  for (int i = 0; i < h.n; ++i)
    printf("%d ", h.a[i]);
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
      int deleted = i;
      int tmp, l, r;
      do
      {
        tmp = -1;
        l = i * 2 + 1 < h->i ? i * 2 + 1 : -1;
        r = i * 2 + 2 < h->i ? i * 2 + 2 : -1;
        if (l != -1 && r != -1)
          tmp = h->a[l] > h->a[r] ? l : r;
        else if (l != -1)
          tmp = l;
        else if (r != -1)
          tmp = r;
        if (tmp != -1)
        {
          h->a[i] = h->a[tmp];
          i = tmp;
        }
      } while (tmp != -1);
      tmp = --h->i;
      for (int j = i; j < h->i; ++j)
        h->a[j] = h->a[j + 1];
      h->i = i;
      for (int k = i; k < tmp; ++k)
        insert(h, h->a[k]);
      return deleted;
    }
  }
  return -1;
}

void sort(struct Heap *h)
{
  int j, k, tmp;
  for (int i = 0; i < h->n; ++i)
  {
    int d = h->a[0];
    h->a[0] = h->a[h->i - 1];
    k = 0;
    j = 1;
    while (j < h->i - 1)
    {
      if (h->a[j] < h->a[j + 1])
        j++;
      if (h->a[j] > h->a[k])
      {
        tmp = h->a[j];
        h->a[j] = h->a[k];
        h->a[k] = tmp;
        k = j;
        j = j * 2 + 1;
      }
      else
        break;
    }
    h->a[--h->i] = d;
  }
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