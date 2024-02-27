#ifndef LLS_H
#define LLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lls_node {
    char *data;
    struct lls_node *next;
} Node;

typedef struct lls {
    Node* head;
    Node* top;
} LLS;

void LLS_CreateStack(LLS **stack);
void LLS_DestroyStack(LLS *stack);

Node* LLS_CreateNode(char *newData);
void LLS_DestroyNode(Node *node);

void LLS_Push(LLS *stack, Node *newNode);
Node* LLS_Pop(LLS *stack);

Node* LLS_Top(LLS *stack);
int LLS_GetSize(LLS *stack);
int LLS_IsEmpty(LLS *stack);


#endif
