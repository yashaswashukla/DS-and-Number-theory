#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *s;
};
void create(struct stack *a)
{
    scanf("%d", &a->size);
    a->top = -1;
    a->s = (int *)malloc(a->size * (sizeof(int)));
}
void push(struct stack *a, int x)
{
    if (a->top == a->size - 1)
        printf("Stack Overflow\n");
    else
    {
        a->top++;
        a->s[a->top] = x;
    }
}
void display(struct stack a)
{
    while (a.top > -1)
    {
        printf("%d ", a.s[a.top]);
        a.top--;
    }
    printf("\n");
}
int pop(struct stack *a)
{
    int x = -1;
    if (a->top == -1)
        x = -1;
    else
    {
        x = a->s[a->top];
        a->top--;
    }
    return x;
}
int peek(struct stack a, int pos)
{
    int x = -1;
    if (a.top - pos + 1 < 0)
        printf("Invalid Index \n");
    x = a.s[a.top - pos + 1];
    return x;
}
void stacktop(struct stack a)
{
    if (a.top == -1)
        printf("-1\n");
    else
        printf("%d\n", a.s[a.top]);
}
void isEmpty(struct stack a)
{
    if (a.top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}
void isFull(struct stack a)
{
    if (a.top == a.size - 1)
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");
}
int main()
{
    struct stack a;
    create(&a);
    // for (int i = 0; i < a.size; i++)
    // {
    //     int x;
    //     scanf("%d", &x);
    //     push(&a, x);
    // }

    push(&a, 10);
    push(&a, 20);
    push(&a, 30);
    push(&a, 40);
    display(a);
    // int x = pop(&a);
    // display(a);
    // int pos;
    // scanf("%d", &pos);
    // printf("%d\n", peek(a, pos));
    // stacktop(a);
    // isEmpty(a);
    // isFull(a);
}