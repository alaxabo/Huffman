#include "treeNode.h"

void createNYT_TreeNode(TreeNode * node){
    node->flag = NYT_NODE;
    node->weight = 0;
    node->l_child = 0;
    node->r_child = 0;
    node->group = (Group*) malloc(sizeof(Group));
    node->group->number = -1;
}

void createNRM_TreeNode(TreeNode * node, float diff){
    node->flag = NRM_NODE;
    node->weight = 1;
    node->l_child = 0;
    node->r_child = 0;
    node->group = fromDiffToGroup(diff);
}

int main(){
   TreeNode *node = malloc(sizeof(TreeNode));
   createNRM_TreeNode(node, 0.3);
   printf("Node %d", node->group->number);
   //cout << "Node " << n->group.group << endl;
}
