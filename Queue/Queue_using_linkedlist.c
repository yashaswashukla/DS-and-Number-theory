#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

//Inputing in a queue

void enqueue(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("Queue is full\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

//deleting a element in the queue

int dequeue()
{
    int x = -1;
    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        x = front->data;
        struct node *t = front;
        front = front->next;
        free(t);
    }
    return x;
}

//Displaying a queue
void display()
{
    struct node *t = front;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int c, x;
    do
    {
        printf("\n1.Enter an element in the queue\n2.Delete an element from the queue\n3.Display the queue\n");
        scanf("%d", &c);
        struct node *q;
        switch (c)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            printf("%d \n", dequeue());
            display();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    } while (c < 4);
}