#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct QueueNode {
    void *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
    size_t element_size;
    size_t size;
} Queue;

Queue *queue_create(size_t element_size);
void queue_enqueue(Queue *queue, void *element);
void *queue_dequeue(Queue *queue);
void *queue_peek(Queue *queue);
int queue_is_empty(Queue *queue);
void queue_free(Queue *queue);

#endif

