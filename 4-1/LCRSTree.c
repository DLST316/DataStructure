#include "LCRSTree.h"

TreeNode* CreateNode(ElementType newdata) 
{
    TreeNode* NewNode = (TreeNode*)malloc(sizeof(TreeNode));
    NewNode->data = newdata;
    NewNode->firstChild = NULL;
    NewNode->nextSibling = NULL;

    return NewNode;
}
 
void DestroyNode(TreeNode* node) 
{
    free(node);
}

void DestroyTree(TreeNode* root) 
{
    if(root->nextSibling != NULL)
        DestroyTree(root->nextSibling);
    if(root->firstChild != NULL)
        DestroyTree(root->firstChild);

    root->firstChild = NULL;
    root->nextSibling = NULL;

    DestroyNode(root);
}

void AddChildNode(TreeNode* parent, TreeNode* child) 
{
    if(parent->firstChild == NULL)
        parent->firstChild = child;
    else
    {
        TreeNode* temp = parent->firstChild;
        while(temp->nextSibling != NULL)
            temp = temp->nextSibling;

        temp->nextSibling = child;
    }
}

void PrintTree(TreeNode* node, int depth) 
{
    for(int i = 0; i < depth; i++)
        printf("  ");
    printf("%c\n", node->data);
    if(depth > 0)
        printf("+--");  

    if(node->firstChild != NULL)
        PrintTree(node->firstChild, depth + 1);
    if(node->nextSibling != NULL)
        PrintTree(node->nextSibling, depth);
}

void PrintNodesAtLevel(TreeNode* root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == 0)
    {
        printf("%c \n", root->data);
        return;
    }

    TreeNode* sibling = root->firstChild;
    while (sibling != NULL)
    {
        PrintNodesAtLevel(sibling, level - 1);
        sibling = sibling->nextSibling;
    }
}