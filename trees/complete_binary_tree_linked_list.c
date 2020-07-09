#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *init(const int *a, int i, int n);

void display_pre_order(struct Node *p);

void display_in_order(struct Node *p);

void display_post_order(struct Node *p);

int main() {
  struct Node *p = init((int[]) {1, 2, 3, 4, 5, 6, 7}, 0, 7);
  display_pre_order(p);
  printf("\n");
  display_in_order(p);
  printf("\n");
  display_post_order(p);
  return 0;
}

void display_post_order(struct Node *p) {
  if (p) {
    display_post_order(p->left);
    display_post_order(p->right);
    printf("%d ", p->data);
  }
}

void display_in_order(struct Node *p) {
  if (p) {
    display_in_order(p->left);
    printf("%d ", p->data);
    display_in_order(p->right);
  }
}
void display_pre_order(struct Node *p) {
  if (p) {
    printf("%d ", p->data);
    display_pre_order(p->left);
    display_pre_order(p->right);
  }
}

struct Node *init(const int *a, int i, int n) {
  if (i < n) {
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p->data = a[i];
    int tmp = i * 2 + 1;
    p->left = init(a, tmp, n);
    p->right = init(a, tmp + 1, n);
    return p;
  }
  return NULL;
}