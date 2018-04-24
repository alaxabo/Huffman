/*
 * HuffmanTree.h
 *
 *  Created on: Mar 8, 2016
 *      Author: Administrator
 */

#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include "treeNode.h"
#include <string.h>
#include <tgmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


    
void initialize(TreeNode *tree);
TreeNode* search(TreeNode *tree,TreeNode *node);
TreeNode* search_nyt(TreeNode *tree);
void buildCode(TreeNode *tree);
void printCode(TreeNode *tree);
char * ConvertToBinary(int n);
int ConvertToDecima(char * BinaryCode);
char * ConvertToBCD(float diff);
float BCDtoDecima(char * BCDcode);
char * traverse(TreeNode *tree, float diff);
char * suffixCode(float diff);
void addNode(TreeNode *tree, float diff);
int reBalance_Step(TreeNode *tree);
void reBalance(TreeNode *tree);
void printTree(TreeNode *tree);
float* createDiffArr(float *currentData, float previousData);
char * encoder(float *Data, TreeNode *root, float previousData);
float * decoder(char * code, TreeNode *root, float preData);


#endif /* HUFFMANTREE_H_ */