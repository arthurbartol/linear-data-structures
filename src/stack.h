#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct StackNode {
    void *data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
    size_t element_size;
    size_t size;
} Stack;

Stack *stack_create(size_t element_size);
void stack_push(Stack *stack, void *element);
void *stack_pop(Stack *stack);
void *stack_peek(Stack *stack);
int stack_is_empty(Stack *stack);
void stack_free(Stack *stack);

#endif

