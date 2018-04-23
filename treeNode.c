#include "treeNode.h"

void createNYT_TreeNode(treeNode * node){
    node->flag = NYT_NODE;
    node->weight = 0;
    node->l_child = 0;
    node->r_child = 0;
    node->group.group = -1;
}

void createNRM_TreeNode(treeNode * node, float diff){
    node->flag = NRM_NODE;
    node->weight = 1;
    node->l_child = 0;
    node->r_child = 0;
    node->group.fromDiffToGroup(diff);
}
