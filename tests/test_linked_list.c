#include "../src/linked_list.h"
#include <stdio.h>

int main() {
    LinkedList *list = list_create(sizeof(int));

    for (int i = 0; i < 5; i++) {
        list_append(list, &i);
        printf("Appended: %d\n", i);
    }

    int val = 99;
    list_prepend(list, &val);
    printf("Prepended: %d\n", val);

    printf("List elements:\n");
    for (size_t i = 0; i < list->size; i++) {
        int *num = (int *)list_get(list, i);
        printf("Index %lu: %d\n", i, *num);
    }

    list_remove(list, 2);
    printf("After removing index 2:\n");
    for (size_t i = 0; i < list->size; i++) {
        int *num = (int *)list_get(list, i);
        printf("Index %lu: %d\n", i, *num);
    }

    list_free(list);
    return 0;
}

