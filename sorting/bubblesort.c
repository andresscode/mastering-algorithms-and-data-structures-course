#include <stdio.h>

void sort(int *a, int n);

void display(const int *a, int n);

int main()
{
  int n = 10;
  int a[] = {5, 4, 3, 2, 1, 12, 4, 3, 4, 7};
  sort(a, n);
  display(a, n);
  return 0;
}

void sort(int *a, const int n)
{
  int flag;
  for (int i = 0; i < n - 1; ++i)
  {
    flag = 1;
    for (int j = 0; j < n - i - 1; ++j)
    {
      if (a[j] > a[j + 1])
      {
        flag = 0;
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
    if (flag)
      break;
  }
}

void display(const int *a, const int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
}