#include "../src/queue.h"
#include <stdio.h>

int main() {
    Queue *queue = queue_create(sizeof(int));

    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, &i);
        printf("Enqueued: %d\n", i);
    }

    printf("Front element: %d\n", *(int *)queue_peek(queue));

    while (!queue_is_empty(queue)) {
        int *val = (int *)queue_dequeue(queue);
        printf("Dequeued: %d\n", *val);
        free(val);
    }

    queue_free(queue);
    return 0;
}

