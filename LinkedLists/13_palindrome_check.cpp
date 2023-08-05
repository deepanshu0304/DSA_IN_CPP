#include<bits/stdc++.h>
#include "00_structure_link_list.cpp"
using namespace std;
/*
1.) we can create array copy the data and then we will check for palindrome.
2.) we will travel till mid point of link list and then after mid point we will reverse the link list
and willl compare both the halvs to check for palindrome...after checking we will again reverse it so that we 
can undo the modification we did.we will write code for this approach
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

Node *reverse(Node *&head)
{
    // iterative approach
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(Node*head){
  // constraint is given is que that link list will not be empty so no need of keeping null check
  if(head->next==NULL){
    return true;
  }
  // step 1 -> find mid
  Node *mid = middle(head);

//   step 2 ->reverse list after middle
  mid->next = reverse(mid->next);

  // step 3 -> compare halves
  Node *head1 = head;
  Node *head2 = mid->next;
  while(head2!=NULL){
    if(head1->data!=head2->data){
      mid->next = reverse(mid->next);
      return false;
    }
    else{
        head1 = head1->next;
        head2 = head2->next;
    }
  }
  mid->next = reverse(mid->next);
  return true;
}
int main(){

  Node *head = new Node(18);
  insertAtHead(head,18);

  print(head);
  bool ans = isPalindrome(head);
  print(head);
  cout<<ans<<endl;

  return 0;
}