#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct {
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray *array_create(size_t element_size);
void array_push(DynamicArray *array, void *element);
void *array_get(DynamicArray *array, size_t index);
void array_set(DynamicArray *array, size_t index, void *element);
void array_free(DynamicArray *array);

#endif

