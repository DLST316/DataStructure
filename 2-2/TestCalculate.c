#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main()
{
    char inFixExpression[100];
    char postFixExpression[100];

    double result = 0.0;
    memset(inFixExpression, 0, sizeof(inFixExpression));
    memset(postFixExpression, 0, sizeof(postFixExpression));

    printf("Enter an expression: ");
    scanf("%s", inFixExpression);

    GetPostFix(inFixExpression, postFixExpression);

    printf("Infix: %s\nPostfix:%s\n",
           inFixExpression, postFixExpression);
    result = Calculate(postFixExpression);
    printf("Result: %lf\n", result);

    return 0;
}