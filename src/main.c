#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "IntVector.h"

#define NEWLINE printf("-----------------\n")

int main() {
    IntVector *new = int_vector_new(3);
    printf("IntVector new\nSize: %d\nCapacity: %d\nPointer: %p\n", new->size, new->capacity, new->pointer);
    IntVector *copy = int_vector_copy(new);
    printf("IntVector copy\nSize: %d\nCapacity: %d\nPointer: %p\n", copy->size, copy->capacity, copy->pointer);
    printf("Size IntVector copy: %ld\nCapacity: %ld\n", int_vector_get_size(copy), int_vector_get_capacity(copy));
    for (int i = 0; i<int_vector_get_capacity(copy); i++) {
	int_vector_push_back(copy,i);
	printf("Items: %d\n", int_vector_get_item(copy, i));
    }
    NEWLINE;
    int_vector_free(copy);
    printf("IntVector copy after free\nSize: %d\nCapacity: %d\nPointer: %p\n", copy->size, copy->capacity, copy->pointer);
    for (int i = 0; i<int_vector_get_size(copy); i++) {
	printf("Items: %d\n", int_vector_get_item(copy, i));
    }
    NEWLINE;
    for (int i = 0; i<int_vector_get_capacity(new); i++) {
	int_vector_push_back(new, i);
	printf("Items: %d\n", int_vector_get_item(new, i));
    }
    printf("Item 2: %d\n", int_vector_get_item(new, 2));
    printf("Before pop_back: Size: %ld\n", int_vector_get_size(new));
    int_vector_pop_back(new);
    printf("After: Size: %ld\n", int_vector_get_size(new));
    for (int i = 0; i<int_vector_get_size(new); i++) {
	printf("Items: %d\n", int_vector_get_item(new, i));
    }
    int_vector_set_item(new, 0, 777);
    for (int i = 0; i<int_vector_get_size(new); i++) {
	printf("Items %d : %d\n",i, int_vector_get_item(new, i));
    }
    NEWLINE;
    IntVector *new_new = int_vector_new(5);
    int_vector_set_item(new_new, 0, 10);
    printf("Size: %ld\nCap: %ld\n", int_vector_get_size(new_new), int_vector_get_capacity(new_new));
    int_vector_shrink_to_fit(new_new);
    printf("Size: %ld\nCap: %ld\n", int_vector_get_size(new_new), int_vector_get_capacity(new_new));
    NEWLINE;
    IntVector *new_new_new = int_vector_new(5);
    int_vector_resize(new_new_new, 6);
	for (int i = 0; i<int_vector_get_capacity(new_new_new); i++) {
	printf("Item %d : %d\n", i, int_vector_get_item(new_new_new, i));
    }
    NEWLINE;
    IntVector *new_1 = int_vector_new(5);
    int_vector_resize(new_1, 3);
    printf("Size: %ld\n Cap: %ld\n", int_vector_get_size(new_1), int_vector_get_capacity(new_1));
    NEWLINE;
    IntVector *new_2 = int_vector_new(5);
    printf("Cap: %ld\n", int_vector_get_capacity(new_2));
    int_vector_reserve(new_2, 8);
    printf("New Cap: %ld\n", int_vector_get_capacity(new_2));
    return 0;
}
