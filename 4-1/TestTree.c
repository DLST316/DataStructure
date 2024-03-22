#include "LCRSTree.h"

int main()
{
    TreeNode* root = CreateNode('A');
    TreeNode* B = CreateNode('B');
    TreeNode* C = CreateNode('C');
    TreeNode* D = CreateNode('D');
    TreeNode* E = CreateNode('E');
    TreeNode* F = CreateNode('F');
    TreeNode* G = CreateNode('G');
    TreeNode* H = CreateNode('H');
    TreeNode* I = CreateNode('I');
    TreeNode* J = CreateNode('J');
    TreeNode* K = CreateNode('K');

    AddChildNode(root, B);
        AddChildNode(B, C);
        AddChildNode(B, D);
            AddChildNode(D, E);
            AddChildNode(D, F);

    AddChildNode(root, G);
        AddChildNode(G, H);

    AddChildNode(root, I);
        AddChildNode(I, J);
            AddChildNode(J, K);

    PrintTree(root, 0);
    printf("_________________________________\n");
    PrintNodesAtLevel(root, 1);
    DestroyTree(root);

    return 0;

}