#include "arrstack.h"

void AS_CreateStack(ArrStack **stack, int capacity) 
{
    *stack = (ArrStack*)malloc(sizeof(ArrStack));
    (*stack)->arr = (Node*)malloc(capacity * sizeof(Node));
    (*stack)->capacity = capacity;
    (*stack)->top = -1;
}

void AS_DestroyStack(ArrStack *stack) 
{
    free(stack->arr);
    free(stack);
}

void AS_Push(ArrStack *stack, int data) 
{
    if (AS_IsFull(stack)) 
    {
        printf("Stack is full\n");
        return;
    }
    stack->arr[++stack->top].data = data;//하나 넣고 top을 증가시킴. 첫 시작 요소를 하나 넣으면 top은 0이 됨.
}

int AS_Pop(ArrStack *stack) 
{
    if (AS_IsEmpty(stack)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top--].data;//하나 빼고 top을 감소시킴. 첫 시작 요소를 하나 빼면 top은 -1이 됨.
}

int AS_Top(ArrStack *stack) 
{
    if (AS_IsEmpty(stack)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top].data;
}

int AS_GetSize(ArrStack *stack) 
{
    return stack->top + 1;
}

int AS_IsEmpty(ArrStack *stack) 
{
    return stack->top == -1;
}

int AS_IsFull(ArrStack *stack) 
{
    return stack->top == stack->capacity - 1;
}