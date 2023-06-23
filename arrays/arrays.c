#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MinCapacity = 16;

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
void resize(Array *arrptr, cadidate_size)
{
    int size = arrptr->size;
    int capacity = arrptr->capacity;
    if (size < cadidate_size)
    {
        if (size == capacity)
        {
            //upsize
            upsize(arrptr);
        }
    }
    else if (size > cadidate_size)
    {
        if (size < capacity/sizeof(int)){
            //downsize
        }
    }
}
void upsize(Array *arrptr){
    *new_data = (int *)realloc(arrptr->data, sizeof(int) * capacity);
    arrptr->data = new_data;
}

void add(Array *arrptr, int element) //nead resize for size
{
  
        
    *(arrptr->data + arrptr->size) = element;
}

int main()
{
    
    Array *arrptr = new(6);
    int c = capacity(arrptr);
    add(arrptr, 5);
    int s = size(arrptr);
    add(arrptr, 6);


    printf("element: %d\n", arrptr->data[1]);
    printf("size: %d\n", s);
    return 0;
}