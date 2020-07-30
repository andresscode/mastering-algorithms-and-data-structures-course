#include <stdio.h>

struct Edge
{
  int a;
  int b;
  int w;
};

void print(struct Edge *g, int n, int v);

int main()
{
  int n = 9;
  int v = 7;
  struct Edge g[] = {{1, 6, 5}, {3, 4, 8}, {2, 7, 10}, {2, 3, 12},
                     {4, 7, 14}, {4, 5, 16}, {5, 7, 18}, {5, 6, 20},
                     {1, 2, 25}};
  print(g, n, v);
  return 0;
}

void print(struct Edge *g, int n, int v)
{
  int i, j;
  int used[n];
  for (i = 0; i < n; ++i)
    used[i] = 0;
  // sort(g, n); # to be implemented
  int a = g[0].a;
  int b = g[0].b;
  printf("a=%d b=%d w=%d", a, b, g[0].w);
  used[0]++;
  for (i = 1; i < v - 1; ++i)
  {
    for (j = 1; j < n; ++j)
    {
      if (used[j] == 0)
      {
        if (g[j].a == a || g[j].b == a || g[j].a == b || g[j].b == b)
        {
          printf("\na=%d b=%d w=%d", g[j].a, g[j].b, g[j].w);
          used[j]++;
          if (g[j].a == a)
            a = g[j].b;
          else if (g[j].a == b)
            b = g[j].b;
          else if (g[j].b == a)
            a = g[j].a;
          else
            b = g[j].a;
          break;
        }
      }
    }
  }
}