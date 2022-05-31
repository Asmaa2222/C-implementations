#include <iostream>
using namespace std;
#include "LL.h"
LinkedList::LinkedList()
{
    head = NULL;
}
int LinkedList::first()
{
    if (head == NULL)
        cout << "There is no elements in the list\n";
    else
        return (head->data);
}

int LinkedList::last()
{
    Node *temp = head;
    while (temp->Next != NULL)
        temp = temp->Next;
    return (temp->data);
}
void LinkedList::Reverse()
{
    Node *temp = NULL;
    Node *CNode = head;
    while (CNode != NULL)
    {
        temp = CNode->Prev;
        CNode->Prev = CNode->Next;
        CNode->Next = temp;
        CNode = CNode->Prev;
    }
    if (temp != NULL)
        head = temp->Prev;
}
void LinkedList::printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << "\n";
}
bool LinkedList::remove(int val)
{
    if (head == NULL)
    {
        cout << "The list is empty\n";
        return false;
    }
    Node *temp;
    temp = head;
    if (temp->data == val)
    {
        head = temp->Next;
        if (head != NULL)
            head->Prev = NULL;
        delete temp;
        return true;
    }

    while (temp != NULL && temp->data != val)
        temp = temp->Next;

    if (temp == NULL)
        return false;
    else
    {
        temp->Prev->Next = temp->Next;
        if (temp->Next != NULL)
            temp->Next->Prev = temp->Prev;
        delete temp;
        return true;
    }
}
void LinkedList::insert(int val)
{
    Node *newnode = new Node;
    newnode->data = val;
    newnode->Next = NULL;
    newnode->Prev = NULL;

    if (head == NULL)
    {
        head = newnode;
        cout << "hi\n";
        return;
    }
    //  Node *temp = head;
    if (newnode->data <= head->data)
    {
        newnode->Next = head;
        head->Prev = newnode;
        head = newnode;
    }
    Node *Current = head;
    while (Current->Next != NULL)
    {
        if (newnode->data <= Current->data)
        {
            Current->Prev->Next = newnode;
            newnode->Prev = Current->Prev;
            newnode->Next = Current;
            Current->Prev = newnode;
        }

        Current = Current->Next;
    }

    Current->Next = newnode;
    newnode->Prev = Current;
}