#include "stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Stack *stack_create(size_t element_size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->element_size = element_size;
    stack->size = 0;
    return stack;
}

void stack_push(Stack *stack, void *element) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = malloc(stack->element_size);
    memcpy(node->data, element, stack->element_size);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

void *stack_pop(Stack *stack) {
    if (stack->top == NULL) return NULL;

    StackNode *temp = stack->top;
    void *data = malloc(stack->element_size);
    memcpy(data, temp->data, stack->element_size);

    stack->top = (temp->next != NULL) ? temp->next : NULL;
    free(temp->data);
    free(temp);
    stack->size--;

    return data;
}

void *stack_peek(Stack *stack) {
    if (stack->top == NULL) return NULL;
    return stack->top->data;
}

int stack_is_empty(Stack *stack) {
    if (stack->top == NULL) return 1;
    return 0;
}

void stack_free(Stack *stack) {
    while (!stack_is_empty(stack)) {
        void *data = stack_pop(stack);
        free(data);
    }
    free(stack);
}

