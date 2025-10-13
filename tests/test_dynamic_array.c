#include "../src/dynamic_array.h"
#include <stdio.h>

int main() {
    DynamicArray *arr = array_create(sizeof(int));

    for (int i = 0; i < 25; i++)
        array_push(arr, &i);

    for (size_t i = 0; i < arr->size; i++) {
        int *val = (int *)array_get(arr, i);
        printf("arr[%lu] = %d\n", i, *val);
    }

    array_free(arr);
    return 0;
}

