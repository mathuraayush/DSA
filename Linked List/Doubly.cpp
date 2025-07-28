#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int data1, Node *prev1, Node *next1)
    {
        data = data1;
        prev = prev1;
        next = next1;
    }
    Node()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
    Node(int data1)
    {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node *convertArrayToLL(vector<int> a)
{
    if (a.empty())
        return nullptr;
    Node *head = new Node(a[0]);
    Node *current = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i]);
        current->next = temp;
        temp->prev = current;
        current = current->next;
    }
    return head;
}
// Searching
void Searching(Node *head, int target)
{
}

// Delete at start
Node *DeleteAtStart(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *newHead = head->next;
    if (newHead)
        newHead->prev = nullptr;
    delete head;
    return newHead;
}

// Delete at end
Node *DeleteAtEnd(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is already empty!" << endl;
        return nullptr;
    }
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    Node *lastNode = temp->next;
    temp->next = nullptr;
    delete lastNode;
    return head;
}
// Delete a Node with Value given
Node *DeleteTarget(Node *head, int target)
{

    // If LL is empty
    if (head == nullptr)
        return nullptr;
    // If head is the target
    if (head->data == target)
    {
        Node *newHead = head->next;
        head->next = nullptr;
        newHead->prev = nullptr;
        delete head;
        return newHead;
    }
    Node *temp = head;
    while (temp != nullptr && temp->data != target)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Node does'nt exist" << endl;
        return head;
    }

    // Now, temp is the node to be deleted
    // temp is the node to delete
    Node *newTemp = temp->prev;
    Node *newNext = temp->next;

    newTemp->next = newNext;
    if (newNext != nullptr)
    {
        newNext->prev = newTemp;
    }

    delete temp;
    return head;
}
// Deleting a given Node ; Given it is not Head
void DeleteGiven(Node *given)
{
    if (given->next == nullptr)
    {
        given->prev->next = nullptr;
    }
    else
    {
        given->next->prev = given->prev;
        given->prev->next = given->next;
    }
    delete given;
}

// Deleting Kth Node
Node *DeleteKthNode(Node *head, int k)
{
    // If LL is empty
    if (head == nullptr)
        return nullptr; // empty list
    Node *temp = head;
    int count = 1;
    // If deleting first node i.e head;
    if (k == 1)
    {
        Node *newHead = head->next;
        if (newHead != nullptr)
            newHead->prev = nullptr;
        delete head;
        return newHead;
    }
    while (temp && count != k)
    {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr)
    {
        cout << "K>Size of LL";
        return head;
    }
    else
    {
        if (temp->next == nullptr)
        {
            temp->prev->next = nullptr;
        }
        else
        {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
    }
    delete temp;
    return head;
}

// To print Linked List
void PrintLL(Node *head)
{
    Node *start = head;
    while (start != nullptr)
    {
        cout << start->data << " ";
        start = start->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {12, 45, 89, 0, 75};
    Node *start = convertArrayToLL(arr);

    PrintLL(start);
    //  while(temp->next != nullptr && temp->data != 89){
    //     temp=temp->next;
    //  }
    //  cout<<temp->prev->data;
    // start=DeleteAtStart(start);
    // PrintLL(start);
    // start=DeleteAtEnd(start);
    // PrintLL(start);
    // start=DeleteAtEnd(start);
    // PrintLL(start);
    // start=DeleteAtEnd(start);
    // PrintLL(start);
    // start=DeleteAtEnd(start);
    // PrintLL(start);
    // start=DeleteAtEnd(start);
    // PrintLL(start);
    start = DeleteTarget(start, 45);
    PrintLL(start);
}