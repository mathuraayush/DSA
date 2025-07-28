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
int main(){
     
}