#include <stdio.h>

struct BinaryTree {
    int size;
    int *data;
};

void init(struct BinaryTree *t, int *d, int n);

void display_pre_order(struct BinaryTree t, int root);

void display_in_order(struct BinaryTree t, int root);

void display_post_order(struct BinaryTree t, int root);

int main() {
  struct BinaryTree t;
  init(&t, (int[]) {1, 2, 3, 4, 5, 6, 7}, 7);
  display_pre_order(t, 0);
  printf("\n");
  display_in_order(t, 0);
  printf("\n");
  display_post_order(t, 0);
  return 0;
}

void display_post_order(struct BinaryTree t, int root) {
  if (root < t.size) {
    int tmp = root * 2 + 1;
    display_post_order(t, tmp);
    display_post_order(t, tmp + 1);
    printf("%d ", t.data[root]);
  }
}

void display_in_order(struct BinaryTree t, int root) {
  if (root < t.size) {
    int tmp = root * 2 + 1;
    display_in_order(t, tmp);
    printf("%d ", t.data[root]);
    display_in_order(t, tmp + 1);
  }
}

void display_pre_order(struct BinaryTree t, int root) {
  if (root < t.size) {
    printf("%d ", t.data[root]);
    int tmp = root * 2 + 1;
    display_pre_order(t, tmp);
    display_pre_order(t, tmp + 1);
  }
}

void init(struct BinaryTree *t, int *d, int n) {
  t->size = n;
  t->data = d;
}