#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int n;
    int *p;
};

int get_option();

void execute_selection(int option, struct Matrix *m);

void create(struct Matrix *m);

void get_execution(struct Matrix m);

void set_execution(struct Matrix *m);

void init_matrix(struct Matrix *m, int n);

int get(struct Matrix m, int x, int y);

void set(struct Matrix *m, int x, int y, int v);

void display(struct Matrix m);

int main() {
  struct Matrix m;
  int count = 0;
  while (1) {
    int option = get_option();
    if (option == 5)
      break;
    execute_selection(option, &m);
    count++;
  }
  if (count > 0)
    free(m.p);
  return 0;
}

int get_option() {
  printf("Select an option\n");
  printf("1. Create\n");
  printf("2. Get\n");
  printf("3. Set\n");
  printf("4. Display\n");
  printf("5. Exit\n");
  int option;
  scanf("%d", &option);
  return option;
}

void execute_selection(int option, struct Matrix *m) {
  switch (option) {
    case 1:
      create(m);
      break;
    case 2:
      get_execution(*m);
      break;
    case 3:
      set_execution(m);
      break;
    case 4:
      display(*m);
      break;
    default:
      printf("Unknown selection, try again.\n");
  }
}

void create(struct Matrix *m) {
  printf("Insert dimension: ");
  int n;
  scanf("%d", &n);
  init_matrix(m, n);
}

void init_matrix(struct Matrix *m, int n) {
  m->n = n;
  m->p = (int *) malloc(sizeof(int) * n);
  for (int i = 0; i < m->n; i++)
    m->p[i] = i + 1;
}

void get_execution(struct Matrix m) {
  int x = 0, y = 0;
  printf("Insert row: ");
  scanf("%d", &x);
  printf("Insert column: ");
  scanf("%d", &y);
  printf("Element retrieved: %d\n", get(m, x, y));
}

int get(struct Matrix m, int x, int y) {
  if (x >= 0 && x <= m.n - 1 && y >= 0 && y <= m.n - 1) {
    if (x == y)
      return m.p[x];
    return 0;
  }
  return -1;
}

void set_execution(struct Matrix *m) {
  int x = 0, y = 0, v = 0;
  printf("Insert row: ");
  scanf("%d", &x);
  printf("Insert column: ");
  scanf("%d", &y);
  printf("Insert value (default 0): ");
  scanf("%d", &v);
  set(m, x, y, v);
}

void set(struct Matrix *m, int x, int y, int v) {
  if (x == y && x >= 0 && x <= m->n - 1 && y >= 0 && y <= m->n - 1)
    m->p[x] = v;
}

void display(struct Matrix m) {
  for (int i = 0; i < m.n; i++) {
    for (int j = 0; j < m.n; j++) {
      if (i == j)
        printf("%2d ", m.p[i]);
      else
        printf("%2d ", 0);
    }
    printf("\n");
  }
}