#ifndef LCRSTREE_H
#define LCRSTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode {
    ElementType data;
    struct TreeNode *firstChild;
    struct TreeNode *nextSibling;
} TreeNode;

TreeNode* CreateNode(ElementType newData);
void     DestroyNode(TreeNode *node);
void     DestroyTree(TreeNode *root);

void     AddChildNode(TreeNode *parent, TreeNode *child);
void     PrintTree(TreeNode *node, int depth);
void     PrintNodesAtLevel(TreeNode* root, int level);

#endif // LCRSTREE_H
