#ifndef ALGORITHMS_DATA_STRUCTURES_AVL_H
#define ALGORITHMS_DATA_STRUCTURES_AVL_H

#include "../binary-search/headers/binary_tree.h"

struct TreeNode *create(const int *a, int l, int r);

struct TreeNode *binary_search(struct TreeNode *root, int x);

int insert(struct TreeNode *root, int x);

struct TreeNode *delete(struct TreeNode *p, int x);

int leaf(struct TreeNode *p);

int height(struct TreeNode *p);

struct TreeNode *ancestor(struct TreeNode *p);

struct TreeNode *successor(struct TreeNode *p);

void display(struct TreeNode *root);

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

struct TreeNode *delete(struct TreeNode *p, int x)
{
  if (!p)
    return NULL;
  if (p->data == x)
  {
    if (leaf(p))
    {
      free(p);
      return NULL;
    }
    else
    {
      if (height(p->left) > height(p->right))
      {
        p->data = ancestor(p->left)->data;
        p->left = delete(p->left, p->data);
      }
      else
      {
        p->data = successor(p->right)->data;
        p->right = delete(p->right, p->data);
      }
    }
  }
  else
  {
    if (p->data > x)
      p->left = delete(p->left, x);
    else
      p->right = delete(p->right, x);
  }
  return p;
}

int leaf(struct TreeNode *p)
{
  return !p->left && !p->right ? 1 : 0;
}

int height(struct TreeNode *p)
{
  if (!p)
    return 0;
  int x = height(p->left);
  int y = height(p->right);
  if (x > y)
    return x + 1;
  else
    return y + 1;
}

struct TreeNode *ancestor(struct TreeNode *p)
{
  if (!p->right)
    return p;
  return ancestor(p->right);
}

struct TreeNode *successor(struct TreeNode *p)
{
  if (!p->left)
    return p;
  return ancestor(p->left);
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

#endif //ALGORITHMS_DATA_STRUCTURES_AVL_H
