#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
};

struct node *head;

int push_front(int value){ // push and actually create list
	struct node *newnode, *temp;
	newnode = (struct node*)malloc(sizeof(struct node)); //create a new node
	newnode->next = NULL;
	newnode->data = value;

    if (head == NULL){
		head = newnode;
		return 1;
	}
	else{
	temp = head;
	head = newnode;
	newnode->next = temp;
	}
}

int main(){
	head = NULL;
	push_front(16);
	push_front(10);
	push_front(8);

	printf("%d", *head->next->next);
}