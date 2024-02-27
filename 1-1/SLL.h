#ifndef SLL_H
#define SLL_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node* nextNode;
    
}Node;

Node* CreateNode(int newData);
void DestroyNode(Node* node);
void AppendNode(Node** head, Node* newNode);
void InsertAfter(Node* current, Node* newNode);
void InsertNewHead(Node** head, Node* newHead);
void RemoveNode(Node** head, Node* remove);
Node* GetNodeAt(Node* head, int location);
int GetNodeCount(Node* head);

#endif
