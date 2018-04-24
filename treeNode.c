#include "treeNode.h"

void createNYT_TreeNode(TreeNode * node){
    node->flag = NYT_NODE;
    node->weight = 0;
    node->l_child = 0;
    node->r_child = 0;
    node->group->number = -1;
}

void createNRM_TreeNode(TreeNode * node, float diff){
    node->flag = NRM_NODE;
    node->weight = 1;
    node->l_child = 0;
    node->r_child = 0;
    //node->group.fromDiffToGroup(diff);
    node->group = fromDiffToGroup(diff);
}

void main(){
    TreeNode *tree = (TreeNode *)malloc(sizeof(TreeNode));
    createNRM_TreeNode(tree, 1.5);
    printf("%d\n", tree->group->number);
}
