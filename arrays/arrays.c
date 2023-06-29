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

int size(Array *arrptr)
{
    return arrptr->size;
}
int capacity(Array *arrptr)
{
    return arrptr->capacity;
}
bool is_empty(Array *arrptr)
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
int push(Array *arrptr, int item)
{
    if (arrptr->size > 0 && arrptr->size == arrptr->capacity ){
        arrptr->capacity += 1;
        arrptr->data = realloc(arrptr->data, arrptr->capacity * sizeof(int));
    }
    *(arrptr->data + arrptr->size) = item;
    arrptr->size++;
}
void insert(Array *arrptr, int item, int index) // insert element by index
{
    for (int i = arrptr->size; i > index; i--){
        arrptr->data[i] = arrptr->data[i-1];
    }
    *(arrptr->data + index) = item;
}
void delete_arr(Array *arrptr)
{
    free(arrptr->data);
    free(arrptr);

}
int pop(Array *arrptr){
    if (arrptr->size == 0){
        exit(EXIT_FAILURE);
    }

    int temp_element = *(arrptr->data + arrptr->size-1);
    arrptr->size--;
    return temp_element;
}

void delete(Array *arrptr, int index)
{
    if (arrptr->size == 0){
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < arrptr->size-1; i++){
        arrptr->data[i] = arrptr->data[i+1];
    }
    *(arrptr->data + index) = 0;
    arrptr->size--;
}

int find(Array *arrptr, int item)
{
    for (int i = 0; i < arrptr->size; i++){
        if (*(arrptr->data + i) == item){
            return i;
        }
    }
    return -1;
}