#ifndef DLL
#define DLL

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *CreateNode(int data);
void DestroyNode(Node *node);
void AppendNode(Node **head, Node *newNode);
void InsertAfter(Node *current, Node *newNode);
void RemoveNode(Node **head, Node *remove);
Node *GetNodeAt(Node *head, int location);
int GetNodeCount(Node *head);

#endif