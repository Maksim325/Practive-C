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
int capacity(Array *arrptr)
{
    return arrptr->capacity;
}
Array *new(int size);
int size(Array *arrptr);
//int capacity(Array *arrptr);
bool is_empty(Array *arrptr);
int at(int *arrptr, int index);
void check_addr(void *ptr);

int main()
{
    
    Array *arrptr = new(6);
    int c = capacity(arrptr);
    arrptr->data[0] = 6;
    arrptr->data[1] = 5;
    arrptr->data[2] = 4;
    arrptr->data[3] = 8;
    //arrptr->data[4] = 2;


    printf("%d\n", size(arrptr));
    printf("%d\n", arrptr->size);
    free(arrptr->data);
    return 0;
}

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
