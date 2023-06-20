#include <stdio.h>
#include <stdlib.h>

//void at(int array, int index);
int* new(int size);
int at(int *arrptr, int index);
int main()
{
    return 0;
}

//vector realization
int* new(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}

int size(int arr[]) // Returned array size. Can be better not O(n). In python function len() have a O(1)
{
    int size = 0;

    int *ptr = arr;

    while (*ptr != '\0') 
    {
        ptr++;
        size++;
    }
    return size;
}
int is_empty(int arr[]) // returned 1 if array is empty
{
    if (size(arr) == 0){
        return 1;
    }
    return 0;
}
int at(int array[], int index) // must return an element by index, resizes if the index is out of range
{
    if (index > size(array )) // must resizes if the index is out of range
    {
        int* new_array = new(index + 2);
        array = new_array;
    }    
    int *arr = array; 
    arr = arr + index; //return the element by index using arifmetic of arrays 
   
    return *arr;
}

