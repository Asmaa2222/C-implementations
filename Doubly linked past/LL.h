#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *Next;
    Node *Prev;
};

class LinkedList
{
private:
    Node *head = new Node;

public:
    LinkedList()
    {
        // head = NULL;
    }
    int first()
    {
        if (head == NULL)
            cout << "There is no elements in the list\n";
        else
            return (head->data);
    }

    int last()
    {
        Node *temp = head;
        while (temp->Next != NULL)
            temp = temp->Next;
        return (temp->data);
    }

    void addFirst(int val)
    {
        Node *newnode = new Node;
        newnode->data = val;

        newnode->Next = head;
        newnode->Prev = NULL;
        if (head != NULL)
            head->Prev = newnode;
        head = newnode;
    }
    void addLast(int val)
    {
        Node *newnode = new Node;
        newnode->data = val;
        newnode->Next = NULL;
        newnode->Prev = NULL;
        if (head == NULL)
        {
            head = newnode;
            return;
        }

        Node *temp = head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        newnode->Prev = temp;
        temp->Next = newnode;
    }

    // void insertMiddle(int num1, int num2) // change this
    // {
    //     Node*newnode=new Node;
    //     newnode->data=num2;
    //         Node *temp = head;
    //     while(head->data=NULL&& temp->Next->data!=num1)
    //     temp=head->Next;

    // newnode->Next=temp->Next;
    // temp->Next=newnode;
    //     newnode->Prev=temp;
    // }
    //• insert(element): inserts an element in its correct place in the list. If the element already exists do nothing.
    void insert(int val)
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

    //     while (temp->Next != NULL && temp->data < val)
    //     cout<<"hi\n";
    //         temp = temp->Next;

    //     if (temp->data == val)
    //         return;
    //     else
    //     {
    //         newnode->Next = temp;
    //         //temp->Next = newnode;
    //         newnode->Prev = temp->Prev;
    //         temp->Prev=newnode;
    //     }
    // }

    bool remove(int val)
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

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->Next;
        }
        cout << "\n";
    }

    //  void printListR()
    // {
    //     Node *temp = head;
    //     if (temp == NULL) return;

    //     while (temp->Next != NULL)
    //     {
    //         temp = temp->Next;
    //     }

    //     while(temp != NULL) {
    //         cout << temp->data << " ";
    //         temp = temp->Prev;
    //     }
    //     cout << "\n";
    // }

    void reverse()
    {
        Node *temp = head;
        while (temp->Next != NULL)
            temp = temp->Next;
        while (temp != NULL)
        {
            // cout << temp->data << " ";
            temp = temp->Prev;
        }
    }

    void Reverse()
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

    //     {
    //         delete head;
    //     }
    // }

    //         head = head->next;

    //         delete temp;
};
// #include <iostream>
// #include "LL.h"

// using namespace std;

// LinkedList::LinkedList()
// {
//     head = NULL;
//     numberOfElement = 0;
// }

// void LinkedList::addFirst(int data)
// {
//     Node *newnode;
//     newnode->data = data;
//     if (head == NULL)
//     {
//         newnode->next = NULL;
//         head = newnode;
//     }
//     else
//     {
//         newnode->next = head;
//         head = newnode;
//     }
// }

// void LinkedList::addLast(int data)
// {
//     Node *temp = head;

//     while (head != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->data = data;
//     temp->next = NULL;
// }
// void LinkedList::insert(int data, int index)
// {
//     Node *temp = head;
//     while ((temp->data != NULL) && (temp->next->data != data))
//     {
//         temp->next = head->next;
//     }
//     temp->data = data;
//     temp->next = head->next;
// }

// void LinkedList::printList()
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data;
//         temp = temp->next;
//     }
// }
// int LinkedList::getNumberOfelements()
// {
//     int count = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         count++;
//         temp = temp->next;
//     }

//     return count;
// }

// void LinkedList::deleteFirst()
// {
//     if (head == NULL)
//     {
//         cout << "The list is empty\n";
//     }
//     else
//     {
//         Node *temp = head;
//         head = head->next;

//         delete temp;
//     }
// }
// void LinkedList::deleteLast()
// {
//     if (head->next == NULL)
//     {
//         delete head;
//     }
// }

// //     }

// // int main()
// // {
// //     LL data;
// //     for(int i=0; i<5; i++)
// //     {
// //         int x; cin>>x;
// //         data.inFirst(x);
// //     }
// //     data.display();

// //     return 0;
// // }