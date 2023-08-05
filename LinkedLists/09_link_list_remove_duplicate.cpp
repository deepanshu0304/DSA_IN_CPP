#include<bits/stdc++.h>
#include"00_structure_link_list.cpp"
using namespace std;

// this is for sorted linked list.
Node* removeDup(Node* head){
    
    if(head==NULL){
        return NULL;
    }

    Node *curr = head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->next->data==curr->data){
            Node *next_next = curr->next->next;
            Node *todelete = curr->next;
            delete (todelete);
            curr->next = next_next;
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}

// for unsorted link list;
/*it has many approach
1.) we will use two loop for every node we will traverse whole link list
2.)we will maintain a visited map 
3.) we will sort the list and weill use upper method */

Node* removeDuplicate1(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node *curr = head;
    while(curr!=NULL){
        Node *check = curr->next;
        Node *prev = curr;
        while(check!=NULL){
            if(check->data!=curr->data){
                prev = check;
                check = check->next;
            }
            else{
                Node *next_next = check->next;
                Node *todelete = check;
                check = check->next;
                delete (todelete);
                prev->next = next_next;
            }
        }
        curr = curr->next;
    }
    return head;
}

Node* removeDuplicate2(Node* head){
    if (head == NULL)
    {
        return NULL;
    }
    map<int, bool> vis;
    Node *curr = head;
    Node *prev = NULL;
    while(curr!=NULL){
      if(vis[curr->data]){
            Node *next_next = curr->next;
            Node *todelete = curr;
            curr = curr->next;
            delete (todelete);
            prev->next = next_next;
      }
      else{
            vis[curr->data] = true;
            prev = curr;
            curr = curr->next;

      }
    }

    return head;
}


int main(){

    Node *head = new Node(7);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 6);
    insertAtHead(head, 6);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    print(head);

    // head = removeDuplicate1(head);
    // print(head);

    // head = removeDuplicate1(head);
    // print(head);

    

    return 0;
}               