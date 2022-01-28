#include <stdio.h>

void create(int p[], int t)
{
    for (int i = 0; i < t; i++)
    {
        // printf("Enter the coefficient of x^%d\n", i);
        scanf("%d", &p[i]);
    }
}

//Addition of two Polynomials

void add(int p1[], int t1, int p2[], int t2)
{
    int max;
    max = (t1 >= t2) ? t1 : t2;
    int p3[max];
    for (int i = 0; i < max; i++)
        p3[i] = 0;
    for (int i = 0; i < t1; i++)
        p3[i] = p1[i];
    for (int i = 0; i < t2; i++)
        p3[i] += p2[i];
    for (int i = 0; i < max; i++)
        printf("%dx^%d ", p3[i], i);
}

//Multiplication of Polynomials

void multiply(int p1[], int t1, int p2[], int t2)
{
    int p3[t1 + t2 - 1];
    for (int i = 0; i < t1 + t2 - 1; i++)
        p3[i] = 0;
    for (int i = 0; i < t1; i++)
    {
        for (int j = 0; j < t2; j++)
            p3[i + j] += p1[i] * p2[j];
    }
    for (int i = 0; i < t1 + t2 - 1; i++)
        printf("%dx^%d ", p3[i], i);
}
int main()
{
    int t1, t2;
    scanf("%d %d", &t1, &t2);
    int p1[t1], p2[t2];
    for (int i = 0; i < t1; i++)
    {
        // printf("Enter the coefficient of x^%d\n", i);
        scanf("%d", &p1[i]);
    }
    // create(p1, t1);
    // create(p2, t2);
    for (int i = 0; i < t2; i++)
    {
        // printf("Enter the coefficient of x^%d\n", i);
        scanf("%d", &p2[i]);
    }
    int p;
    scanf("%d", &p);
    switch (p)
    {
    case 1:
        add(p1, t1, p2, t2);
        break;
    case 2:
        multiply(p1, t1, p2, t2);
        break;
    }
}