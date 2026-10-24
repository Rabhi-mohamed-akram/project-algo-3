#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node {
    int customernumber;
    struct node *next;
} node;
typedef struct queue{
node *front;
node *rear;
}queue;
void initqueue(queue *q){
q->front=NULL;
q->rear=NULL;
}
int isempty(queue *q){
return (q->front==NULL);
}
void enqueue(queue* q, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->customernumber = data;
    newNode->next = NULL;

    if (isempty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int dequeue(queue* q) {
    if (isempty(q)) {
        printf("queue is empty.\n");
        return -1;
    }
    node* temp = q->front;
    int data = temp->customernumber;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}
int peek(queue* q) {
    if (isempty(q)) {
        printf("queue is empty.\n");
        return -1;
    }
    return q->front->customernumber;
}
void display(queue* q) {
    if (isempty(q)) {
        printf("The queue is empty.\n");
        return;
    }
    node* current = q->front;
    printf("queue: ");
    while (current != NULL) {
        printf("%d ", current->customernumber);
        current = current->next;
    }
    printf("\n");
}
int main() {
    queue bankqueue;
    initqueue(&bankqueue);

     printf("Customer 1 arrived and got a token.\n");
    enqueue(&bankqueue, 1);

     printf("Customer 2 arrived and got a token.\n");
    enqueue(&bankqueue, 2);

    printf("Customer %d is being served.\n", peek(&bankqueue));

    printf("Customer 3 arrived and got a token.\n");
    enqueue(&bankqueue, 3);

    printf("Customer %d served, have a good day.\n",dequeue(&bankqueue));

    printf("Customer %d is being served.\n", peek(&bankqueue));

    printf("Customer %d served, have a good day.\n",dequeue(&bankqueue));

    printf("Customer %d is being served.\n", peek(&bankqueue));
    printf("Customer %d served, have a good day.\n",dequeue(&bankqueue));

    if (isempty(&bankqueue)) {
        printf("queue is empty.\n");
    }

    return 0;
}
