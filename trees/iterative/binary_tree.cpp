#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int get_int(const char *message, int x);

void init(struct Node *root);

void display_pre_order(struct Node *p);

void display_in_order(struct Node *p);

void display_post_order(struct Node *p);

int main() {
  struct Node root{};
  init(&root);
  display_pre_order(&root);
  printf("\n");
  display_in_order(&root);
  printf("\n");
  display_post_order(&root);
  return 0;
}

void display_post_order(struct Node *p) {
  if (p) {
    stack<Node *> s;
    long int tmp;
    struct Node *t = p;
    while (t || !s.empty()) {
      if (t) {
        s.push(t);
        t = t->left;
      } else {
        tmp = (long int) s.top();
        s.pop();
        if (tmp > 0) {
          s.push((struct Node *) -tmp);
          t = ((struct Node *) tmp)->right;
        } else {
          printf("%d ", ((struct Node *) -tmp)->data);
          t = nullptr;
        }
      }
    }
  }
}

void display_in_order(struct Node *p) {
  if (p) {
    stack<Node *> s;
    struct Node *t = p;
    while (t || !s.empty()) {
      if (!t) {
        t = s.top();
        s.pop();
        printf("%d ", t->data);
        t = t->right;
      } else {
        s.push(t);
        t = t->left;
      }
    }
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

void init(struct Node *root) {
  queue<Node *> q;
  struct Node *p, *t;
  int x;
  root->data = get_int("Enter root", 0);
  root->left = root->right = nullptr;
  p = root;
  while(p) {
    x = get_int("Enter left", p->data);
    if (x != -1) {
      t = new struct Node;
      t->data = x;
      t->left = t->right = nullptr;
      p->left = t;
      q.push(t);
    }
    x = get_int("Enter right", p->data);
    if (x != -1) {
      t = new struct Node;
      t->data = x;
      t->left = t->right = nullptr;
      p->right = t;
      q.push(t);
    }
    p = q.front();
    q.pop();
  }
}

int get_int(const char *message, int x) {
  int y;
  printf("%s for %d\t", message, x);
  scanf("%d", &y);
  return y;
}