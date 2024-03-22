#include "ExpressionTree.h"

ETNode* ET_CreateNode(char data)
{
    ETNode* newNode = (ETNode*)malloc(sizeof(ETNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void ET_DestroyNode(ETNode* node)
{
    free(node);
}

void ET_DestroyTree(ETNode* root)
{
    if (root == NULL)
        return;

    ET_DestroyTree(root->left);
    ET_DestroyTree(root->right);
    ET_DestroyNode(root);
}

void ET_PreorderPrintTree(ETNode* node)
{
    if (node == NULL)
        return;

    printf("%c ", node->data);
    ET_PreorderPrintTree(node->left);
    ET_PreorderPrintTree(node->right);
}

void ET_InorderPrintTree(ETNode* node)
{
    if (node == NULL)
        return;

    ET_InorderPrintTree(node->left);
    printf("%c ", node->data);
    ET_InorderPrintTree(node->right);
}

void ET_PostorderPrintTree(ETNode* node)
{
    if (node == NULL)
        return;

    ET_PostorderPrintTree(node->left);
    ET_PostorderPrintTree(node->right);
    printf("%c ", node->data);
}

void ET_BuildExpressionTree(char* postfixExpression, ETNode** node)
{
    int len     = strlen(postfixExpression);
    char token  = postfixExpression[len - 1];
    postfixExpression[len - 1] = '\0';

    switch (token)
    {
        case'+': case'-': case'*': case'/':
            (*node) = ET_CreateNode(token);
            ET_BuildExpressionTree(postfixExpression, &(*node)->right);
            ET_BuildExpressionTree(postfixExpression, &(*node)->left);
            break;
        default:
            (*node) = ET_CreateNode(token);
            break;
    }
}

double ET_Evaluate(ETNode* tree)
{
    char temp[2];
    double left = 0.0;
    double right = 0.0;
    double result = 0.0;
    
    if(tree == NULL)
        return 0.0;

    switch(tree->data)
    {
        case '+': case '-': case '*': case '/':
            left = ET_Evaluate(tree->left);
            right = ET_Evaluate(tree->right);

            switch(tree->data)
            {
                case '+': result = left + right; break;
                case '-': result = left - right; break;
                case '*': result = left * right; break;
                case '/': result = left / right; break;
            }
            break; // Add a break statement here

        default:
            memset(temp, 0, sizeof(temp));
            temp[0] = tree->data;
            result = atof(temp);
            break;
    }
    return result;
}

