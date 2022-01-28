#include <iostream>
using namespace std;

//class for node of a tree

class node
{
public:
    int data;
    node *l;
    node *r;
};

//Class for the queue

class queue
{
private:
    node *data;
    queue *next;

public:
    void enqueue(node *p);
    node *dequeue();
    int isempty();
} *front = nullptr, *rear = nullptr;

void queue::enqueue(node *p)
{
    queue *t;
    t = new queue;
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

node *queue::dequeue()
{
    node *t = nullptr;
    if (front == nullptr)
        cout << "Queue is empty\n";
    else
    {

        t = front->data;
        queue *p;
        p = front;
        front = front->next;
        delete (p);
    }
    return t;
}
int queue::isempty()
{
    return (front == nullptr) ? 0 : 1;
}
