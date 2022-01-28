#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

// Creating a linked list

void create(struct node **p, int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (*p == NULL)
    {
        *p = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

//Displaying the complete linked list

void display(struct node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//Counting the total number of nodes

int count(struct node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

//Adding all the elements of a linked list

int add(struct node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

//Finding a maximum element in a linked list

int max(struct node *p)
{
    int max = p->data;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

//Improved Linear Search in a linked list

// struct node *search(struct node *p, int key)
// {
//     while (p != NULL)
//     {
//         struct node *q = NULL;
//         if (p->data == key)
//         {
//             q->next = p->next;
//             p->next = first;
//             first = p;
//             return p;
//         }
//         q = p;
//         p = p->next;
//     }
// }

//Inserting an element in the linked list

void insert(struct node *p, int index, int x)
{
    struct node *t;
    int i;
    if (index < 0)
        return;
    if (p == NULL)
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
    }

    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (index == 0)
    {
        t->next = p;
        p = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

//delete a node
void remov(struct node *p, int x)
{
    struct node *t = NULL;
    if (x == 1)
    {
        t = p;
        p = p->next;
    }
    else
    {
        for (int i = 0; i < x - 1; i++)
        {
            t = p;
            p = p->next;
        }
        t->next = p->next;
    }
}

//Checking if the list is sorted or not

int sorted(struct node *p)
{
    int x = p->data;
    while (p)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

//reversing the linked list using array

void reverse1(struct node *p)
{
    struct node *e = p;
    int *a, i = 0;
    a = (int *)malloc(sizeof(int) * count(p));
    while (e)
    {
        a[i] = e->data;
        e = e->next;
        i++;
    }
    i--;
    while (p)
    {
        p->data = a[i];
        i--;
        p = p->next;
    }
}

//reversing the array using sliding pointers

void reverse2(struct node *first)
{
    struct node *p = first;
    struct node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        create(&first, x);
    }
    // printf("%d", first->data);
    display(first);
    // int coun = count(first);
    // int ad = add(first);
    // int ma = max(first);
    // printf("\ncount = %d\nmax = %d\nadd = %d\n", coun, ma, ad);
    // printf("%d", search(first, 7));
    // insert(first, 0, 1);
    // insert(first, 2, 2);
    // insert(first, 7, 3);
    // display(first);
    // delete (first, 1);
    // delete (first, 3);
    // display(first);
    // printf("%d\n", sorted(first));
    // reverse2(first);
    // display(first);
}