#include "headers/binary_tree.h"

struct TreeNode *create(const int *a, int l, int r);

struct TreeNode *binary_search(struct TreeNode *root, int x);

int insert(struct TreeNode *root, int x);

void display(struct TreeNode *root);

int main()
{
  struct TreeNode *root = create((int[]) {5, 9, 12, 22, 25, 26, 40}, 0, 6);
  printf("inserted=%d\n", insert(root, 10));
  display(root);
  return 0;
}

struct TreeNode *create(const int *a, int l, int r)
{
  if (l > r)
    return NULL;
  int h = (l + r) / 2;
  struct TreeNode *p = (struct TreeNode *) malloc(sizeof(struct TreeNode));
  p->data = a[h];
  p->left = create(a, l, h - 1);
  p->right = create(a, h + 1, r);
  return p;
}

struct TreeNode *binary_search(struct TreeNode *root, int x)
{
  if (root)
  {
    struct TreeNode *p = root;
    while (p)
    {
      if (p->data == x)
        return p;
      else if (p->data > x)
        p = p->left;
      else
        p = p->right;
    }
  }
  return NULL;
}

int insert(struct TreeNode *root, int x)
{
  if (!root)
    return 0;
  struct TreeNode *t = NULL;
  while (root)
  {
    t = root;
    if (root->data == x)
      return 0;
    else if (root->data > x)
      root = root->left;
    else
      root = root->right;
  }
  struct TreeNode *new = (struct TreeNode *) malloc(sizeof(struct TreeNode));
  new->data = x;
  new->left = new->right = NULL;
  if (t->data > x)
    t->left = new;
  else
    t->right = new;
  return 1;
}

void display(struct TreeNode *root)
{
  printf("pre\t\t");
  pre_order(root);
  printf("\n");
  printf("in\t\t");
  in_order(root);
  printf("\n");
  printf("post\t");
  post_order(root);
}