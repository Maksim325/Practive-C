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
	if (index > size()){
		printf("Index out of range");
		exit(EXIT_FAILURE);
	}
	struct node *temp = head;
	int i = 0;
	while (temp != NULL){
		
		if (index == i){
			return temp->data;
		}
		temp = temp->next;
		i++;
	}
}
void pop_front(){
	if (head == NULL){
		printf("Dude... create a node first");
		exit(EXIT_FAILURE);
	}
	struct node *temp = head;
	head = head->next;
	free(temp);
}

int main(){
	head = NULL;
	push_front(16);
	push_front(10);
	push_front(8);
	push_front(11);
	pop_front();
	printf("%d, size: %d", value_at(0),size()); //16
}