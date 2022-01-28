#include <stdio.h>
#include <stdlib.h>
struct node
{
    int col, val;
    struct node *next;
};
void create(struct node *arr[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            if (x)
            {
                struct node *temp;
                temp = (struct node *)malloc(sizeof(struct node));
                temp->col = n;
                temp->val = x;
                temp->next = NULL;
                arr[m] = temp;
            }
        }
    }
}
void display(struct node *arr[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        struct node *p = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (j == p->col)
            {
                printf("%d ", p->val);
                p = p->next;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    struct node *arr[m];
    create(arr, m, n);
    display(arr, m, n);
}