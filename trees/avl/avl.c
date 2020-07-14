#include "avl.h"

void insert_avl(struct TreeNode *p, int x);

void scan_balance_factors(struct TreeNode *p);

int balance_factor(const struct TreeNode *p);

int main()
{
  struct TreeNode *root = create((int[]) {3}, 0, 0);
  insert_avl(root, 2);
  insert_avl(root, 1);
  return 0;
}

void insert_avl(struct TreeNode *p, int x)
{
  if (p)
  {
    insert(p, x);
    if (abs(balance_factor(p)) > 1)
//    scan_balance_factors(p);
    printf("\nbalance_factor=%d", balance_factor(p));
  }
}

void scan_balance_factors(struct TreeNode *p)
{
  if (p)
  {
    printf("\nnode=%d balance_factor=%d", p->data, balance_factor(p));
    scan_balance_factors(p->left);
    scan_balance_factors(p->right);
  }
}

int balance_factor(const struct TreeNode *p)
{
  return height(p->left) - height(p->right);
}
