#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *init(int a[], int i, int n);

void display_pre_order(struct Node *p);

void display_in_order(struct Node *p);

void display_post_order(struct Node *p);

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  struct Node *p = init(a, 0, 7);
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
    stack<Node *> s;
    s.push(p);
    struct Node *tmp;
    while (!s.empty()) {
      tmp = s.top();
      s.pop();
      printf("%d ", tmp->data);
      if (tmp->right)
        s.push(tmp->right);
      if (tmp->left)
        s.push(tmp->left);
    }
  }
}

struct Node *init(int a[], int i, int n) {
  if (i < n) {
    auto *p = new struct Node;
    p->data = a[i];
    int tmp = i * 2 + 1;
    p->left = init(a, tmp, n);
    p->right = init(a, tmp + 1, n);
    return p;
  }
  return nullptr;
}

