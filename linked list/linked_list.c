#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

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
int size(){
	int size = 0;
	struct node *temp = head;
	while (temp != NULL){
		temp = temp->next;
		++size;
	}
	return size;
}
bool is_empty(){
	if (head == NULL){
		return true;
	}
	return false;
}
int value_at(int index){
	struct node *temp = head;
	int i = 0;
	while (temp != NULL){
		temp = temp->next;
		i++;
		if (index == i){
			return temp->data;
		}
	}

}
int main(){
	head = NULL;
	push_front(16);
	push_front(10);
	push_front(8);
	push_front(10);
	push_front(10);

	printf("%d", value_at(4)); //16
}