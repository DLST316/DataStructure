#include "lls.h"

int main() {
    int i = 0;
    int count = 0;

    Node* popped;

    LLS *stack;

    LLS_CreateStack(&stack);

    LLS_Push(stack, LLS_CreateNode("ABC"));
    LLS_Push(stack, LLS_CreateNode("DEF"));
    LLS_Push(stack, LLS_CreateNode("GHI"));
    LLS_Push(stack, LLS_CreateNode("JKL"));

    count = LLS_GetSize(stack);
    printf("Size: %d\n", count);
    printf("Top: %s\n", LLS_Top(stack)->data);

    printf("Pop & Top\n");
    for(i = 0; i < count; i++) 
    {
        if(LLS_IsEmpty(stack))
            break;

        popped = LLS_Pop(stack);
        printf("Popped: %s\n", popped->data);
        LLS_DestroyNode(popped);

        if(!LLS_IsEmpty(stack))
            printf("Top: %s\n", LLS_Top(stack)->data);
        else
            printf("Stack is empty.\n");
    }
    LLS_DestroyStack(stack);
    return 0;
}
