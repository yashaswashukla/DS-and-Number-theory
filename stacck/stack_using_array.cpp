#include <iostream>
#include <string>
using namespace std;
class stack
{
private:
    int size;
    int top;
    int *t;

public:
    stack()
    {
        size = 0;
        top = -1;
    }
    stack(int s)
    {
        size = s;
        top = -1;
        t = new int[size];
    }
    void push(int x);
    void display();
    int pop();
    int peek(int pos);
    int stacktop();
    int isEmpty();
    void isFull();
};
void stack::push(int x)
{
    if (top == size - 1)
        cout << "Stack Overflow\n";
    else
    {
        top++;
        t[top] = x;
    }
}
void stack::display()
{
    int x = top;
    while (x > -1)
    {
        cout << t[x] << " ";
        x--;
    }
    cout << endl;
}
int stack::pop()
{
    int x = -1;
    if (top == -1)
        return x;
    else
    {
        x = t[top];
        top--;
    }
    return x;
}
int stack::peek(int pos)
{
    int x = -1;
    if (top - pos + 1 < 0)
        cout << "Invalid Index\n";
    x = t[top - pos + 1];
    return x;
}
int stack::stacktop()
{
    if (top == -1)
        return -1;
    else
        return t[top];
}
void stack::isFull()
{
    if (top == size - 1)
        cout << "Stack is full\n";
    else
        cout << "stack is not full\n";
}
int stack::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    cin >> n;
    stack a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    a.display();
    a.pop();
    a.display();
    int pos;
    cin >> pos;
    a.peek(pos);
}