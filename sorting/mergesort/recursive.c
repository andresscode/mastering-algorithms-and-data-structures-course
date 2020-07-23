#include <stdio.h>

void sort(int *a, int n);

void split(int *a, int l, int r);

void merge(int *a, int l, int m, int r);

void display(const int *a, int n);

int main()
{
  int n = 8;
  int a[] = {8, 2, 9, 6, 5, 3, 7, 4};
  sort(a, n);
  display(a, n);
  return 0;
}

void sort(int *a, int n)
{
  if (n > 1)
    split(a, 0, n - 1);
}

void split(int *a, int l, int r)
{
  if (l < r)
  {
    int m = (l + r) / 2;
    split(a, l, m);
    split(a, m + 1, r);
    merge(a, l, m, r);
  }
}

void merge(int *a, int l, int m, int r)
{
  int b[r - l + 1];
  int i = l;
  int j = m + 1;
  int k = 0;
  while (i <= m && j <= r)
  {
    if (a[i] < a[j])
      b[k++] = a[i++];
    else
      b[k++] = a[j++];
  }
  for (; i <= m; ++i)
    b[k++] = a[i];
  for (; j <= r; ++j)
    b[k++] = a[j];
  for (k = 0, i = l; i <= r; ++i)
    a[i] = b[k++];
}

void display(const int *a, int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
}