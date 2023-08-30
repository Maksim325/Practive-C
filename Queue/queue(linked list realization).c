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
    QPointers *queue = malloc(sizeof(QPointers));
    check_addr(queue);
    
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}
bool empty(QPointers *q){return q->head == NULL;}
int destroy_queue(QPointers *queue){
    struct node *temp, *next;
    check_addr(temp);
    check_addr(next);
    temp = queue->head;
    while (temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(queue);
}

int enqueue(QPointers *q, int value){
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    check_addr(newnode);
    check_addr(temp);

    newnode->next = NULL;
	newnode->data = value;

    if (q->tail) {
    q->tail->next = newnode;
  }
  q->tail = newnode;

  if (q->head == NULL) {
    q->head = newnode;
  }
}

void check_addr(void *ptr){
    if (ptr == NULL){
        printf("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
}

int dequeue(QPointers *q){
    int value = q->head->data;
    if (empty(q) == true){
        printf("Dude.. create element first");
        exit(EXIT_FAILURE);
    }
    struct node *temp = q->head;

    
    q->head = q->head->next;
    free(temp);

    return value;
}


int main(){
    QPointers *q = Create_queue();
    //enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    printf("%d\n ", dequeue(q)); // 2 - OK


}