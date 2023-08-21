#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node *next;
};

typedef struct LinkedListPointers
{
    struct node *head;
} LinkedList;

LinkedList *Create_linked_list(){
    LinkedList *list = malloc(sizeof(LinkedList));
    check_addr(list);
    
    list->head = NULL;

    return list;
}

int destroy_linked_list(LinkedList *list){
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
int push_front(LinkedList *list, int value){
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    check_addr(newnode);
    check_addr(temp);

    newnode->next = NULL;
	newnode->data = value;

    if (list->head == NULL){
		list->head = newnode;
		return 1;
	}
    else{
		temp = list->head;
		list->head = newnode;
		newnode->next = temp;
	}
}


void check_addr(void *ptr){
    if (ptr == NULL){
        printf("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
}
int main(){
    LinkedList *list = Create_linked_list();
    push_front(list, 1234567);
    push_front(list, 1234569);

    printf("%d", *list->head);
}