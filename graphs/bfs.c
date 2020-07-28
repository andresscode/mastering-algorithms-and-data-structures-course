#include <stdio.h>

void bfs(int *a, int n);

int main()
{
  int n = 4;
  int a[] = {5, 8, 10, 13, 15, 2, 3, 4, 1, 3, 1, 2, 4, 1, 3};
  bfs(a, n);
  return 0;
}

void bfs(int *a, int n)
{
  if (n > 0)
  {
    int i, j;
    int b[n];
    for (i = 0; i < n; ++i)
      b[i] = 0;
    for (i = 3; i < n; ++i)
    {
      if (b[i] == 0)
      {
        printf("%d ", i + 1);
        b[i]++;
      }
      for (j = a[i]; j < a[i + 1]; ++j)
      {
        if (b[a[j] - 1] == 0)
        {
          printf("%d ", a[j]);
          b[a[j] - 1]++;
        }
      }
    }
  }
}