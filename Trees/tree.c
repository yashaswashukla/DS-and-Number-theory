#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
struct node *root = NULL;

//Creating the tree

void create()
{
    struct node *p;
    int x;
    struct queue *q;
    printf("Enter root value");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
    root->l = root->r = NULL;
    root->data = x;
    enqueue(root);
    while (isempty())
    {
        p = dequeue();
        int l, r;
        printf("\nEnter Left child:");
        scanf("%d", &l);
        if (l == -1)
            p->l = NULL;
        else
        {
            struct node *t;
            t = (struct node *)malloc(sizeof(struct node));
            t->data = l;
            t->l = t->r = NULL;
            p->l = t;
            enqueue(t);
        }

        printf("\nEnter right child:");
        scanf("%d", &r);
        if (r == -1)
            p->r = NULL;
        else
        {
            struct node *t;
            t = (struct node *)malloc(sizeof(struct node));
            t->data = r;
            t->l = t->r = NULL;
            p->r = t;
            enqueue(t);
        }
    }
}

//printing the tree
void preorder(struct node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->l);
        preorder(p->r);
    }
}
int main()
{
    create();
    preorder(root);
}