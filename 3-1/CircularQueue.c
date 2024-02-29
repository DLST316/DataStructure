#include "CircularQueue.h"
void CQ_CreateQueue(CircularQueue** queue, int capacity)
{
    (*queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

    (*queue)->nodes = (Node*)malloc(sizeof(Node)*capacity+1);

    (*queue)->capacity = capacity;
    (*queue)->front = 0;
    (*queue)->rear = 0;
}

void CQ_DestroyQueue(CircularQueue* queue)
{
    free(queue->nodes);
    free(queue);
}

void CQ_Enqueue(CircularQueue* queue, ElementType data)
{
    int position = 0;

    position = queue->rear;

    if(queue->rear == queue->capacity)  queue->rear = 0;
    else                                queue->rear++;
    
    queue->nodes[position].data = data;
}

ElementType CQ_Dequeue(CircularQueue* queue)
{
    int position = queue->front;

    if(queue->front == queue->capacity)  queue->front = 0;
    else                                queue->front++;

    return queue->nodes[position].data;
}

int CQ_GetSize(CircularQueue* queue)
{
    if(queue->front <= queue->rear)
    {
        return queue->rear - queue->front;
    }
    else
    {
        return queue->capacity - queue->front + queue->rear;
    }
}

int CQ_IsEmpty(CircularQueue* queue)
{
    return (queue->front == queue->rear);
}

int CQ_IsFull(CircularQueue* queue)
{
    if(queue->front < queue->rear)
    {
        return (queue->rear - queue->front) == queue->capacity;
    }
    else
    {
        return (queue->rear + 1) == queue->front;
    }
}