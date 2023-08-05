#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // connstructor
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head; 
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{

    // all i need to do is travel till pos-1 change its address to new node
    // and newnode->pos is equal to the (pos-1)->index;

    // handling if position is one
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int ct = 1;
    while (ct < pos - 1)
    {
        temp = temp->next;
        ct++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

int getlength(Node *head)
{

    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        // deleting head node
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any other node
        Node *curr = head;
        Node *prev = NULL;
        int ct = 1;
        while (ct < pos)
        {
            prev = curr;
            curr = curr->next;
            ct++;
        }
        prev->next = curr->next;
        if (curr->next == NULL)
            tail = prev;
        curr->next = NULL;
        delete curr;
    }
}
