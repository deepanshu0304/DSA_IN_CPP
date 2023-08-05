#include <bits/stdc++.h>
#include "00_structure_link_list.cpp"
using namespace std;

int middleEl(Node *temp, int len)
{
    while (len--)
    {
        temp = temp->next;
    }
    return temp->data;
}

int middleEl2(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow->data;
}
int main()
{

    Node *head = new Node(5);
    for (int i = 12; i <= 18; i++)
    {
        insertAtHead(head, i);
    }
    int len = getlength(head);
    int temp = middleEl(head, len / 2);

    cout << temp << endl;

    int temp2 = middleEl2(head);
    cout << temp2 << endl;
    return 0;
}