#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
      int data;
      Node *next;
      Node(int d)
      {

            this->data = d;
            this->next = NULL;
      }

      ~Node()
      {
            int value = this->data;
            if (this->next != NULL)
            {
                  delete next;
                  next = NULL;
            }
            cout << "memory free up for : " << value << endl;
      }
};

void insertNode(Node *&tail, int element, int d)
{

      if (tail == NULL)
      {
            Node *temp = new Node(d);
            temp->next = temp;
            tail = temp;
      }
      else
      {

            Node *curr = tail;
            while (curr->data != element)
            {
                  curr = curr->next;
            }
            Node *temp = new Node(d);
            temp->next = curr->next;
            curr->next = temp;
      }
}

void print(Node *tail)
{

      if (tail == NULL)
      {
            cout << "List is empty" << endl;
            return;
      }
      Node *temp = tail;

      do
      {
            cout << tail->data << " ";
            tail = tail->next;
      } while (tail != temp);
}

void deleteNode(Node *&tail, int element)
{

      if (tail == NULL)
            return;
      //   Node *curr = tail;
      //   Node *prev = NULL;

      Node *prev = tail;
      Node *curr = prev->next;
      if (curr == prev)
      {

            tail = NULL;
            return;
      }

      while (curr->data != element)
      {
            prev = curr;
            curr = curr->next;
      }

      prev->next = curr->next;
      if (tail == curr)
      {
            tail = prev;
      }
      curr->next = NULL;
      delete curr;
}
int main()
{

      Node *tail = NULL;
      insertNode(tail, 2, 2);
      insertNode(tail, 2, 4);
      //   insertNode(tail, 2, 5);
      //   insertNode(tail, 2, 67);
      //   insertNode(tail, 4, 66);
      //   print(tail);
      //   deleteNode(tail,5);
      deleteNode(tail, 2);
      print(tail);

      deleteNode(tail, 4);
      print(tail);

      insertNode(tail, 2, 4);
      print(tail);
      return 0;
}