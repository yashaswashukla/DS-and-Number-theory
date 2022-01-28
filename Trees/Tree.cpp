#include <iostream>
#include "queuecpp.h"
using namespace std;
class tree
{
    node *root;

public:
    tree()
    {
        root = nullptr;
    }
    void createtree();
    void preorder()
    {
        preorder(root);
    }
    void preorder(node *p);
    void postorder() { postorder(root); }
    void postorder(node *p);
    void inorder() { inorder(root); }
    void inorder(node *p);
    void levelorder() { levelorder(root); }
    void levelorder(node *p);
    int count() { return count(root); }
    int count(node *p);
    int height() { return height(root); }
    int height(node *p);
};

void tree::createtree()
{
    node *p, *t;
    queue q;
    cout << "Enter the root value\n";
    int x;
    cin >> x;
    p = new node;
    p->data = x;
    p->l = p->r = nullptr;
    root = p;
    q.enqueue(p);
    while (q.isempty())
    {
        p = q.dequeue();

        cout << "Enter the left child\n";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->l = t->r = nullptr;
            p->l = t;
            q.enqueue(t);
        }

        cout << "Enter the right child\n";
        cin >> x;
        if (x != -1)
        {
            node *t = new node;
            t->data = x;
            t->l = t->r = nullptr;
            p->r = t;
            q.enqueue(t);
        }
    }
}

//Preorder Traversal

void tree::preorder(node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->l);
        preorder(p->r);
    }
}

//Postorder Traversal

void tree::postorder(node *p)
{
    if (p)
    {
        postorder(p->l);
        postorder(p->r);
        cout << p->data << " ";
    }
}

//Inorder Traversal

void tree::inorder(node *p)
{
    if (p)
    {
        inorder(p->l);
        printf("%d ", p->data);
        inorder(p->r);
    }
}

//Level Order traversal

void tree::levelorder(node *p)
{
    queue q;
    cout << p->data << " ";
    q.enqueue(p);
    while (q.isempty())
    {
        p = q.dequeue();
        if (p->l)
        {
            cout << p->l->data << " ";
            q.enqueue(p->l);
        }
        if (p->r)
        {
            cout << p->r->data << " ";
            q.enqueue(p->r);
        }
    }
}

//Counting the total number of nodes in the Tree
int tree::count(node *p)
{
    int x, y;
    if (p)
    {
        x = count(p->l);
        y = count(p->r);
        return x + y + 1;
    }
    else
        return 0;
}

//Height of the tree

int tree::height(node *p)
{
    int x = 0, y = 0;
    if (p == nullptr)
        return 0;
    else
    {
        x = height(p->l);
        y = height(p->r);
        return (x > y) ? x + 1 : y + 1;
    }
}

int main()
{
    tree t;
    t.createtree();
    t.levelorder();
    cout << "\n"
         << t.count();
    return 0;
}