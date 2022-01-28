#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;
void create(int arr[], int n)
{
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct node *p)
{
    if (p != 0)
    {
        printf("%d" p->data);
        display(p->next);
    }
}
int add(struct node *p)
{
    if (p == 0)
        return 0;
    else
        return p->data + add(p->next);
}
int count(struct node *p)
{
    if (p == 0)
        return 0;
    else
        return 1 + add(p->next);
}
int max(struct node *p)
{
    if (p == 0)
        return INT32_MIN;
    x = max(p->next);
    return x > p->data ? x : p->data;
}
int search(null *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    else
        return search(p->next, key);
}

int main()
{
    int arr[5] = {12, 54, 63, 1, 5};
}