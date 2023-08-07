/*
1.) Link list is data structure which is very similar to array.
2.) Array have continous allocation but linklist dont.
3.) As array have continous allocation you can access it easily if we are given with address of first element.
4.) But for linkList we can not do this so we also need to store the address of the next element.
5.) So a LinkList is collection of nodes(user defined data-type) which can store data of same type like arrays
6.) Where each node has mainly two properties. i) data we waqnt to store(int , char, string,vector,etc..). ii) address of next element
7.) Basic knowledge of classes,constructor,dynamic allocation is required.
For classes you can refer this ---> (https://www.w3schools.com/cpp/cpp_classes.asp).
I will upload classes in somedays.
*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data; // value stored by our node
    Node *next;
    // paramaterized constructor
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
    // print is method defined which will print whole linkList...you can add remove elemenmts using different methods ans can check using
    // print function 

    // Node n1(10);             // static allocation
    Node *n2 = new Node(16); // dynamic allocation

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
    // print(head);

    insertAtPosition(head, tail, 5, 18);
    // print(head);

    // cout << head->data << " " << tail->data<<endl;

    deleteNode(head,tail, 5);
    // print(head);
    

    // cout << head->data << " " << tail->data<<endl;
    return 0;
}
