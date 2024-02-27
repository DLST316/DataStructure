#include "SLL.h"

Node* CreateNode(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->nextNode = NULL;
    return newNode;
}

void DestroyNode(Node* node) {
    free(node);
}

void AppendNode(Node** head, Node* newNode) {
    if ((*head) == NULL) {
        *head = newNode;
    } else {
        Node* tail = *head;
        while (tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        tail->nextNode = newNode;
    }
}

void InsertAfter(Node* current, Node* newNode) {
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
}

void InsertNewHead(Node** head, Node* newHead) {
    if ((*head) == NULL) {
        *head = newHead;
    } else {
        newHead->nextNode = *head;
        *head = newHead;
    }
}

void InsertBefore(Node** head, Node* current, Node* newNode) 
{
    if (*head == current) 
    {
        InsertNewHead(head, newNode);
    }
    else 
    {
        Node* prev = *head;
        while (prev != NULL && prev->nextNode != current) 
        {
            prev = prev->nextNode;
        }
        if (prev != NULL) 
        {
            newNode->nextNode = current;
            prev->nextNode = newNode;
        }
    }
}

void RemoveNode(Node** head, Node* remove) {
    if (*head == remove) {
        *head = remove->nextNode;
    } else {
        Node* prev = *head;
        while (prev != NULL && prev->nextNode != remove) {
            prev = prev->nextNode;
        }
        if (prev != NULL)
            prev->nextNode = remove->nextNode;
    }
}

Node* GetNodeAt(Node* head, int location) {
    Node* current = head;
    for (int i = 0; i < location && current != NULL; ++i) {
        current = current->nextNode;
    }
    return current;
}

int GetNodeCount(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        current = current->nextNode;
        ++count;
    }
    return count;
}