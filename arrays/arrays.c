#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MinCapacity = 16;
const int CrowthFactor = 2;

typedef struct ImplementationArray {
    int size;
    int capacity;
    int *data;
} Array;
//temparary
void upsize(Array *arrptr);
void downsize(Array *arrptr);
void check_addr(void *ptr);


//vector realization
Array *new(int capacity) {
    Array *arr = malloc(sizeof(Array));
    check_addr(arr);
    arr->size = 0;
    arr->capacity = capacity;
    arr->data = (int *)malloc(sizeof(int) * capacity);
    check_addr(arr->data);
    return arr;
}

int size(Array *arrptr) // Dont work
{
    int size = 0;

    while (*arrptr->data != '\0') 
    {
        size++;
        arrptr->data++;
        
    }
    arrptr->size = size;
    return size;
}
int capacity(Array *arrptr)
{
    return arrptr->capacity;
}
bool is_empty(Array *arrptr) // returned true if array is empty
{
    return arrptr->size == 0;
}

void check_addr(void *ptr)
{
    if (ptr = NULL){
        printf("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
}

int at(Array *arrptr, int index) // return element by index. If index out of range changing the capacity
{
    if (index > arrptr->capacity){
        int old_capacity = arrptr -> capacity;
        int new_capacity = old_capacity + (index-old_capacity)+1;
        int *new_data = realloc(arrptr->data, new_capacity * sizeof(int));
        arrptr->data = new_data;
        arrptr->capacity = new_capacity;
        return 0;
    }
    return *(arrptr->data + index);
    
}
// tests
int main()
{
    
    Array *arr = new(MinCapacity);
    int element = at(arr,10);
    
    for (int i = 1; i <= MinCapacity; i++){
        arr->data[i] = i;
    }

    for (int i = 1; i <= MinCapacity; i++){
        printf("element %d: %d\n", i, arr->data[i]);
    }
    arr->data[10] = 0;

    size(arr);
    printf("capacity: %d\n", arr->capacity);
    printf("size(arr): %d\n", arr->size);
    printf("size: %d\n", size(arr));
    return 0;
}