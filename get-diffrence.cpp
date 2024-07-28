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

int main()
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

  int min, max = 0;

  Node *tmp = head;
  while (1)
  {
    if (tmp->value > max)
    {
      max = tmp->value;
    }
    if (tmp->value < min)
    {
      min = tmp->value;
    }
    if (tmp->next == NULL)
    {
      break;
    }
    tmp = tmp->next;
  }
  int diff = max - min;
  cout << diff;

  return 0;
};
