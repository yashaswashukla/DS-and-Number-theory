#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int front, rear, size;
    int *a;
};

//Creating a Queue

void create(struct queue *q)
{
    scanf("%d", &q->size);
    q->rear = q->front = 0;
    q->a = (int *)malloc(q->size * sizeof(int));
}
//Pushing a value in the queue

void enqueue(struct queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->a[q->rear] = x;
    }
}

//displaying the queue

void display(struct queue q)
{
    int i = q.front;
    i++;
    while (i <= q.rear)
    {
        printf("%d ", q.a[i++]);
    }
    printf("\n");
}

// deleting the first value

int dequeue(struct queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->a[q->front];
    }
    return x;
}
int main()
{
    struct queue q;
    create(&q);
    for (int i = 0; i < q.size; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }
    display(q);
    printf("%d\n", dequeue(&q));
    display(q);
}