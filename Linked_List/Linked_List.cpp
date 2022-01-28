#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next
};
class linkedlist
{
private:
    Node *head;

public:
    linkedlist()
    {
        head = NULL;
    }
    linkedlist(int arr[], int n);
    void display();
    void sum();
    int max();
    Node *search();
    void insert();
    void remove();
    int sorted();
    void reverse();
};
int main()
{
}