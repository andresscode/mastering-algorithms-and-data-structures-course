#include <stdio.h>

void sort(int *a, int n);

int get_max(const int *a, int n);

int main()
{
  int n = 5;
  int a[] = {5, 5, 3, 2, 1};
  sort(a, n);
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
  return 0;
}

void sort(int *a, int n)
{
  int i;
  int j;
  int max = get_max(a, n);
  int b[max + 1];
  for (i = 0; i < max + 1; ++i)
    b[i] = 0;
  for (i = 0; i < n; ++i)
    b[a[i]]++;
  i = j = 0;
  while (j < max + 1)
  {
    if (b[j] > 0)
    {
      a[i++] = j;
      b[j]--;
    }
    else
      j++;
  }
}

int get_max(const int *a, int n)
{
  int max = -1;
  for (int i = 0; i < n; ++i)
  {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}