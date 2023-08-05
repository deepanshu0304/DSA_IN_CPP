#include<bits/stdc++.h>
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

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory freed for : " << val << endl;
    }
};

void insertAtHead(Node *&head,  int d)
{

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        // tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
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

Node* reverseIte(Node* head){
 
    if(head==NULL|| head->next==NULL){
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* kreverseIte(Node* head,int pos){
 
    if(head==NULL|| head->next==NULL){
        return head;
    }
    int cnt = 0;

    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while(curr!=NULL && cnt<pos){
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        cnt++;
    }
    head->next = kreverseIte(curr, pos);
    return prev;
}

int main(){
    Node *head = new Node(6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 11);
    insertAtHead(head, 102);
    print(head);

    head = reverseIte(head);
    print(head);

    insertAtHead(head, 10);
    print(head);

    head = reverseIte(head);
    print(head);

    insertAtHead(head, 12);
    print(head);

    head = reverseIte(head);
    print(head);
    
    head = reverseIte(head);
    print(head);
    head = kreverseIte(head, 3);
    print(head);
    return 0;
}