#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stddef.h>

typedef struct DllNode {
    void *data;
    struct DllNode *prev;
    struct DllNode *next;
} DllNode;

typedef struct {
    DllNode *head;
    DllNode *tail;
    size_t element_size;
    size_t size;
} DoubleLinkedList;

DoubleLinkedList *dll_create(size_t element_size);
void dll_append(DoubleLinkedList *list, void *element);
void dll_prepend(DoubleLinkedList *list, void *element);
void *dll_get(DoubleLinkedList *list, size_t index);
int dll_remove(DoubleLinkedList *list, size_t index);
void *dll_get_first(DoubleLinkedList *list);
void *dll_get_last(DoubleLinkedList *list);
void dll_free(DoubleLinkedList *list);

#endif

