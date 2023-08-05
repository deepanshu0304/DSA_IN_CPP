#include <bits/stdc++.h>
#include "00_structure_link_list.cpp"

using namespace std;
/*
here you will be given wit  two link list you need treat them as inumver and add them together
and return a link list representing tht number
*/
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

Node *add(Node *head1, Node *head2)
{
    int firstNode = head1->data + head2->data;
    int car = firstNode / 10;

    Node *head3 = new Node(firstNode % 10);

    head1 = head1->next;
    head2 = head2->next;

    while (head1 != NULL || head2 != NULL || car!=0)
    {

        int sum = car;

        if (head1 != NULL)
            sum += head1->data;

        if (head2 != NULL)
            sum += head2->data;

        car = sum / 10;

        insertAtHead(head3, sum % 10);

        if (head1 != NULL)
            head1 = head1->next;

        if (head2 != NULL)
            head2 = head2->next;
    }
    
    return head3;
}

Node *addTwoList(Node *head1, Node *head2)
{
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node *head3 = add(head1, head2);

    head1 = reverse(head1);
    head2 = reverse(head2);

    // head3 = reverse(head3);
    return head3;
}

int main()
{

    Node *head1 = new Node(3);
    insertAtHead(head1, 6);
    // insertAtHead(head1, 12);

    Node *head2 = new Node(7);
    // insertAtHead(head2, 79);
    // insertAtHead(head2, 3);

    Node *head3 = addTwoList(head1, head2);
    print(head1);
    print(head2);
    print(head3); 

    return 0;
}