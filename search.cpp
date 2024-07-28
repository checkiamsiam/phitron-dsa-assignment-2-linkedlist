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
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    Node *head = NULL;
    while (1)
    {
      int value;
      cin >> value;
      if (value == -1)
      {
        break;
      }
      insertIntoTail(head, value);
    }

    int x;
    cin >> x;

    int position = -1;
    int index = 0;

    Node *tmp = head;
    while (1)
    {
      if (tmp->value == x)
      {
        position = index;
        break;
      }
      if (tmp->next == NULL)
      {
        break;
      }
      tmp = tmp->next;
      index++;
    }

    cout << position << endl;
  }
  return 0;
};
