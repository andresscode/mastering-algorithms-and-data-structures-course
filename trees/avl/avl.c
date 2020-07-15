#include "avl.h"

void insert_avl(struct TreeNode *p, int x);

int balance_factor(const struct TreeNode *p);

void left_rotation(struct TreeNode *p);

int main()
{
  struct TreeNode *root = create((int[]) {3}, 0, 0);
  insert_avl(root, 2);
  insert_avl(root, 1);
  display(root);
  return 0;
}

// This function should be refactored to return a pointer, to be able to rotate the root whenever is needed.
// Skipping this module.
void insert_avl(struct TreeNode *p, int x)
{
  if (p)
  {
    insert(p, x);
    // These variables shouldn't be calculated this way, a better approach would be adding a height variable to hold
    // this information inside the TreeNode. To be implemented in real use-cases.
    int p_balance = balance_factor(p);
    int l_balance = balance_factor(p->left);
    int r_balance = balance_factor(p->right);
    // if (p_balance == 2 && l_balance == 1)
      // left_rotation(p);
    // if (p_balance == 2 && l_balance == -1)
      // left_right_rotation(p);
    // if (p_balance == -2 && r_balance == -1)
      // right_rotation(p);
    // if (p_balance == -2 && r_balance == 1)
      // right_left_rotation(p);
  }
}

int balance_factor(const struct TreeNode *p)
{
  if (p)
    return height(p->left) - height(p->right);
  return 0;
}