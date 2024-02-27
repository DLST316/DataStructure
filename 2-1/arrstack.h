#ifndef ARRSTACK
#define ARRSTACK

#include <stdio.h>
#include <stdlib.h>

typedef struct node {int data;} Node;

typedef struct arrstack 
{
    int capacity;
    int top;
    Node *arr;
} ArrStack;

void AS_CreateStack(ArrStack **stack, int capacity);
void AS_DestroyStack(ArrStack *stack);
void AS_Push(ArrStack *stack, int data);
int AS_Pop(ArrStack *stack);
int AS_Top(ArrStack *stack);
int AS_GetSize(ArrStack *stack);
int AS_IsEmpty(ArrStack *stack);
int AS_IsFull(ArrStack *stack);

#endif