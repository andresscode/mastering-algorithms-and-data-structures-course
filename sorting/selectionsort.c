#include <stdio.h>

void sort(int *a, int n);

void swap(int *a, int *b);

void display(const int *a, int n);

int main()
{
  int n = 5;
  int a[] = {5, 4, 3, 2, 1};
  sort(a, n);
  display(a, n);
  return 0;
}

void sort(int *a, const int n)
{
  int k;
  for (int i = 0; i < n; ++i)
  {
    k = i;
    for (int j = i + 1; j < n; ++j)
    {
      if (a[j] < a[i])
        k = j;
    }
    swap(&a[i], &a[k]);
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