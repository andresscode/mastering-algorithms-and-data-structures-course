#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int size;
    int *a;
};

void init_matrix(struct Matrix *m, int n);
void print_matrix(struct Matrix m, int n);

int main() {
  struct Matrix m;
  init_matrix(&m, 5);
  print_matrix(m, 5);
  free(m.a);
  return 0;
}

void init_matrix(struct Matrix *m, int n) {
  m->size = n * (n + 1) / 2;
  m->a = (int *) malloc(sizeof(int) * m->size);
  for (int i = 0; i < m->size; i++)
    m->a[i] = i + 1;
}

void print_matrix(struct Matrix m, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; j++) {
      if (j < i)
        printf("%3d ", 0);
      else
        printf("%3d ", m.a[i * (2 * n - i + 1) / 2 + j - i]);
    }
    printf("\n");
  }
}