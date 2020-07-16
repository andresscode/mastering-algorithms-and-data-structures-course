#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  int height;
  struct Node *left;
  struct Node *right;
};

struct Tree
{
  struct Node *root;
};

void display(struct Tree t);

void format_display(struct Tree t);

void pre_order(const struct Node *root);

void in_order(const struct Node *root);

void post_order(const struct Node *root);

void insert(struct Tree *t, int x);

struct Node *append(struct Node *p, int x);

int height(const struct Node *p);

struct Node *balance(struct Node *p);

int balance_factor(const struct Node *p);

struct Node *left_rotation(struct Node *p);

struct Node *left_right_rotation(struct Node *p);

struct Node *right_rotation(struct Node *p);

struct Node *right_left_rotation(struct Node *p);

struct Node *delete(struct Node *p, int x);

int leaf(struct Node *p);

struct Node *ancestor(struct Node *p);

struct Node *successor(struct Node *p);

int main()
{
  struct Tree t = {NULL};
  insert(&t, 11);
  format_display(t);
  insert(&t, 20);
  format_display(t);
  insert(&t, 30);
  format_display(t);
  insert(&t, 25);
  format_display(t);
  insert(&t, 28);
  format_display(t);
  insert(&t, 27);
  format_display(t);
  insert(&t, 10);
  format_display(t);
  t.root = delete(t.root, 11);
  format_display(t);
  t.root = delete(t.root, 20);
  format_display(t);
  t.root = delete(t.root, 10);
  format_display(t);
  return 0;
}

struct Node *delete(struct Node *p, int x)
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
  p->height = height(p);
  return balance(p);
}

int leaf(struct Node *p)
{
  return !p->left && !p->right ? 1 : 0;
}

struct Node *ancestor(struct Node *p)
{
  if (!p->right)
    return p;
  return ancestor(p->right);
}

struct Node *successor(struct Node *p)
{
  if (!p->left)
    return p;
  return ancestor(p->left);
}

void insert(struct Tree *t, int x)
{
  if (!t->root)
  {
    t->root = (struct Node *) malloc(sizeof(struct Node));
    t->root->data = x;
    t->root->height = 0;
    t->root->left = t->root->right = NULL;
    return;
  }
  t->root = append(t->root, x);
}

struct Node *append(struct Node *p, int x)
{
  if (!p)
  {
    struct Node *tmp = (struct Node *) malloc(sizeof(struct Node));
    tmp->data = x;
    tmp->height = 0;
    tmp->left = tmp->right = NULL;
    return tmp;
  }
  if (p->data == x)
    return NULL;
  else if (p->data > x)
    p->left = append(p->left, x);
  else
    p->right = append(p->right, x);
  p->height = height(p);
  return balance(p);
}

struct Node *balance(struct Node *p)
{
  int x, y, z;
  x = balance_factor(p);
  if (x > 1)
  {
    y = balance_factor(p->left);
    if (y > 0)
      return left_rotation(p);
    else
      return left_right_rotation(p);
  }
  else if (x < -1)
  {
    z = balance_factor(p->right);
    if (z < 0)
      return right_rotation(p);
    else
      return right_left_rotation(p);
  }
  else
    return p;
}

struct Node *left_rotation(struct Node *p)
{
  struct Node *tmp = p->left;
  p->left = tmp->right;
  tmp->right = p;
  p->height = height(p);
  tmp->height = height(tmp);
  return tmp;
}

struct Node *left_right_rotation(struct Node *p)
{
  struct Node *pl = p->left;
  struct Node *plr = p->left->right;
  p->left = plr->right;
  pl->right = plr->left;
  plr->left = pl;
  plr->right = p;
  pl->height = height(pl);
  p->height = height(p);
  plr->height = height(plr);
  return plr;
}

struct Node *right_rotation(struct Node *p)
{
  struct Node *tmp = p->right;
  p->right = tmp->left;
  tmp->left = p;
  p->height = height(p);
  tmp->height = height(tmp);
  return tmp;
}

struct Node *right_left_rotation(struct Node *p)
{
  struct Node *pr = p->right;
  struct Node *prl = p->right->left;
  p->right = prl->left;
  pr->left = prl->right;
  prl->left = p;
  prl->right = pr;
  pr->height = height(pr);
  p->height = height(p);
  prl->height = height(prl);
  return prl;
}

int balance_factor(const struct Node *p)
{
  int x, y;
  x = p->left ? p->left->height + 1 : 0;
  y = p->right ? p->right->height + 1 : 0;
  return x - y;
}

int height(const struct Node *p)
{
  if (!p)
    return -1;
  int x, y;
  x = p->left ? p->left->height + 1 : 0;
  y = p->right ? p->right->height + 1 : 0;
  return x > y ? x : y;
}

void display(struct Tree t)
{
  printf("pre\t\t");
  pre_order(t.root);
  printf("\n");
  printf("in\t\t");
  in_order(t.root);
  printf("\n");
  printf("post\t");
  post_order(t.root);
}

void pre_order(const struct Node *root)
{
  if (root)
  {
    printf("%2d-%d-%d ", root->data, root->height, balance_factor(root));
    pre_order(root->left);
    pre_order(root->right);
  }
}

void in_order(const struct Node *root)
{
  if (root)
  {
    in_order(root->left);
    printf("%2d-%d-%d ", root->data, root->height, balance_factor(root));
    in_order(root->right);
  }
}

void post_order(const struct Node *root)
{
  if (root)
  {
    post_order(root->left);
    post_order(root->right);
    printf("%2d-%d-%d ", root->data, root->height, balance_factor(root));
  }
}

void format_display(struct Tree t)
{
  display(t);
  printf("\n");
  printf("\n");
}