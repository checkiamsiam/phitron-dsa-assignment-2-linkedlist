#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int value;
  Node *next;
  Node(int value)
  {
    this->value = value;
    this->next = NULL;
  }
};

void insertIntoHead(Node *&head, int val)
{
  Node *newVal = new Node(val);
  newVal->next = head;
  head = newVal;
}

void insertIntoTail(Node *&head, int val)
{
  Node *newVal = new Node(val);
  if (head == NULL)
  {
    head = newVal;
    return;
  }
  Node *tail = head;
  while (1)
  {
    if (tail->next == NULL)
    {
      break;
    }
    tail = tail->next;
  }
  tail->next = newVal;
}

void deleteAtPostion(Node *&head, int pos)
{
  if (pos < 0)
  {
    return;
  }
  if (pos == 0)
  {
    head = head->next;
    delete head;
    return;
  }
  Node *tmp = head;
  for (int i = 1; i <= pos - 1; i++)
  {
    tmp = tmp->next;
    if (tmp == NULL)
    {
      return;
    }
  }
  if (tmp->next == NULL)
  {
    return;
  }
  Node *forDelete = tmp->next;
  tmp->next = forDelete->next;
  delete forDelete;
}

void printList(Node *&head)
{
  Node *tail = head;
  while (1)
  {
    cout << tail->value << " ";
    if (tail->next == NULL)
    {
      break;
    }
    tail = tail->next;
  }
  cout << endl;
}

int main()
{
  Node *head = NULL;
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++)
  {
    int option, val;
    cin >> option >> val;
    if (option == 0)
    {
      insertIntoHead(head, val);
    }
    else if (option == 1)
    {
      insertIntoTail(head, val);
    }
    else if (option == 2)
    {
      deleteAtPostion(head, val);
    }
    printList(head);
  }
  return 0;
};
