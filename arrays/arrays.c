#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct ImplementationArray {
    int size;
    int capacity;
    int *data;
} Array;
//temparary

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

int size(Array *arrptr) // Returned array size. Can be better not O(n). In python function len() have a O(1)
{
    int size = 0;

    while (*arrptr->data != '\0') 
    {
        size++;
        arrptr->data++;
        
    }
    arrptr->size = size;
    return size;
    //Here we done
}
int capacity(Array *arrptr)
{
    return arrptr->capacity;
}
bool is_empty(Array *arrptr) // returned 1 if array is empty
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
        arrptr->capacity = index;
        return 0;
    }
    return *(arrptr->data + index);
    
}

int main()
{
    
    Array *arrptr = new(6);
    int c = capacity(arrptr);
    arrptr->data[0] = 6;
    arrptr->data[1] = 5;
    arrptr->data[2] = 4;
    arrptr->data[3] = 8;


    printf("element: %d\n", at(arrptr, 8));
    printf("capacity: %d\n", arrptr->capacity);
    return 0;
}