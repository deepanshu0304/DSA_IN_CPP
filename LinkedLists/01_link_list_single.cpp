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
    Node *next; // pointer pointing to next node of linked list
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

    // all we need to do is travel till pos-1 change its address to new node
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
    /* 
    1.) We will receive head of link list.
    2.) We will traverse whole link list and will the data stored in it.
    3.) Every node will contain the address of next node except last which will contain NULL( absence of value).
    4.) So we will make a pointer pointing to head and we will always change its value to its next pointer and print its data.
    5.) We will terminate when we reach NULL.
    
       */
    
    Node *temp = head; // intialized pointer as specified in step-4.
    while (temp != NULL)
    {
        cout << temp->data << " "; // printing its data.
        temp = temp->next; // changing our pointer address to point to next node.
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

    
    // Node n1(10);   // static allocation
    Node *head = new Node(16); // dynamic allocation
    // intitialized a head of our link list with value of 16 and whose next pointer will be pointing to NULL.
   
    // we can always insert a element at start of linklist but sometime its required to insert new element at end of link list.
    // so for that we need to maintain tail also
    // as currently there is only single node in our linklist so that node will be head and tail also.
    
    Node *tail = n2; // head and tail pointing to same node.
    // because if there is single element it is head and it is tail also
    cout << n2 << " " << head << endl;
    // print(head);

    insertAtHead(head, 12);  // this function will insert a node with value 12 at start of linklist
    // print(head);

    insertAtHead(head, 123);
    // print(head);

    insertAtTail(tail, 44);  // this function will insert a node with value 44 (you can take value and send here) at end of linklist
    // print(head);

    insertAtPosition(head, tail, 5, 18);  // this funtion receive  4 parameters i) head of list ii) tail iii) position iv) value of node
    // print(head);

    // cout << head->data << " " << tail->data<<endl;

    deleteNode(head,tail, 5); // It will delete node from linklist whose value is 5..In case of duplicate it will delete first instance.
    // print(head);
    

    // cout << head->data << " " << tail->data<<endl;
    return 0;
}
