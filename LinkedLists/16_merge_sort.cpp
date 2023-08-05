#include<bits/stdc++.h>
#include "00_structure_link_list.cpp"
using namespace std;
/*
one tpe in which we can sort is first we will copy our data in array we will sort array and then copy it again in link list or instead of array we can use set or any other data structure

another method if we are not allow to change the data ....we are allowed to change only links and sort it 
*/
Node* middle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        
        slow = slow->next;
    }

    return slow;
}

Node* merge(Node*left,Node*right){
    if(left == NULL) return right;
    if(right == NULL) return left;

    Node *ans =  new Node(-1);
    Node *temp = ans;

    while(left!=NULL  && right!=NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

Node* sortList(Node*head){
   
   if(head==NULL || head->next == NULL){
       return head;
   }

   Node *mid = middle(head);

   Node *left = head;
   Node *right = mid->next;
   mid->next = NULL;

   left = sortList(left);
   right = sortList(right);

   Node *result = merge(left, right);

   return result;
}
int main(){

    Node *head = new Node(1);
    insertAtHead(head, 4);
    insertAtHead(head, 2);
    insertAtHead(head, 5);
    insertAtHead(head,3);
    print(head);

    head = sortList(head);
    print(head);
    return 0;
}