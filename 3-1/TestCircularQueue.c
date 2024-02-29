#include "CircularQueue.h"

int main()
{
    CircularQueue* queue = NULL;
    CQ_CreateQueue(&queue, 10);

    CQ_Enqueue(queue, 1);
    CQ_Enqueue(queue, 2);
    CQ_Enqueue(queue, 3);
    CQ_Enqueue(queue, 4);
    CQ_Enqueue(queue, 5);

    while(CQ_IsEmpty(queue) == 0)
    {
        printf("Dequeue: %d\n", CQ_Dequeue(queue));
    }

    CQ_DestroyQueue(queue);

    return 0;
}