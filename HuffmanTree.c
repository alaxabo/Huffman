/*
 * HuffmanTree.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: Administrator
 */
#include <stdio.h>
#include "HuffmanTree.h"


TreeNode * search(TreeNode *tree, TreeNode *node) {
    if (tree != NULL) {
        if (tree->group->number == node->group->number) {
            //cout << "Node " << node->group.group << " founded." << endl;
            return tree;
        } else {
            TreeNode *left = search(tree->l_child, node);
            if (left != NULL)
                return left;
            TreeNode *right = search(tree->r_child, node);
            if (right != NULL)
                return right;
        }
    } else {
        //cout << "Node " << node->group.group << " not found" << endl;
        return NULL;

    }

}

TreeNode * search_nyt(TreeNode *tree) {
    if (tree != NULL) {
        if (tree->flag == NYT_NODE) {
            //cout << "NYT node founded." << endl;
            return tree;
        } else {
            TreeNode *left = search_nyt(tree->l_child);
            if (left != NULL)
                return left;
            TreeNode *right = search_nyt(tree->r_child);
            if (right != NULL)
                return right;
        }
    } else {
        //cout << "NYT node not found." << endl;
        return NULL;
    }

}

void buildCode(TreeNode *tree) {
    if (tree->l_child != NULL) {
        //tree->l_child->huffmanCode = tree->huffmanCode + '0';
        strcpy(tree->l_child->huffmanCode, strcat(tree->huffmanCode, '0'));
        buildCode(tree->l_child);
    }
    if (tree->r_child != NULL) {
        //tree->r_child->huffmanCode = tree->huffmanCode + '1';
        strcpy(tree->r_child->huffmanCode, strcat(tree->huffmanCode, '1'));
        buildCode(tree->r_child);
    }
}

void printCode(TreeNode *tree) {
    if (tree->l_child == NULL && tree->r_child == NULL)
        // cout << tree->group.group << " " << tree->weight << " "
        //         << tree->huffmanCode << endl;
        printf("%d %d %c", tree->group->number, tree->weight, tree->huffmanCode);
    if (tree->l_child != NULL)
        printCode(tree->l_child);
    if (tree->r_child != NULL)
        printCode(tree->r_child);
}
char * traverse(TreeNode *tree, float diff) {
    char * prefixCode;
    TreeNode *n;
    TreeNode *tmp;
    createNRM_TreeNode(tmp, diff);
    n = search(tree, tmp);
    if (n != NULL) {
        prefixCode = n->huffmanCode;
    } else if (n == NULL) {
        n = search_nyt(tree);
        prefixCode = n->huffmanCode;
    }
    return prefixCode;
}

char * ConvertToBinary(int n) {
    char * r;
    if (n == 0) {
        return "0";
    }
    while (n != 0) {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}

char * suffixCode(float diff) {
    char * suffixCode;
    Group *g;
    g = fromDiffToGroup(diff);
    int index;
    for (int i = 0; i < g->size; i++) {
        if (absFloat(diff) == g->difference[i]) {
            index = i;
            //cout << index << endl;
        }

    }
    if (diff < 0) {
        //cout << g->difference.size() - index - 1 << endl;
        suffixCode = ConvertToBinary(g->size - index - 1);
    }
    if (diff >= 0) {
        //cout << g->difference.size() + index << endl;
        suffixCode = ConvertToBinary(g->size + index);
    }
    char * zero = "0000000000000000000000";
    char tmp;
    strcat(tmp, zero);
    strcat(tmp, suffixCode);
    strcpy(suffixCode, tmp);
    //suffixCode = zero + suffixCode;
    suffixCode = suffixCode.substr(
            strlen(suffixCode) - log2(g->size - 1,
            strlen(suffixCode)) );
    return suffixCode;
}

int ConvertToDecima(char * BinaryCode){
    long i = strtol(BinaryCode.c_str(), NULL ,2);
    return (int)i;
}

char * ConvertToBCD(float diff) {
    float f = diff * 10;
    int n = (int) f;
    //cout << n << endl;
    char * BCDcode;
    char * symbol;
    char * zero = "0000000000000000";
    if (n == 0) {
        BCDcode = "0";
    }
    while (n != 0) {
        //symbol = zero + ConvertToBinary(n % 10);
        strcat (zero, ConvertToBinary(n % 10));
//        cout << n % 10 << endl;
        symbol = symbol.substr(symbol.size() - 4, 4);
//        cout << symbol << endl;
        BCDcode = symbol + BCDcode;
        n = n / 10;
    }
   // BCDcode = zero + BCDcode;
    strcat (zero, BCDcode);
    BCDcode = BCDcode.substr(strlen(BCDcode) - 16, 16);
    if(diff < 0){
        BCDcode[0] = '1';
    }
    return BCDcode;

}

float BCDtoDecima(char * BCDcode){
    int index = strlen(BCDcode);
    int n = 0;
    int count = 0;
    char first = BCDcode[0];
    if(first == '1'){
        BCDcode[0] = '0';
    }
    while(count < strlen(BCDcode)/4){
        char * symbol;
        int temp;
        symbol = BCDcode.substr(index - 4*(count+1), 4);
        temp = ConvertToDecima(symbol);
        n += temp * pow(10, count);
        count++;
    }
    float res = (float)n/10;
    if(first == '1')
        return -res;
    else
        return res;
}

void addNode(TreeNode *tree, float diff) {
    TreeNode* nyt;
    TreeNode* nrm;
    TreeNode* temp = search_nyt(tree);
    createNYT_TreeNode(nyt);
    temp->l_child = nyt;
    temp->flag = COMP_NODE;
    temp->weight = -1;
    //temp->group.group = -2;
    createNRM_TreeNode(nrm, diff);
    temp->r_child = nrm;
    //cout << "New node " << temp->r_child->group.group << endl;

}

int reBalance_Step(TreeNode *tree) {
    //cout << "Rebalance" << endl;
    int count = 0;
    if (tree->l_child->r_child != NULL && tree->r_child != NULL
            && tree->l_child != NULL) {
        //cout << tree->r_child->weight << endl;
        //cout << tree->l_child->r_child->weight << endl;
        if (tree->r_child->weight < tree->l_child->r_child->weight) {
            //cout << tree->l_child->r_child->weight << endl;
            TreeNode *temp;
            temp = tree->r_child;
            tree->r_child = tree->l_child->r_child;
            tree->l_child->r_child = temp;
            count += 1;
            ////cout << "error founded." << endl;
        }

        reBalance_Step(tree->l_child);
    }
    return count;

}

void reBalance(TreeNode *tree) {
    int count;
    count = reBalance_Step(tree);
    while (count != 0) {
        count = reBalance_Step(tree);
    }
    buildCode(tree);
}

void printTree(TreeNode *tree) {
    //if(tree->l_child == NULL && tree->r_child == NULL)
    // cout << tree->flag << " " << tree->group.group << " " << tree->weight
    //         << endl;
    printf("%d %d %d \n", tree->flag, tree0>group.group, tree->weight);
    if (tree->l_child != NULL)
        printTree(tree->l_child);
    if (tree->r_child != NULL)
        printTree(tree->r_child);

}

float * createDiffArr(float * currentData, float previousData) {
    float *diffArr;
    diffArr = (float *) malloc(currentData.size() * sizeof(float *));
    for (int i = 0; i < currentData.size(); i++) {
        if (i == 0) {
            diffArr[i] = currentData[i] - previousData;
            diffArr[i] = (float) round(diffArr[i] * 10) / 10;
        } else {
            diffArr[i] = currentData[i] - currentData[i - 1];
            diffArr[i] = (float) round(diffArr[i] * 10) / 10;
        }
    }
    return diffArr;
}

char * encoder(float * Data, TreeNode *root, float previousData) {
    float *diff;
    diff = createDiffArr(Data, previousData);
    for(int i = 0; i < Data.size(); i++){
       // cout << diff[i] << " " ;
        printf("%d ", diff[i]);
    }
    //cout << endl;
    char * code;
    for (int i = 0; i < sizeof(Data) i++) {
        TreeNode *temp;
        temp = createNRM_TreeNode(diff[i]);
        temp = search(root, temp);
        if (temp == NULL) {
            char * prefixCode = traverse(root, diff[i]);
            char * suffixCode = tree->ConvertToBCD(diff[i]);
            code = code + prefixCode + suffixCode;
            addNode(root, diff[i]);
            reBalance(root);
        } else {
            char * prefixCode = traverse(root, diff[i]);
            char * suffixCode = suffixCode(diff[i]);
            code = code + prefixCode + suffixCode;
            temp->weight += 1;
            reBalance(root);
        }
    }
    return code;
}

float * decoder(char * code, TreeNode *root, float preData) {
    float * data;
    TreeNode *currNode = root;
    float previousData = preData;
    int count = 0;
    while (count < strlen(code)) {
        char c;

        char * prefixCode;
        if (currNode->l_child == NULL && currNode->r_child == NULL) {
            prefixCode = currNode->huffmanCode;
            if (currNode->flag == NRM_NODE) {
                char * suffixCode;
                for (int i = count ; i < count + log2((double) currNode->group->size) + 1 ; i++) {
                    c = code[i];
                    suffixCode = suffixCode + c;
                }

                //cout << prefixCode << "+" << suffixCode << endl;
                printf("%c + %c\n", prefixCode, suffixCode);
                int index = ConvertToDecima(suffixCode);
                float diff = getDataByIndex(index, currNode->group);
                float curdata = (float) round((diff + previousData) * 10) / 10;
                data.push_back(curdata);
                count = count + log2((double) currNode->group.difference.size()) + 1;
                previousData = diff + previousData;
                currNode->weight += 1;
                reBalance(root);
            } else if (currNode->flag == NYT_NODE) {
                char * suffixCode;
                for (int i = count; i < count + 16; i++) {
                    c = code[i];
                    suffixCode = suffixCode + c;
                }
                //cout << prefixCode << "+" << suffixCode << endl;
                printf("%c + %c\n", prefixCode, suffixCode);
                float diff = BCDtoDecima(suffixCode);
                float curdata = (float) round((diff + previousData) * 10) / 10;
                data.push_back(curdata);
                count = count + 16;
                previousData = diff + previousData;
                addNode(root, diff);
                reBalance(root);
            }
            currNode = root;
        } else {
            c = code[count];
            if (c == '0') {
                currNode = currNode->l_child;
            } else if (c == '1') {
                currNode = currNode->r_child;
            }
            count++;
        }
    }
    return data;
}