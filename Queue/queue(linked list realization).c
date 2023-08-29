#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node *next;
};

typedef struct QueuePointers
{
    struct node *head;
    struct node *tail
} QPointers;

QPointers *Create_queue(){
    QPointers *list = malloc(sizeof(QPointers));
    check_addr(list);
    
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int destroy_queue(QPointers *list){
    struct node *temp, *next;
    check_addr(temp);
    check_addr(next);
    temp = list->head;
    while (temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
}

