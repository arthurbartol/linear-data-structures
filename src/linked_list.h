#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct ListNode {
    void *data;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    size_t element_size;
    size_t size;
} LinkedList;

LinkedList *list_create(size_t element_size);
void list_append(LinkedList *list, void *element);
void list_prepend(LinkedList *list, void *element);
void *list_get(LinkedList *list, size_t index);
int list_remove(LinkedList *list, size_t index);
void list_free(LinkedList *list);

#endif

