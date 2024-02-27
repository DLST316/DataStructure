#include <stdio.h>
#include "SLL.h"

void PrintList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->nextNode;
    }
    printf("\n");
}

int main() {
    // Test CreateNode
    Node* node1 = CreateNode(10);
    Node* node2 = CreateNode(20);
    Node* node3 = CreateNode(30);

    // Test AppendNode
    Node* head = NULL;
    AppendNode(&head, node1);
    AppendNode(&head, node2);
    AppendNode(&head, node3);
    printf("List after appending nodes: ");
    PrintList(head);

    // Test InsertAfter
    Node* newNode = CreateNode(15);
    InsertAfter(node1, newNode);
    printf("List after inserting node after node1: ");
    PrintList(head);

    // Test InsertNewHead
    Node* newHead = CreateNode(5);
    InsertNewHead(&head, newHead);
    printf("List after inserting new head: ");
    PrintList(head);

    // Test RemoveNode
    RemoveNode(&head, node2);
    printf("List after removing node2: ");
    PrintList(head);

    // Test GetNodeAt
    Node* node = GetNodeAt(head, 2);
    printf("Data at location 2: %d\n", node->data);

    // Test GetNodeCount
    int count = GetNodeCount(head);
    printf("Number of nodes in the list: %d\n", count);

    // Clean up
    DestroyNode(node1);
    DestroyNode(node2);
    DestroyNode(node3);
    DestroyNode(newNode);
    DestroyNode(newHead);

    return 0;
}