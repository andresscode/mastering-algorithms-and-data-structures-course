#include <stdio.h>

#define SIZE 4

void dfs(int *a, int i);

int main()
{
  int a[] = {5, 8, 10, 13, 15, 2, 3, 4, 1, 3, 1, 2, 4, 1, 3};
  dfs(a, 3);
  return 0;
}

void dfs(int *a, int i)
{
  static int b[SIZE];
  if (b[i] == 0)
  {
    printf("%d ", i + 1);
    b[i]++;
    for (int j = a[i]; j < a[i + 1]; ++j)
      dfs(a, a[j] - 1);
  }
}