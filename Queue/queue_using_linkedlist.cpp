#include <iostream>
using namespace std;
class queue
{
private:
    int data;
    queue *next;

public:
    void enqueue(int p);
    int dequeue();
    int isempty();
} *front = nullptr, *rear = nullptr;
void queue::enqueue(int p)
{
    queue *t;
    if (t == nullptr)
        cout << "Queue is full\n";
    else
    {
        t->data = p;
        t->next = nullptr;
        if (front == nullptr)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int queue::dequeue()
{
    int t = -1;
    if (front == nullptr)
        cout << "Queue is empty\n";
    else
    {

        t = front->data;
        queue *p;
        p = front->next;
        delete (p);
    }
    return t;
}
int queue::isempty()
{
    return (front == nullptr) ? 0 : 1;
}
int main()
{
    return 0;
}