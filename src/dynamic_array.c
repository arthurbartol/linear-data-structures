#include "dynamic_array.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_CAPACITY 16

DynamicArray *array_create(size_t element_size) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = malloc(element_size * INITIAL_CAPACITY);
    array->element_size = element_size;
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
    return array;
}

void array_push(DynamicArray *array, void *element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, (array->capacity * array->element_size));
    }
    void *target = (char *)array->data + (array->size * array->element_size);
    memcpy(target, element, array->element_size);
    array->size++;
}

void *array_get(DynamicArray *array, size_t index) {
    if (index >= array->size) return NULL;
    return (char *)array->data + (index * array->element_size);
}

void array_set(DynamicArray *array, size_t index, void *element) {
    if (index >= array->capacity) return;
    void *target = (char *)array->data + (index * array->element_size);
    memcpy(target, element, array->element_size);
}

void array_free(DynamicArray *array) {
    free(array->data);
    free(array);
}

#undef INITIAL_CAPACITY

