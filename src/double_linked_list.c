#include "double_linked_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

DoubleLinkedList *dll_create(size_t element_size) {
    DoubleLinkedList *list = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->element_size = element_size;
    list->size = 0;
    return list;
}

void dll_append(DoubleLinkedList *list, void *element) {
    DllNode *node = (DllNode *)malloc(sizeof(DllNode));
    node->data = malloc(list->element_size);
    memcpy(node->data, element, list->element_size);
    node->next = NULL;
    node->prev = list->tail;

    if (list->tail) list->tail->next = node;
    else            list->head = node;

    list->tail = node;
    list->size++;
}

void dll_prepend(DoubleLinkedList *list, void *element) {
    DllNode *node = (DllNode *)malloc(sizeof(DllNode));
    node->data = malloc(list->element_size);
    memcpy(node->data, element, list->element_size);
    node->prev = NULL;
    node->next = list->head;

    if (list->head) list->head->prev = node;
    else            list->tail = node;

    list->head = node;
    list->size++;
}

void *dll_get(DoubleLinkedList *list, size_t index) {
    if (index >= list->size)
        return NULL;

    DllNode *current;
    if (index < list->size/2) {
        current = list->head;
        for (size_t i = 0; i < index; i++) current = current->next;
    } else {
        current = list->tail;
        for (size_t i = list->size-1; i > index; i--) current = current->prev;
    }
    return current->data;
}

int dll_remove(DoubleLinkedList *list, size_t index) {
    if (index >= list->size)
        return 0;

    DllNode *current = NULL;
    if (index < list->size/2) {
        current = list->head;
        for (size_t i = 0; i < index; i++) current = current->next;
    } else {
        current = list->tail;
        for (size_t i = list->size-1; i > index; i--) current = current->prev;
    }

    if (current->prev) current->prev->next = current->next;
    else               list->head = current->next;

    if (current->next) current->next->prev = current->prev;
    else               list->tail = current->prev;

    free(current->data);
    free(current);

    list->size--;
    return 1;
}

void *dll_get_first(DoubleLinkedList *list) {
    if (!list->head) return NULL;
    return list->head->data;
}

void *dll_get_last(DoubleLinkedList *list) {
    if (!list->tail) return NULL;
    return list->tail->data;
}

void dll_free(DoubleLinkedList *list) {
    DllNode *current = list->head;
    while (current) {
        DllNode *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}

