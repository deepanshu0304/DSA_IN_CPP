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
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    // cout << head << endl;
    head = temp;
    // cout << head << endl;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(Node *&head, Node* &tail, int pos, int d)
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

void deleteNode(Node *&head,Node * &tail, int pos)
{
    if(pos==1){
       // deleting head node
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
       // deleting any other node
        Node *curr = head;
        Node *prev = NULL;
        int ct = 1;
        while(ct<pos){
            prev = curr;
            curr = curr->next;
            ct++;
        }
        prev->next = curr->next;
        if(curr->next==NULL)
        tail = prev;
        curr->next=NULL;
        delete curr;
    }
}

int main()
{

    // Node n1(10);             // static allocation
    Node *n2 = new Node(16); // dynamic allocation
    // cout << n1.data << " " << n1.next;

    // cout << n2->data << endl;

    Node *head = n2; // this will point to head
    // now we also want that we can insert element in backward also hen we need to maintai tail
    Node *tail = n2;
    // because if there is single element it is head and it is tail also
    cout << n2 << " " << head << endl;
    // print(head);

    insertAtHead(head, 12);
    // print(head);

    insertAtHead(head, 123);
    // print(head);

    insertAtTail(tail, 44);
    print(head);

    insertAtPosition(head, tail, 5, 18);
    print(head);

    cout << head->data << " " << tail->data<<endl;

    deleteNode(head,tail, 5);
    print(head);
    

    cout << head->data << " " << tail->data<<endl;
    return 0;
}