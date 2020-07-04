#include <stdio.h>
#include <stdlib.h>

struct Element {
    int n;
    int m;
    int v;
};

struct Matrix {
    int m;
    int n;
    int t;
    struct Element *a;
};

void init_matrix(struct Matrix *m);
void display(struct Matrix m);
void add(struct Matrix x, struct Matrix y);

int main() {
  struct Matrix x;
  init_matrix(&x);
  display(x);

  struct Matrix y;
  init_matrix(&y);
  display(y);

  add(x, y);

  free(x.a);
  free(y.a);

  return 0;
}

void init_matrix(struct Matrix *m) {
  printf("Rows: ");
  scanf("%d", &m->n);
  printf("Cols: ");
  scanf("%d", &m->m);
  printf("Total elements: ");
  scanf("%d", &m->t);
  m->a = (struct Element *) malloc(sizeof(struct Element) * m->t);
  for (int i = 0; i < m->t; i++) {
    printf("Element %d\n", i + 1);
    int row = 1;
    while (1) {
      printf("Row: ");
      scanf("%d", &row);
      if (row < 1 || row > m->n)
        printf("Invalid row, try again.\n");
      else
        break;
    }
    m->a[i].n = row;
    int col = 1;
    while (1) {
      printf("Col: ");
      scanf("%d", &col);
      if (col < 1 || col > m->m)
        printf("Invalid col, try again.\n");
      else
        break;
    }
    m->a[i].m = col;
    printf("Value: ");
    scanf("%d", &m->a[i].v);
  }
}

void display(struct Matrix m) {
  int index = 0;
  for (int i = 0; i < m.n; ++i) {
    for (int j = 0; j < m.m; ++j) {
      if (i == m.a[index].n - 1 && j == m.a[index].m - 1)
        printf("%2d ", m.a[index++].v);
      else
        printf("%2d ", 0);
    }
    printf("\n");
  }
}

void add(struct Matrix x, struct Matrix y) {
  struct Matrix result;
  result.n = x.n;
  result.m = x.m;
  result.t = 0;
  result.a = (struct Element *) malloc(sizeof(struct Element) * (x.t + y.t));
  int i = 0, j = 0;
  while (i < x.t && j < y.t) {
    if (x.a[i].n < y.a[j].n)
      result.a[result.t++] = x.a[i++];
    else if (x.a[i].n > y.a[j].n)
      result.a[result.t++] = y.a[j++];
    else {
      if (x.a[i].m < y.a[j].m)
        result.a[result.t++] = x.a[i++];
      else if (x.a[i].m > y.a[j].m)
        result.a[result.t++] = y.a[j++];
      else {
        result.a[result.t] = x.a[i];
        result.a[result.t++].v = x.a[i++].v + y.a[j++].v;
      }
    }
  }
  while (i < x.t)
    result.a[result.t++] = x.a[i++];
  while (j < y.t)
    result.a[result.t++] = y.a[j++];
  display(result);
  free(result.a);
}