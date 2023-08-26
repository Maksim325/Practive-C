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
int size(LinkedList *list){
    int size = 0;
    struct node *temp = list->head;
    check_addr(temp);

    while (temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}

bool empty(LinkedList *list){return list->head == NULL;}

int value_at(LinkedList *list, int index){
    if (index > size(list)){
		printf("Index out of range");
		exit(EXIT_FAILURE);
	}
    struct node *temp = list->head;
    for (int i = 0; temp != NULL; i++){
        if (index == i){
            return temp->data;
        }
        temp = temp->next;
    }
}

int pop_front(LinkedList *list){
	if (list->head == NULL){
		printf("Dude... create a node first");
		exit(EXIT_FAILURE);
	}
	struct node *temp = list->head;
	list->head = list->head->next;
	free(temp);
}

int front(LinkedList *list){return list->head->data;}

int back(LinkedList *list){
    struct node *temp = list->head; 
    while(temp != NULL){
        if (temp->next == NULL){
            return temp->data;
        }
        temp = temp->next;
    }
}

void insert(LinkedList *list, int index, int value){
    struct node *temp = list->head, *next, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    check_addr(newnode);
    newnode->data = value;
    for (int i = 0; i < index; i++){
        temp = temp->next;
    }
    next = temp->next;
    temp->next = newnode;
    newnode->next = next;
}
void erase(LinkedList *list, int index){
    struct node *temp = list->head, *next;
    for (int i = 0; i < index; i++){
        
        if (i+1 == index){
            break;
        }
        temp = temp->next;
    }
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
    
}

int remove_value(LinkedList *list, int value){
    struct node *temp = list->head, *next;
    while (temp != NULL){
        if (temp->next->data == value){
            next = temp->next->next;
            free(temp->next);
            temp->next = next;
            break;
        }
        temp = temp->next;
    }
}

int revers(LinkedList *list){
    struct node *curent = list->head, *next, *prev = NULL;
    while (curent){
        next = curent->next;
        curent->next = prev;
        prev = curent;
        curent = next;
    }
    list->head = prev;
}

void check_addr(void *ptr){
    if (ptr == NULL){
        printf("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
}
int main(){
    LinkedList *list = Create_linked_list();
    push_front(list, 84);
    push_front(list, 54);
    push_front(list, 8);
    push_front(list, 2);
    push_front(list, 1);
    revers(list);
    printf("%d", value_at(list, 0)); //8 -  OK
}