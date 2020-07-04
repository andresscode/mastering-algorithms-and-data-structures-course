#include <stdio.h>

void init_array(int *a, int n);
void print_array(int *a, int n);

int main() {
  int a[10];
  init_array(a, 10);
  print_array(a, 10);
  return 0;
}

void init_array(int *a, int n) {
  for (int i = 0; i < n; i++)
    a[i] = 1;
}

void print_array(int *a, int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}