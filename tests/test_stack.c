#include "../src/stack.h"
#include <stdio.h>

int main() {
    Stack *stack = stack_create(sizeof(int));

    for (int i = 0; i < 5; i++) {
        stack_push(stack, &i);
        printf("Pushed: %d\n", i);
    }

    printf("Top element: %d\n", *(int *)stack_peek(stack));

    while (!stack_is_empty(stack)) {
        int *val = (int *)stack_pop(stack);
        printf("Popped: %d\n", *val);
        free(val);
    }

    stack_free(stack);
    return 0;
}

