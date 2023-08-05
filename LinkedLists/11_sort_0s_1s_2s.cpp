#include <bits/stdc++.h>
#include "00_structure_link_list.cpp"
using namespace std;
/*
1.) we will count total no of zero one and two then wwe will again traverse llink list we will change the data we will put all zero first then all l1 and then all 2..this is easy we will not solve irt
2.) three different link list anf then will merege it*/

void populate(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *sort(Node *head)
{
    // create three list
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            populate(zerotail, temp);
        }
        else if (temp->data == 1)
        {
            populate(onetail, temp);
        }
        else if (temp->data == 2)
        {
            populate(twotail, temp);
        }
        temp = temp->next;
    }

    // merge three list
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
       onetail->next = twohead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }
    twotail->next = NULL;

    Node *newHead = zerohead->next;
    delete (zerohead);
    delete (onehead);
    delete (twohead);
    return (newHead);
}

int main()
{
    Node *head = new Node(2);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    print(head);

    head = sort(head);
    print(head);
    // sort(head);

    return 0;
}