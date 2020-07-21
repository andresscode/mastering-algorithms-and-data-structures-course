#include <stdio.h>

void sort(int *a, int l, int r);

void swap(int *a, int *b);

void display(const int *a, int n);

int main()
{
  int n = 5;
  int a[] = {5, 4, 3, 2, 1};
  sort(a, 0, n);
  display(a, n);
  return 0;
}

void sort(int *a, const int l, const int r)
{
  if (l < r)
  {
    int i = l;
    int j = r;
    while (i < j)
    {
      while (i < j && a[i] <= a[l]) i++;
      while (a[j] > a [l]) j--;
      if (i < j)
        swap(&a[i], &a[j]);
    }
    swap(&a[l], &a[j]);
    sort(a, l, j - 1);
    sort(a, j + 1, r);
  }
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void display(const int *a, const int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
}