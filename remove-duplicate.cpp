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
    if (head == NULL)
    {
        return;
    }
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

    Node *tmp = head;
    while (1)
    {
        if (tmp == NULL || tmp->next == NULL)
        {
            break;
        }

        Node *innerTmp = tmp;

        while (1)
        {
            if (innerTmp->next == NULL)
            {
                break;
            }

            if (tmp->value == innerTmp->next->value)
            {
                Node *forDelete = innerTmp->next;
                innerTmp->next = forDelete->next;
                delete forDelete;
            }
            else
            {
                innerTmp = innerTmp->next;
            }
        }

        if (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
    }

    printList(head);

    return 0;
};