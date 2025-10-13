#include "queue.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Queue *queue_create(size_t element_size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->element_size = element_size;
    queue->size = 0;
    return queue;
}

void queue_enqueue(Queue *queue, void *element) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = malloc(queue->element_size);
    memcpy(node->data, element, queue->element_size);
    node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

void *queue_dequeue(Queue *queue) {
    if (queue->front == NULL) return NULL;

    QueueNode *temp = queue->front;
    void *data = malloc(queue->element_size);
    memcpy(data, temp->data, queue->element_size);

    queue->front = temp->next;
    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp->data);
    free(temp);
    
    queue->size--;
    return data;
}

void *queue_peek(Queue *queue) {
    if (queue->front == NULL) return NULL;
    return queue->front->data;
}

int queue_is_empty(Queue *queue) {
    return queue->front == NULL;
}

void queue_free(Queue *queue) {
    while (!queue_is_empty(queue)) {
        void *data = queue_dequeue(queue);
        free(data);
    }
    free(queue);
}

