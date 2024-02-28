#include <stdio.h>
#include <string.h>
#include "Calculator.h"



#include "Calculator.h"

char number[] = {'0','1','2','3','4','5','6','7','8','9','.'};

int IsNumber(char cipher)
{
    int arrayLength = sizeof(number)/sizeof(number[0]);

    for(int i = 0; i < arrayLength; i++)
    {
        if(cipher == number[i])
        {
            return 1; //현재 토큰이 숫자일 경우
        }
    }

    return 0; //현재 토큰이 숫자가 아닐 경우
}

unsigned int GetNextToken(char* expression, char* token, int* type)
{
    unsigned int i = 0;

    for(i = 0; 0 != expression[i]; i++) 
    {
        token[i] = expression[i]; // 토큰에 문자를 복사

        if(IsNumber(expression[i]) == 1) // 첫 문자가 숫자이면 토큰의 타입을 숫자로 설정 하고 다음 문자가 숫자가 아닐때까지 반복하여 이어지는 숫자 전체를 토큰으로 만든다
        {
            *type = OPERAND;

            if(IsNumber(expression[i+1]) != 1)
            {
                break;
            }
        }
        else // 첫 문자가 숫자가 아니면 토큰의 타입을 연산자로 설정하고 반복 종료
        {
            *type = expression[i];
            break;
        }

    }
    token[++i] = '\0';// 토큰하나를 문자열 하나로 만든다
    return i;// 토큰의 길이를 반환
}

int GetPriority(char operator, int inStack)
{
    int priority = -1; // 연산자의 우선순위를 저장할 변수

    switch (operator)
    {
    case LEFT_PARENTHESIS:
        if(inStack)
        {
            priority = 3;
        }
        else
        {
            priority = 0;
        }
        break;
    case MULTIPLY:
    case DIVIDE:
        priority = 1;
        break;

    case PLUS:
    case MINUS:
        priority = 2;
        break;
    }

    return priority; // 연산자의 우선순위를 반환
}

int IsPrior(char op1, char op2) //토큰이 우선순위가 높은지 참 거짓 반환
{
    return GetPriority(op1,1) > GetPriority(op2,0);
}

void GetPostFix(char* infix, char* postfix)
{
    LLS* stack;

    char token[32];
    int type = -1;
    unsigned int pos = 0;
    unsigned int len = strlen(infix);

    LLS_CreateStack(&stack);

    while( pos < len)
    {
        pos += GetNextToken(&infix[pos], token, &type);

        if(type == OPERAND)
        {
            strcat(postfix, token);
            strcat(postfix, " ");
        }
        else if(type == RIGHT_PARENTHESIS)
        {
            while(!LLS_IsEmpty(stack))
            {
                Node* node = LLS_Pop(stack);

                if(node->data[0] == LEFT_PARENTHESIS)
                {
                    LLS_DestroyNode(node);
                    break;
                }
                else
                {
                    strcat(postfix, node->data);
                    LLS_DestroyNode(node);
                }
            }
        }
        else
        {
            while(!LLS_IsEmpty(stack) && !IsPrior(LLS_Top(stack)->data[0], token[0]))
            {
                Node* node = LLS_Pop(stack);

                if(node->data[0] != LEFT_PARENTHESIS)
                    strcat(postfix, node->data);
                
                LLS_DestroyNode(node);
            }
            
            LLS_Push(stack, LLS_CreateNode(token));    
        }
    }
    while(!LLS_IsEmpty(stack))
    {
        Node* node = LLS_Pop(stack);
        if(node->data[0] != LEFT_PARENTHESIS)
            strcat(postfix, node->data);
        LLS_DestroyNode(node);
    }
    LLS_DestroyStack(stack);
}

double Calculate(char * post)
{
    LLS* stack;
    Node* resultNode;

    double result;
    char token[32];
    int type = -1;
    unsigned int read = 0;
    unsigned int len = strlen(post);

    LLS_CreateStack(&stack);

    while(read < len)
    {
        read += GetNextToken(&post[read], token, &type);
        if(type == SPACE)
            continue;

        if(type == OPERAND)
        {
            LLS_Push(stack, LLS_CreateNode(token));
        }
        else
        {
            char resultString[32];
            double operand1, operand2, tempResult;
            Node*  operatorNode;

            operatorNode = LLS_Pop(stack);
            operand2 = atof(operatorNode->data);
            LLS_DestroyNode(operatorNode);

            operatorNode = LLS_Pop(stack);
            operand1 = atof(operatorNode->data);
            LLS_DestroyNode(operatorNode);

            switch (type)
            {
            case PLUS:
                tempResult = operand1 + operand2;
                break;
            case MINUS:
                tempResult = operand1 - operand2;
                break;
            case MULTIPLY:
                tempResult = operand1 * operand2;
                break;
            case DIVIDE:
                tempResult = operand1 / operand2;
                break;
            }
            gcvt(tempResult, 10, resultString);
            LLS_Push(stack, LLS_CreateNode(resultString));
        }
    }

    resultNode = LLS_Pop(stack);
    result = atof(resultNode->data);

    LLS_DestroyNode(resultNode);

    LLS_DestroyStack(stack);

    return result;
}