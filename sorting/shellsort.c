#include <stdio.h>

void sort(int *a, int n);

int main()
{
  int n = 11;
  int a[] = {9, 5, 16, 8, 13, 6, 12, 10, 4, 2, 3};
  sort(a, n);
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
  return 0;
}

void sort(int *a, int n)
{
  int tmp;
  for (int i = n / 2; i >= 1; i /= 2)
  {
    for (int j = i; j < n; ++j)
    {
      int k = j;
      while (k - i >= 0)
      {
        if (a[k] < a[k - i])
        {
          tmp = a[k];
          a[k] = a[k - i];
          a[k - i] = tmp;
        }
        k -= i;
      }
    }
  }
}