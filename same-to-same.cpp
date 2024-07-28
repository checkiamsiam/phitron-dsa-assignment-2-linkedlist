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
  Node *headOne = NULL;
  while (1)
  {
    int value;
    cin >> value;
    if (value == -1)
    {
      break;
    }
    insertIntoTail(headOne, value);
  }
  Node *headTwo = NULL;
  while (1)
  {
    int value;
    cin >> value;
    if (value == -1)
    {
      break;
    }
    insertIntoTail(headTwo, value);
  }

  bool isMatch = true;

  Node *tmpOne = headOne;
  Node *tmpTwo = headTwo;

  while (1)
  {
    if (tmpOne->next == NULL || tmpTwo->next == NULL)
    {
      if (tmpOne->next != tmpTwo->next)
      {
        isMatch = false;
      }
      break;
    }
    if (tmpOne->value != tmpTwo->value)
    {
      isMatch = false;
      break;
    }
    tmpOne = tmpOne->next;
    tmpTwo = tmpTwo->next;
  }

  string message = isMatch ? "YES" : "NO";

  cout << message;

  return 0;
};
