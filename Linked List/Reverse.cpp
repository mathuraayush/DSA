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

//Reversing a LL Naive approach using stack
Node* ReverseNaive(Node* head){
    Node* temp=head;
    stack<int> a;
    while(temp!=nullptr){
        a.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr && a.empty()!=true){
        temp->data=a.top();
        a.pop();
        temp=temp->next;
    }
    return head;
    
}
void swap(Node *&a){
    Node*temp=a->next;
    a->next=a->prev;
    a->prev=temp;
    
}
Node* ReverseBySwapping(Node* head){
    Node* temp=head;
    Node* NewHead=nullptr;
    while(temp!=nullptr){
        swap(temp);
        NewHead=temp;
        temp=temp->prev;
    }
    return NewHead;

}
int main()
{
    vector<int> arr = {12, 45, 89, 0, 75};
    Node *start = convertArrayToLL(arr);

    PrintLL(start);

    start=ReverseNaive(start);
    PrintLL(start);

    start=ReverseBySwapping(start);
    PrintLL(start);

}