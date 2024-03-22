#include "BinaryTree.h"

int main()
{
    BinaryNode* root = SBT_CreateNode('A');
    BinaryNode* B = SBT_CreateNode('B');
    BinaryNode* C = SBT_CreateNode('C');
    BinaryNode* D = SBT_CreateNode('D');
    BinaryNode* E = SBT_CreateNode('E');
    BinaryNode* F = SBT_CreateNode('F');
    BinaryNode* G = SBT_CreateNode('G');
    
    root->left = B;
    B->left = C;
    B->right = D;

    root->right = E;
    E->left = F;
    E->right = G;

    printf("Preorder:...\n ");
    SBT_PreorderPrintTree(root);
    printf("\n");

    printf("Inorder:...\n ");
    SBT_InorderPrintTree(root);
    printf("\n");

    printf("Postorder:...\n ");
    SBT_PostorderPrintTree(root);
    printf("\n");

    SBT_DestroyTree(root);

    return 0;
}