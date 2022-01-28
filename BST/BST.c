#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *l;
    struct node *r;
} *root = NULL;

// Creating and inserting in the BST

void insert(int x)
{
    struct node *p = NULL, *t = root, *r = NULL;
    if (root == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = x;
        p->l = p->r = NULL;
        root = p;
        return;
    }

    while (t)
    {
        r = t;
        if (x > t->data)
            t = t->r;
        else if (x < t->data)
            t = t->l;
        else
            return;
    }
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->l = p->r = NULL;
    if (x < r->data)
        r->l = p;
    else
        r->r = p;
}

// Printing the BST

void inorder(struct node *p)
{
    if (p)
    {
        inorder(p->l);
        printf("%d ", p->data);
        inorder(p->r);
    }
}

// Searching int the BST

struct node *Rsearch(struct node *t, int x)
{
    if (t == NULL)
        return NULL;
    else if (x > t->data)
        Rsearch(t->r, x);
    else if (x < t->data)
        Rsearch(t->l, x);
}

// Finding the height of a tree

int height(struct node *p)
{
    int x = 0, y = 0;
    if (p == NULL)
        return 0;
    else
    {
        x = height(p->l);
        y = height(p->r);
        return (x > y) ? x + 1 : y + 1;
    }
}

// Inorder Predecessor

struct node *inpre(struct node *p)
{
    if (p && p->r)
    {
        p = p->r;
    }
    return p;
}

// Inorder sucessor

struct node *insuc(struct node *p)
{
    if (p && p->l)
    {
        p = p->l;
    }
    return p;
}

// Deleting an element in the BST

struct node *Rdelete(struct node *p, int x)
{
    struct node *q;
    if (p == NULL)
        return NULL;
    if (p->l == NULL && p->r == NULL)
    {
        if (root == p)
            root = NULL;
        free(p);
    }
    if (x > p->data)
        p->r = Rdelete(p->r, x);
    else if (x < p->data)
        p->l = Rdelete(p->l, x);
    else
    {
        if (height(p->l) > height(p->r))
        {
            q = inpre(p->l);
            p->data = q->data;
            p->l = Rdelete(p->l, p->data);
        }
        else
        {
            q = inpre(p->r);
            p->data = q->data;
            p->r = Rdelete(p->r, p->data);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        insert(x);
    }
    inorder(root);
}