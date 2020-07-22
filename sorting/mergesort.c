#include <stdio.h>

void sort(int *a, int n);

void merge(int *a, int l, int mid, int r);

void display(const int *a, int n);

int main()
{
  int n = 11;
  int a[] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 11};
  sort(a, n);
  display(a, n);
  return 0;
}

void sort(int *a, int n)
{
  int i, j;
  for (i = 2; i <= n; i *= 2)
  {
    for (j = 0; j + i - 1 < n ; j += i)
      merge(a, j, (j * 2 + i) / 2,j + i - 1);
  }
  if (i / 2 < n)
    merge(a, 0, i / 2, n - 1);
}

void merge(int *a, int l, int mid, int r)
{
  if (l < r)
  {
    int tmp[r - l + 1];
    int i = l;
    int j = mid;
    int k = 0;
    while (i < mid && j <= r)
    {
      if (a[i] < a[j])
        tmp[k++] = a[i++];
      else
        tmp[k++] = a[j++];
    }
    for (; i < mid; ++i)
      tmp[k++] = a[i];
    for (; j <= r; ++j)
      tmp[k++] = a[j];
    for (k = 0; l <= r; ++l)
      a[l] = tmp[k++];
  }
}

void display(const int *a, int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
}