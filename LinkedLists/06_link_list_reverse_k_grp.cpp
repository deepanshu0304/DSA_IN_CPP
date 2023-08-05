#include<bits/stdc++.h>
#include "00_structure_link_list.cpp"
using namespace std;

Node* kreverse(Node* head , int k){
    // base case 
    if(head==NULL){
        return NULL;
    }
    // reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // recursion
    if(next!=NULL){
        head->next = kreverse(next, k);
    }

    return prev;
}
int main(){

    Node *head = new Node(6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    head = kreverse(head, 2);
    print(head);

    return 0;
}