#include <bits/stdc++.h>
#include "00_structure_link_list.cpp"
using namespace std;

Node* mergetwosort(Node* first, Node* second){

    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    // now the starting element of first list will always be smaller
    // we will traverse second list one by one and will see where it fits in first list;

    Node *curr1 = first;
    Node *next1 = curr1->next;

    Node *curr2 = second;

    while(next1!=NULL&&curr2!=NULL){
        if(curr2->data >= curr1->data && curr2->data <= next1->data){
            curr1->next = curr2;
            Node *temp = curr2->next;
            curr2->next = next1;  
            curr1 = curr2;
            curr2 = temp;
        }
        else {
            curr1 = next1;
            next1 = next1->next;
        }
        
    }
    if(next1==NULL){
        curr1->next = curr2;
    }

    return first;
}
 
int main()
{

    Node *head1 = new Node(1);
    // insertAtHead(head1, 3);
    // insertAtHead(head1, 1);

    Node *head2 = new Node(6);
    insertAtHead(head2, 3);
    insertAtHead(head2,2);
    insertAtHead(head2,2);
    
    Node *head3 = head2->data < head1->data ? mergetwosort(head2, head1) : mergetwosort(head1, head2);
    print(head3);

    return 0;
}