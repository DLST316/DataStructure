#ifndef BINARTTREE_H
#define BINARTTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char elementType;

typedef struct node
{
    elementType data;
    struct node *left;
    struct node *right;
} BinaryNode;

BinaryNode* SBT_CreateNode(elementType newData);
void SBT_DestroyNode(BinaryNode* node);
void SBT_DestroyTree(BinaryNode* root);

void SBT_PreorderPrintTree(BinaryNode* node);
void SBT_InorderPrintTree(BinaryNode* node);
void SBT_PostorderPrintTree(BinaryNode* node);

#endif
