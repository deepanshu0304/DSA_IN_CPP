#include<bits/stdc++.h>
#include"00_structure_link_list.cpp"
using namespace std;

Node* reverseIte(Node* &head){
 // iterative approach
    Node *prev = NULL;
    Node *curr = head; 
    Node* forward = NULL;

    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
} 

void reverseRec1(Node* & head,Node*curr,Node*prev){
  
   if(curr==NULL){
        head = prev;
        return;                                                                                                                                                                                                                                                                                                                     
   }

   reverseRec1(head, curr->next, curr);
   curr->next = prev;
}

Node* reverseRec2(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node *newHead = reverseRec2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main(){

    Node *head = new Node(18);

    insertAtHead(head, 17);
    insertAtHead(head, 11);
    insertAtHead(head, 122);    

    print(head);

    head = reverseIte(head); // iterative approach
    print(head);


    // recursive approach 1
    reverseRec1(head, head, NULL);
    print(head);

    // recursive approach 2
    head = reverseRec2(head);
    print(head);

    insertAtHead(head,212);
    print(head);

    head= reverseIte(head);
    print(head);

    cout << getlength(head) << endl;
    return 0;
}