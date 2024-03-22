#include "ExpressionTree.h"

int main()
{
    ETNode* root = NULL;

    char postfixExpression[] = "71*52-/";
    ET_BuildExpressionTree(postfixExpression, &root);

    printf("Preorder:... \n");
    ET_PreorderPrintTree(root);
    printf("\n\n");

    printf("Inorder:... \n");
    ET_InorderPrintTree(root);
    printf("\n\n");

    printf("Postorder:... \n");
    ET_PostorderPrintTree(root);
    printf("\n\n");

    printf("Evaluation Result : %f\n", ET_Evaluate(root));

    ET_DestroyTree(root);

    return 0;
}