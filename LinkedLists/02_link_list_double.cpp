#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;

        }
        cout << "memory freed for : " << val << endl;
    }
};

void insertAtHead(Node *&head,Node* &tail, int d)
{

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head,Node *&tail, int d)
{
    if(tail==NULL){
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int d, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head,tail, d);
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
        insertAtTail(head,tail, d);
        return;
    }
    Node *toinsert = new Node(d);
    toinsert->prev = temp;
    toinsert->next = temp->next;
    temp->next = toinsert;
    temp->next->prev = toinsert;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

void deleteNode(Node* &head,Node* &tail,int pos){
    if(pos==1){
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node *curr = head;
        Node *previ = NULL;
        int ct = 1;
        while(ct<pos){
            previ = curr;
            curr = curr->next;
            ct++;
        }
        curr->prev = NULL;
        previ->next = curr->next;
        if(curr->next==NULL){
            tail = previ;
        }
        else {
        curr->next->prev = previ;
        curr->next = NULL;
        }
        delete curr;
    }
}
int main()
{

    Node *n1 = new Node(9);
    Node *head = NULL;
    Node *tail = NULL;
    print(head);
    // cout << getlength(head)<<endl;

    insertAtHead(head,tail, 11);
    print(head);
    // cout << getlength(head)<<endl;

    insertAtTail(head,tail, 18);
    print(head);
    // cout << getlength(head)<<endl;

    insertAtTail(head,tail, 17);
    print(head);
    // cout << getlength(head)<<endl;

    insertAtPosition(head, tail, 45, 2);
    print(head);

    insertAtTail(head,tail, 177);
    print(head);
    // cout << getlength(head)<<endl;

    insertAtPosition(head, tail, 4565, 3);
    print(head);

    insertAtHead(head, tail,1351);
    print(head);

    insertAtTail(head,tail, 4577);
    print(head);

    insertAtTail(head,tail, 2902);
    print(head);

    cout << getlength(head) << endl;

    deleteNode(head, tail, 1);
    print(head);

    deleteNode(head, tail, 8);
    print(head);

    deleteNode(head, tail, 3);
    print(head);

    deleteNode(head, tail, 1);
    print(head);

    deleteNode(head, tail, 5);
    print(head);

    deleteNode(head, tail, 2);
    print(head);

     
    cout << getlength(head) << endl;

    cout << head->data << " " << tail->data << endl;
    return 0;
}