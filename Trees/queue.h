#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *l;
    struct node *r;
};
struct queue
{
    struct node *data;
    struct queue *next;
};
struct queue *front = NULL, *rear = NULL;

//Inserting in the queue

void enqueue(struct node *x)
{
    struct queue *t;
    t = (struct queue *)malloc(sizeof(struct queue));
    t->data = x;
    t->next = NULL;
    if (t == NULL)
        printf("Queue is full\n");
    else
    {
        if (front == NULL)
        {
            front = t;
            rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

//deleting from the queue

struct node *dequeue()
{
    struct node *t;
    if (front == NULL)
        printf("queue is empty\n");
    else
    {
        t = front->data;
        struct queue *p = front;
        front = front->next;
        free(p);
    }
    return t;
}

int isempty()
{
    return (front == NULL) ? 0 : 1;
}
