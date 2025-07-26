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
// Converting an array to LL
Node* convertArrayToLL(vector<int> a){
    if(a.empty()) return nullptr;
    Node* head=new Node(a[0]);
    Node* current=head;
    for(int i=1;i<a.size();i++){
        Node* temp=new Node(a[i]);
        current->next=temp;
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
}
// Length of LL
int LengthLL(Node* head){
    int count=0;
    Node*temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}
// Searching in a linklist
bool Ispresent(Node* head,int target){
    
    Node* temp=head;
    while(temp){
        if(temp->data==target){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int main()
{   // One Way 
    // Node* x= new Node(45,nullptr);
    // Node * y=new Node(33,nullptr);
    // x->next=y;
    // // Other Way
    // Node a=Node(45,nullptr);
    // Node b=Node(33,nullptr);

    // a.next=&b;

    // // Printing
    // //!st Method
    // Node* head=x;
    // while (head != nullptr)
    // {
        
    //     cout<<head->data<<" ";
    //     head=head->next;
    // }
    // cout<<endl;
    // //2nd Method
    // Node *start= &a;
    // while(start != nullptr){
    //     cout<<start->data<<" ";
    //     start=start->next;
    // }

    vector<int> arr={12,45,89,0,75};
    Node* start=convertArrayToLL(arr);
    PrintLL(start);
    int Length= LengthLL(start);
    cout<<endl;
    cout<<Length;
    cout<<endl;
    bool a = Ispresent(start,75);
    cout<<a;


    


}