#include <stdio.h>
#include "LinkedQueue.h"

void printQueue(LinkedQueue* Queue) {
    Node* current = Queue->Front;
    while (current != NULL) {
        printf("%s ", current->Data);
        current = current->NextNode;
    }
    printf("\n");
}

int main() {
    LinkedQueue* Queue;
    LQ_CreateQueue(&Queue);

    // Test Enqueue
    printf("Enqueue: ");
    LQ_Enqueue(Queue, LQ_CreateNode("Apple"));
    LQ_Enqueue(Queue, LQ_CreateNode("Banana"));
    LQ_Enqueue(Queue, LQ_CreateNode("Cherry"));
    printQueue(Queue); // Expected output: Apple Banana Cherry

    // Test Dequeue
    printf("Dequeue: ");
    Node* dequeuedNode = LQ_Dequeue(Queue);
    printf("%s \n", dequeuedNode->Data); // Expected output: Apple
    free(dequeuedNode);
    printQueue(Queue); // Expected output: Banana Cherry

    // Test IsEmpty
    printf("Is Empty: %s\n", LQ_IsEmpty(Queue) ? "Yes" : "No"); // Expected output: No

    // Test DestroyQueue
    LQ_DestroyQueue(Queue);
    printf("Is Empty: %s\n", LQ_IsEmpty(Queue) ? "Yes" : "No"); // Expected output: Yes

    return 0;
}
