#include "headers/binary_tree.h"

int main()
{
  struct TreeNode root;
  init_tree(&root);
  pre_order(&root);
  return 0;
}