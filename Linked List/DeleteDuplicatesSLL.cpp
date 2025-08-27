#include <iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(){
        data=0;
        next=nullptr;
      
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
void InsertAtEnd(Node* &head,int value){
    Node* start=head;
    Node* New=new Node(value);
    if(start==nullptr) {
        head=New;
        return;
    } 
    while(start->next){
        start=start->next;
    }
    start->next=New;
}
void PrintLL(Node* head){
    Node* start=head;
    while(start!=nullptr){
        cout<<start->data<<" ";
        start=start->next;
    }
    cout<<endl;
}
bool isExist(set<int>a,int target){
    if(a.find(target)!=a.end()) return true;
    return false;
}
void DeleteDuplicates(Node* &head){
  set<int> a;
  a.insert(head->data);
  Node* temp=head->next;
  Node* prev=head;
  while(temp!=nullptr){
    if(isExist(a,temp->data)){
        prev->next=temp->next;
    }
    else{
        a.insert(temp->data);
        prev=temp;

    }
    temp=temp->next;
  }
}
int main(){
    Node* head=new Node(10);
    InsertAtEnd(head,20);
    InsertAtEnd(head,10);
    InsertAtEnd(head,20);
    InsertAtEnd(head,30);
    InsertAtEnd(head,40);

    cout<<"Intially :"<<endl;
    PrintLL(head);

    cout<<"After :"<<endl;
    DeleteDuplicates(head);
    PrintLL(head);




    
}