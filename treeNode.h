#include "definition.h"
#include "group.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  Group * group;
  int weight;
  int flag;
  struct TreeNode *l_child;
  struct TreeNode *r_child;
  char *huffmanCode;
} TreeNode;

void createNYT_TreeNode(TreeNode * node);
void createNRM_TreeNode(TreeNode * node, float diff);
