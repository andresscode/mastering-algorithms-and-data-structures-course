#include <stdio.h>
#include "queue.h"

#ifndef ALGORITHMS_DATA_STRUCTURES_BINARY_TREE_H
#define ALGORITHMS_DATA_STRUCTURES_BINARY_TREE_H

void init_tree(struct TreeNode *root);

int get_int(const char *message, int x);

void pre_order(struct TreeNode *root);

void in_order(struct TreeNode *root);

void post_order(struct TreeNode *root);

void init_tree(struct TreeNode *root)
{
  struct Queue q;
  init_queue(&q);
  struct TreeNode *p, *t;
  int x;
  root->data = get_int("Enter root", 0);
  root->left = root->right = NULL;
  p = root;
  while (p)
  {
    x = get_int("Enter left", p->data);
    if (x != -1)
    {
      t = (struct TreeNode *) malloc(sizeof(struct TreeNode));
      t->data = x;
      t->left = t->right = NULL;
      p->left = t;
      enqueue(&q, t);
    }
    x = get_int("Enter right", p->data);
    if (x != -1)
    {
      t = (struct TreeNode *) malloc(sizeof(struct TreeNode));
      t->data = x;
      t->left = t->right = NULL;
      p->right = t;
      enqueue(&q, t);
    }
    p = dequeue(&q);
  }
}

int get_int(const char *message, int x)
{
  int y;
  printf("%s for %d\t", message, x);
  scanf("%d", &y);
  return y;
}

void pre_order(struct TreeNode *root)
{
  if (root)
  {
    printf("%3d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
  }
}

void in_order(struct TreeNode *root)
{
  if (root)
  {
    in_order(root->left);
    printf("%3d ", root->data);
    in_order(root->right);
  }
}

void post_order(struct TreeNode *root)
{
  if (root)
  {
    post_order(root->left);
    post_order(root->right);
    printf("%3d ", root->data);
  }
}

#endif //ALGORITHMS_DATA_STRUCTURES_BINARY_TREE_H
