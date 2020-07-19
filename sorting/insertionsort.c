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
  for (int i = 1; i < n; ++i)
  {
    for (int j = i; j > 0; --j)
    {
      if (a[j] < a[j - 1])
        swap(&a[j], &a[j - 1]);
    }
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