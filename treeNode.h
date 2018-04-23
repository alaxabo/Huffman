#include "definition.h"

typedef struct node {
  group * group;
  int weight = -1;
  int flag = COMP_NODE;
  TreeNode *l_child;
  TreeNode *r_child;
  char *huffmanCode;
} treeNode;
