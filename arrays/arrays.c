#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ImplementationArray {
    int size;
    int capacity;
    int *data;
} Array;

//temparary
Array *new(int size);
int size(Array *arrptr);
int is_empty(int arr[]);
int at(int *arrptr, int index);
void check_addr(void *ptr);

int main()
{
    
    Array *arrptr = new(4);
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
        arrptr++;
        size++;
    }
    arrptr->size = size;
    return size;
}
int is_empty(int arr[]) // returned 1 if array is empty
{
    if (size(arr) == 0){
        return 1;
    }
    return 0;
}
int at(Array *arrptr, int index) // must return an element by index, resizes if the index is out of range
{
    if (index > *arrptr->data || ) // must resizes if the index is out of range
    {
        
        
    }
        return *newArray;

       
    int *arr = *arrptr->data + index; //return the element by index using arifmetic of arrays 
   
    return *arr;
}
void check_addr(void *ptr)
{
    if (ptr = NULL){
        printf("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
}
