#include <stdio.h>
#include <stdlib.h>
#include "definition.h"
#include "group.h"

typedef struct TreeNode {
  Group * group;
  // int weight = -1;
  // int flag = COMP_NODE;
  int weight;
  int flag;
  struct TreeNode *l_child;
  struct TreeNode *r_child;
  char *huffmanCode;
} TreeNode;

void createNYT_TreeNode(TreeNode * node);
void createNRM_TreeNode(TreeNode * node, float diff);
