#include <stdio.h>

int main()
{
    int array[16] = {};
    //printf("%d", array[2]);
    int *arr = array;
    int index = 2;
    arr = arr + index;
    //arr++;
    int length = sizeof(array) / 4;    

    printf("%d", is_empty(array));
    //printf("%d", *arr);

    return 0;
}
int size(int arr[]) // can be better not O(n). In python function len() have a O(1)
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
int is_empty(int arr[])
{
    if (size(arr) == 0){
        return 1;
    }
    return 0;
}