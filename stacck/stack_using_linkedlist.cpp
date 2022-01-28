#include <iostream>
using namespace std;
class node
{
public:
    node *next;
    int data;
};
class stack
{
private:
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    void display();
    int peek(int pos);
    int isFull();
    int isEmpty();
    int stacktop();
};
void stack::push(int x)
{
    node *t = new node;
    if (t == NULL)
        cout << "Stack is full\n";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int stack::pop()
{
    int x = -1;
    if (top == NULL)
        cout << "Stack is empty\n";
    else
    {
        node *p = top;
        x = top->data;
        top = top->next;
        delete p;
    }
    return x;
}
void stack::display()
{
    node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int stack::peek(int pos)
{
    int x = -1;
    node *p;
    for (int i = 0; p != NULL && i < pos - 1; i++)
        p = p->next;
    if (p)
        return p->data;
    else
        return x;
}
int stack ::stacktop()
{
    if (top)
        return top->data;
    else
        return -1;
}
int stack::isEmpty()
{
    return (top) ? 1 : 0;
}
int stack::isFull()
{
    node *t = new node;
    int r = (t) ? 1 : 0;
    free(t);
    return r;
}
int main()
{
    int n;
    cin >> n;
    stack a;
    while (n--)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    a.display();
}