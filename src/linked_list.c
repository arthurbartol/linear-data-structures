#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

LinkedList *list_create(size_t element_size) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->element_size = element_size;
    list->size = 0;
    return list;
}

void list_append(LinkedList *list, void *element) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = malloc(list->element_size);
    memcpy(node->data, element, list->element_size);
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        ListNode *current = list->head;
        while (current->next != NULL)
            current = current->next;
        current->next = node;
    }
    list->size++;
}

void list_prepend(LinkedList *list, void *element) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = malloc(list->element_size);
    memcpy(node->data, element, list->element_size);
    node->next = list->head;
    list->head = node;
    list->size++;
}

void *list_get(LinkedList *list, size_t index) {
    if (index >= list->size)
        return NULL;

    ListNode *current = list->head;
    for (size_t i = 0; i < index; i++)
        current = current->next;
    return current->data;
}

int list_remove(LinkedList *list, size_t index) {
    if (index >= list->size)
        return 0;

    ListNode *temp = NULL;
    if (index == 0) {
        temp = list->head;
        list->head = temp->next;
    } else {
        ListNode *current = list->head;
        for (size_t i = 0; i < index-1; i++)
            current = current->next;
        temp = current->next;
        current->next = temp->next;
    }

    free(temp->data);
    free(temp);
    list->size--;
    return 1;
}

void list_free(LinkedList *list) {
    ListNode *current = list->head;
    while (current != NULL) {
        ListNode *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}

