#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *first = NULL;

//creating a doubly linked list

void create(int arr[], int n)
{
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

//displaying the linked list

void display(struct node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//inserting in a doubly liked list

void insert(struct node *p, int index, int x)
{
    if (index == 0)
        return;
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    t->prev = NULL;
    if (index == 0)
    {
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
        t->prev = p;
    }
}

//removing an element from the linked list

void delete (struct node *p, int n)
{
    for (int i = 0; i < n; i++)
        p = p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
}

//reversing a Doubly linked list
void reverse(struct node *p)
{
    struct node *temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    create(arr, n);
    display(first);
    // int index, x;
    // scanf("%d %d", &index, &x);
    // insert(first, index, x);
    // display(first);
    // delete (first, 3);
    // display(first);
    reverse(first);
    display(first);
}