#include <stdio.h>
#include "arrstack.h"

int main() {
    ArrStack *stack;
    int capacity = 5;

    AS_CreateStack(&stack, capacity);

    // Push elements into the stack
    AS_Push(stack, 10);
    AS_Push(stack, 20);
    AS_Push(stack, 30);

    // Pop elements from the stack
    printf("Popped element: %d\n", AS_Pop(stack));
    printf("Popped element: %d\n", AS_Pop(stack));

    // Get the top element of the stack
    printf("Top element: %d\n", AS_Top(stack));

    // Get the size of the stack
    printf("Stack size: %d\n", AS_GetSize(stack));

    // Check if the stack is empty or full
    printf("Is stack empty? %s\n", AS_IsEmpty(stack) ? "Yes" : "No");
    printf("Is stack full? %s\n", AS_IsFull(stack) ? "Yes" : "No");

    AS_DestroyStack(stack);

    return 0;
}
