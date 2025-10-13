#include "../src/double_linked_list.h"
#include <stdio.h>

int main() {
    DoubleLinkedList *list = dll_create(sizeof(int));

    for (int i = 0; i <= 5; i++) {
        dll_append(list, &i);
        printf("Appended: %d\n", i);
    }

    int val = 9;
    dll_prepend(list, &val);
    printf("Prepended: %d\n", val);

    printf("List elements (forward):\n");
    for (size_t i = 0; i < list->size; i++) {
        int *num = (int *)dll_get(list, i);
        printf("Index %lu: %d\n", i, *num);
    }

    printf("First: %d\n", *(int *)dll_get_first(list));
    printf("Last: %d\n", *(int *)dll_get_last(list));

    dll_remove(list, 3);
    printf("After removing index 3:\n");
    for (size_t i = 0; i < list->size; i++) {
        int *num = (int *)dll_get(list, i);
        printf("Index %lu: %d\n", i, *num);
    }

    dll_free(list);
    return 0;
}

