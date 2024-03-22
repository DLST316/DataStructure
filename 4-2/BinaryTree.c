#include "BinaryTree.h"

BinaryNode* SBT_CreateNode(elementType newData)
{
    BinaryNode* NewNode = (BinaryNode*)malloc(sizeof(BinaryNode));
    NewNode->data = newData;
    NewNode->left = NULL;
    NewNode->right = NULL;

    return NewNode;
}

void SBT_DestroyNode(BinaryNode* node)
{
    free(node);
}

void SBT_DestroyTree(BinaryNode* root)
{
    if(root == NULL)
        return;

    SBT_DestroyTree(root->left);
    SBT_DestroyTree(root->right);
    SBT_DestroyNode(root);
}

void SBT_PreorderPrintTree(BinaryNode* node)
{
    if(node == NULL)
        return;

    printf("%c ", node->data);
    SBT_PreorderPrintTree(node->left);
    SBT_PreorderPrintTree(node->right);
}

void SBT_InorderPrintTree(BinaryNode* node)
{
    if(node == NULL)
        return;

    SBT_InorderPrintTree(node->left);
    printf("%c ", node->data);
    SBT_InorderPrintTree(node->right);
}

void SBT_PostorderPrintTree(BinaryNode* node)
{
    if(node == NULL)
        return;

    SBT_PostorderPrintTree(node->left);
    SBT_PostorderPrintTree(node->right);
    printf("%c ", node->data);
}

