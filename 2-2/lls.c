#include "lls.h"

void LLS_CreateStack(LLS **stack) 
{
    *stack = (LLS *)malloc(sizeof(LLS));
    (*stack)->top = NULL;
}

void LLS_DestroyStack(LLS *stack) 
{
    while (!LLS_IsEmpty(stack)) 
    {
        LLS_DestroyNode(LLS_Pop(stack));
    }
    free(stack);
}

Node* LLS_CreateNode(char *newData) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = (char *)malloc(strlen(newData) + 1);
    strcpy(newNode->data, newData);
    newNode->next = NULL;
    return newNode;
}

void LLS_DestroyNode(Node *node) 
{
    free(node->data);
    free(node);
}

void LLS_Push(LLS *stack, Node *newNode) 
{
    if(stack->head == NULL) 
    {
        stack->head = newNode;
    } 
    else 
    {
        stack->top->next = newNode;
    }
    stack->top = newNode;
}

Node* LLS_Pop(LLS *stack) 
{
    Node *popped = stack->top;
    Node *newTop = stack->head;

    if(popped == NULL) 
    {
        return NULL;
    }

    if(popped == newTop) 
    {
        stack->head = NULL;
        stack->top = NULL;
    } 
    else 
    {
        while(newTop != NULL && newTop->next != popped) 
        {
            newTop = newTop->next;
        }
        stack->top = newTop;
        newTop->next = NULL;
    }

    return popped;
}

Node* LLS_Top(LLS *stack) 
{
    return stack->top;
}

int LLS_GetSize(LLS *stack) 
{
    int count = 0;
    Node *current = stack->head;

    while(current != NULL) 
    {
        current = current->next;
        count++;
    }

    return count;
}

int LLS_IsEmpty(LLS *stack) 
{
    return (stack->head == NULL);
}
