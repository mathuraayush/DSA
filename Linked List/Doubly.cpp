#include <iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *prev;
    Node *next;


    Node(int data1, Node* prev1,Node* next1)
    {
        data = data1;
        prev=prev1;
        next = next1;
    }
    Node(){
        data=0;
        prev=nullptr;
        next=nullptr;
      
    }
    Node(int data1){
        data=data1;
        prev=nullptr;
        next=nullptr;
    }
};

Node* convertArrayToLL(vector<int> a){
    if(a.empty()) return nullptr;
    Node* head=new Node(a[0]);
    Node* current=head;
    for(int i=1;i<a.size();i++){
        Node* temp=new Node(a[i]);
        current->next=temp;
        temp->prev=current;
        current=current->next;
    }
    return head;

}
// To print Linked List
void PrintLL(Node* head){
    Node* start=head;
    while(start!=nullptr){
        cout<<start->data<<" ";
        start=start->next;
    }
    cout<<endl;
}
void deleteAtSpecific(Node* head,int target){
    Node
    while()
    Node* temp=tobedeleted->next;
    tobedeleted->prev->next=temp;
    delete tobedeleted;
}
int main(){
    vector<int> arr={12,45,89,0,75};
    Node* start=convertArrayToLL(arr);
    PrintLL(start);
    

     
}